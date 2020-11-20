#include <stdio.h>
#include <stdlib.h>

void usage(char *);

int main(int argc, char const *argv[]) {
  // test du nombre d'arguments
  if (argc < 2 ) usage("veuillez entrer un nom de fichier");

  // declaration des variables
  int c = 0;
  FILE * fichier = fopen(argv[1], "r");
  // vérification de l'ouverture du flux
  if (!fichier) usage("lecture du fichier impossible, assurrez vous que le fichier existe");

  // lecture  et renvoi de chaques caractères lus
  while((c = fgetc(fichier)) != EOF ) fputc(c , stdout);

  // fermeture du flux
  fclose(fichier);
  return 0;
}




void usage(char * message){
  printf("usage : %s\n", message );
  exit(1);
}
