#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include "fonctions.c"


int main(int argc, char * argv[]){

  Point origine;
  initialiser(&origine);

  printf("Abscisse : %i\nOrdonnée : %i\n \n", origine.x, origine .y);


  Personne elie;
  definirPersonne(&elie);
  printf("vos données sont:\nnom : %s\nprénom : %s\nadresse : %s\nage : %i\nargent : %i\n", elie.nom, elie.prenom , elie.adresse, elie.age, elie.argent);



  Volume son = FORT;
  printf("le son est à %i\n", son);

  return 0;
}
