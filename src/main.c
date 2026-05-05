#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "cpu.h"
#include "alu.h"
#include "ram.h"
#include "controlunit.h"

// #define printf // Fast mode, no logs

static const uint8_t PROGRAM[] = {
  1,
  2,
  3
};


static inline void printTable(void) {
  printf("++------++------++------++------++------++------++------++\n");
  printf("||  AF  ||  BC  ||  DE  ||  HL  ||  PC  || [HL] || [PC] ||\n");
  printf("++------++------++------++------++------++------++------++\n");
}


static void printState(ControlUnit *cu) {
  CPU *cpu = cu->cpu;
  RAM *ram = cu->ram;

  printf("||"
    "\x1b[95m %04X \x1b[0m||"
    "\x1b[95m %04X \x1b[0m||"
    "\x1b[95m %04X \x1b[0m||"
    "\x1b[95m %04X \x1b[0m||"
    "\x1b[95m %04X \x1b[0m||"

    "\x1b[95m  %02X  \x1b[0m||"
    "\x1b[95m  %02X  \x1b[0m||\n",
    cpu->af, cpu->bc, cpu->de, cpu->hl, cpu->pc, ram->data[cpu->hl], ram->data[cpu->pc]
  );
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

  printTable();
  while (!cu.halt) {
    printState(&cu);
    updateCU(&cu);
  }

  printf("++------++------++------++------++------++------++------++\n");
  printf("||                     \x1b[91m-> HALTED <-\x1b[0m                     ||\n");
  printTable();
  printState(&cu);
  printf("++------++------++------++------++------++------++------++\n");

  return 0;
}

