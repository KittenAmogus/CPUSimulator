#include <string.h>
#include <stdio.h>

#include "utils.h"

int main(void) {

  // Create hardware
  CPU cpu;
  RAM ram;
  ALU alu;
  BusData bus;
  ControlUnit cu;

  // Reset hardware
  memset(&cpu, 0, sizeof(CPU));
  memset(&ram, 0, sizeof(RAM));
  memset(&alu, 0, sizeof(ALU));
  memset(&bus, 0, sizeof(BusData));
  memset(&cu,  0, sizeof(ControlUnit));

  // Set bus pointers
  cpu.bus = &bus;
  ram.bus = &bus;
  alu.bus = &bus;
  cu.bus  = &bus;

  // Set CU pointers
  cu.cpu = &cpu;
  cu.ram = &ram;
  cu.alu = &alu;

  while (!cu.halt) {
    printState(&cu);
    step(&cu);
  }
  printf("-- HALTED --\n");
   printState(&cu);

	return 0;
}

