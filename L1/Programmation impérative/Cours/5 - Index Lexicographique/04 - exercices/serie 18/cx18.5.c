#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// definition de nil
#define nil NULL

// Definition du type node et list
typedef struct node { void * car ; struct node * cdr ; } node , *list;
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


int main(int argc, char * argv[]) {
  // conversion en liste d'entiers
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
  printf("\nconversion d'une liste en table:\n");
  listToArray(lMots);
  return 0;
}








// IMPRESSION DE MESSAGE D'ERREUR (sur flux stderr)
void usage(char * message){ fprintf(stderr, "Usage : %s\n", message), exit(1) ;}

// RENVOI LA TAILLE D'UNE LISTE
int length(list L){
    int n = 0;
    while(L) {
        n++;
        L = L->cdr;
    }
    return n;
}

// CONSTRUCTION D'UN DOUBLET
list cons(void * car, list cdr){
  list L = malloc(sizeof(node));
  if (!L) usage("espace insufisant");

  L -> car = car;
  L -> cdr = cdr;

  return L;
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


// FONCTION 'IN'
// vérifie la présence d'une ref dans une liste
// affichage des valeurs de la liste
int in(void * elt  ,list L, Type t){
  if (t == INT){
    int * P = malloc(sizeof(int));  // allocation d'un pointeur
    P = elt;
    while(L){
      if (L -> car == P) return 1;
      L = L->cdr;
    }
    return 0;
  } else {
    char * P = malloc(sizeof(char));  // allocation d'un pointeur
    P = elt;
    while(L){
      if (L -> car == P) return 1;
      L = L->cdr;
    }
    return 0;
  }
}
