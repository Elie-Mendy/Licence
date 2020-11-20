/* INVERSION DE CHAINE SUR PLACE */

#include <stdio.h>
#include <stdlib.h>


int inverser(char * chaine);
void usage(char *);

int main(int argc, char *argv[]) {
  if (argc < 2) usage("veuillez entrer un mot au minimum");
  while (*++argv){
    if (inverser(*argv)) puts(*argv);
    else{
      puts("impossible");
      argv++;
    }
  }

  return 0;
}




void usage( char * P) { printf("USAGE : %s\n",P ); exit(1);};

int inverser(char * chaine){
  int i = 0, n = 0;
  // recuperation de la taille de ma CHAINE
  while(chaine[i]) i++;

  // inversion des valeurs
  while(n <= i/2)
  { char tmp = chaine[n];
    chaine[n++] = chaine[--i];
    chaine[i] = tmp;
  }
  return 1;
}
