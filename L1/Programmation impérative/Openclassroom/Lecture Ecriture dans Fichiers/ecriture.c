#include <stdio.h>
#include <stdlib.h>

/*
fpuc
fputs
fprintf
*/


int main(int argc, char const *argv[]) {
  // ouverture du fichier
  FILE * fichier = fopen("fichier.txt", "w");

  // test du flux
  if (!fichier)
    exit(1);


  //fputc
  fputc('a', fichier);



  //fputs
  char chaine[] = " dieu monsieur le prof\n";
  fputs(chaine, fichier);


  // fprintf
  char prof[] = "GB";
  int note = 19;
  fprintf(fichier, "merci pour le %i monsieur %s\n", note , prof);



  // fermeture du flux
  fclose(fichier);
  return 0;
}
