#include <stdio.h>
#include <stdlib.h>
#include "fonctions.c"


int main(int k, char *argv[]) {
  int i = 1;
  while (i < k) scan_x(argv[i++]);
  return 0;
}
