#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nil NULL

typedef struct node node, *list;
struct node{
  char * car;
  struct node * cdr;
  };



#define max_mots 128                                // nombre maximum d'éléments dans la table de mots



// MESSAGE D'ERREUR (sur flux stderr)
void usage(char * message);

// CONSTRUCTION D'UNE LISTE
list cons(char * car, list L);

// AFFICHAGE D'UNE LISTE (a l'endroit)
void putlist(list L);

// RENVOI LA TAILLE D'UNE LISTE
int lenght(list L);





int main(int argc, char const *argv[]) {
  // definition d'une liste vide
  list L = nil;

  char * code [] = { "papa", "alpha", "zulu", "hotel", "charlie", nil };

  // recuperation de la taille du tableau
  int n = 0;
  while(code[n]) n++;


  // remplissage de la liste
  int i = 0;
  for (i = 0 ; i < n ;i++){
    L = cons(code[i], L);
  }


  // affichage de la liste
  // (apparait vide mais au vu des entiers c'est normal)
  // changer le renvoi de putlist par %i au lieu de %c
  putlist(L);
  return 0;
}


















// MESSAGE D'ERREUR (sur flux stderr)
void usage(char * message) {
  fprintf(stderr, "%s\n", message);
  exit(1);
}

// CONSTRUCTION D'UNE LISTE
list cons(char * car, list L){
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
  int n = lenght(L), i;

  // allocation dynalique d'un vecteur qui contiendra les elements de la liste
  char **v;
  v = malloc(max_mots * sizeof(*v));
  if (! v) usage("usage : impossible d'allouer l'espace en mémoire pour stoquer les éléments de la liste");

  // boucle de lecture de la liste
  for (i = n -1 ; i >= 0 ; i--){
    v[i] = strdup(L-> car);
    L = L-> cdr;
  }
  // affichage des elements récupérés
  for( i = 0 ; i < n; i++){
    printf("%s ",v[i]);
  }
  puts("");
}

// RENVOI LA TAILLE D'UNE LISTE
int lenght(list L){
  int n = 0;
  if (L->car) n++;
  while (L->cdr){
    L = L->cdr;
    n++;
    }
    return n;
  }
