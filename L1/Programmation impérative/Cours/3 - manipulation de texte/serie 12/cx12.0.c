/* INVERSION DE CHAINE SUR PLACE */

#include <stdio.h>
#include <stdlib.h>

void inverse(char *);
int main(int argc, char const *argv[]) {


  // declaration d'une CHAINE

  char chaine[] = "bonjour";

  inverse(chaine);

  printf("%s\n", chaine);
  return 0;
}



void inverse(char * chaine){
  // variable temporaire
  char tmp = '\0';
  // récupération de la taille de la chaine
  int i = 0, n = 0;
  while(chaine[i]) i++;

  // inversion de valeurs
  while(n <= i/2)
  {
    tmp = chaine[n];
    chaine[n++] = chaine[--i];
    chaine[i] = tmp;
  }
}
