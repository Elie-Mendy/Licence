#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  printf("void : %li\n", sizeof(void));
  printf("char  : %li\n", sizeof(char));
  printf("short : %li\n", sizeof(short));
  printf("int  : %li\n", sizeof(int));
  printf("float  : %li\n", sizeof(float));
  printf("double : %li\n", sizeof(double));
  printf("long int: %li\n", sizeof(long int));
  printf("long long int  : %li\n", sizeof(long long int));
  printf("char * : %li\n", sizeof(char *));
  return 0;
}
