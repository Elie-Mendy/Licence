#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define max_mots 800                                // nombre maximum d'éléments dans la table de mots
#define max_refs 20                                 // nombre maximum de ref par mots
#define maximum 4096                                // nombre maximal de caractères composant un mot
#define taille_mot 1024

typedef unsigned idx ;                              // definition du type idx
typedef char * str;                                 // definirion du type str
typedef enum {False, True} bool ;                   // definition du type bool



// implémentation des structures de listes élastiques (entier et chaines de caractères)
#define nil NULL

typedef struct node node, *list;
struct node{
  idx  car;
  struct node * cdr;
  };

typedef struct wd_list wd_list, *stp;
struct wd_list{
  char * car;
  struct wd_list * cdr;
  };



// definition d'un nouveau type pour emuler un index
typedef struct ndex ndex;
struct ndex{
  str mot ;
  list refs ;
};


/* Fichier rassemblant l'implétentation d'une structure de liste elastique
 * pouvant contenir des ==>  ENTIERS  <===
 * comprenant les fonctions suivantes :
    - construction de liste d'entiers
    - renvoyer la taille d'une liste d'entiers
    - controler la présence d'un entier dans une liste d'entiers
    - afficher le contenu d'une liste d'entiers
    */





// IMPRESSION DE MESSAGE D'ERREUR (sur flux stderr)
void usage(char * message){ fprintf(stderr, "Usage : %s\n", message), exit(1) ;}


// CONSTRUCTION D'UNE LISTE
list cons(idx car, list L){
  list new = malloc(sizeof(node));
  if (!new) usage("cons : manque de RAM") ;
  new -> car = car;
  new -> cdr = L;
  return new; }

// FONCTION 'IN'
// vérifie la présence d'une ref dans une liste
// affichage des valeurs de la liste
int in(int ref ,list L){
  while(L){
    if (L -> car == ref) return 1;
    L = L->cdr;
  }
  return 0;
}

// RENVOI LA TAILLE D'UNE LISTE
int length(list L){
  int n = 0;
  if (L->car) n++;
  while (L->cdr){
    L = L->cdr;
    n++;
    }
    return n;
  }


// AFFICHAGE D'UNE LISTE (a l'endroit)
void putlist(list L){
  // recuperation de la taille de la liste
  int n = length(L), i;


  // allocation dynalique d'un vecteur qui contiendra les elements de la liste
  idx *v;
  v = malloc(max_refs * sizeof(*v));
  if (! v) usage("usage : impossible d'allouer l'espace en mémoire pour stoquer les éléments de la liste");

  // boucle de lecture de la liste
  for (i = n -1 ; i >= 0 ; i--){
    v[i] = L-> car;
    L = L-> cdr;
  }
  // affichage des elements récupérés
  for( i = 0 ; i < n; i++){
    printf("%d ",v[i]);
  }


}
