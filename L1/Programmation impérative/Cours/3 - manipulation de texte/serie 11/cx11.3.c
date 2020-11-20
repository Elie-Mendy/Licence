#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.c"

int option_i(char *);
void afficher(char *[]);
void retourner(char *[], int);

int main (int k , char * argv[]){
  // parcourir la ldc pour capter une éventuelle option -i
  int i = 0;
  int inverse = 0;
  while (argv[i]){
    if (option_i(argv[i++]))
      inverse = 1;
  }

  if (! inverse)
    afficher(argv);

  else
    retourner(argv, k);
  return 0;
}
