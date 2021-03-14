#include <stdio.h>
#include <stdlib.h>
#include <string.h>



// definition de nil
#define nil NULL;

// Definition du type node et list
typedef struct node { int car ; struct node * cdr ; } node , *list;



int main(void) {

  list L, top = nil;
  int x;




  // remplissage de liste
  for (x = 'a' ; x < 'i' ; x++){
    L = malloc(sizeof(node));
    L -> car = x;
    L -> cdr = top;
    top = L;
  }




  // affichage (vidage de liste)
  while(L){
    printf("%c ", L -> car);
    L = L -> cdr;
  }

  puts("");

  return 0;
}
