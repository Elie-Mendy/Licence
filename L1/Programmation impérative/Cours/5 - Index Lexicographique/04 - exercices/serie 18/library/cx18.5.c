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


/* DEMARCHE

gcc -c cx18.5.c cx18.5.l.c              // creation des fichier .o
ar -r lib18.a cx18.5.l.o                // creation de la library
gcc -Wall cx18.5.c lib18.a -o essai     // generation de l'executable

*/
