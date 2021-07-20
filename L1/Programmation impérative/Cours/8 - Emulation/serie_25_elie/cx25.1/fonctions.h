#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

/*______________________________________________________________________________

        DEFINITION FONCTIONS DE L'EMULATEUR : ORDINATEUR EN PAPIER
______________________________________________________________________________*/

/*  fonction: usage()
    objectif: impression de messages d'erreur (sur flux stderr)
    parametres: une string (le messages à renvoyer)*/
void usage(str message) { fprintf(stderr, "Usage : %s\n", message), exit(1) ;}

/*  fonction: stepper()
    objectif: permettre a l'utilisateur d'utiliser la touche 'Enter'
              pour passer une instruction */
void stepper() {
  char c = 0;
  while((c =getchar()) != '\n') ;
}




/*  fonction: initialiserRegistres()
    objectif: attribuer une valeur initiale aux différents registres */
void initialiserRegistres(int adresse){
  // Program Counter
  PC = adresse;
  // unité de calcul
  A = 0;
}

/*  fonction: chargerProgramme()
    objectif: 
      - ecrit le programme dans la mémoire 
      - sans passer par le bootstrap manuel
    parametres: 
      - un entier 
        (l'adresse de la premiere instruction du programme en memoire)
      - le nom du programme a charger*/
void chargerProgramme(int adresse, char * fileName){  
  // ouverture du flux
  FILE * fichier = fopen(fileName, "r");
  if (! fichier) usage("programme illisible");

  unsigned i = adresse;
  char lu = '\0';
  while (i < TAILLE_MEMOIRE && lu != EOF){
    long int sas;               // sas de reception du mot
    lu = fscanf(fichier, "%lx ", &sas);
    if (lu != EOF){
      memoire[i++] = sas;
      }
    }
  // fermeture du flux
  fclose(fichier);
};


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
  case 32: A = A + memoire[PC] ; strcpy(lib, "ADD #"); break;
  // ADD α  60
  case 96: A = A + memoire[memoire[PC]] ; strcpy(lib, "ADD α "); break;
  // ADD *α E0
  case 224: A = A + memoire[memoire[memoire[PC]]] ; strcpy(lib, "ADD *α"); break;
  // SUB #  21
  case 33: A = A - memoire[PC] ; strcpy(lib, "SUB #"); break;
  // SUB α  61
  case 97: A = A - memoire[memoire[PC]] ; strcpy(lib, "SUB α");break;
  // SUB *α E1
  case 225: A = A - memoire[memoire[memoire[PC]]]; strcpy(lib, "SUB *α");break;
  //
  // LOGIQUE
  //
  // NAND #  22
  case 34: A = ~(A & memoire[PC]) ; strcpy(lib, "NAND #");break;
  // NAND α  62
  case 98: A = ~(A & memoire[memoire[PC]]) ; strcpy(lib, "NAND α");break;
  // NAND *α E2
  case 226: A = ~(A & memoire[memoire[memoire[PC]]]) ; strcpy(lib, "NAND *α");break;
  //
  //  TRANSFERTS
  //
  // LOAD #  00
  case 0: A = memoire[PC] ; strcpy(lib, "LOAD #");break;
  // LOAD α  40
  case 64: A = memoire[memoire[PC]]  ; strcpy(lib, "LOAD α"); break; 
  // LOAD *α C0
  case 192: A = memoire[memoire[memoire[PC]]] ; strcpy(lib, "LOAD *α"); break;
  // STORE α  48
  case 72: memoire[memoire[PC]]  = A ; strcpy(lib, "STORE α"); break;
  // STORE *α C8
  case 200: memoire[memoire[memoire[PC]]]  = A ; strcpy(lib, "STORE *α"); break;
  //
  // ENTREE / SORTIES
  //
  // IN α  49
  case 73: printf("\n\nveuillez entrer une donnée: ") ; scanf("%li", &memoire[memoire[PC]]); strcpy(lib, "IN α "); break;
  // IN *α C9
  case 201: printf("\n\nveuillez entrer une donnée: ") ; scanf("%li", &memoire[memoire[memoire[PC]]]) ; strcpy(lib, "IN *α"); break;
  // OUT α 41
  case 65: printf("\n\nValeur de sortie : %li\n", memoire[memoire[PC]]); strcpy(lib, "OUT α "); break;
  // OUT *α C1
  case 193: printf("\n\nValeur de sortie : %li\n", memoire[memoire[memoire[PC]]]); strcpy(lib, "OUT *α"); break;
  // 
  // BRANCHEMENT INCONDITIONNEL
  //
  // JUMP α 10
  case 16: PC = memoire[PC]; strcpy(lib, "JUMP α") ; return 0 ; break;
  // 
  // BRANCHEMENT CONDITIONNEL
  //
  // BRN α 11
  case 17: if (A < 0) { PC = memoire[PC] ; return 0;} ; strcpy(lib, "BRN α"); break;
  // BRZ α 12
  case 18: if (A == 0) { PC = memoire[PC] ; return 0;} ; strcpy(lib, "BRZ α "); break;
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
  PC ++ ;
};


