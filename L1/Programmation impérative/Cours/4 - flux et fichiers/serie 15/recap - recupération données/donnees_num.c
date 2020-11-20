/* script qui lit un fichier ontenant des donnés numériques
- le format de la donnée est donné en début de fichier


-> phase 1 récupération du nombre d'occurence
-> phase 2 récupération du format de chaques occurences
-> phase 3 boucle de récupération des données


*/


#include <stdio.h>
#include <stdlib.h>
#include "fonctions.c"

int main(int argc, char const *argv[]) {
  // test du nombre d'occurences
  if (argc < 2 ) usage("saisir un nom de fichier");

  // ouverture  du flux
  FILE * fichier = fopen(argv[1], "r");
  if (! fichier) usage("fichier illisible");

  // recupération du nombre de données
  int nb = 0;
  fscanf(fichier, "%i ", &nb);

  // récupération du format de la donnée
  char format[10];
  fscanf(fichier, "%s ", format);

  // allocation d'espace pour la donnée
  int * tab = malloc(sizeof(int) * nb);
  if (!tab) usage("stockage impossible");

  // lecture des données


  int i = 0;
  while( i < nb){
    fscanf(fichier, "%i ", &tab[i++]);
  }

  // affichage des données
  for (i = 0; i < nb ;i ++){
    printf("score %i : %i\n", i+1, tab[i]);
  }

  // libération de la mémoire allouée
  free(tab);

  // fermeture du flux
  fclose(fichier);

  return 0;
}
