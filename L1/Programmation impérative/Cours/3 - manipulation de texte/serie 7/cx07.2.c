#include <stdio.h>
#include <stdlib.h>


void ascii(int , int);


int main(int argc, char const *argv[]) {
  ascii(atoi(argv[1]), atoi(argv[2]));
  return 0;
}

void ascii(int inf, int max){
  while(inf++ < max) printf("%i  :  %c\n", inf , inf);
}
