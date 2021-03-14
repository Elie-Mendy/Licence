#include <stdio.h>
#include <stdlib.h>

// definition de nil
#define nil NULL;

#define car(node) ((node)->car)
#define cdr(node) ((node)->cdr)

// Definition du type node et list
typedef struct node { void * car ; struct node * cdr ; } node , *list;

// prototype desfonctions
list cons (void * car, list cdr);
void putlist(list L);
void usage(char *);

int main(void) {

  int i;
  list L = nil;
  for (i = 'a'; i < 'i'; i++){
    //printf("%i\n", k);
    int * k = malloc(sizeof(int));
    *k = i;
    L = cons(k , L);
  }

  putlist(L);
  return 0;
}




// declaration de des fonctions

// IMPRESSION DE MESSAGE D'ERREUR (sur flux stderr)
void usage(char * message){ fprintf(stderr, "Usage : %s\n", message), exit(1) ;}

list cons(void * car, list cdr){
  list L = malloc(sizeof(node));
  if (!L) usage("espace insufisant");

  car(L) = car;
  cdr(L) = cdr;

  return L;
}



/*FONCTION POUR S'INSPIRER DANS LA MODIFICATION DE L'affichage à l'endroit*/
// AFFICHAGE D'UNE LISTE (a l'endroit)
void putlist(list L){

  int * P = malloc(sizeof(int));
  // recuperation de la taille de la liste
  int n = 0, i;
  list Copy = L;
  while (Copy){ n ++; Copy = Copy->cdr;
  }

  // allocation dynalique d'un vecteur qui contiendra les elements de la liste
  char * v = malloc(sizeof(char) * n);
  if (! v) usage("usage : impossible d'allouer l'espace en mémoire pour stoquer les éléments de la liste");

  // boucle de lecture de la liste
  for (i = n -1 ; i >= 0 ; i--){
    P = L->car;
    v[i] = *P;
    L = L-> cdr;
  }
  // affichage des elements récupérés
  for( i = 0 ; i < n; i++){
    printf("%c ",v[i]);
  }
  puts("");
}

/*
void putlist(list L){
  int * P = malloc(sizeof(int));
    // definir un pointeur transitoire
    while(L){
      P = L->car;
      printf("%c ", *P);
      L = L->cdr;
    }
}
*/
