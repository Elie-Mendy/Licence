#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// definition de nil
#define nil NULL

// Definition du type node et list
typedef char * str;                                 // definirion du type str
typedef enum {False, True} bool ;                   // definition du type bool
typedef struct node { void * car ; struct node * cdr ; } node , *list;
// Indication de typage à donner aux fonctions de traitement de liste
typedef enum Type {INT , MOTS} Type;
// IMPRESSION DE MESSAGE D'ERREUR (sur flux stderr)
void usage(char * message){ fprintf(stderr, "Usage : %s\n", message), exit(1) ;}


// COMPARAISON DE DEUX CHAINES
bool pareil(str x, str y) { return strcasecmp(x,y) ? False : True ; }




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
}


/*  fonction: in()
    objectif: verifie la présence d'un element dans une liste
    parametres:
      - l'adresse de l'element à identifier
      - la liste a parcourir
      - le type de l'element*/
int in(void * elt  ,list L, Type t){
  if (t == INT){
    int * P = malloc(sizeof(int));  // allocation d'un pointeur
    int * C = malloc(sizeof(int));  // allocation d'un pointeur qui prendra le car
    P = elt;
    while(L){
      C = L -> car;
      if (*C == *P) return 1;
      L = L->cdr;
    }
  } else {
    char * P = malloc(sizeof(char));  // allocation d'un pointeur
    char * C = malloc(sizeof(char));  // allocation d'un pointeur qui prendra le car
    P = elt;
    while(L){
      C = L -> car;
      if (! strcasecmp(C, P)) return 1;
      L = L->cdr;
    }
  }
  return 0;
}
