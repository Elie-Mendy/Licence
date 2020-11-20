#include <stdio.h>
#include <stdlib.h>
#define str char *


int main (int k , const str argv[]){
  int count = 0;
  while(k > count) { puts(argv[count++]) ; };
  return 0;
}
