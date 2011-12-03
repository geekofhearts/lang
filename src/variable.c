#include <stdlib.h>
#include "variable.h"

void ctype_variable_destructor(void* var) {
  variable_t* typed_var = (variable_t*)var;
  free(typed_var->name);
  free(typed_var->value);
}
