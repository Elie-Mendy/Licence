#include <stdio.h>
#include <stdlib.h>

void ascii( int);


int main(int argc, char const *argv[]) {
  ascii(atoi(argv[1]));
  return 0;
}


void ascii(int max){
  int ascii = 0;
  while(ascii++ < max) printf("%i  :  %c\n", ascii, ascii);
}
