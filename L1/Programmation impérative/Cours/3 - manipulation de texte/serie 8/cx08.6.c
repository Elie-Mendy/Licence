#include <stdlib.h>
#include <stdio.h>
#include "fonctions.c"

int main(int argc, char *argv[]) {
  // clause d'usage
  if (argc < 2)
    usage("veuillez relancer le progrmme avec un mot à analyser");

  // programme
  argv++;
  while (*argv) scan_r(*argv++);
  return 0;
}
