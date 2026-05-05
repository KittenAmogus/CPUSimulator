#ifndef ALU_H
#define ALU_H

#include <stdint.h>
#include "wires.h"

typedef enum {
  // Mathematical
  ALU_ADD,  // +=
  ALU_SUB,  // -=
  ALU_INC,  // ++

  // Logical
  ALU_OR,       // |=
  ALU_AND,      // &=
  ALU_NOT,      // ~
  ALU_SHIFT_R,  // >>
  ALU_SHIFT_L   // <<
} ALUOp;

typedef struct {
  Wires *wires;
  uint8_t *regA;
  uint8_t *regB;
  uint8_t res;    // OUT
} PACKED ALU;

void updateALU(ALU *alu);

#endif // ALU_H

