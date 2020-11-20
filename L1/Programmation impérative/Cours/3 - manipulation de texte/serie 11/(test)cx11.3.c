#include <stdio.h>
#include <stdlib.h>
#include "fonctions.c"


int main( int k, char * ldc[]){
  // parcours de la ldc + recherche d'option
  int inverse = 0;
  while(*++ldc){
    if (option_i(*ldc))
      inverse = 1;
  }
  // reinitialisation du pointeur ldc
  ldc -= k;
  // affichage des valeurs
  if (! inverse)
    afficher(ldc);

  else
    renverser(ldc, k);

  return 0;
}
