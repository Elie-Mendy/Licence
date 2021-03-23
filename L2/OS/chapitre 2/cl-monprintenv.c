/* cl −monprintenv.c
Refaire le travail de printenv
*/

#include <stdio.h>

int main(int argc, char const *argv[], char * envp[]) {
  int i;

  for (i = 0; envp[i] != 0 ; i ++){
    printf("%s\n", envp[i]);
  }
  return 0;
}
