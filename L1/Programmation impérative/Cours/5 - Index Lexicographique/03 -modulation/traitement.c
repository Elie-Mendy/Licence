#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned idx ;                              // definition du type idx
typedef char * str;                                 // definirion du type str
typedef enum {False, True} bool ; // nouveau type


#define max_mots 128                                // nombre maximum d'éléments dans la table de mots
#define max_refs 16                                 // nombre maximum de ref par mots
#define maximum 4096                                // taille d'acceuil d'une ligne





// allocation d'espace pour:
char * mots[max_mots];              // l'index de mots
idx refs[max_mots][max_refs];       // la table de references associée
idx ref_libre[max_mots];            // la table indiquant les indices des ref_libre
char ligne[maximum];                // la ligne de texte a indexer
idx mot_libre = 0;                  // l'index indiquant le mot libre (au départ 0)

// definition d'une liste de caractères a exclure
// on se sert de ces caractères pour découper la ligne de texte
const str split_chars = "(., ;'\n!)";



#include "fonctions.c"
#include "usage.c"


int main(int k, char const *argv[]) {

  // test du nombre d'arguments
  if (k < 2) usage(" veuillez indiquer le nom du fichier a lire");

  // ouverture du flux
  FILE * fichier = fopen(argv[1], "r");
  if ( ! fichier) usage(" fichier illisible");


  /* TRAITEMENT */
  // boucle d'indexation de chaque ligne
  idx i = 0;                                // i represente le numéro de ligne
  while (fgets(ligne, maximum, fichier))
    indexe(ligne, ++i);

  // fermeture du flux
  fclose(fichier);

  // affichage de l'indexe
  dump (mot_libre);

  return 0;
}
