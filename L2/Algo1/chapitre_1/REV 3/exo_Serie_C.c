#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// desambiguiser
//#define car(doublet) (doublet)->car // macro d'appel de car
//#define cdr(doublet) (doublet)->cdr // macro d'appel de car
#define caar(doublet) car(car(doublet))
#define cadr(doublet) car(cdr(doublet))


typedef char * string ;


// definition de nil
#define nil NULL

// Definition du type Doublet et list
typedef struct Doublet { void * car ; struct Doublet * cdr ; } Doublet , *list;
// Indication de typage à donner aux fonctions de traitement de liste
typedef enum Type {INT , MOTS} Type;

// prototype desfonctions
void usage(char *);
list cons (void * car, list cdr);
void putlist(list L, Type);
int length(list L);
list arrayToList(void * tab, int taille, Type);
void listToArray(list L);
int in(void * elt  ,list L, Type t);
char * car(list L);
list cdr(list L);







int main(int argc, char * argv[]) {
  //conversion en liste d'entiers
  printf("conversion en liste d'entiers:\n");
  int entiers [] = { 1, 2, 4, 6, 8, 1, 3, 5, 7, 9 };  // declaration d'un tableau
  list lEntiers = arrayToList(entiers, 10, INT);            // conversion du tableau en liste
  putlist(lEntiers, INT);                                         // affichage de la liste



  // conversion en liste de mots
  printf("\nconversion en liste de mots:\n");
  char * code [] = { "papa", "alpha", "zulu", "hotel", "charlie", nil };
  list lMots = arrayToList(code, 5, MOTS);
  putlist(lMots, MOTS);

  // test avec la LDC
  printf("\ntest avec la LDC:\n");
  list lLdc = arrayToList(argv, argc, MOTS);
  putlist(lLdc, MOTS);


  // Conversion d'une liste en table
  printf("\n\nconversion d'une liste en table:\n");
  listToArray(lMots);




  // affichage du car
  printf("\ntest afichage du car: %s\n", car(lMots));

  // affichage du car
  printf("\ntest afichage du cdr:\n");
  putlist(cdr(lMots), MOTS);


  // affichage du cadr
  printf("\ntest afichage du cadr:  %s\n",  cadr(lMots));





  /* affichage du caar
  
  int sousList[] = {10,20,30} ;
  list sL = arrayToList(sousList, 3, INT);
  lEntiers = cons(sousList,lEntiers);
  printf("test afichage du caar:  %i\n", caar(sL));
  
  */

  return 0;
}








// IMPRESSION DE MESSAGE D'ERREUR (sur flux stderr)
void usage(char * message){ fprintf(stderr, "Usage : %s\n", message), exit(1) ;}



// CONSTRUCTION D'UN DOUBLET
list cons(void * car, list cdr){
  list L = malloc(sizeof(Doublet));
  if (!L) usage("espace insufisant");

  L -> car = car;
  L -> cdr = cdr;

  return L;
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



// RENVOI LA TAILLE D'UNE LISTE
int length(list L){
    int n = 0;
    while(L) {
        n++;
        L = L->cdr;
    }
    return n;
}



// CONVERTIR UNE TABLE EN LISTE
list arrayToList(void * tab , int taille, Type t){
    // definition d'une liste
    list L = nil;

    if (t == INT){
      // definition d'un pointeur type
      int *p = tab;
      // recuperation des entiers
      int n = 0;
      while(n++ < taille){
          // printf("%i ", *p++);
          L = cons(p++, L);
      }

    } else {
      // definition d'un pointeur type
      char **p = tab;
      // recuperation des mots
      int n = 0;
      while(n++ < taille){
          // printf("%i ", *p++);
          L = cons(*p++, L);
      }
    }
    return L;
}

//CONVERTIR UNE LISTE EN Table
void listToArray(list L){
  // recuperation de la taille de la liste
  int n = length(L);

  // allocation dynalique d'un vecteur qui contiendra les elements de la liste
  char **v = malloc(n * sizeof(char *));
  if (! v) usage("usage : impossible d'allouer l'espace en mémoire pour stoquer les éléments de la liste");

  // boucle de lecture de la liste
  int i = 0;
  char * P;
  for (i = n -1 ; i >= 0 ; i--){
    P = L -> car;
    v[i] = strdup(P);
    L = L-> cdr;
  }
  // affichage des elements récupérés
  for( i = 0 ; i < n; i++){
    printf("%s ",v[i]);
  }
  puts("");

}

// AFFICHAGE D'UNE LISTE
void putlist(list L, Type t){
  // récupération de la taillede la liste
  int nb = length(L);
  // création d'un Pointeur sur une liste
  list Copy = nil;

  if (t == INT){
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

  } else {
    char * P = malloc(sizeof(char));  // allocation d'un pointeur

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
      printf("%s ", P);
    }
  }
  puts("");
}
