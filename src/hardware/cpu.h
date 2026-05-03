#ifndef CPU_H
#define CPU_H

#include <stdint.h>
#include "bus.h"

#define UNITED_REG(ra, rb)\
  union {\
    struct {\
      uint8_t rb;\
      uint8_t ra;\
    };\
    uint16_t ra##rb;\
  }

#define UNITED_REG_RW(ra, rb)\
  uint8_t ra##_r : 1;\
  uint8_t ra##_w : 1;\
  uint8_t rb##_r : 1;\
  uint8_t rb##_w : 1

#define REG_IO(ra)\
  uint8_t ra;\
  uint8_t ra##_in  : 1;\
  uint8_t ra##_out : 1

typedef struct {
  BusData *bus;

  // Registers
  UNITED_REG(a, f);
  UNITED_REG(b, c);
  UNITED_REG(d, e);
  UNITED_REG(h, l);

  // R/W flags
  struct {
    UNITED_REG_RW(a, f);
    UNITED_REG_RW(b, c);
    UNITED_REG_RW(d, e);
    UNITED_REG_RW(h, l);
  } rwflags;

  REG_IO(ip); // Instruction pointer  (ADDR)
  REG_IO(ir); // Instruction register (BYTE)
  REG_IO(pc); // Program counter      (ADDR)

  uint8_t sc; // Step counter (Sub-step)
} CPU;

#endif // CPU_H

