#include <stdio.h>
#include <string.h>

#define MAX_LIMIT 100

int main() {
  char hello[] = "Hello";
  char name[MAX_LIMIT];

  printf("What is your name? ");

  scanf("%[^\n]s", name);

  printf("%s %s!\n\n", hello, name);

  /** Exercise 1**/
  char welcome[MAX_LIMIT];
  strcpy(welcome, hello);
  strcat(welcome, " ");
  strcat(welcome, name);
  printf("%s!\n", welcome);

  /** Exercise 2**/
  int nameLength = strlen(name);
  printf("%s%d%s\n","Your name is ", nameLength, " characters long.");
  
  /** Exercise 3**/
  char prof[8] = {'P','a','t','r','i','c','k','\0'};
  int resultsOfNameCompare = strcmp(name, prof);
  if (resultsOfNameCompare == 1) {
    printf("%s%s%s%s\n", name, " is after ", prof, ".");
  } else if (resultsOfNameCompare == 0) {
    printf("%s%s%s%s\n", name, " is ", prof, ".");
  } else {
    printf("%s%s%s%s\n", name, " is before ", prof, ".");  
  }
  return 0;
}
