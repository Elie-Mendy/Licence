#include <stdio.h>
#include <stdlib.h>
#define str char *
int main (int k , const str argv[]){
  while(k) { puts(argv[--k]) ; };
  return 0;
}
