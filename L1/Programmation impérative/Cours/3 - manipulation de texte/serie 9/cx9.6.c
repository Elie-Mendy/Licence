#include <stdio.h>
#include <stdlib.h>
#include "fonctions.c"


int main(int argc, char *argv[]) {
  // usage
  if (argc < 2)
    usage("veuillez saisir au minimum un mot a analyser (relancez le progarmme)");

  // programme
  argv++;
  int i = 1;
  while (*argv) printf("le mot %i contient %i caractères\n", i++, size_r(*argv++));
  return 0;
}
