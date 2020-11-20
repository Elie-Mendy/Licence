#include <stdio.h>
#include <stdlib.h>



void ascii(int, int);

int main(int argc, char const *argv[]) {
  int inf = strtol(argv[1], NULL, 10);
  int max = strtol(argv[2], NULL, 10);
  ascii(inf, max);
  return 0;
}

void ascii(int inf, int max){
  while(inf++ < max) printf("%i  : %c\n", inf, inf );
}
