
#include <stdio.h>
#include <stdlib.h>

//proto d'une fonction de comparaison pour trier des entier
int compare(int *, int *);



int main(int k, char * argv[]){

  // recuperation de la taille du vecteur
  int x, v[] = {7,4,1,0,8,5,2,9,6,3};     // dimension calculée par le compilateur
  size_t n = sizeof(v) / sizeof(int);      // taille totale rapportée a taille élément

  // comparaison des elements:
  // affichage non trié
  for (x = 0 ; x < n ; ++x) printf("%i : %i\n", x , v[x]) ;
  puts("\n");

  // tri
  qsort(v, n, sizeof(int), compare) ;                    // algo de COMPARAISON

  // affichage trié
  for (x = 0 ; x < n ; ++x) printf("%i : %i\n", x , v[x]) ;
  return 0;
}



// FONCTION DE COMPARAISON   --> fonction abrégée
int compare(int *n, int *m) { return *n < *m ? -1 : *n == *m ? 0 : 1 ; }
