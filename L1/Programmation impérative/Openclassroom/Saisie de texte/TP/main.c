/* Le but de ce Tp est de s'entrainer à la saisie de texte
Pour modifier les caractéristiques d'une structure */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include "fonctions.c"

int main(int argc, char const *argv[]) {
  // initialiser une personne
  Joueur zefy;
  // modifier ses caractéristiques
  definirJoueur(&zefy);

  // retours des données saisies
  printf("\n\nVoici les données de votre personnage\n");
  printf("nom : %s\n", zefy.nom);
  printf("prenom : %s\n", zefy.prenom);
  printf("age : %d\n", zefy.age);
  switch (zefy.classe){
    case 0:
      printf("classe : Magicien\n");
      break;
    case 1:
      printf("classe : Gierrier \n");
      break;
    case 2:
      printf("classe : Archer\n");
      break;
  }
  return 0;
}
