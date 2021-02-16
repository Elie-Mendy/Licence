/* NOM : MENDY
 * Prenom : Elie
 * n°etudiant : 19004664

  Consigne :
  Écrivez un programme qui lit une suite de nombres dans un fichier et les met dans
  un vecteur (une table). Affichez chaque nombre avec son indice dans la table. On
  suppose connue à l’avance la taille de la suite.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  // définition de tables
  int entiers[5] = {0}, i, lu;      //  - de 5 entiers,
  float flottants[5] = {};          //  - de 5 flottants,
  long int long_entiers[5] = {};    //  - de 5 long int


  /*========================================================================
                      OUVERTURE d'UN FICHIER EN LECTURE
  =========================================================================*/
  FILE * fichier = fopen("data_1.A.1", "r");
  if (!fichier) exit(1);

  /*========================================================================
                      LECTURE ET REMPLISSAGE DES TABLES
  =========================================================================*/
  // remplissage table des entiers
  for (i = 0 ; i < 5 && lu != EOF ; i++){
    lu = fscanf(fichier, "%i", &entiers[i]);
  }

  // - table des long int
  rewind(fichier);
  for (i = 0 ; i < 5 && lu != EOF ; i++){
    lu = fscanf(fichier, "%ld", &long_entiers[i]);
  }

  // - table des flottants
  rewind(fichier);
  for (i = 0 ; i < 5 && lu != EOF ; i++){
    lu = fscanf(fichier, "%f", &flottants[i]);
  }



  // fermeture du flux
  fclose(fichier);


  /*========================================================================
                          AFFICHAGE DES TABLES
  =========================================================================*/
  // - affichage des entiers
  printf("Affichage de la table 'entiers'\n");
  for (i = 0 ; i < 5 ; i++){
    printf("%i. %i\n", i+1 , entiers[i]);
  }
  puts("\n");


  // - affichage des long int
  printf("Affichage de la table 'long entiers'\n" );
  for (i = 0 ; i < 5 ; i++){
    printf("%i. %li\n", i+1 , long_entiers[i]);
  }
  puts("\n");


  // - affichage des flottants
  printf("Affichage de la table 'flottants'\n" );
  for (i = 0 ; i < 5 ; i++){
    printf("%i. %f\n", i+1 , flottants[i]);
  }
  puts("\n");



  return 0;
}
