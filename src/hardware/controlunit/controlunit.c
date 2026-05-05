#include "alu.h"
#include "controlunit.h"

static inline void math(ControlUnit *cu, uint8_t opcode) {
  
}

static inline void jmpAddr(ControlUnit *cu, uint16_t addr) {
  cu->cpu->pc = addr;
}

static inline void loadNJump(ControlUnit *cu) {
  uint16_t addr = getAddr(cu, cpu->pc++);
  addr = (addr << 8) | getAddr(cu, cpu->pc++);
  jmpAddr(cu, addr);
}

static inline void movAddr(ControlUnit *cu, uint16_t addr, uint8_t byte) {
  cu->ram.data[addr] = byte;
}

static inline uint8_t getAddr(ControlUnit *cu, uint16_t addr) {
  return cu->ram.data[addr];
}

static void processCommand(ControlUnit *cu) {
  CPU *cpu = cu->cpu;
  ALU *alu = cu->alu;
  RAM *ram = cu->ram;

  switch (cpu->ir) {
    case OP_HLT: cu->halt = 1; break;
    case OP_NOP: break;

    case OP_MOVR:
      uint8_t dest = getAddr(cu, cpu->pc++);
      uint8_t src  = getAddr(cu, cpu->pc++);
      cpu->regs[dest] = cpu->regs[src];
      break;
 
    case OP_MOVI:
      uint8_t dest = getAddr(cu, cpu->pc++);
      uint8_t byte = getAddr(cu, cpu->pc++);
      cpu->regs[dest] = byte;
      break;

    case OP_LOAD:
      uint8_t dest  = getAddr(cu, cpu->pc++);
      uint16_t addr = getAddr(cu, cpu->pc++);
      addr = (addr << 8) | getAddr(cu, cpu->pc++);
      cpu->regs[dest] = getAddr(cu, addr);
      break;

    case OP_STR:
      uint8_t src   = getAddr(cu, cpu->pc++);
      uint16_t addr = getAddr(cu, cpu->pc++);
      addr = (addr << 8) | getAddr(cu, cpu->pc++);
      movAddr(cu, addr, cpu->regs[src]);
      break;

    case OP_JMP_HL:
      uint16_t addr = cpu->hl;
      jmpAddr(cu, addr);
      break;

    case OP_JMP:
      loadNJump(cu);
      break;

    case OP_JMP_ZRO:
      if (cu->wires->alu.zro) loadNJump(cu);
      break;

    case OP_JMP_OVF:
      if (cu->wires->alu.ovf) loadNJump(cu);
      break;

    case OP_JMP_NEG:
      if (cu->wires->alu.neg) loadNJump(cu);
      break;

    case OP_PUSH:
      uint8_t src = getAddr(cpu->pc++);
      movAddr(cu, cpu->sp--, src);
      break;

    case OP_POP:
      uint8_t dest = getAddr(cpu->pc++);
      cpu->regs[dest] = getAddr(++cpu->sp);
      break;

    case OP_CALL: break;
    case OP_RET : break;

    case OP_INC:
      math(cu, ALU_INC);
      break;

    default:
      cu->halt = 1; // Invalid command
  }
}

void updateCU(ControlUnit *cu) {
  updateCPU(cu->cpu);
  updateALU(cu->alu);
  updateRAM(cu->ram);

  cu->cpu->pc++;
}

