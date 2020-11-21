#include <stdio.h>
#include <stdlib.h>
#include "usage.c"
#include "fonctions.c"

#define max_mots 128                                // nombre maximum d'éléments dans la table de mots
#define max_refs 16                                 // nombre maximum de ref par mots
#define maximum 4096                                // taille d'acceuil d'une ligne

typedef unsigned idx ;                              // definition du type idx
typedef char * str;                                 // definirion du type str



int main(int argc, char const *argv[]) {

  // test du nombre d'arguments
  if (argc < 2) usage(" veuillez indiquer le nom du fichier a lire");

  // ouverture du flux
  FILE * fichier = fopen(argv[1], "r");
  if ( ! fichier) usage(" fichier illisible");


  // allocation d'espace pour la ligne du texte
  char ligne[maximum];

  // indexation
  idx i = 0;
  while (fgets(ligne, maximim, fichier))
    indexe(ligne, ++x)                                    // fonction a créer

  // fermeture du flux
  fclose(fichier);

  // affichage de l'indexe
  dump (mot_libre);                                       // fonction a créer

  return 0;
}
