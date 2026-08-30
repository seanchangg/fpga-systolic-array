# Build in the container, flash from the Mac.
Q       ?= $(HOME)/quartus-build/q
PROJECT ?= blink
# The kit has an on-board USB-Blaster II behind the USB connector.
# Its FX2 chip is blank at power on. openFPGALoader uploads the
# firmware from FW on each first use after a power cycle.
CABLE   ?= usb-blasterII
FW       = $(HOME)/quartus-build/blaster_6810.hex
OFL      = openFPGALoader -c $(CABLE) --probe-firmware $(FW)
OUT      = output_files
CPF      = quartus_cpf -c -q 12.0MHz -g 3.3 -n p

# Every source of this project: blink.v, or uart.v plus uart_*.v.
SYN_SRCS = $(filter-out tb_%.v,$(wildcard $(PROJECT)*.v))

all: $(OUT)/$(PROJECT).sof

$(OUT)/$(PROJECT).sof: $(SYN_SRCS) $(PROJECT).qsf $(PROJECT).sdc
	$(Q) quartus_sh --flow compile $(PROJECT)

# Load into SRAM. Fast. Lost at power off.
# WARNING: A raw SOF-derived SVF erases the ICB before the CRAM load
# ("!Max 10 DSM Clear" .. "!Max 10 Program ICB"). That kills the CFM
# "Program Done Bit", so the flashed design no longer starts after a
# power cycle. The awk filter removes the flash section and keeps the
# CRAM load. See openFPGALoader issue #507.
load: $(OUT)/$(PROJECT).sof
	$(Q) $(CPF) $(OUT)/$(PROJECT).sof $(OUT)/$(PROJECT)_full.svf
	awk '/^!Max 10 DSM Clear/{s=1} /^!Max 10 Disable ISP/{s=0} !s' \
	    $(OUT)/$(PROJECT)_full.svf > $(OUT)/$(PROJECT)_sram.svf
	@grep -q '!Max 10 DSM Clear' $(OUT)/$(PROJECT)_sram.svf \
	    && { echo "ERROR: the flash-erase section survived the filter"; exit 1; } || true
	$(OFL) $(OUT)/$(PROJECT)_sram.svf

# Write the internal flash. Survives power off. The full SVF is correct
# here: the erase and the program steps are the purpose.
flash: $(OUT)/$(PROJECT).sof
	$(Q) $(CPF) $(OUT)/$(PROJECT).pof $(OUT)/$(PROJECT)_flash.svf
	$(OFL) $(OUT)/$(PROJECT)_flash.svf

# Simulate with Icarus Verilog. Give the testbench file:
#   make simulate                  (uses tb_blink.v)
#   make simulate TB=tb_uart.v
# Build and flash the UART bridge with:
#   make PROJECT=uart load
# The design sources are every *.v file that is not a tb_*.v file.
# Open the waveform dump with: surfer sim/<name>.fst
TB   ?= tb_$(PROJECT).v
SRCS  = $(filter-out tb_%.v,$(wildcard *.v))

simulate: $(TB) $(SRCS)
	@mkdir -p sim
	iverilog -g2012 -Wall -o sim/$(basename $(TB)).vvp $(TB) $(SRCS)
	cd sim && vvp $(basename $(TB)).vvp -fst
	@ls sim/*.fst sim/*.vcd 2>/dev/null || true

detect:
	$(OFL) --detect

clean:
	rm -rf $(OUT) sim db incremental_db *.qws *.rpt *.summary *.smsg *.done *.jdi
.PHONY: all load flash simulate detect clean
