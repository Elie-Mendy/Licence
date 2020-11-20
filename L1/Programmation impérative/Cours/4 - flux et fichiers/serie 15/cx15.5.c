#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fonctions.c"

#define TAILLE_MOT 1024

int main(int argc, char const *argv[]) {
  // test nb arguments
  if ( argc < 2) usage("entrez un nom de fichier");

  // ouverture du flux
  FILE * fichier = fopen(argv[1], "r");
  if (! fichier) usage("fichier illisible");

  // allocation d'espace pour les données
  char * mots[4];    // 3 mots + NULL
  int  cote[3];     // 3 entiers


  // lecture des données
  int i = 0;
  while( i < 3){
    char sas[TAILLE_MOT];
    fscanf(fichier, "%s %d ", sas, &cote[i]);
    mots[i++] = strdup(sas);
  }

  // affichage des données
  for (i = 0 ; i < 3 ; i++){
    printf(" %s à une cote de %i\n", mots[i], cote[i] );
  }

  // fermeture du flux
  fclose(fichier);

  return 0;
}
