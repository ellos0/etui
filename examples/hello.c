#include <stdio.h>
#include <stdlib.h>

#include "etui.h"

int main(int argc, char** argv) {
  setup();
  
  printf("hello\n");
  
  fgetc(stdin);
  
  return 0;
}
