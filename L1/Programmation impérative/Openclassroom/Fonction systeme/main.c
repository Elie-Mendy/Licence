#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  /* faire retourner une commande au shell parent  */
  return system("ls -l");
}
