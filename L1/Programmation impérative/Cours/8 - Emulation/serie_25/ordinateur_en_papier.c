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
#define TAILLE_DATA 3                     // taille de la chaine representative d'une adresse 
#define TAILLE_BOOTSTRAP 32                  // combre d'instruction que contient le bootstrap
#define TAILLE_MAX_PROGRAMME 200             // combre de lignes maximum que peut contenir le programme - mode automatique

typedef char Hexa ;                          // definition du type Hexadecimal 
typedef char * str ;                         // definition du type str 
typedef unsigned idx;                        // definition du type str 
// Allocation d'espace pour:
// - la memoire
Hexa * memoire[TAILLE_MEMOIRE];       // --> la barette memoire (ressource de l'ordinateur)

// -les registres
Hexa PC[TAILLE_DATA];                     // --> registre Program Counter
Hexa A[TAILLE_DATA];                      // --> registre Accumulateur




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

  // initialisation des registres A et PC
  initialiserRegistres();

  // chargement du bootstrap 
  chargerBootstrap();
  
  //afficherMemoire(250);

  //ZONE TEST ET DEBUG
  /*
  int a = strtol(A, NULL, 10);
  printf("a = %i    ", a);
  int b = strtol(memoire[hexaToInt(memoire[hexaToInt(PC)])], NULL, 10);

  printf("b = %i\n", b); 

  sprintf(A,"%ld\n",  (strtol(A, NULL, 10) + strtol(memoire[hexaToInt(memoire[hexaToInt(PC)])], NULL, 10)));
  */
  
  int opCode = hexaToInt(memoire[hexaToInt(PC)]);
  executer(opCode); 
  afficherRegistre();
  /*
  do{
      int opCode = hexaToInt(memoire[hexaToInt(PC)]);
      executer(opCode); 
      afficherRegistre(); 
      #ifdef STEPPER
      stepper();
      #endif
    } while (strcasecmp(PC , "00"));  // fin du programme quand on jump sur 00
  */  
    return 0;
}




void usage(str message) { fprintf(stderr, "Usage : %s\n", message), exit(1) ;}

/*  fonction: chargerBootstrap()   
    objectif: 
      - li le fichier "bootstrap"
      - le charge en memoire
*/
void chargerBootstrap(){  
  // ouverture du flux
  FILE * fichier = fopen("bootstrap", "r");
  if (! fichier) usage("bootstrap illisible");

  idx i = 0;
  char lu = '\0';
  while (i < TAILLE_MEMOIRE && lu != EOF){
    char sas[TAILLE_DATA];               // sas de reception du mot
    lu = fscanf(fichier, "%s ", sas);
    if (lu != EOF){
      memoire[i++] = strdup(sas);
      }
    }

  // fermeture du flux
  fclose(fichier);
};


void stepper() {
  printf("('Enter' pour passer à l'instruction suivante)");
  char c;
  while((c =getchar()) == '\0');
}



void afficherMemoire(int adresse) {
  for (int i = 0; i < adresse && i < TAILLE_MEMOIRE ; i++) {
    printf("adresse %i\t--> b16: %x:\t%s\n", i, i, memoire[i]);
  }
}

void afficherRegistre() {
  printf("____________________________________________________________________\n");
  printf("Etat des Registres:\n");
  printf("- PC=%s \t - A=%s \n" , PC, A);
  printf("____________________________________________________________________\n\n\n");  
}



void initialiserRegistres(){
  // Program Counter
  strcpy(PC,"14");

  // unité de calcul
  strcpy(A,"10");
}

int hexaToInt(Hexa h[TAILLE_DATA] ){ 
  #ifdef DEBUG_n2 
    int i = strtol(h, NULL, 16);
    printf("   - convertion hexa: %s  --> ToInt : %i\n", h, i);
  #endif 
  
  return strtol(h, NULL, 16);   
}

void intToHexa(Hexa * registre , int code ){ 
  Hexa value[TAILLE_DATA];
  sprintf(value, "%x", code);
  
  // gestion des valeurs < 10
  if (strlen(value) < 2) {
    value[1] = value[0];
    value[0] = '0';
  }

  // attribution de la nouvelle valeur au registre
  strcpy(registre, value);
  #ifdef DEBUG_n2 
    printf("   - convertion int: %i  --> ToHexa : %s\n", code, registre); 
  #endif 
  
}


void executer(int code) {
  switch (code)
  {
    //
    // ARITHMETIQUE
    //
    // ADD #  20
    case 32: sprintf(A,"%ld\n",  (strtol(A, NULL, 10) + strtol(memoire[hexaToInt(PC)], NULL, 10 ))); break;

    // ADD α  60
    case 96: sprintf(A,"%ld\n",  (strtol(A, NULL, 10) + strtol(memoire[hexaToInt(memoire[hexaToInt(PC)])], NULL, 10))); break;

    // ADD *α E0
    case 224: sprintf(A,"%ld\n",  (strtol(A, NULL, 10) + strtol(memoire[hexaToInt(memoire[hexaToInt(memoire[hexaToInt(PC)])])], NULL, 10))); break;
    
    // SUB #  21
    case 33: sprintf(A,"%ld\n",  (strtol(A, NULL, 10) - strtol(memoire[hexaToInt(PC)], NULL, 10 ))); break;

    // SUB α  61
    case 97: sprintf(A,"%ld\n",  (strtol(A, NULL, 10) - strtol(memoire[hexaToInt(memoire[hexaToInt(PC)])], NULL, 10))); break;

    // SUB *α E1
    case 225: sprintf(A,"%ld\n",  (strtol(A, NULL, 10) - strtol(memoire[hexaToInt(memoire[hexaToInt(memoire[hexaToInt(PC)])])], NULL, 10))); break;
  }
}
/*
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
}*/


//TODO - simplifier chargement du bootstrap et du programme par un paramettre a entrer 