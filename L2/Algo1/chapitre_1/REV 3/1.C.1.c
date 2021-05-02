#include <stdio.h>
#include <stdlib.h>


typedef char * string ;

// structure d'implémentatio des listes élastiques
typedef struct Doublet { void * car ; struct Doublet * cdr ; } *list;
#define car(doublet) (doublet)->car // macro d'appel de car
#define cdr(doublet) (doublet)->cdr // macro d'appel de car
#define caar(doublet) car(car(doublet))
#define cadr(doublet) car(cdr(doublet))

// definition de nil
#define nil NULL

// protos implementation listes
list cons(void * car, const list cdr);
int car(list);
list cdr(list);

// main
int main(int argc, char const *argv[]) {

  // construction d'une liste de quatre éléments
  list L = nil;
  L = cons(1,L);
  L = cons(2,L);
  L = cons(3,L);
  L = cons(4,L);

  // affichage des éléments de la liste
  printf("element 1 : %i\n", car(L) );
  printf("element 2 : %i\n", car(cdr(L)) );
  printf("element 3 : %i\n", car(cdr(cdr(L))) );
  printf("element 4 : %i\n", car(cdr(cdr(cdr(L)))) );



  // utilisation de caar et cadr
  list L2 = nil;      // nil
  L2 = cons(10, L2);  // (10)
  L2 = cons(20, L2);  // (20 10)
  L2 = cons(L2, L2);  // ((20 10) 20 10)
  printf("caar(L2) >> %i\n", cadr(L2) );


  /*
  L2 = cons(30, L2);  // (30 (20 10) 20 10)
  printf("cadr(L2) >> %i\n", caar(L2));*/

  return 0;

}




// AFFICHAGE DU CAR D'UNE LISTE
char* car(list L) {
  char * P = malloc(sizeof(char));  // allocation d'un pointeur
  P = L->car;
  return P;
}


// AFFICHAGE DU CDR D'UNE LISTE
list cdr(list L) {
  Doublet * P = malloc(sizeof(Doublet));  // allocation d'un pointeur
  P = L->cdr;
  return P;
}


// CONSTRUCTION D'UN DOUBLET
list cons(void * car, const list cdr){
  list Cons = malloc(sizeof(struct Doublet));

  Cons->car = car;
  Cons->cdr = cdr;

  return Cons;
}





/*// AFFICHAGE D'UNE LISTE
int  putlist(list L){
  // récupération de la taillede la liste
  int nb = length(L);
  // création d'un Pointeur sur une liste
  list Copy = nil;
    int * P = malloc(sizeof(int));  // allocation d'un pointeur

  while (nb--){
    int i = 0;
    // Copie de la liste L
    Copy = L;
    // parcour de la liste Copy
    while(i++ <= nb){
      //L = L->cdr;
      P = Copy->car;
      Copy = Copy->cdr;
    }
    // affichage de la valeur
    printf("%i ", *P);
  }
return 0;
}*/

/*

1.C.1.c:9:30: error: request for member ‘car’ in something not a structure or union
    9 | #define car(doublet) (doublet->car) // macro d'appel de char

    */