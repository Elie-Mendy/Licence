#include <stdlib.h>
#include <stdio.h>
#include "fonctions.c"


int main(int argc, char  *argv[]) {
  int i = 1;
  while(i < argc) printf("Le mot %d contient %d lettres.\n", i , size_x(argv[i++]));
  return 0;
}
