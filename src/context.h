#ifndef __LANG_CONTEXT_H__
#define __LANG_CONTEXT_H__ 17

typedef struct {
  void** local_variables;
  int thread_id;
  void** global_variables;
} context_t;

context_t* context_create(void** local_vars, int thread_id, void** global_vars);

void context_add_local_variable(context_t* context, void* local_variable);

void context_destroy(void* the_context);

#endif
