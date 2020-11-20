#include <stdlib.h>
#include <stdio.h>


/*
fgetc
fgets
fscanf
*/

int main (int argc, char * argv[]){

  // ouverture d'un flux
  FILE * fichier = fopen("fichier.txt","r");

  // test du flux
  if (!fichier)
    exit(1);

  // fgetc
  char caractere = fgetc(fichier);
  printf("le caractere lu est : %c\n", caractere);


  // fgets
  rewind(fichier);       // repositionnement du curseur
  // fseek(fichier,0 ,0)   similaire
  char chaine[100];     // allocation d'espace
  fgets(chaine, 100, fichier);
  printf("chaine lue : %s\n", chaine);

  // fermeture du fichier
  fclose(fichier);


  // ouverture d'un tableau de scores
  FILE * resultats = fopen("scores.txt", "r");
  if (! resultats)
    exit(1);

  int tableau[4] = {0};
  fscanf(fichier, "%d %d %d %d", &tableau[0],&tableau[1],&tableau[2],&tableau[3]);

  printf("les resultats sont %i % i % i %i \n", tableau[0], tableau[1], tableau[2], tableau[3]);

  fclose(resultats);



  // CHALLENGE TAB SCORES + TAB NOM
  char * noms[5];
  int scores[5], i;

  FILE * classement = fopen("classement.txt", "r");
  if (!classement)
    exit(1);


  fscanf(classement, "%i %s %i %s %i %s", &scores[0], noms[0], &scores[1], noms[1], &scores[2], noms[2]);

  for (i = 0; i < 4 ; i ++)
    printf("le joueur nommé %s a obtenu un score de %d points\n", noms[i], scores[i] );


  fclose(classement);
  return 0;
}
