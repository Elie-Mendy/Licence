#include <stdio.h>
#include <stdlib.h>




int main(int argc, char const *argv[]) {
  void * v = NULL;
  char * c = NULL;
  short * sh = NULL;
  int * i = NULL;
  float * f = NULL;
  double * d = NULL;
  long int * li = NULL;
  long long int * lli = NULL;





  printf("void : %li\n", v + 1);
  printf("char  : %li\n", c + 1);
  printf("short : %li\n", sh + 1);
  printf("int  : %li\n", i + 1);
  printf("float  : %li\n", f + 1);
  printf("double : %li\n", d + 1);
  printf("long int: %li\n", li + 1);
  printf("long long int  : %lli\n", lli + 1);
  return 0;
}
