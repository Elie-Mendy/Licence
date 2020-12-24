#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* A CONTINUER DE TRAVAILLER */


// proto de la fonction de COMPARAISON
int compare(char * mot1, char * mot2);

int main(int argc, char const *argv[]) {

  int x;
  char * index[] = {"avec", "ouer", "sans", "toie", "c't", "reil"};

  // recuperationde la taille du vecteur
  int n = 0;
  while (index[n]) n++;


  for (x = 0 ; x < n-2  ; ++x){ printf("%i : %s\n", x , index[x] );}
  puts("affichage terminé");
  qsort(index, n , 5 , compare);
  printf("%i : %i\n", x , n  );
  for (x = 0 ; x < n-2  ; ++x){ printf("%i : %s\n", x , index[x] );}
  puts("tri terminé");



  return 0;
}



// FONCTION DE COMPARAISON
int compare(char * mot1, char * mot2) {return strcasecmp(mot1, mot2);} ;
