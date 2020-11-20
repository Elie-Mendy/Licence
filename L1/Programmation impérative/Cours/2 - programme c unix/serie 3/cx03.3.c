#include <stdio.h>
#include <stdlib.h>
#define str char *
int main(int k, const str argv[] ){
  *argv = NULL;
  argv += k;
  while (*--argv) { puts(*argv) ;} ;
  return 0;
}
