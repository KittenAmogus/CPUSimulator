#ifndef BUS_H
#define BUS_H

#include <stdint.h>

typedef struct {
  uint8_t data;
  uint8_t addr;
  uint8_t clck : 1;
} __attribute__((packed)) BusData;

#endif // BUS_H

