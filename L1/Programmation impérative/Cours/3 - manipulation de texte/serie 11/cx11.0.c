#include <stdio.h>
#include <stdlib.h>

#include "fonctions.c"

int main(int argc, char *argv[]) {
  // parcour de la ldc
  int inverse = option_i(argv[1]);

  // affichage des mot selon option
  if (! inverse )
    afficher(argv);
  else
    renverser(argv, argc);

  return 0;
}
