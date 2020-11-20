/* Le format %i interprete les reels comme des reeles on dirait bien



float f=1.2;

int a=10;

printf("%d\n",a);

printf("%4d\n",a);

printf("%04d\n",a);

printf("%f\n",f);

printf("%9f\n",f);

printf("%.2f\n",f);

printf("%6.2f\n",f);

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.c"

#define str char*
#define TAILLE_MOT 1024


int main(int k, str argv[]){
  // test du nombre d'arguments
  if (k < 2) usage("veuillez entrer un nom de ficher a lire");

  // ouverture du flux
  FILE * fichier = fopen(argv[1], "r");
  if(! fichier) usage("fichier illisible ! ");

  // allocation d'espace
  char * mots[4];    // espace pour 3 mots + NULL
  float tab[3] = {0};        // espace pour trois entiers

  // lecture des données
  int i = 0;
  while( i < 3){
    char sas[TAILLE_MOT];
    fscanf(fichier, "%s ", sas);
    mots[i++] = strdup(sas);
  }

  for ( i = 0; i < 3 ; i++){
    fscanf(fichier, "%f ", &tab[i]);
  }


  // fermeture du flux
  fclose(fichier);

  // affichage des valeurs
  printf("AFFICHAGE DES MOTS :\n");
  for(i = 0; i < 3 ; i++){
    printf("mot %i :   %s\n", i+1 , mots[i]);
  }

  printf("\nAFFICHAGE DES NOMBRES :\n");
  for(i = 0; i < 3 ; i++){
    printf("nombre %i :   %4f\n", i+1 , tab[i]);
  }



  return 0;
}




/* AFFICHAGE

%d (print as a decimal integer)
%6d (print as a decimal integer with a width of at least 6 wide)
%06d (print as a decimal integer with a width of at least 6 wide,precedes with 0)
%f (print as a floating point)
%4f (print as a floating point with a width of at least 4 wide)
%.4f (print as a floating point with a precision of four characters after the decimal point)
%3.2f (print as a floating point at least 3 wide and a precision of 2)
Example:

int a=10;

printf(“%d”,a);
OUTPUT: 10

printf(“%4d”,a);
OUTPUT: __10 ( _ - represents white space in the output, for clarity convenience I used _ )

printf(“%04d”,a);
OUTPUT: 0010

float f=1.2;

printf(“%f”,f);
OUTPUT: 1.200000

printf(“%9f”,f);
OUTPUT: _1.200000 ( _ - represents white space in the output, for clarity convenience I used _ )

printf(“%.2f”,f);
OUTPUT: 1.20

printf(“%6.2f”,f);
OUTPUT: ___1.20 */
