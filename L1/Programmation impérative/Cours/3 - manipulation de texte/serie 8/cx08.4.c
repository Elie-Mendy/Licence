#include <stdio.h>
#include <stdlib.h>
#include "fonctions.c"


int main(int argc, char  *argv[]) {
  printf("Le deuxième mot de la ligne de commande contient %d caracteres\n", size_x(argv[1]) );
  return 0;
}
