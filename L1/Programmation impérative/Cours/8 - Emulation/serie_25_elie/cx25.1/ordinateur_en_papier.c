/*
  NOM: MENDY
  Prenom : Elie
  n°etudiant : 19004664

  EXERCICE cx17.8
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define TAILLE_MEMOIRE 256                    // nombre d'adresses disponible en memoire
#define TAILLE_DATA 3                         // taille de la chaine representative d'une adresse 
#define NB_BREAKPOINTS 5
typedef char Hexa ;                           // definition du type Hexadecimal 
typedef char * str ;                          // definition du type str 

// Allocation d'espace pour la mémoire et les registres 
long int memoire[TAILLE_MEMOIRE];             // --> la barette memoire (ressource de l'ordinateur)
long int PC;                                  // --> registre Program Counter
long int A;                                   // --> registre Accumulateur
char lib[1024];                               // --> le mnémonique de l'opération en cours 


// variable de configuration pour l'execution du debuggeur
int prompt = 1;                               // declanchement du prompt 
int run = 0;                                  // permet de boucler sur les instruction sauf en cas de breakpoint
int finish = 0;                               // permet de boucler sur les instruction jusqu'a la fin du programme
str breakpoints[NB_BREAKPOINTS];              // contient la liste des breakpoints 
int needIncrement = 1;                        // permet de le pas incrementer PC pour les branchements  
char ligne[1024];                             // --> saisie utilisateur  capturé dans un vecteur de caracteres
str ldc[4];                                   // --> la ligne de commande du debuggeur parsée

// inclusion des fonctions
#include "fonctions.c"        


/*______________________________________________________________________________

                    EMULATION DE L'ORDINATEUR EN PAPIER (main) 
______________________________________________________________________________*/

int main(int k, char  *argv[]) {
  // test du nombre d'arguments
  if (k < 2) usage("veuillez indiquer le nom du programme a lire");

  printf("\n\n____________________________________________________________________\n");
  printf(" Emulateur de l'Ordinateur En Papier \n");
  printf("____________________________________________________________________\n\n"); 

  // affichage des commandes disponibles 
  afficherHelp();

  // chargement du bootstrap 
  int adresse = 0; 
  chargerProgramme(adresse, "bootstrap_loader");

  // saisie de l'adresse de la premiere instruction
  printf("veuillez entrer l'adresse de la première instruction du programme : ");
  scanf("%x", &adresse);  
  viderBuffer();

  // chargement du programme
  chargerProgramme(adresse, argv[1]);

  // initialisation de PC et A
  initialiserRegistres(adresse);

  // boucle d'execution du programme
  do{
    if (finish) executerIstruction(0);                      
    else if (run) { executerIstruction(1); continue ; }
    else if (prompt) {            
      // affihage du prompt  
      printf(">>>  ");

      // lancement de la saisie utilisateur 
      if (!fgets(ligne, 1024, stdin)) usage("lecture de la ldc impossible");

      // découpage et parsing de la saisie
      str mot = strtok(strdup(ligne), " \n");
      parserSaisieUtilisateur(mot);

      // execution de la commande saisie
      if (strcasecmp(ldc[0], "next") == 0) { executerIstruction(0) ; continue ;} 
      else if (strcasecmp(ldc[0], "run") == 0) { run = 1 ; prompt = 0 ; } 
      else if (strcasecmp(ldc[0], "continue") == 0) { executerIstruction(0) ; run = 1 ; prompt = 0 ;   continue; } 
      else if (strcasecmp(ldc[0], "finish") == 0) { finish = 1 ; prompt = 0 ;}   
      else if (ldc[0] && strcasecmp(ldc[0], "break") == 0 && ldc[1]) addBreackpoint(ldc[1]);  
      else if (ldc[0] && strcasecmp(ldc[0], "disable" ) == 0 && ldc[1]) removeBreackpoint(ldc[1]) ;  
      else if (ldc[0] && strcasecmp(ldc[0], "breaklist") == 0) afficherBreackpoints(ldc[1]) ;
      else if (ldc[0] && strcasecmp(ldc[0], "disable" ) == 0 && ldc[1]) removeBreackpoint(ldc[1]) ;  
      else if (ldc[0] && strcasecmp(ldc[0], "print") == 0 && ldc[1]) printf("Valeur de la case %s (en hexadecimal) : %lx \n", ldc[1], memoire[strtol(ldc[1], NULL, 16)]) ; 
      else if (ldc[0] && strcasecmp(ldc[0], "help") == 0) afficherHelp();
      else if (ldc[0] && strcasecmp(ldc[0], "quit") == 0) { printf("arrer de l'emulateur\n") ; exit(1); }
      else { printf("Cette commande n'est pas reconnue ... \n"); continue ;}
    } 
  } while (PC);  // fin du programme quand on jump sur 00
  
  puts(""); 
  return 0;
}


