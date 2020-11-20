#include <stdio.h>
#include <stdlib.h>

// par défaut
// getchar() lis sur le flux stdin
// putchar() ecrit sur stdout


int main(int argc, char const *argv[]) {
  char c = 0;
  while((c = getchar()) != EOF) putchar(c);
  return 0;
}
