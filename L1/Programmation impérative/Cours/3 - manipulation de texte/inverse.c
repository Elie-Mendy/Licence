#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void usage(char * );
int inverse(char *);

int main(int k, char *argv[]) {
  if (k < 2 ) usage("veuillez entrer des mots sur la ldc");

  while(*++argv){
    if (inverse(*argv))
      printf("%s\n", *argv);
    else
      printf("impossible\n");
  }

  return 0;
}



void usage(char * message){
  printf("USAGE : %s\n", message);
  exit(1);
}



int inverse(char * mot){
  if(strlen(mot) <= 1) return 0;
  int taille = 0;
  while(mot[taille]) taille++;

  int i = 0;
  while(i <= taille/2){
    char tmp = mot[i];
    mot[i++] = mot[--taille];
    mot[taille] = tmp;
  }
  return 1;
}
