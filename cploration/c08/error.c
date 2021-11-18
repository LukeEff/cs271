#include "error.h"
#include <stdio.h>
#include <stdlib.h>

const char *error_messages[] = 
{
  [EXIT_INCORRECT_ARGUMENTS] = "Usage: %s [filename]",
};

void exit_program(enum exitcode code, ...)
{
  va_list arguments;
  va_start(arguments, code);

  printf("ERROR: ");
  vfprintf(stdout, error_messages[code], arguments);
  printf("\n");

  va_end(arguments);
  exit(code);
}
