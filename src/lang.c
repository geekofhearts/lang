#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "lang.h"
#include "script.h"
#include "prompt.h"

char** parseopts(int, char**, int*);
void print_version_info(char*);
int file_exists(const char*);
void setup_error_handling(void);
void segfault_handler(int);

int main(int argc, char** argv) {
  
  setup_error_handling();
  
  if (argc > 1) {
    int* script_argc = (int*)malloc(sizeof(int));
    char** script_and_args = parseopts(argc, argv, script_argc);
    if (*(script_argc)) {
      return script(*(script_argc), script_and_args);
    }
    return 0;
  } else {
    print_version_info(argv[0]);
    return prompt();
  }
}

char** parseopts(int argc, char** argv, int* script_argc) {
  int i;
  char** script_and_args = NULL;
  for (i = 1; i < argc; i++) {
    if (!strcmp(argv[i], "-V")) {
      if (script_and_args != NULL) {
        free(script_and_args);
        *(script_argc) = 0;
        script_and_args = NULL;
      }
      print_version_info(argv[0]);
      break;
    } else if (file_exists(argv[i])) {
      *(script_argc) = argc - i;
      script_and_args = argv + i * sizeof(char);
      break;
    } else {
      printf("warning, unrecognised argument \"%s\"\n", argv[i]);
    }
  }
  return script_and_args;
}

void print_version_info(char* name) {
  printf("%s v%i.%i\n", name, __LANG_MAJOR_VERSION__, __LANG_MINOR_VERSION__);
}

int file_exists(const char* filename) {
  FILE *fp = fopen(filename,"r");
  if( fp ) {
    fclose(fp);
    return 1;
  }
  return 0;
}

void setup_error_handling(void) {
  struct sigaction* action = (struct sigaction*)malloc(sizeof(struct sigaction));
  
  action->sa_handler = &segfault_handler;
  sigemptyset(&(action->sa_mask));
  action->sa_flags = 0;
  
  sigaction(SIGSEGV, action, NULL);
}

void segfault_handler(int signal) {
  printf("ERROR: caught a segmentation fault: most likely the system refused to allocate the RAM you or lang requested.\n");
  printf("exiting now.\n");
  exit(1);
}



