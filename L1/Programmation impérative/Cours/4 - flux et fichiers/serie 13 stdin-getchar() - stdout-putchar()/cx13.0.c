/* Fonction CAT */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
  signed char x;
  while( (x = getchar()) != EOF) putchar(x);
}


/* leçon
un Volume (DD SSH ... ) est un fichier ...


la fonction getcher() lit sur le flux stdin

dans le shell on peut très bien passer du texte comme la fonction cat
ou passer un ficher à copier


Ctrl + D envoi EOF au programme*/
