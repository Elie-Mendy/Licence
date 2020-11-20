#include <stdio.h>
#include <stdlib.h>

/* leçon :
char V[] = "azertyuiop" ; // V comme vecteur : une référence fixe, immuable
char * R = V ; // R est une référence libre à la même valeur que V

char V [] = "azertyuiop" //déclare un pointeur fixe sur une valeur variable
char * R = "azertyuiop" // déclare un pointeur libre sur une valeur constante


SEQUENCES NUMERIQUES
impossible d'ecrire
int * seq = {1,2,3};

on ecrira:
int seq[] = {1,2,3}
int * Pointeur = seq      // on parcourera seq au moyen de R

*/


int main(int argc, char const *argv[]) {
  // si on definie des pointeurs sur des sequences de caractères
  // ces sequences sont ecrites et partagées pour les valeurs equivalentes
  // bloquées en ecriture par le programme (segment text)
  char * var1 = "azerty";
  char * var2 = "azerty";   // toutes ces chaines sont immutable
  char * var3 = "azer";
  char * var4 = "azer";

  // différentes si chaines ecrite litéralement en mémoire  (segment data)
  char chaine[] = "azerty";   // chaine est mutable

  printf("adresses de var 1 :%p %c %p\n",&*var1, *var1, &var1);
  printf("adresses de var 2 :%p %c %p\n",&*var2, *var2, &var2);
  printf("adresses de la chaine :%p %c %p \n", &*chaine, *chaine, &chaine);


  printf("adresses de var 3 :%p %c %p\n",&*var3, *var3, &var3);
  printf("adresses de var 4 :%p %c %p\n",&*var4, *var4, &var4);
  return 0;
}
