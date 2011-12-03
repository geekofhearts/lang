#include <stdlib.h>
#include "error.h"
#include "context.h"
#include "variable.h"

context_t* context_create(void** local_vars, int thread_id, void** global_vars) {
  context_t* new_context = (context_t*)malloc(sizeof(context_t));
  
  new_context->local_variables = local_vars;
  new_context->thread_id = thread_id;
  new_context->global_variables = global_vars;
  
  return new_context;
}

void context_add_local_variable(context_t* context, void* local_variable) {
  int i = 0;
  
  while(context->local_variables[i] != NULL) {
    i++;
  }
  
  void** new_ptr = (void**)realloc((void*)context->local_variables, (i + 2) * sizeof(void*));
  
  new_ptr[i] = local_variable;
  new_ptr[i+1] = NULL;
  
  context->local_variables = new_ptr;
}

void context_destroy(void* the_context) {
  context_t* typed_context = (context_t*)the_context;
  variable_t* var = (variable_t*)typed_context->local_variables[0];
  int i;
  
  // free the local variables:
  for (i = 0; var != NULL; var = (variable_t*)(typed_context->local_variables[++i])) {
    var->destructor((void*)var);
  }
  free(typed_context->local_variables);
  
}




