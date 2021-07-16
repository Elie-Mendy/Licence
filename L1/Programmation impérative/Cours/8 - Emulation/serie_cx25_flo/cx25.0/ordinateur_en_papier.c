

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

// definition de types supplementaires
typedef char Hexa ;                          
typedef char * str ;               

// inclusion des headers
void usage(str message);
void initialiserRegistres(int adresse);
void loadProgram(int adresse, char * fileName);
int hexaToInt(Hexa h[3] );
void intToHexa(Hexa * registre , int code );
int executer(int code) ;
void incrementerPC();
void afficherRegistre();   


// Allocation d'espace pour la mémoire et les registres 
Hexa * memoire[256];            // --> la barette memoire (ressource de l'ordinateur)
Hexa PC[3];                     // --> registre Program Counter
Hexa A[3];                      // --> registre Accumulateur
Hexa mnemonique[1024];                 // --> le mnémonique de l'opération en cours 

   

/*______________________________________________________________________________

                    EMULATION DE L'ORDINATEUR EN PAPIER (main) 
______________________________________________________________________________*/

int main(int k, char  *argv[]) {
  // test du nombre d'arguments
  if (k < 2) usage("veuillez indiquer le nom du programme a lire");

  printf("\n\n____________________________________________________________________\n");
  printf(" Emulateur de l'Ordinateur En Papier \n");
  printf("____________________________________________________________________\n\n"); 

  // chargement du bootstrap en memoire
  loadProgram(0, "bootstrap_loader");

  // chargement du programme utilisateur en memoire
  int adresse  = 0; 
  printf("veuillez entrer l'adresse de la première instruction du programme : ");
  scanf("%x", &adresse);  

  // chargement du programme
  loadProgram(adresse, argv[1]);

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

    // affichage en console
    #ifndef NO_DEBUG
    afficherRegistre(); 
    #endif

    if (needIncrement == 1) incrementerPC();

  } while (strcasecmp(PC , "00"));  // fin du programme quand on jump sur 00
  
  puts("");
  return 0;
}



/*______________________________________________________________________________

        DEFINITION FONCTIONS DE L'EMULATEUR : ORDINATEUR EN PAPIER
______________________________________________________________________________*/

/*  fonction: usage()
    objectif: impression de messages d'erreur (sur flux stderr)
    parametres: une string (le messages à renvoyer)*/
void usage(str message) { fprintf(stderr, "Usage : %s\n", message), exit(1) ;}

/*  fonction: initialiserRegistres()
    objectif: attribuer une valeur initiale aux différents registres */
void initialiserRegistres(int adresse){
  // Program Counter
  sprintf(PC , "%x", adresse );
  // unité de calcul
  strcpy(A,"00");
}

/*  fonction: loadProgram()
    objectif: 
      - ecrit le programme dans la mémoire 
      - sans passer par le bootstrap manuel
    parametres: 
      - un entier 
        (l'adresse de la premiere instruction du programme en memoire)
      - le nom du programme a charger*/
void loadProgram(int adresse, char * fileName){  
  FILE * fichier = fopen(fileName, "r");
  if (! fichier) usage("Erreur : le programme est illisible ou inexistant");
  int i = adresse;
  char lu = '\0';
  while (lu != EOF && i < 256){
    char data[3];               
    lu = fscanf(fichier, "%s ", data);
    if (lu != EOF){
      memoire[i++] = strdup(data);
      }
    }
  fclose(fichier);
};

/*  fonction: hexaToInt()
    objectif: 
      - traduit un hexadecimal en int
    parametres: 
      - un hexa (l'operande a traduire)
    retour: 
      - un entier */
int hexaToInt(Hexa h[3] ){ 
  return strtol(h, NULL, 16);   
}

/*  fonction: intToHexa()
    objectif: 
      - traduit un hexadecimal en int
    parametres: 
      - un entier (l'operande a traduire)
    retour: 
      - un hexadecimal */
void intToHexa(Hexa * registre , int code ){ 
  Hexa value[3];
  sprintf(value, "%x", code);
  // gestion des valeurs < 10
  if (strlen(value) < 2) {
    value[1] = value[0]; value[0] = '0';
  }
  // attribution de la nouvelle valeur au registre
  strcpy(registre, value);
}


/*  fonction: executer()
    objectif: 
      - prend en compte l'op-code entré en parametre 
      - execute l'instruction associé (voir page 111)
    parametres: 
      - un entier (le code associé a une fonction)*/
