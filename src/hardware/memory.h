#ifndef RAM_H
#define RAM_H

#include <stdint.h>
#include "bus.h"

#define RAM_SIZE 256

typedef struct {
  BusData *bus;

	uint8_t data[RAM_SIZE];
	uint8_t read  : 1;
	uint8_t write : 1;
} RAM;


#endif // RAM_H