/*  fonction: afficherRegistre()   
    objectif: 
      - afficher l'etat des registres à chaque execution
*/
void afficherRegistre() {
  printf("\nPC: %lx \t | A: %li \t| %s %lx \t    \n" , PC, A, lib , memoire[PC]); 
}


//TODO remoce cette fonction 
void afficherSaisie() {
  for (int i = 0 ; i < 3; i++)
    printf("lcd[%i] = %s\n", i, ldc[i]);
}
//TODO remoce cette fonction 
void afficherBreackpoints() {
  puts("");
  for (int i = 0 ; breakpoints[i] && i <  NB_BREAKPOINTS ; i++)
    printf("break[%i] = %s\n", i, breakpoints[i]);
  puts("");
}


/*  fonction: lireSaisieUtilisateur()
    objectif: enregistrer la saisie utilisateur dans un vecteur de mots
*/
void parserSaisieUtilisateur(char * mot){
  
  // si ce n'est pas la chaine vide
  int i = 0;
  while (i < 4  && mot){  
    ldc[i++] =  strdup(mot);  
    mot = strtok(NULL, " \n"); // continuer sur le mot suivant
  }
}

/*  fonction: addBreackpoint()
    objectif: ajouter un code opératoire a la liste des breackpoints
*/
void addBreackpoint(char * mot){
  int i = 0;

  while (breakpoints[i++]) {
    if (!strcmp(breakpoints[i - 1] , mot)) {
      printf("vous avez déjà ajouté ce breakpoint\n") ; 
      return;
    }
  }
  breakpoints[i - 1] = strdup(mot);

}

/*  fonction: removeBreackpoint()
    objectif: retirer un code opératoire de la liste des breakpoint
*/
void removeBreackpoint(char * mot){
  int i = 0;
  while (breakpoints[i]) {
    printf("test : %i\n", !strcmp(breakpoints[i] , mot));
    if (! strcmp(breakpoints[i++] , mot)) breakpoints[i - 1] = NULL;
  } 
  
}

int ctrlBreakpoint(long int instruction) {
  char convertedOpCode[33];
  sprintf(convertedOpCode, "%lx", instruction);

  for (int i = 0 ; i < NB_BREAKPOINTS ; i ++) 
    if (breakpoints[i] && ! strcmp(breakpoints[i] , convertedOpCode)) {
      return 1;
    }
  return 0;
}





/*  fonction: executerIstruction()
*/
void executerIstruction(int checkBreakpoints) {

    // lecture du code opération 
    int opCode = memoire[PC];

    // si un breakPoint est reperé un sort
    if (checkBreakpoints && ctrlBreakpoint(opCode)) {
      printf("Un breakpoint a été rencontré\n");
      run = 0;
      prompt = 1;
      return;
    }

    // execution de l'opération
    incrementerPC();
    needIncrement = executer(opCode);

    // affichage en console
    #ifndef NO_DEBUG
    afficherRegistre(); 
    #endif

    // appuyer sur 'Enter' pour validation 
    #ifdef STEPPER
    stepper();
    #endif

    if (needIncrement == 1) incrementerPC();
}

void afficherHelp() {
  FILE * help = fopen("help.txt", "r");
  if (! help) usage("erreur de lecture du fichier 'help.txt'");

  int c = 0;
  while((c = fgetc(help)) != EOF) fputc(c , stdout);
}

// TODO developper les fonctions suivantes 
//afficherHelp
// Wording pour le breakpoint (add remove et ctrl)
