#include <stdio.h>
#include <stdlib.h>

// definition de nil
#define nil NULL;

// Definition du type node et list
typedef struct node { void * car ; struct node * cdr ; } node , *list;

// prototype desfonctions
list cons (void * car, list cdr);
void putlist(list L);
void usage(char *);
int length(list L);
list arrayToList(void * tab, int taille);


int main(void) {
  int entiers [] = { 1, 2, 4, 6, 8, 1, 3, 5, 7, 9 };  // declaration d'un tableau
  list L = arrayToList(entiers, 10);                  // conversion du tableau en liste
  putlist(L);                                         // affichage de la liste
  return 0;
}




// declaration de des fonctions




// IMPRESSION DE MESSAGE D'ERREUR (sur flux stderr)
void usage(char * message){ fprintf(stderr, "Usage : %s\n", message), exit(1) ;}


int length(list L){
    int n = 0;
    while(L) {
        n++;
        L = L->cdr;
    }
    return n;
}

// FONCTION DE CONVERSION d'UNE TABLE EN LISTE
list arrayToList(void * tab , int taille){
    // definition d'un pointeur type
    int *p = tab;

    // definition d'une liste
    list L = nil;
    // recuperation des valeurs du tableau
    int n = 0;
    while(n++ < taille){
        // printf("%i ", *p++);
        L = cons(p++, L);
    }

    return L;
}






list cons(void * car, list cdr){
  list L = malloc(sizeof(node));
  if (!L) usage("espace insufisant");

  L -> car = car;
  L -> cdr = cdr;

  return L;
}


void putlist(list L){
  int * P = malloc(sizeof(int));
  int nb = length(L);           // récupération de la taillede la liste

  // création d'un Pointeur sur une liste
  list Copy = nil;

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
  puts("");
}
