#include <string.h>
#include <stdint.h>
#include <string.h>

#include <stdio.h>

#define NUM_PREDEFINED_SYMBOLS 23

#define OPCODE_TO_BINARY(opcode) \
  (opcode & 0x8000 ? '1' : '0'), \
  (opcode & 0x4000 ? '1' : '0'), \
  (opcode & 0x2000 ? '1' : '0'), \
  (opcode & 0x1000 ? '1' : '0'), \
  (opcode & 0x0800 ? '1' : '0'), \
  (opcode & 0x0400 ? '1' : '0'), \
  (opcode & 0x0200 ? '1' : '0'), \
  (opcode & 0x0100 ? '1' : '0'), \
  (opcode & 0x0080 ? '1' : '0'), \
  (opcode & 0x0040 ? '1' : '0'), \
  (opcode & 0x0020 ? '1' : '0'), \
  (opcode & 0x0010 ? '1' : '0'), \
  (opcode & 0x0008 ? '1' : '0'), \
  (opcode & 0x0004 ? '1' : '0'), \
  (opcode & 0x0002 ? '1' : '0'), \
  (opcode & 0x0001 ? '1' : '0')

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
  COMP_M = COMP_A,
  COMP_notM = COMP_notA,
  COMP_negM = COMP_negA,
  COMP_Mplus1 = COMP_Aplus1,
  COMP_Mminus1 = COMP_Aminus1,
  COMP_DplusM =  COMP_DplusA,
  COMP_DminusM = COMP_DminusA,
  COMP_MminusD = COMP_AminusD,
  COMP_DandM = COMP_DandA,
  COMP_DorM = COMP_DorA,
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

static inline jump_id str_to_jumpid(const char *s) {
  jump_id id = JMP_INVALID;
  printf("Comparing:%s\n", s);
  if (s == NULL) {
    id = JMP_NULL;
  } else if (strcmp(s, "JGT") == 0) {
    id = JGT;
  } else if (strcmp(s, "JEQ") == 0) {
    id = JEQ;
  } else if (strcmp(s, "JGE") == 0) {
    id = JGE;
  } else if (strcmp(s, "JLT") == 0) {
    id = JLT;
  } else if (strcmp(s, "JNE") == 0) {
    id = JNE;
  } else if (strcmp(s, "JLE") == 0) {
    id = JLE;
  } else if (strcmp(s, "JMP") == 0) {
    id = JMP;
  }
  printf("Found:%d\n\n", id);
  return id;
}

static inline dest_id str_to_destid(const char *s) {
  dest_id id = DEST_INVALID;
  if (s == NULL) {
    id = DEST_NULL; 
  } else if (strcmp(s, "M") == 0) {
    id = M;
  } else if (strcmp(s, "D") == 0) {
    id = D;
  } else if (strcmp(s, "MD") == 0) {
    id = MD;
  } else if (strcmp(s, "A") == 0) {
    id = A;
  } else if (strcmp(s, "AM") == 0) {
    id = AM;
  } else if (strcmp(s, "AD") == 0) {
    id = AD;
  } else if (strcmp(s, "AMD") == 0) {
    id = AMD;
  }
  return id;
}

static inline comp_id str_to_compid(const char *s, int *a) {
  comp_id id = COMP_INVALID;
  if (strcmp(s, "0") == 0) {
    id = COMP_0;
  } else if (strcmp(s, "1") == 0) {
    id = COMP_1;
  } else if (strcmp(s, "-1") == 0) {
    id = COMP_neg1;
  } else if (strcmp(s, "D") == 0) {
    id = COMP_D;
  } else if (strcmp(s, "A") == 0) {
    id = COMP_A;
  } else if (strcmp(s, "!D") == 0) {
    id = COMP_notD;
  } else if (strcmp(s, "!A") == 0) {
    id = COMP_notA;
  } else if (strcmp(s, "-D") == 0) {
    id = COMP_negD;
  } else if (strcmp(s, "-A") == 0) {
    id = COMP_negA;
  } else if (strcmp(s, "D+1") == 0) {
    id = COMP_Dplus1;
  } else if (strcmp(s, "A+1") == 0) {
    id = COMP_Aplus1;
  } else if (strcmp(s, "D-1") == 0) {
    id = COMP_Dminus1;
  } else if (strcmp(s, "A-1") == 0) {
    id = COMP_Aminus1;
  } else if (strcmp(s, "D+A") == 0) {
    id = COMP_DplusA;
  } else if (strcmp(s, "D-A") == 0) {
    id = COMP_DminusA;
  } else if (strcmp(s, "A-D") == 0) {
    id = COMP_AminusD;
  } else if (strcmp(s, "D&A") == 0) {
    id = COMP_DandA;
  } else if (strcmp(s, "D|A") == 0) {
    id = COMP_DorA;
  } else if (strcmp(s, "M") == 0) {
    id = COMP_M;
    *a = 1;
  } else if (strcmp(s, "!M") == 0) {
    id = COMP_notM;
    *a = 1;
  } else if (strcmp(s, "-M") == 0) {
    id = COMP_negM;
    *a = 1;
  } else if (strcmp(s, "M-1") == 0) {
    id = COMP_Mminus1;
    *a = 1;
  } else if (strcmp(s, "M+1") == 0) {
    id = COMP_Mplus1;
    *a = 1;
  } else if (strcmp(s, "D+M") == 0) {
    id = COMP_DplusM;
    *a = 1;
  } else if (strcmp(s, "D-M") == 0) {
    id = COMP_DminusM;
    *a = 1;
  } else if (strcmp(s, "M-D") == 0) {
    id = COMP_MminusD;
    *a = 1;
  } else if (strcmp(s, "D&M") == 0) {
    id = COMP_DandM;
    *a = 1;
  } else if (strcmp(s, "D|M") == 0) {
    id = COMP_DorM;
    *a = 1;
  }
  return id;
}



