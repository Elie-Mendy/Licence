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
    // declarations de variables
    int var1 = 1;
    int var2 = 8;
    char var3 = 'e';
    float var4 = 4.9;
    char var5[5] = "test";

    printf("Avec affectation:\n");
    printf("variable 1: %p \n", &var1);
    printf("variable 2: %p \n", &var2);
    printf("variable 3: %p \n", &var3);
    printf("variable 4: %p \n", &var4);
    printf("variable 5: %p \n", &var5);

    int var6 ;
    int var7 ;
    char var8 ;
    float var9 ;
    char var10[5] ;


    printf("\nSans affectation:\n");
    printf("variable 6: %p \n", &var6);
    printf("variable 7: %p \n", &var7);
    printf("variable 8: %p \n", &var8);
    printf("variable 9: %p \n", &var9);
    printf("variable 10: %p \n", &var10);

    return 0;
}
