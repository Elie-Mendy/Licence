#include <stdio.h>
#include <stdlib.h>
#include <string.h>   // modules sur les chaines
#include <math.h>    // module sur les fonctions mathématiques
#include "fichier.h"  // import de fichier persos


#define str char *    // remplacement d'expression dans le text
#define MAX 1024      // définition de constante de préprocésseur
#define HAUTEUR 600
#define LARGEUR 800
#define NB_PIXEL (HAUTEUR + LARGEUR)




/* constantes de préprocésseur prédéfinies
__LINE__: donne le numéro de la ligne actuelle.
__FILE__: donne le nom du fichier actuel.
__DATE__: donne la date de la compilation.
__TIME__: donne l'heure de la compilation.*/


#define COUCOU() printf("coucou!\n");     // définition d'une macro

#define RACONTER_SA_VIE(nom, prenom)  printf("je m'appelle %s %s\n", nom, prenom); \
                                      printf("j'Habite Chartres\n"); \
                                      printf("j'aime l'info\n");
#define MAJEUR(age)     if(age > 18)\
                          printf("Vous etes Majeur\n");


int main(int k ,  str argv[]) {
  COUCOU()
  RACONTER_SA_VIE("elie", "MENDY")                              // execution d'une macro

  MAJEUR(22)
  printf("ce fichier à été compilé le %s  a %s\n", __DATE__, __TIME__ );

  return 0;
}
