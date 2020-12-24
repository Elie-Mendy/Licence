#include <stdio.h>
#include <stdlib.h>

#define nil NULL

typedef struct node node, *list;
struct node{
  int car;
  struct node * cdr;
  };


#include "fonctions.c"


int main(int argc, char const *argv[]) {
  // definition d'une liste vide
  list L = nil;

  int entier [] = {0,2,65,6,8,1,3,5,7,9};

  // recuperation de la taille du tableau
  int n = sizeof(entier) / sizeof(int);
  printf("%i\n", n);



  // remplissage de la liste
  int i = 0;
  for (i = 0 ; i < n ;i++){
    L = cons(entier[i], L);
  }


  // affichage de la liste
  // (apparait vide mais au vu des entiers c'est normal)
  // changer le renvoi de putlist par %i au lieu de %c
  putlist(L);

  printf("la taille de la liste est de %i \n", lenght(L));
  return 0;
}
