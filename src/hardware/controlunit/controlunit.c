#include "controlunit.h"

void updateCU(ControlUnit *cu) {
  updateCPU(cu->cpu);
  updateALU(cu->alu);
  updateRAM(cu->ram);

  cu->cpu->pc++;
  cu->halt = 1;
}

