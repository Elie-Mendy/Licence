#include <stdio.h>
#include <stdlib.h>
#include "usage.c"


/* les mots comportant des parenthèses doivent etre mis entre "<mot>"
   les mots entre guillemets perdent leur guillemets */

int main(int argc, char const *argv[]) {
  // test du nombre d'arguments
  if (argc < 2 ) usage(" veuillez indiquer un nom de fichier a lire");

  // ouverture du flux
  FILE * fichier = fopen(argv[1], "w");
  if (! fichier) usage ("fichier impossible a ouvrir");

  // ecriture des données
  while (*argv) fprintf(fichier, "%s ", *argv++);

  // fermeture du flux
  fclose(fichier);

  return 0;
}
