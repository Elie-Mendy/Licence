#include <stdlib.h>
#include <stdio.h>
#include "fonctions.c"



int main(int argc, char const *argv[]) {
  // test du nombre d'arguments
  if (argc < 2) usage("veuillez entrer un fichier a lire");

  // ouverture du flux
  FILE * fichier = fopen(argv[1], "r");
  if (! fichier) usage("fichier illisible");

  // lecture des entiers
  int max, i, tab[10] = {0};

  for(max = 0; max < 10 ; max ++){
    fscanf(fichier, "%d ", &tab[max]);
  }

  // affichage des valeurs
  for (i = 0; i <= max-1 ; i++){
    printf("%i\n", tab[i]);
  }

  // fermeture du flux
  fclose(fichier);

  return 0;
}
