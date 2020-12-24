#include <stdio.h>
#include <stdlib.h>

// definition du nil
#define nil NULL;

// definition de deux structures
  // les doublet (node)
  // les listes --> reference un doublet
typedef struct node node, *list;
struct node {
  int car;
  struct node * cdr;
};



int main(void){
  // definition d'un car et d'un cdr à nil
  list L, top = nil

  // remplissage de la liste par huit caracteres
  int x;
  for (x = 'a' ; x < 'i' ; x++){
    L = malloc(sizeof(node));
    L->car = x;
    L->cdr = top;
    top = L;
  }


  // affichage des valeurs de la liste
  while(L){
    printf("%c\n", L->car);
    L = L->cdr;
  }
  return 0;
}
