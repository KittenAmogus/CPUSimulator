#ifndef RAM_H
#define RAM_H

#include <stdint.h>
#include "wires.h"

#define RAM_SIZE  0x10000

typedef struct {
  Wires *wires;
  uint8_t data[RAM_SIZE];
} RAM;

void updateRAM(RAM *ram);

#endif // RAM_H

