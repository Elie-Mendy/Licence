#include <stdio.h>
#include <stdlib.h>

// mise en place du nil
#define nil NULL


// construction des doublets et listes
typedef struct node node, *list;
struct node{
  int car;
  node * cdr;
};

// prototype des fonctions utilisées
void putlist(list L);
list cons(int , list);
void usage(char *);


int main(void){      // k utilisé comme local
  int k;
  list L = nil;
  // remplissage de la liste
  for (k = 'a' ; k < 'i' ; k++){
    L = cons(k, L);}
  // affichage de la liste
  putlist(L);
  return 0;
}





// MESSAGE D'ERREUR (sur flux stderr)
void usage(char * message) {
  fprintf(stderr, "%s\n", message);
  exit(1);
}

// CONSTRUCTION D'UNE LISTE
list cons(int car, list L){
  list new = malloc(sizeof(node));
  if (!new) usage("cons : manque de RAM") ;
  new -> car = car;
  new -> cdr = L;
  return new; }

/*
// AFFICHAGE D'UNE LISTE (ecriture façon lisp)
void putlist(list L){
  if (!L) return;            // nil : fin de la liste
  printf("%c ", L-> car) ;
  putlist(L -> cdr) ;
}*/


// AFFICHAGE D'UNE LISTE (a l'endroit)
void putlist(list L){
  // recuperation de la taille de la liste
  int n = 0, i;
  list Copy = L;
  while (Copy){
    n ++;
    Copy = Copy->cdr;
  }

  // allocation dynalique d'un vecteur qui contiendra les elements de la liste
  char * v = malloc(sizeof(char) * n);
  if (! v) usage("usage : impossible d'allouer l'espace en mémoire pour stoquer les éléments de la liste");

  // boucle de lecture de la liste
  for (i = n -1 ; i >= 0 ; i--){
    v[i] = L-> car;
    L = L-> cdr;
  }
  // affichage des elements récupérés
  for( i = 0 ; i < n; i++){
    printf("%c ",v[i]);
  }
  puts("");
}
