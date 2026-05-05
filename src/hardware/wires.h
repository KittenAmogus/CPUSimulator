#ifndef WIRES_H
#define WIRES_H

#include <stdint.h>

#define PACKED __attribute__((packed))

typedef struct {
  struct {
    uint8_t data;
    uint16_t addr;
  } bus;

  struct {

    struct {
      struct {
        uint8_t a : 1;
        uint8_t f : 1;
        uint8_t b : 1;
        uint8_t c : 1;
        uint8_t d : 1;
        uint8_t e : 1;
        uint8_t h : 1;
        uint8_t l : 1;

        uint8_t pc : 1;
        uint8_t ir : 1;
        // UNUSED 6
      } PACKED read;

      struct {
        uint8_t a : 1;
        uint8_t f : 1;
        uint8_t b : 1;
        uint8_t c : 1;
        uint8_t d : 1;
        uint8_t e : 1;
        uint8_t h : 1;
        uint8_t l : 1;

        uint8_t pc : 1;
        uint8_t ir : 1;
      } PACKED write;
    } cpu;

    struct {
      uint8_t read  : 1;
      uint8_t write : 1;
      // UNUSED 6
    } PACKED ram;

    struct {
      uint8_t out : 1;
      uint8_t zro : 1;
      uint8_t ovf : 1;
      uint8_t neg : 1;

      uint8_t opcode : 3;
      // UNUSED 1
    } PACKED alu;

    // No RAISE and FALL, just diff
    uint8_t clck_prev : 1;
    uint8_t clck : 1;
    // UNUSED 6

  };
} PACKED Wires;

// No updateWires, they're just wires aren't they?

#endif // WIRES_H

