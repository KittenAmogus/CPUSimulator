#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "cpu.h"
#include "alu.h"
#include "ram.h"
#include "controlunit.h"


const uint8_t PROGRAM[] = {
  1,
  2,
  3
};


void printState(ControlUnit *cu) {
  CPU *cpu = cu->cpu;
  RAM *ram = cu->ram;

  printf(" || CPU || ");
  printf("AF %04X | ", cpu->af);
  printf("BC %04X | ", cpu->bc);
  printf("DE %04X | ", cpu->de);
  printf("HL %04X", cpu->hl);

  printf("  ||\n || RAM || ");
  printf("HL %04X [HL] %04X | ", cpu->hl, ram->data[cpu->hl]);
  printf("PC %04X [PC] %04X", cpu->pc, ram->data[cpu->pc]);

  printf(" ||\n\n");
}


int main(void) {

  // Create hardware & wires
  Wires wires;
  CPU cpu;
  ALU alu;
  RAM ram;
  ControlUnit cu;

  // Reset hardware
  memset(&wires, 0, sizeof(Wires));
  memset(&cpu, 0, sizeof(CPU));
  memset(&alu, 0, sizeof(ALU));
  memset(&ram, 0, sizeof(RAM));
  memset(&cu, 0, sizeof(ControlUnit));

  // Connect wires
  cpu.wires = &wires;
  alu.wires = &wires;
  ram.wires = &wires;
  cu.wires = &wires;

  // Connect hardware
  cu.cpu = &cpu;
  cu.alu = &alu;
  cu.ram = &ram;

  // Connect registers
  alu.regA = &(cpu.a);
  alu.regB = &(cpu.b);

  // Load program
  memcpy(ram.data, PROGRAM, sizeof(PROGRAM));

  while (!cu.halt) {
    printState(&cu);
    updateCU(&cu);
  }

  printf("==> HALTED <==\n");
  printState(&cu);

  return 0;
}

