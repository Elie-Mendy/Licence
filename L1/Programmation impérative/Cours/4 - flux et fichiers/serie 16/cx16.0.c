#include <stdio.h>
#include <stdlib.h>
#include "usage.c"

#define TAILLE_LIGNE 4096


int main(int argc, char const *argv[]) {
  // test du nombre d'arguments
  if (argc < 2 ) usage("veuillez saisir le nom d'un fichier a lire");

  // ouverture d'un flux
  FILE * fichier = fopen(argv[1], "r");
  if (! fichier) usage("fichier ilisible");

  // allocation d'espace our une ligne
  char ligne[TAILLE_LIGNE];

  // lecture du fichier (avec fgets)
  while (fgets(ligne, TAILLE_LIGNE, fichier)) puts(ligne);

  // technique pour supprimer le saut de ligne
  // char * fin_chaine  = strchr(ligne, '\n');   // suppression du '\n' causé par fgets
  // *fin_chaine = '\0';

  // fermeture du flux
  fclose(fichier);

  return 0;
}
