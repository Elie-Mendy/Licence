#include <stdlib.h>
#include <stdio.h>


void usage(char * );

int main(int argc, char const *argv[]) {
  // test du nombre d'arguments
  if  (argc <2) usage("veuillez entrer au moins un nom de fichier");
  // declaration des variables
  int c = 0;
  // ouverture des flux
  FILE * lecture = fopen(argv[1], "r");
  if (! lecture) usage(" erreur de lecture du premier fichier");


  if (argc >= 3){
    FILE * ecriture = fopen(argv[2], "w");
    if (! ecriture) usage("erreur de lecture du deuxieme fichier\n");
    // affichage de chaques caractères lu dans le fichier
    while((c = fgetc(lecture)) != EOF) fputc(c , ecriture);
    fclose(ecriture);
  }
  else {
    // affichage de chaques caractères lu dans le fichier
    while((c = fgetc(lecture)) != EOF) fputc(c , stdout);
  }




  // fermeture des flux
  fclose(lecture);

  return 0;
}



void usage(char * message){
  printf("usage : %s\n", message);
  exit(1);
}
