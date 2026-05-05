#ifndef CONTROLUNIT_H
#define CONTROLUNIT_H

#include <stdint.h>
#include "wires.h"
#include "cpu.h"
#include "alu.h"
#include "ram.h"

typedef struct {
  Wires *wires;
  CPU *cpu;
  ALU *alu;
  RAM *ram;

  uint8_t halt : 1;
  // UNUSED 7
} PACKED ControlUnit;

void updateCU(ControlUnit *cu);

#endif // CONTROLUNIT_H

