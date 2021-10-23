#include "parser.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void parse(FILE * file) {
  char line[MAX_LINE_LENGTH] = {0};
  
   while (fgets(line, sizeof(line), file)) {
     strip(line);
     if (*line == NULL) {
       continue;
     }
     printf("%s\n", line);
   }
}

char *strip(char *s) {
  char s_new[sizeof(s) + 1];
  int i = 0;
  for (char *s2 = s; *s2; s2++) {
    if ((*s2 == '/') && (*(s2 + 1) == '/')) {
      break;
    } else if (!isspace(*s2)) {
      s_new[i++] = *s2;
    }
  }
  strcpy(s,s_new);
  return s;
}
