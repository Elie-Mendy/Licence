#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.c"

#define TAILLE_MOT 1024

int main(int argc, char const *argv[]) {
  // test du nb d'arguments
  if (argc < 2) usage("veuillez entrer un message a lire");

  // ouverture du flux
  FILE * fichier = fopen(argv[1], "r");
  if (! fichier) usage("fichier illisible");

  // allocation d'un espace pour 6 mots
  char * mots[7];

  // lecture des mots
  int i = 0;
  while( i <= 6) {
    // allocation d'un sas
    char sas[TAILLE_MOT];
    fscanf(fichier, "%s ", sas);
    mots[i++] = strdup(sas);
  }

  for(i = 0; i < 6 ; i++){
    printf("%s\n", mots[i]);
  }

  // fermeture du flux
  return 0;
}
