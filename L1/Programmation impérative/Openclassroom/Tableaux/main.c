#include <stdio.h>
#include <stdlib.h>
#include "fonctions.c"


int main(int k, char * argv[]){

  int i, tab[5] = {1,2,3,4,5};
  printf("la somme des valeurs de tab est : %i\n", sommeTableau(tab, 5));

  printf("la moyenne des valeurs est égale à : %i\n", moyenneTableau(tab, 5));

  int copie[5] = {0};
  printf("voici la copie du tableau (à l'envers):   \n");
  copierTableau(tab, copie, 5);
  for ( i = 0; i < 5 ; i++)
    printf("%i\n", copie[i]);


  printf("le maximum dans le tableau est %i\n", maximumTableau(tab, 5) );

  printf("Tri du tableau : \n");
  for (i = 0; i < 5 ; i++)
    printf("%i\n", tab[i]);
  return 0;
}
