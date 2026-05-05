#ifndef CPU_H
#define CPU_H

#include <stdint.h>
#include "wires.h"

#define REG_UNITED(a, b)\
  union {\
    struct {\
      uint8_t a;\
      uint8_t b;\
    };\
    uint16_t a##b;\
  }

typedef struct {
  Wires *wires;

  struct {
    REG_UNITED(a, f); // AF
    REG_UNITED(b, c); // BC
    REG_UNITED(d, e); // DE
    REG_UNITED(h, l); // HL
  } PACKED;

  uint8_t ir;
  uint16_t pc;

} CPU;

void updateCPU(CPU *cpu);

#endif // CPU_H

