# MAX 10 FPGA Development Kit — board reference

Board: **DK-DEV-10M50-A**, PCB 100-0321401 Rev C
Device: **10M50DAF484C6GES**, 484-pin FineLine BGA

Source for every pin below: **UG-01169**, *MAX 10 FPGA Development Kit User
Guide*, 2015-11-06. Altera no longer serves the PDF directly; a mirror lives at
`https://docs.rs-online.com/daea/0900766b8148c950.pdf`.

Keep this file. The pin numbers are not derivable from the device datasheet.
They depend on how this board is wired, and that record is a 2015 document.

---

## Device resources (UG-01169 Table 4-2)

| Item | Count |
|---|---|
| Equivalent LEs | 50,000 |
| M9K memory | 1,638 Kb |
| Total RAM | 736 Kb + M9K |
| 18x18 multipliers | 144 |
| PLLs | 4 |
| Transceivers | none |

Quartus reports the usable figures as 49,760 LEs, 1,677,312 memory bits,
288 nine-bit multiplier elements, 4 PLLs, 1 UFM block and 2 ADC blocks.

---

## Clocks (UG-01169, On-Board Oscillators)

| Signal | Frequency | I/O standard | FPGA pin |
|---|---|---|---|
| `CLK_25_MAX10` | 25 MHz | 2.5 V LVDS | **M8** |
| `CLK_50_MAX10` | 50 MHz | 2.5 V LVDS | **M9** |
| `CLK_DDR3_100_P` | 100 MHz | 2.5 V LVDS | **N14** |
| `CLK_DDR3_100_N` | 100 MHz | 2.5 V LVDS | **N15** |
| `CLK_25_ENET` | 25 MHz | 2.5 V LVDS | Ethernet PHY, not the FPGA |
| `CLK_50_MAXII` | 25 MHz | 2.5 V LVDS | MAX II USB-Blaster II, not the FPGA |
| `CLK_LVDS_125` | 125 MHz | 2.5 V LVDS | see the user guide |

The oscillators are LVDS. Existing designs drive `clk` as single-ended
`2.5 V` on M9 and that works.

---

## User LEDs (Table 4-10)

Green. **The LED is on when the pin is low.**

| Board ref | Signal | FPGA pin | I/O standard |
|---|---|---|---|
| D15 | `USER_LED0` | **T20** | 1.5 V |
| D16 | `USER_LED1` | **U22** | 1.5 V |
| D17 | `USER_LED2` | **U21** | 1.5 V |
| D18 | `USER_LED3` | **AA21** | 1.5 V |
| D19 | `USER_LED4` | **AA22** | 1.5 V |

## User push buttons (Table 4-8)

Low while pushed.

| Board ref | Signal | FPGA pin | I/O standard |
|---|---|---|---|
| S1 | `USER_PB0` | **L22** | 1.5 V |
| S2 | `USER_PB1` | **M21** | 1.5 V |
| S3 | `USER_PB2` | **M22** | 1.5 V |
| S4 | `USER_PB3` | **N21** | 1.5 V |

## User DIP switches (Table 4-9)

| Board ref | Signal | FPGA pin | I/O standard |
|---|---|---|---|
| SW1.1 | `USER_DIPSW0` | **H21** | 1.5 V |
| SW1.2 | `USER_DIPSW1` | **H22** | 1.5 V |
| SW1.3 | `USER_DIPSW2` | **J21** | 1.5 V |
| SW1.4 | `USER_DIPSW3` | **J22** | 1.5 V |
| SW2.1 | `USER_DIPSW4` | **G19** | 1.5 V |

> **Conflict in the document.** Table 4-6 lists SW2.1 `USER_DIPSW4` at
> **H21**, which Table 4-9 assigns to `USER_DIPSW0`. Table 4-9 is the
> specific table, so prefer **G19**. Confirm against the schematic before
> you rely on SW2.1.

## General push buttons (Table 4-7)

| Board ref | Signal | FPGA pin | I/O standard |
|---|---|---|---|
| S5 | `PULSE_NCONFIG` | **H9** | 3.3 V |
| S6 | `CPU_RESETn` | **D9** | 3.3 V |

---

## USB to UART (Table 4-21)

Connector **J11**, the mini-USB port marked *USB to UART*. Bridge chip is an
**FT232R** (U11). The I/O sits in **Bank 4**.

