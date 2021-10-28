#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 200

char *strip(char *s);

void parse(FILE * file);

bool is_Atype(const char*);

bool is_label(const char*);

bool is_Ctype(const char*);

