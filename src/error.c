#include <stdio.h>
#include <stdlib.h>
#include "error.h"

void raise_error(char* message) {
  printf("ERROR: %s\n", message);
  exit(1);
}

