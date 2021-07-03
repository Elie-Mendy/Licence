/*
  NOM: MENDY
  Prenom : Elie
  n°etudiant : 19004664

  EXERCICE cx17.8
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

//#define DEBUG                                // debug général
//#define DEBUG_n2                             // debug plus pointu
//#define STEPPER                              // possibilitée d'executer chaques instruction via la touche 'enter'
#define AUTO                                 // chargement automatique du programme en mémoire
#define EXO                                  // contexte de l'exercice 10.6 
#define TAILLE_MEMOIRE 256                   // nombre d'adresses disponible en memoire
#define TAILLE_ADRESSE 3                     // taille de la chaine representative d'une adresse 
#define TAILLE_BOOTSTRAP 32                  // combre d'instruction que contient le bootstrap
#define TAILLE_MAX_PROGRAMME 200             // combre de lignes maximum que peut contenir le programme - mode automatique
#define FIRST_INSTRUCTION "28"                 // adresse de la première instruction (en hexadécimal) - mode automatique
#define FIRST_INSTRUCTION_EXO_10_6 "50"                 // adresse de la première instruction (en hexadécimal) - mode automatique

typedef char Hexa ;                          // definition du type Hexadecimal 
typedef char * str ;                         // definition du type str 
typedef unsigned idx;                        // definition du type str 
// Allocation d'espace pour:
// - la memoire
Hexa * memoire[TAILLE_MEMOIRE];       // --> la barette memoire (ressource de l'ordinateur)

// -les registres
Hexa RS[TAILLE_ADRESSE];                     // --> registre de Selection
Hexa RM[TAILLE_ADRESSE];                     // --> registre de Mot

Hexa IN[TAILLE_ADRESSE];                     // --> peripherique Entrée
Hexa OUT[TAILLE_ADRESSE];                    // --> peripherique Sortie (affichage)

Hexa PC[TAILLE_ADRESSE];                     // --> registre Program Counter

Hexa OP[TAILLE_ADRESSE];                     // --> registre de Registre Instruction (code opératoire)
Hexa AD[TAILLE_ADRESSE];                     // --> registre de Registre Instruction (adresse de la donnée à traiter)

Hexa A[TAILLE_ADRESSE];                      // --> registre Accumulateur

// - l'unité de calcul        
int UAL;                    // --> registre d'indication du calcul a effectuer

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

  // initialisation de la mémoire 
  initialiserRegistres();
  chargerBootstrap();
  //afficherMemoire(55);

  // chargement du programme
  int taille = lireProgramme(argv[1]);
  //afficherProgramme();
  chargerProgramme(taille);
  //afficherMemoire(250);
  

  
  #ifdef EXO
    Hexa fin[TAILLE_ADRESSE] = "6E";
  #else
    Hexa fin[TAILLE_ADRESSE] = "00";
  #endif 


  do{
    #ifdef DEBUG 
      printf("____________________________________________________________________\n"); 
    #endif 
    phase1();         // recherche d'instruction
    executer(hexaToInt(OP));  
    #ifdef DEBUG 
      printf("____________________________________________________________________\n");
      printf("Etat des Registres:\n");
      printf("- PC=%s \t A=%s\n" , PC, A);
      printf("____________________________________________________________________\n\n\n");  
    #endif 
    #ifdef STEPPER
    stepper();
    #endif
  } while (strcasecmp(PC , fin));  // fin du programme quand on jump sur 00
  return 0;
}




void usage(str message) { fprintf(stderr, "Usage : %s\n", message), exit(1) ;}


void stepper() {
  printf("('Enter' pour passer à l'instruction suivante)");
  char c;
  while((c =getchar()) == '\0');
}



void afficherMemoire(int adresse) {
  #ifdef DEBUG 
    printf("- affichage de la memoire \n");  
  #endif 
  for (int i = 0; i < adresse && i < TAILLE_MEMOIRE ; i++) {
    printf("adresse %i\t--> b16: %x:\t%s\n", i, i, memoire[i]);
  }
}



void initialiserRegistres(){
  #ifdef DEBUG 
    printf("- initialisation des registres  \n"); 
  #endif 
 
  // registre memoire
  strcpy(RS,"00");
  strcpy(RM,"15");

  // Entrées / sorties
  strcpy(IN,"00");
  strcpy(OUT,"00");

  // Program Counter
  #ifdef EXO
    strcpy(PC,FIRST_INSTRUCTION_EXO_10_6);
  #else
    strcpy(PC,FIRST_INSTRUCTION);
  #endif
  // Registre Instruction
  strcpy(OP,"00");
  strcpy(AD,"00");

  // unité de calcul
  strcpy(A,"10");
  UAL = 0;
}


int lireProgramme(str programme) {
  // ouverture du flux
  FILE * fichier = fopen(programme, "r");
  if (! fichier) usage(" stoplist illisible");

  int i = 0;
  char lu = '\0';
  while (i < TAILLE_MAX_PROGRAMME && lu != EOF){
    char sas[TAILLE_ADRESSE];              // sas de reception du mot
    lu = fscanf(fichier, "%s ", sas);
    if (lu != EOF){
      prog[i++] = strdup(sas);
      }
    }
  fclose(fichier);
  return i -1;
}


void executer(int code) {
  #ifdef DEBUG 
    printf("==> phase 2 : exec code -> %i \n", hexaToInt(OP)); 
  #endif 
  switch (code)
  {
    //
    // ARITHMETIQUE
    //
    // ADD #  20
    case 32:  
      addValeur();
      break;

    // ADD α  60
    case 96:
      addValeurP();
      break;

    // ADD *α E0
    case 224:
      addValeurPP();
      break;
    
      // SUB #  21
    case 33:  
      subValeur();
      break;

    // SUB α  61
    case 97:
      subValeurP();
      break;

    // SUB *α E1
    case 225:
      subValeurPP();
      break;
    

    //
    // LOGIQUE
    //
    // NAND #  22
    case 34:  
      nand();
      break;

    // NAND α  62
    case 98:
      nandP();
      break;

    // NAND *α E2
    case 226:
      nandPP();
      break;


    //
    //  TRANSFERTS
    //
    // LOAD #  00
    case 0:  
      load();
      break;

    // LOAD α  40
    case 64:
      loadP();
      break;

    // LOAD *α C0
    case 192:
      loadPP();
      break;

    // STORE α  48
    case 72:
      storeP();
      break;

    // STORE *α C8
    case 200:
      storePP();
      break;

    //
    // ENTREE / SORTIES
    //
    // IN α  49
    case 73:
      inP();
      break;

    // IN *α C9
    case 201:
      inPP();
      break;

    // OUT α 41
    case 65:
      outP();
      break;

    // OUT *α C1
    case 193:
      outPP();
      break;

    // 
    // BRANCHEMENT INCONDITIONNEL
    //
    // JUMP α 10
    case 16:
      jump();
      break;

    // 
    // BRANCHEMENT CONDITIONNEL
    //
    // BRN α 11
    case 17:
      brn();
      break;
    
    // BRN α 12
    case 18:
      brz();
      break;

    default:
      printf("/!\\ CODE OP %i INNEXISTANT /!\\", code);
      exit(1);
      break;
  }
}


//TODO - simplifier chargement du bootstrap et du programme par un paramettre a entrer 