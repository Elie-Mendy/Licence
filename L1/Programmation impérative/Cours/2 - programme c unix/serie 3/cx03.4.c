#include <stdio.h>

int main(int k, char const * L[]) {
  // affichage des valeurs a l'endroit en utilisant le pointeur L
  if (*L){
    puts(*L);
    return main(k-1, L+1);
  }
  return 0;
}