int executer(int code) {
  switch (code){
  //
  // ARITHMETIQUE
  //
  // ADD #  20
  case 32: sprintf(A,"%'.02ld",  (strtol(A, NULL, 10) + strtol(memoire[hexaToInt(PC)], NULL, 10 ))); strcpy(mnemonique, "ADD #"); break;
  // ADD α  60
  case 96: sprintf(A,"%'.02ld",  (strtol(A, NULL, 10) + strtol(memoire[hexaToInt(memoire[hexaToInt(PC)])], NULL, 10))); strcpy(mnemonique, "ADD α "); break;
  // ADD *α E0
  case 224: sprintf(A,"%'.02ld",  (strtol(A, NULL, 10) + strtol(memoire[hexaToInt(memoire[hexaToInt(memoire[hexaToInt(PC)])])], NULL, 10))); strcpy(mnemonique, "ADD *α"); break;
  // SUB #  21
  case 33: sprintf(A,"%'.02ld",  (strtol(A, NULL, 10) - strtol(memoire[hexaToInt(PC)], NULL, 10 ))); strcpy(mnemonique, "SUB #"); break;
  // SUB α  61
  case 97: sprintf(A,"%'.02ld",  (strtol(A, NULL, 10) - strtol(memoire[hexaToInt(memoire[hexaToInt(PC)])], NULL, 10))); strcpy(mnemonique, "SUB α");break;
  // SUB *α E1
  case 225: sprintf(A,"%'.02ld",  (strtol(A, NULL, 10) - strtol(memoire[hexaToInt(memoire[hexaToInt(memoire[hexaToInt(PC)])])], NULL, 10))); strcpy(mnemonique, "SUB *α");break;
  //
  // LOGIQUE
  //
  // NAND #  22
  case 34: sprintf(A,"%'.02ld",  ~(strtol(A, NULL, 10) & strtol(memoire[hexaToInt(PC)], NULL, 10 ))); strcpy(mnemonique, "NAND #");break;
  // NAND α  62
  case 98: sprintf(A,"%'.02ld",  ~(strtol(A, NULL, 10) & strtol(memoire[hexaToInt(memoire[hexaToInt(PC)])], NULL, 10 ))); strcpy(mnemonique, "NAND α");break;
  // NAND *α E2
  case 226: sprintf(A,"%'.02ld",  ~(strtol(A, NULL, 10) & strtol(memoire[hexaToInt(memoire[hexaToInt(memoire[hexaToInt(PC)])])], NULL, 10 ))); strcpy(mnemonique, "NAND *α");break;
  //
  //  TRANSFERTS
  //
  // LOAD #  00
  case 0: strcpy(A, memoire[hexaToInt(PC)]); strcpy(mnemonique, "LOAD #");break;
  // LOAD α  40
  case 64: strcpy(A, memoire[hexaToInt(memoire[hexaToInt(PC)])]); strcpy(mnemonique, "LOAD α"); break; 
  // LOAD *α C0
  case 192: strcpy(A, memoire[hexaToInt(memoire[hexaToInt(memoire[hexaToInt(PC)])])]); strcpy(mnemonique, "LOAD *α"); break;
  // STORE α  48
  case 72: strcpy(memoire[hexaToInt(memoire[hexaToInt(PC)])], A); strcpy(mnemonique, "STORE α"); break;
  // STORE *α C8
  case 200: strcpy(memoire[hexaToInt(memoire[hexaToInt(memoire[hexaToInt(PC)])])], A); strcpy(mnemonique, "STORE *α"); break;
  //
  // ENTREE / SORTIES
  //
  // IN α  49
  case 73: printf("\n\nveuillez entrer une donnée: ") ; scanf("%s", memoire[hexaToInt(memoire[hexaToInt(PC)])]) ; strcpy(mnemonique, "IN α "); break;
  // IN *α C9
  case 201: printf("\n\nveuillez entrer une donnée: ") ; scanf("%s", memoire[hexaToInt(memoire[hexaToInt(memoire[hexaToInt(PC)])])]) ; strcpy(mnemonique, "IN *α"); break;
  // OUT α 41
  case 65: printf("\n\nValeur de sortie : %s\n", memoire[hexaToInt(memoire[hexaToInt(PC)])]); strcpy(mnemonique, "OUT α "); break;
  // OUT *α C1
  case 193: printf("\n\nValeur de sortie : %s\n", memoire[hexaToInt(memoire[hexaToInt(memoire[hexaToInt(PC)])])]); strcpy(mnemonique, "OUT *α"); break;
  // 
  // BRANCHEMENT INCONDITIONNEL
  //
  // JUMP α 10
  case 16: strcpy(PC, memoire[hexaToInt(PC)]); return 0; strcpy(mnemonique, "JUMP α"); break;
  // 
  // BRANCHEMENT CONDITIONNEL
  //
  // BRN α 11
  case 17: if (hexaToInt(A) < 0) { strcpy(PC, memoire[hexaToInt(PC)]) ; return 0;} ; strcpy(mnemonique, "BRN α"); break;
  // BRZ α 12
  case 18: if (hexaToInt(A) == 0) { strcpy(PC, memoire[hexaToInt(PC)]) ; return 0;} ; strcpy(mnemonique, "BRZ α "); break;
  default:
    printf("/!\\ CODE OP %i INNEXISTANT /!\\\n", code);
    exit(1);
    break;
  }
  return 1; 
}

/*  fonction: incrementerPC()
    objectif: 
      - increpenter la valeur contenu dans le regitre PC*/
void incrementerPC(){ 
  int pc = hexaToInt(PC);
  pc ++;
  intToHexa(PC , pc);
};


/*  fonction: afficherRegistre()   
    objectif: 
      - afficher l'etat des registres à chaque execution
*/
void afficherRegistre() {
  printf("\nPC: %s \t | A: %s \t| %s %s \t    ? " , PC, A, mnemonique , memoire[hexaToInt(PC)]); 
}
