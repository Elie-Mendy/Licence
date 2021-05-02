#include <stdio.h>
#include <stdlib.h>


typedef char * string ;

// desambiguiser
// a l'aide de define et typedef
#define bool char // pour les booléennes
#define true 1
#define false 0

#define OK_type char // pour les autres
#define OK 0
#define not_OK 1

#define eql ==
#define neql !=

// protos typages
OK_type fonction1(bool);
bool fonction2(bool);




// structure d'implémentatio des listes élastiques
typedef struct Doublet { void * car ; struct Doublet * cdr ; } *list;
#define car(doublet) ((doublet)->car) // macro d'appel de char
#define cdr(doublet) ((doublet)->cdr) // macro d'appel du cdr

// definition de nil
#define nil NULL

// protos implementation listes
list cons(void * car, const list cdr);
list push (void *, list * L);



// main
int main(int argc, char const *argv[]) {

  fonction1(OK);

  fonction2(false);

  // construction d'une liste de quatre éléments
  list L = nil;
  L = cons(1,L);
  L = cons(2,L);
  L = cons(3,L);
  L = cons(4,L);

  // affichage des éléments de la liste


  push(&i, &L);
  int *p = L->car;
  printf("element 1\n", *p );
  return 0;
}



// interer du type OK_type pour renvoyer 0 ou 1
OK_type fonction1(OK_type value) {
  value? printf("fonction 1: OK\n") : printf("fonction 1: Non OK\n");
  return value;
}


// interer du type bool pour renvoyer true ou false
bool fonction2(bool value) {
  value? printf("fonction 2: vrai\n") : printf("fonction 2: faux\n");
  return value;
}




// CONSTRUCTION D'UN DOUBLET
list cons(void * car, const list cdr){
  list Cons = malloc(sizeof(struct Doublet));

  car(Cons) = car;
  cdr(Cons) = cdr;

  return Cons;
}

list push (void * elt , list  * L) {
  int * P = malloc(sizeof(int));  // allocation d'un pointeur
  P = elt;
  *L = cons(P, *L);
  return *L;
}
