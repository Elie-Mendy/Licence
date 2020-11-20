#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.c"

int main(int argc, char const *argv[]) {
  // test du nombre d'arguments
  if (argc <2) usage("veuillez saisir le nom d'un fichier a lire");

  // ouverture du flux
  FILE * fichier = fopen(argv[1], "r");
  if (! fichier) usage("fichier illisible");

  // recupération du nombre d'elements
  int i, nb = 0;
  fscanf(fichier, "%d ", &nb);

  // refuperation du format
  char format[10];
  fscanf(fichier, "%s ", format);

  // lecture des données

  for (i = 0; i < nb ; i ++){
      char sas[1024];
      fscanf(fichier, format, sas);
      printf("%s\n", sas);
  }



  // fermeture du flux
  fclose(fichier);




  return 0;
}
