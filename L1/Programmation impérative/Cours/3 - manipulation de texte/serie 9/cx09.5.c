#include <stdlib.h>
#include <stdio.h>
#include "fonctions.c"

int main(int argc, char *argv[]) {
  argv++;
  int i = 1;
  while(*argv) printf("le mot %i contient %i lettres \n", i++ , size_r(*argv++) );

  return 0;
}
