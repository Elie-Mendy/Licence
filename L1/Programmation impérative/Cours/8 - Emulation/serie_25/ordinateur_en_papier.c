/*
  NOM: MENDY
  Prenom : Elie
  n°etudiant : 19004664

  EXERCICE cx17.8
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

//#define STEPPER                              // possibilitée d'executer chaques instruction via la touche 'enter'
#define TAILLE_MEMOIRE 256                   // nombre d'adresses disponible en memoire
#define TAILLE_DATA 3                        // taille de la chaine representative d'une adresse 

typedef char Hexa ;                          // definition du type Hexadecimal 
typedef char * str ;                         // definition du type str 

// Allocation d'espace pour la mémoire et les registres 
Hexa * memoire[TAILLE_MEMOIRE];           // --> la barette memoire (ressource de l'ordinateur)
Hexa PC[TAILLE_DATA];                     // --> registre Program Counter
Hexa A[TAILLE_DATA];                      // --> registre Accumulateur
Hexa lib[1024];                           // --> le mnémonique de l'opération en cours 

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
  chargerProgramme(adresse, "bootstrap");

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
    int opCode = hexaToInt(memoire[hexaToInt(PC)]);

    // execution de l'opération
    incrementerPC();
    needIncrement = executer(opCode); 
    afficherRegistre(); 

    // appuyer sur 'Enter' pour validation 
    #ifdef STEPPER
    stepper();
    #endif

    if (needIncrement == 1) incrementerPC();

  } while (strcasecmp(PC , "00"));  // fin du programme quand on jump sur 00
  
  puts("");
  return 0;
}



