#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>                        // utilisation de la fonction toupper()
#include "fonctions.c"



int main(int argc, char const *argv[]) {
  /* INITIALISATION DES VARIABLES */
  size_t i = 0;
  int tours = 0, nb_mots = 0, index;
  char lettre = 0, mot[100];

  /* SELECTION DU MOT */
  // lecture du fichier dictionnaire
  FILE * dico = fopen("dictionnaire.txt", "r");
  // test du flux
  if (! dico)
    usage("lecture du dictionnaire impossible");

  // comptage du nombre de mot dans le dico
  nb_mots = compterMots(dico);

  // selection d'un nombre au hasard entre 1 et nb_mots
  srand(time(NULL));
  index = (rand() % (nb_mots - 1+1)) + 1;

  // placement dans le Fichier
  placerCurseur(dico, index);

  // lecture du mot et suppression du saut de ligne a la fin:
  fgets(mot, 100, dico);
  mot[strlen(mot) - 1] = '\0';





  /* CREATION DU CACHE */
  // creation d'un pointeur
  char * cache = malloc(sizeof(char) * strlen(mot));
  // test du pointeur
  if (! cache)
    usage("erreur lors de l'initialisation du pointeur");
  for (i = 0 ; i < strlen(mot) ; i++ ){
    cache[i] = '*';
  }




  /* BOUCHE DE JEU */
  printf("Bienvenu dans le Pendu !\n");
  /* boucle de tours */
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


} while((diff(mot, cache)) && tours);

  printf("\nGagne ! Le mot secret etait bien : %s\n", cache);
  free(cache); // liberation de l'espace alloué
  return 0;
}
