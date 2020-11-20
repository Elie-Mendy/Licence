#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lire(char * , int);

int main(int argc, char const *argv[]){
  /* utilisation de fgets */
  char nom[10];
  printf("Quel est votre nom ? ");
  fgets(nom, 10, stdin);
  printf("Ah ! très bien, vous vous appelez %s !\n", nom);



  /* utilisation d'une fonction lire
  qui supprime le saut de ligne en fin de saisie user */
  char prenom[10];
  printf("Quel est votre prénom ? ");
  lire(prenom, 10);
  printf("OK vous etes %s %s !\n", nom, prenom);

  lire(prenom, 10);
  printf("OK vous etes %s %s !\n", nom, prenom);
  return 0;

}


int lire(char * mot, int taille){
  if (fgets(mot, taille, stdin)){
    char * monPointeur = strchr(mot,'\n');
    if (monPointeur)
      *monPointeur = '\0';

    while(getchar() != '\n' && getchar() != EOF);
    return 1;
  }
  while(getchar() != '\n' && getchar() != EOF);
  return 0; // si impossible delire la saisie
}
