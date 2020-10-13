#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>                        // utilisation de la fonction toupper()
#include "fonctions.c"



int main(int argc, char const *argv[]) {
  /* initialisation des variables */
  size_t i = 0;
  int tours = 0;
  char lettre = 0;

  /* Selection du mot */
  char mot[] = "MARRON";

  /* creation du cache */
  char * cache = malloc(sizeof(char) * strlen(mot));
  for (i = 0 ; i < strlen(mot) ; i++ ){
    cache[i] = '*';
  }


  printf("le mot caché est %s\n", cache );

  /* jeu */
  printf("Bienvenu dans le Pendu !\n");
  /* boucle de jeu */
  do {
    printf("\nIl vous reste %i coups a jouer\n", tours);
    printf("Quel est le mot secret? %s\n", cache);
    printf("Proposez une lettre : ");
    lettre = lireCaractere();

    for (i = 0 ; i < strlen(mot) ; i ++){
      if (lettre == mot[i])
        cache[i] = lettre;
    }
    printf("\n");   // saut de ligne


} while(diff(mot, cache));

  printf("\nGagne ! Le mor secret etait bien : %s\n", cache);
  free(cache); // liberation de l'espace alloué
  return 0;
}
