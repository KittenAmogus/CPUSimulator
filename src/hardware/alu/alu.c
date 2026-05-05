#include "alu.h"

#define REGA (*alu->regA)
#define REGB (*alu->regB)

static void add(ALU *alu) {
  alu->res = REGA + REGB;
  alu->wires->alu.ovf = ((uint16_t)REGA + (uint16_t)REGB > 0xFF);
};

static void sub(ALU *alu) {
  alu->res = REGA - REGB;
  alu->wires->alu.neg = REGA < REGB;
};

static void inc(ALU *alu) {
  alu->wires->alu.ovf = REGA == 0xFF;
  alu->res = REGA + 1;
};

static void or(ALU *alu) {
  alu->res = REGA | REGB;
};

static void and(ALU *alu) {
  alu->res = REGA & REGB;
};

static void not(ALU *alu) {
  alu->res = ~REGA;
};

static void shiftR(ALU *alu) {
  alu->res = REGA << 1;
};

static void shiftL(ALU *alu) {
  alu->res = REGA >> 1;
};

void updateALU(ALU *alu) {

  // Update res
  switch (alu->wires->alu.opcode) {
    case ALU_ADD: add(alu); break;
    case ALU_SUB: sub(alu); break;
    case ALU_INC: inc(alu); break;

    case ALU_OR:      or(alu); break;
    case ALU_AND:     and(alu); break;
    case ALU_NOT:     not(alu); break;
    case ALU_SHIFT_R: shiftR(alu); break;
    case ALU_SHIFT_L: shiftL(alu); break;
  };

  // Update ZRO flag
  alu->wires->alu.zro = alu->res == 0;

  // Write
  if (alu->wires->alu.out)
    alu->wires->bus.data |= alu->res;
}

#undef REGA
#undef REGB

