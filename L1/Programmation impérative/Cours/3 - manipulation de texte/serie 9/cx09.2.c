#include <stdlib.h>
#include <stdio.h>

#include "fonctions.c"

int main(int argc, char *argv[]) {

  while (*argv) scan_r(*argv++);

  return 0;
}
