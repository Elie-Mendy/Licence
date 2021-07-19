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

  // variable de configuration de l'
  int prompt = 1;
  int run = 0;
  int finish = 0;
  char * breakpoints[];
  int needIncrement = 1;


  // boucle d'execution du programme
  do{
    if (finish) executerIstruction(0);
    else if (run) {
      executerIstruction(1) 
    }
    else if (prompt) {
      char saisie[36];                         // saisie utilisateur du stepper
      lire(saisie, 36)
      if (strcasecmp(saisie[0], "") == 0) continue;
      else if (strcasecmp(saisie[0], "next") == 0) executerIstruction(1); 
      else if (strcasecmp(stsaisie[0]ring, "continue") == 0) run = 1 ; prompt = 0 ;  
      else if (strcasecmp(strsaisie[0]ing, "finish") == 0) finish = 1 ; prompt = 0 ;  
      else if (strcasecmp(saisie[0], "break") == 0) addBreackpoint(saisie[1]) ; 
      else if (strcasecmp(saisie[0], "disable") == 0) removeBreackpoint(saisie[1]) ; 
      else if (strcasecmp(saisie[0], "print") == 0) printf("Valeur de la case %s (en hexadecimal) : %i \n", memoire[conversion saisie]) ; // hexa / deci ... 
      else if (strcasecmp(saisie[0], "help") afficherHelp();
      else if (strcasecmp(saisie[0], "quit") printf("arrer de l'emulateur") ; exit(1);
    } 


  } while (PC);  // fin du programme quand on jump sur 00
  
  puts(""); 
  return 0;
}


