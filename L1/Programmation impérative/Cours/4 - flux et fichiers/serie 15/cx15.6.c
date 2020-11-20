#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.c"

#define TAILLE_MOT 1024

int main(int argc, char const *argv[]) {
  // test du nb d'arguments
  if (argc < 2) usage("veuillez entrer le nom d'un fichier a lire");

  // ouverture du flux
  FILE * fichier = fopen(argv[1], "r");
  if (! fichier) usage ("fichier illisible");

  // allocation d'espace pour la data
  char * mots[4];   // 3 mots + NULL
  int tab[3] = {0}; // stoquage de 3 entiers

  // lecture des données
  int i = 0;
  while (i < 3){
    char sas[TAILLE_MOT];   // allocation d'un espace de recuperation des mots
    fscanf(fichier, "%s ", sas);
    mots[i++] = strdup(sas);
  }
  // affichage des mots;
  printf("%i mots : \n", i);
  for (i = 0 ; i < 3 ; i++){
    printf("%s\n", mots[i]);
  }


  // lecture des nombres
  for (i = 0; i< 3 ; i++){
    fscanf(fichier, "%i ", &tab[i]);
  }


  // affichage des valeurs
  printf("%i nombres\n", i );
  for (i = 0 ; i < 3 ; i++){
    printf("%i\n", tab[i]);
  }
  return 0;
}
