#include <stdio.h>
#include <stdlib.h>


/* si le \n est ajouté dans le fichier...   les mot est lu avec soit "%i\n"
 il faut lui ajouter après l'avoir lu */

int main(int argc, char const *argv[]) {
  // ouverture du flux
  FILE * fichier = fopen("cx15.9.data", "r");

  // lecture du nb de valeurs et de la chaine de format
  int i, nb, valeur;
  char format[10];
  fscanf(fichier, "%i %s ", &nb, format);
  format[2] = '\n'; format[3] = '\0';     // ajout d'un fin de chaine propre en fin de format


  // lecture des valeurs (+ affichage)
  for (i = 0; i < nb ; i++){
    fscanf(fichier, format, &valeur);
    printf(format, valeur );
  }

  // fermeture du flux
  fclose(fichier);

  return 0;
}
