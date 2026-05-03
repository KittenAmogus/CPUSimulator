#ifndef CONTROL_H
#define CONTROL_H

#include <stdint.h>
#include "bus.h"
#include "cpu.h"
#include "memory.h"

typedef struct {
  BusData *bus;
  CPU *cpu;
  ALU *alu;
  RAM *ram;

  uint8_t halt : 1;
} __attribute__((packed)) ControlUnit;

#endif // CONTROL_H

