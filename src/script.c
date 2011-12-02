
#include <stdio.h>
#include "script.h"
int script(int argc, char** argv) {
  printf("imma run script called %s now with args ", argv[0]);
  int i;
  for (i = 1; i < argc; i++) {
    printf("%s, ", argv[i]);
  }
  printf(" aaaand that's all.\n");
  return 0;
}
