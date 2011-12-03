#ifndef __LANG_LOCAL_VARIABLE_H__
#define __LANG_LOCAL_VARIABLE_H__ 47

typedef struct {
  char* name;
  void* value;
  void (*destructor)(void*);
} variable_t;

void ctype_variable_destructor(void*);

#endif
