#include <stdio.h>
#include <stdlib.h>
#define str char *



int main(int argc, char const *argv[]) {
  while (*argv) { puts(*argv++); };
  return 0;
}
