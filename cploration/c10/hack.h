#include <string.h>
#include <stdint.h>

#define NUM_PREDEFINED_SYMBOLS 23

typedef enum symbol_id {
  SYM_R0 = 0,
  SYM_R1 = 1,
  SYM_R2 = 2,
  SYM_R3 = 3,
  SYM_R4 = 4,
  SYM_R5 = 5,
  SYM_R6 = 6,
  SYM_R7 = 7,
  SYM_R8 = 8,
  SYM_R9 = 9,
  SYM_R10 = 10,
  SYM_R11 = 11,
  SYM_R12 = 12,
  SYM_R13 = 13,
  SYM_R14 = 14,
  SYM_R15 = 15,
  SYM_SP = 0,
  SYM_LCL = 1,
  SYM_ARG = 2,
  SYM_THIS = 3,
  SYM_THAT = 4,
  SYM_SCREEN = 16384,
  SYM_KBD = 24576,
} symbol_id;

typedef enum jump_id {
  JMP_INVALID = -1,
  JMP_NULL,
  JGT,
  JEQ,
  JGE,
  JLT,
  JNE,
  JLE,
  JMP,
} jump_id;

typedef enum dest_id {
  DEST_INVALID = -1,
  DEST_NULL,
  M,
  D,
  MD,
  A,
  AM,
  AD,
  AMD,
} dest_id;

typedef enum comp_id {
  COMP_INVALID = -1,
  COMP_0 = 42,
  COMP_1 = 63,
  COMP_neg1 = 58,
  COMP_D = 12,
  COMP_A = 48,
  COMP_notD = 13,
  COMP_notA = 49,
  COMP_negD = 15,
  COMP_negA = 51,
  COMP_Dplus1 = 31,
  COMP_Aplus1 = 55,
  COMP_Dminus1 = 14,
  COMP_Aminus1 = 50,
  COMP_DplusA = 2,
  COMP_DminusA = 19,
  COMP_AminusD = 7,
  COMP_DandA = 0,
  COMP_DorA = 21,
  COMP_M = 64 + COMP_A,
  COMP_notM = 64 + COMP_notA,
  COMP_negM = 64 + COMP_negA,
  COMP_Mplus1 = 64 + COMP_Aplus1,
  COMP_Mminus1 = 64 + COMP_Aminus1,
  COMP_DplusM =  64 + COMP_DplusA,
  COMP_DminusM = 64 + COMP_DminusA,
  COMP_MminusD = 64 + COMP_AminusD,
  COMP_DandM = 64 + COMP_DandA,
  COMP_DorM = 64 + COMP_DorA,
} comp_id;

typedef struct {
  char name[10];
  int16_t address;
} predefined_symbol;

static const predefined_symbol predefined_symbols[NUM_PREDEFINED_SYMBOLS] = {
  {"R0", SYM_R0},
  {"R1", SYM_R1},
  {"R2", SYM_R2},
  {"R3", SYM_R3},
  {"R4", SYM_R4},
  {"R5", SYM_R5},
  {"R6", SYM_R6},
  {"R7", SYM_R7},
  {"R8", SYM_R8},
  {"R9", SYM_R9},
  {"R10", SYM_R10},
  {"R11", SYM_R11},
  {"R12", SYM_R12},
  {"R13", SYM_R13},
  {"R14", SYM_R14},
  {"R15", SYM_R15},
  {"SP", SYM_SP},
  {"LCL", SYM_LCL},
  {"ARG", SYM_ARG},
  {"THIS", SYM_THIS},
  {"THAT", SYM_THAT},
  {"SCREEN", SYM_SCREEN},
  {"KBD", SYM_KBD},
};

