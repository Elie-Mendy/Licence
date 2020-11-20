#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int i= 0 , x;
  while ((x = getchar()) != EOF){
    if (x == '\n') i++;
    putchar(x);
  }

  printf("%i lignes dans le fichier\n", i);
  return 0;
}
