#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
  for(;;){
    fork();
  }
  return 0;
}


/* dans un shell on peut tapper : fork while fork */
