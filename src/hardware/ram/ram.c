#include "ram.h"

void updateRAM(RAM *ram) {
  // Read
  if (ram->wires->ram.read) {
    ram->wires->bus.data |= ram->data[ram->wires->bus.addr];
  }

  // Write
  if (ram->wires->ram.write) {
    ram->data[ram->wires->bus.addr] = ram->wires->bus.data;
  }
}

