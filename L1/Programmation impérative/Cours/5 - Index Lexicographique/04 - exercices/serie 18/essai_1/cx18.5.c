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
int length(list L);

// CONVERSION Table en Liste
list table_to_list(char **);

// CONVERSION List en Table
char ** list_to_table(list);






int main(int argc, char *argv[]) {


  char * code [] = { "papa", "alpha", "zulu", "hotel", "charlie", nil };

  list L = table_to_list(code);

  char ** v = list_to_table(L);

  // exemple d'affichage de listes
  int n = length(L), i;
  for( i = 0 ; i < n; i++){
    printf("%s ",v[i]);
  }


  puts("");
  return 0;
}




// CONVERSION List en Table
char ** list_to_table(list L){
  // recuperation de la taillede la liste
  int n = length(L), i;

  // allocation dynamique d'une tableaude mots
  char **v;
  v = malloc(max_mots * sizeof(*v));
  if (! v) usage("usage : impossible d'allouer l'espace en mémoire pour stoquer les éléments de la liste");

  // remplissage de la table
  for (i = n -1 ; i >= 0 ; i--){
    v[i] = strdup(L-> car);
    L = L-> cdr;
  }
  return v;
}

// CONVERSION Table en Liste
list table_to_list(char * table[]){
  // definition d'une liste vide
  list L = nil;
  // recuperation de la taille du tableau
  int n = 0;
  while(table[n]) n++;
  // remplissage de la liste
  int i = 0;
  for (i = 0 ; i < n ;i++){
    L = cons(table[i], L);
  }
  return L;
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

// AFFICHAGE D'UNE LISTE (a l'endroit)
void putlist(list L){
  // recuperation de la taille de la liste
  int n = length(L), i;


  // allocation dynalique d'un vecteur qui contiendra les elements de la liste
  char **v;
  v = malloc(max_mots * sizeof(*v));
  if (! v) usage("usage : impossible d'allouer l'espace en mémoire pour stoquer les éléments de la liste");

  // boucle de lecture de la liste
  for (i = n -1 ; i >= 0 ; i--){
    v[i] = strdup(L-> car);
    printf("%s\n", v[i] );
    L = L-> cdr;
  }
  // affichage des elements récupérés
  for( i = 0 ; i < n; i++){
    printf("%s ",v[i]);
  }
  puts("");

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
