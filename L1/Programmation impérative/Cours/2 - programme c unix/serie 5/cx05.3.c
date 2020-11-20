#include <stdio.h>
#include <stdlib.h>

void affichage(char * mots[]);
int main(int argc, char *argv[], char * envp[]) {
  printf("AFFICHAGE ARGV\n");
  affichage(argv);
  printf("\n\n\nAFFICHAGE ENVP\n");
  affichage(envp);
  return 0;
}

void affichage(char * mots[]){
  while(*mots){ puts(*mots++);};
}
