#ifndef __ERROR_H__
#define __ERROR_H__

#include <stdarg.h>

/*
 * Error code 1 represents that given file does not exist.
 */
enum exitcode { EXIT_INCORRECT_ARGUMENTS = 1 };

void exit_program(enum exitcode code, ...);

#endif