| U11 pin | Signal | FPGA pin | I/O standard | Description |
|---|---|---|---|---|
| U11.2 | `UART_TX` | **W18** | 2.5 V | Transmit asynchronous data output |
| U11.30 | `UART_RX` | **Y19** | 2.5 V | Receive asynchronous data input |

**The names are written from the FT232R side.** The bridge chip drives
`UART_TX`, so W18 is the **FPGA input**. The FPGA drives `UART_RX`, so
Y19 is the **FPGA output**. This deduction rests on the description column,
not on the names. If a link stays silent, swap the two.

Status LEDs for this port: D13 `UART_TXLED`, D14 `UART_RXLED`, both green.

---

## Pmod connectors (Tables 4-19 and 4-20)

Two 12-pin Digilent Pmod headers, 8 I/O each, on **Bank 8**. Each carries
`VCC` at 3.3 V and `GND`.

| Pmod A | FPGA pin | | Pmod B | FPGA pin |
|---|---|---|---|---|
| `PMODA_D0` | **C7** | | `PMODB_D0` | **E8** |
| `PMODA_D1` | **C8** | | `PMODB_D1` | **D5** |
| `PMODA_D2` | **A6** | | `PMODB_D2` | **B5** |
| `PMODA_D3` | **B7** | | `PMODB_D3` | **C4** |
| `PMODA_D4` | **D8** | | `PMODB_D4` | **A2** |
| `PMODA_D5` | **A4** | | `PMODB_D5` | **A3** |
| `PMODA_D6` | **A5** | | `PMODB_D6` | **B4** |
| `PMODA_D7` | **E9** | | `PMODB_D7` | **B3** |

All 3.3 V. Connector references are J4 (Pmod A) and J5 (Pmod B).

> One vendor summary claims the Pmod power pins run at 2.5 V. The user guide
> says 3.3 V for both the I/O and `VCC`. Check the schematic before you
> connect a module that cannot tolerate the wrong rail.

---

## Analog

The MAX 10 ADC inputs are dedicated pins, so they carry no ordinary pin
assignment. The board routes them like this:

| ADC | SMA connector | Channels |
|---|---|---|
| ADC 1 | `ANAIN1_SMA` (**J18**) | `ADC1_CH0..CH7` on J20 odd pins 1,3,5,7,11,13,15,17 |
| ADC 2 | `ANAIN2_SMA` (**J19**) | channels 0..7 on J20 even pins 2,4,6,8,12,14,16,18 |

The potentiometer feeds ADC 1 channel 6. Jumper **J7** selects the source:
J7.1 selects `POT1`, J7.2 selects the header pin J20.15.

The 16-bit DAC output leaves the board on SMA **J1** (`DACOUT`).

---

## Board setup switches (Table 4-6)

| Board ref | Signal | Device / pin | I/O standard |
|---|---|---|---|
| SW2.2 | `CONFIG_SEL` | MAX 10 / **H10** | 3.3 V |
| SW2.3 | `VTAP_BYPASSN` | MAX II / **P17** | 3.3 V |
| SW2.4 | `HSMC_BYPASSn` | MAX II / **P18** | 3.3 V |

> **SW2.3 must stay ON.** With it off, the VTAP10 TAP (idcode `0x020D10DD`)
> joins the JTAG chain and blocks `openFPGALoader`. Verified 2026-08-23:
> with SW2.3 on, the chain reports idcode `0x31050DD`.

---

## Connectors, for orientation

| Reference | What it is |
|---|---|
| J1 | SMA, DAC output |
| J2 | HSMC connector |
| J4, J5 | Pmod A, Pmod B |
| J8 | HDMI output |
| J11 | mini-USB, USB to UART (FT232R) |
| J12 | mini-USB, on-board USB-Blaster II |
| J14 | 10-pin JTAG header |
| J15 | 12 V DC input |
| J18, J19 | SMA, ADC inputs ANAIN1 and ANAIN2 |
| J20 | 2x10 ADC and GPIO header |
| RJ1 | dual Gigabit Ethernet |
| SW3 | power switch |

---

## Not recorded here

DDR3, HSMC, HDMI and QSPI flash pin tables are large and live in UG-01169
sections 4-17 through 4-30. The board schematic ships with the kit and is the
final authority whenever the user guide and the GHRD disagree.

Quartus also writes `output_files/<project>.pin` on every compile. That file
lists the final location of every port, including any the fitter chose for
you. Read it to see what actually happened.
