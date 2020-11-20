#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[]) {

  int c = 0;

  while(c < 256)
    printf("%i  : %c\n",c , c++ );
  return 0;
}
