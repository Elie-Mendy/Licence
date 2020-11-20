#include <stdio.h>
#include <stdlib.h>


unsigned int size_x(char * chaine);

int main(int argc, char const *argv[]) {

  char chaine[] = "Chaine de test";
  printf("la chaine de test contient %d caractères \n", size_x(chaine) );
  return 0;
}

unsigned int size_x(char * chaine){
  unsigned int i = 0;
  while(* chaine++) i ++;
  return i;
}
