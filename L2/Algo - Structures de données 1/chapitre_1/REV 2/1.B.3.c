/* NOM : MENDY
 * Prenom : Elie
 * n°etudiant : 19004664

  Consigne :
  Écrire un programme récupérant dans un fichier une chaîne de caractères en al-
  louant dynamiquement un pointeur sur cette chaîne. Afficher cette chaîne en cas-
  tant chaque caractère comme un entier, avec un cast explicite, et avec un espace
  entre chaque entier.
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(int argc, char const *argv[])
{
  // ouverture d'un fichier
  FILE * fichier = fopen("data_1.B.3.txt", "r");
  if (! fichier) exit(1);

  // récupération de la chaine de caractère
  char texte[];
  fscanf(fichier, "%s ", &texte);

  // allocation dynamique d'un pointeur
  char * P = malloc(strlen(texte)/sizeof(char));


  // affichage des caractères
  while (*P) { printf("%i ", (int) *P++);}
  return 0;
}
