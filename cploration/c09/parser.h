#ifndef __PARSER_H__
#define __PARSER_H__
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "symtable.h"
#include "hack.h"

#define MAX_LINE_LENGTH 200
#define MAX_LABEL_LENGTH MAX_LINE_LENGTH - 2
#define MAX_HACK_ADDRESS INT16_MAX
#define MAX_INSTRUCTIONS MAX_HACK_ADDRESS // use this when not testing
//#define MAX_INSTRUCTIONS 1 // use this for testing
typedef int16_t hack_addr;
typedef int16_t opcode;

enum instr_type {
  Invalid = -1,
  A_TYPE,
  C_TYPE,
};

typedef struct c_instruction {
  opcode a:1;
  opcode comp:6;
  opcode dest:3;
  opcode jump:3;
} c_instruction;

typedef struct a_instruction {
  union {
    hack_addr address;
    char * label;
  };
  bool is_addr;
} a_instruction;

typedef struct instruction {
  union {
    a_instruction a_instr;
    c_instruction c_instr;
  };
  bool instr_type;
} instruction;

char *strip(char *s);

void parse(FILE * file);

bool is_Atype(const char*);

bool is_label(const char*);

bool is_Ctype(const char*);

char *extract_label(const char *line, char* label);

void add_predefined_symbols();

bool parse_A_instruction(const char *line, a_instruction *instr);

#endif
