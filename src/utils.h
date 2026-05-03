#ifndef UTILS_H
#define UTILS_H

#include "cpu.h"
#include "bus.h"
#include "alu.h"
#include "memory.h"
#include "control.h"

void resetWires(ControlUnit *cu);
void printState(ControlUnit *cu);
void step(ControlUnit *cu);

#endif // UTILS_H

