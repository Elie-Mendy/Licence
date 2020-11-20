/* fichier explicatif de l'allocation dynamique en case  */

#include <stdio.h>
#include <stdlib.h>



 int main(int argc, char const *argv[]) {

   /* EXEMPLE 1 : avec un  entier */
   // initialisation d'un pointeur
   int * monEntier = NULL;

   // allocation d'espace
   monEntier = malloc(sizeof(int));

   // test de validité de l'espace alloué
   if (! monEntier) exit(1);

   // utilisation de l'espace
   char sas[10];                                              // allocaton espace saisie
   printf("Quel age avez vous ? ");
   *monEntier = strtol (fgets(sas, 10, stdin), NULL, 10);     // saisie user + conversion en entier
   printf("Vous avez %i ans.\n", *monEntier);

   // libération de l'espace
   free(monEntier);





   /* EXEMPLE 2 : avec un tableau d'entier */
   // recupération de la taille du tableau
   printf("Combien avez vous d'amis ? ");
   char saisie[10];
   int nb = strtol(fgets(saisie, 10, stdin), NULL, 10);

   if (nb){                                                   // si pas d'amis ... on ne fait rien
    // initialisation d'un pointeur
    int * tabAgeAmis = NULL;
    int i;

    // allocation d'espace d'un tab[nb * int]
    tabAgeAmis = malloc(sizeof(int) * nb);

    // test de validité de l'espace alloué
    if (! tabAgeAmis) exit(1);

    // utilisation de l'espace
    for (i = 0; i < nb ; i++){
      char age[10];
      printf("Quel age à votre ami %i ",  i+1);
      tabAgeAmis[i] = strtol(fgets(age, 10, stdin) , NULL, 10);
     }


     printf("\nVos amis ont les ages suivants: \n");
     for (i = 0; i< nb ; i++){
       printf("Votre ami %i à : %i ans\n", i+1, tabAgeAmis[i]);
     }

     // libération de l'espace


   }

   return 0;
 }
