#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.c"

#define TAILLE_MOT 1024
int main(int argc, char const *argv[]) {
  // test du nombre d'arguments
  if (argc < 2) usage("veuillez entrer un fichier a lire ...");

  // allocation d'espace pour 4 mots
  char * mots[5];

  // ouverture du flux
  FILE * fichier = fopen(argv[1], "r");
  if (! fichier) usage("fichier illisible");

  // lecture des mots
  int i = 0;
  while (i < 4){
    char sas[TAILLE_MOT];     // allocation d'un sas
    fscanf(fichier, "%s ", sas);
    mots[i++] = strdup(sas);
  }

  // affichage des valeurs
  for (i = 0 ; i < 4 ; i ++){
    printf("%s\n", mots[i]);
  }
  // fermeture du flux
  fclose(fichier);

  return 0;
}
