#include <stdio.h>
#include <string.h>

#include "utils.h"

void resetWires(ControlUnit *cu) {
  memset(cu->bus, 0, sizeof(BusData));
  memset(&(cu->cpu->rwflags), 0, sizeof(cu->cpu->rwflags));
  cu->cpu->ip_in = 0; cu->cpu->ip_out = 0;
  cu->cpu->ir_in = 0; cu->cpu->ir_out = 0;
  cu->cpu->pc_in = 0; cu->cpu->pc_out = 0;
  cu->cpu->sc = 0;
}

void step(ControlUnit *cu) {
  cu->halt = 1; 
}

void printState(ControlUnit *cu) {
  printf("CPU || ");
  printf("AF \x1b[94m%04X\x1b[0m | ", cu->cpu->af);
  printf("BC \x1b[94m%04X\x1b[0m | ", cu->cpu->bc);
  printf("DE \x1b[94m%04X\x1b[0m | ", cu->cpu->de);
  printf("HL \x1b[94m%04X\x1b[0m ", cu->cpu->hl);

  printf("|| ");
  printf("[HL] \x1b[95m%02X\x1b[0m | ",
    cu->ram->data[cu->cpu->hl]);
  printf("[PC] \x1b[95m%02X\x1b[0m ",
    cu->ram->data[cu->cpu->pc]);

  printf("||\n");
}

