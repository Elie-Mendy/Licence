#include <stdio.h>
#include <stdlib.h>
#include "../usage.c"

#define MAX 4096


int main(int argc, char const *argv[]) {
  // test du nombre d'arguments
  if (argc < 2) usage("veuillez entrer le nom d'un fichier a lire");

  // ouverture du flux
  FILE * fichier = fopen(argv[1], "r");
  if (! fichier) usage("fichier illisible ");



  // affichage du contenu du fichier
  char ligne[MAX];
  while (fgets(ligne, MAX, fichier)) puts(ligne);

  // fermeture du flux
  fclose(fichier);

  return 0;
}
