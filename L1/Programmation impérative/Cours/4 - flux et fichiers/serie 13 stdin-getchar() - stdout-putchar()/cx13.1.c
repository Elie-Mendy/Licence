#include <stdio.h>
#include <stdlib.h>

int main (int k, char * argv[]){
  int i = 0, c;
  while( (c = getchar()) != EOF){ putchar(c); i++;}
  printf("%i caractères lus\n", i);
}
