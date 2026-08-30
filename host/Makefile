CXXFLAGS ?= -std=c++17 -O2 -Wall -Wextra

probe: probe.cpp fpga.hpp
	$(CXX) $(CXXFLAGS) -o $@ probe.cpp

clean:
	rm -f probe
.PHONY: clean
