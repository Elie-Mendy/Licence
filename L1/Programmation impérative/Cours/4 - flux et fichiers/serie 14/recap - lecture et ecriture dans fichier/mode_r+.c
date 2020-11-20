/* Script qui ouvre un fichier en mode r+
  - lis intégralement le fichier (sans afficher -> positionnele curseur a la fin)
  - ecrit dans le fichier
  - repositionne le curseur au début
  - relis intégralement le fichier en affichant le contenu
  */


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  // ouverture du flux
  FILE * fichier = fopen("fichier.txt", "r+");    // le fichier doit déja exister
  if(! fichier) exit(1);

  // positionnement du curseur en fin de fichier
  char c = 0;
  while((c = fgetc(fichier)) != EOF);

  // ecriture d'un texte random ...
  int age = 10;
  fprintf(fichier, "bonjour j'ai %i ans ! \n", age);

  // position du fichier au début di fichier
  //rewind(fichier);                // méthode 1
  fseek(fichier , 0, SEEK_SET);     // méthode 2


  // affichage du contenu du fichier
  while((c = fgetc(fichier)) != EOF) fputc(c, stdout);


  return 0;
}
