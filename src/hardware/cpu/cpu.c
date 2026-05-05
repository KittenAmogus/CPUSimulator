#include "cpu.h"

#define UPDATE_REG_R(reg)\
  if (cpu->wires->cpu.read.reg) cpu->wires->bus.data |= cpu->reg;

#define UPDATE_REG_W(reg)\
  if (cpu->wires->cpu.write.reg) cpu->reg = cpu->wires->bus.data

void updateCPU(CPU *cpu) {
  // Read
  UPDATE_REG_R(a);
  UPDATE_REG_R(f);
  UPDATE_REG_R(b);
  UPDATE_REG_R(c);
  UPDATE_REG_R(d);
  UPDATE_REG_R(e);
  UPDATE_REG_R(h);
  UPDATE_REG_R(l);

  UPDATE_REG_R(pc);
  UPDATE_REG_R(ir);

  // Write
  UPDATE_REG_W(a);
  UPDATE_REG_W(f);
  UPDATE_REG_W(b);
  UPDATE_REG_W(c);
  UPDATE_REG_W(d);
  UPDATE_REG_W(e);
  UPDATE_REG_W(h);
  UPDATE_REG_W(l);

  UPDATE_REG_W(pc);
  UPDATE_REG_W(ir);
}

#undef UPDATE_REG_R
#undef UPDATE_REG_W

