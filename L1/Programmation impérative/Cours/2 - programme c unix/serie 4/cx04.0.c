#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  // declaration d'une chaine de caractere
  // par le pointeur premier
  char * premier = "programme";

  printf("adresse du pointeur : %p\n", &premier);
  printf("adresse contenu par le pointeur : %p\n", premier);
  printf("valeur a cette adresse : %c\n", *premier);


  return 0;
}
