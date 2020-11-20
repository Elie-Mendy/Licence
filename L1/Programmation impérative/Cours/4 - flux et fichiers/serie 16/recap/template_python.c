#include <stdio.h>
#include <stdlib.h>

#define TAILLE 4096

int main(int argc, char const *argv[]) {
  // données textuelles
  char * hex = "CAB", *n = "123";

  // variables d'acceuilles
  int n1, n2;

  // recupération d'une valeur avec sscanf
  sscanf(hex, "%x", &n1);
  sscanf(n, "%i", &n2);

  // ecriture d'une valeur avec sprintf
  char chaine[TAILLE];
  char format[] = "for x in range(%i); print(x * %i)";
  sprintf(chaine, format, n1, n2);

  // ecriture de la chaine formatée sur sortie standard
  printf("%s\n", chaine);

  

  return 0;
}
