#include <stdio.h>
#include <stdlib.h>
#include "usage.c"

/* pour le moment il m'est impossible de lancer le programme générée
   depuis l'interieur de celui que j'ecris */

int main(int argc, char const *argv[]) {
  char *H = "CAB", *N = "123" ;             // déclaration de données textuelles
  int n1, n2;                               // déclaration de variables d'acceuil

  sscanf(H, "%x", &n1);                      // conversion: attribution des valeurs aux valeurs n1 et n2
  sscanf(N, "%i", &n2);                      // conversion

  char P[] = "for x in range(%i): print(x * %i)";    // template python
  char R[128] ;                                     // texte a afficher

  sprintf(R, P, n1, n2);
  printf("%s\n", R);



  return system("python3 test.py");
}
