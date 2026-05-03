#ifndef ALU_H
#define ALU_H

#include <stdint.h>
#include "bus.h"

typedef struct {
  BusData *bus;
  uint8_t carry;
  uint8_t zero;
  uint8_t out;
} __attribute((packed)) ALU;

#endif // ALU_H

