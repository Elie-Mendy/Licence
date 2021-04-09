/* NOM : MENDY
 * Prenom : Elie
 * n°etudiant : 19004664

  Consigne :
  Écrire un programme contenant quelques déclarations de variables et affichant
  l’adresse de ces variables.

  Que constatez-vous dans ces adresses?
    • s’il n’y a pas d’initialisation (ni d’affectation) des variables ?
    • avec initialisation, si on exécute plusieurs fois le même programme ?
 */


#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
  // declarer des entiers sans init
  int i1;
  int i2;
  int i3;

  
  // declaration d'entiers avec init
  int i4 = 102;
  int i5 = 5;
  int i6 = 12;

  // declarer de flottants sans init
  float f1;
  float f2;
  float f3;

  // declaration de flottants avec init
  float f4 = 3.14;
  float f5 = 78.6;
  float f6 = 8.2;


  // declarer de char sans init
  char c1;
  char c2;
  char c3;

  // declaration de char avec init
  char c4 = 'A';
  char c5 = 'z';
  char c6 = 'f';



  // affichage des adresses
  printf("\n\nCHARS:\n");
  printf("c1 : %p\n", &c1);
  printf("c2 : %p\n", &c2);
  printf("c3 : %p\n", &c3);
  puts("");
  printf("c4 : %p\n", &c4);
  printf("c5 : %p\n", &c5);
  printf("c6 : %p\n", &c6);

  printf("\nENTIERS:\n");
  printf("i1 : %p\n", &i1);
  printf("i2 : %p\n", &i2);
  printf("i3 : %p\n", &i3);
  puts("");
  printf("i4 : %p\n", &i4);
  printf("i5 : %p\n", &i5);
  printf("i6 : %p\n", &i6);

  printf("\nFLOTTANTS:\n");
  printf("f1 : %p\n", &f1);
  printf("f2 : %p\n", &f2);
  printf("f3 : %p\n", &f3);
  puts("");
  printf("f4 : %p\n", &f4);
  printf("f5 : %p\n", &f5);
  printf("f6 : %p\n", &f6);


  return 0;
}
