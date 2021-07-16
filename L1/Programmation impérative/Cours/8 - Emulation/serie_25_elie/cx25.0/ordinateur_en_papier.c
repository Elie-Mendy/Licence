/*
  NOM: MENDY
  Prenom : Elie
  n°etudiant : 19004664

  EXERCICE cx17.8
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define TAILLE_MEMOIRE 256                   // nombre d'adresses disponible en memoire
#define TAILLE_DATA 3                        // taille de la chaine representative d'une adresse 

typedef char Hexa ;                          // definition du type Hexadecimal 
typedef char * str ;                         // definition du type str 

// Allocation d'espace pour la mémoire et les registres 
long int memoire[TAILLE_MEMOIRE];        // --> la barette memoire (ressource de l'ordinateur)
long int PC;                             // --> registre Program Counter
long int A;                                       // --> registre Accumulateur
char lib[1024];                              // --> le mnémonique de l'opération en cours 

// inclusion des headers
#include "fonctions.h"        


/*______________________________________________________________________________

                    EMULATION DE L'ORDINATEUR EN PAPIER (main) 
______________________________________________________________________________*/

int main(int k, char  *argv[]) {
  // test du nombre d'arguments
  if (k < 2) usage("veuillez indiquer le nom du programme a lire");

  printf("\n\n____________________________________________________________________\n");
  printf(" Emulateur de l'Ordinateur En Papier \n");
  printf("____________________________________________________________________\n\n"); 

  // chargement du bootstrap 
  int adresse  = 0; 
  chargerProgramme(adresse, "bootstrap_loader");

  // saisie de l'adresse de la premiere instruction
  printf("veuillez entrer l'adresse de la première instruction du programme : ");
  scanf("%x", &adresse);  

  // chargement du programme
  chargerProgramme(adresse, argv[1]);

  // initialisation de PC et A
  initialiserRegistres(adresse);

  
  // boucle d'execution du programme
  int needIncrement = 1;
  do{
    // lecture du code opération 
    int opCode = memoire[PC];

    // execution de l'opération
    incrementerPC();
    needIncrement = executer(opCode);

    // affichage en console
    #ifndef NO_DEBUG
    afficherRegistre(); 
    #endif

    if (needIncrement == 1) incrementerPC();

  } while (PC);  // fin du programme quand on jump sur 00
  
  puts(""); 
  return 0;
}


