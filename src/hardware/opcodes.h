#ifndef OPCODES_H
#define OPCODES_H

typedef enum {
  OP_HLT      = 0x00,
  OP_NOP      = 0x01,

  OP_MOVR     = 0x02,
  OP_MOVI     = 0x03,

  OP_LOAD     = 0x04,
  OP_STR      = 0x05,

  OP_JMP_HL   = 0x06,
  OP_JMP      = 0x07,

  OP_JMP_ZRO  = 0x08,
  OP_JMP_OVF  = 0x09,
  OP_JMP_NEG  = 0x0A,

  OP_PUSH     = 0x0B,
  OP_POP      = 0x0C,

  OP_CALL     = 0x0D,
  OP_RET      = 0x0E,

  OP_INC      = 0x0F,
  OP_DEC      = 0x10,

  OP_ADD      = 0x11,
  OP_SUB      = 0x12,
  OP_SHIFTL   = 0x13,
  OP_SHIFTR   = 0x14,

  OP_AND      = 0x15,
  OP_OR       = 0x16,
  OP_NOT      = 0x17
} OpCode;

#endif // OPCODES_H

