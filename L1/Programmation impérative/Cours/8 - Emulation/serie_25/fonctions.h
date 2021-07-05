/*______________________________________________________________________________

        DEFINITION FONCTIONS DE L'EMULATEUR : ORDINATEUR EN PAPIER
______________________________________________________________________________*/

/*  fonction: usage()
    objectif: impression de messages d'erreur (sur flux stderr)
    parametres: une string (le messages à renvoyer)*/
void usage(str message) { fprintf(stderr, "Usage : %s\n", message), exit(1) ;}

/*  fonction: stepper()
    objectif: permettre a l'utilisateur d'utiliser la touche 'enter
              pour passer une instruction */
void stepper() {
  char c = 0;
  while((c =getchar()) != '\n') ;
}

/*  fonction: initialiserRegistres()
    objectif: attribuer une valeur initiale aux différents registres */
void initialiserRegistres(int adresse){
  // Program Counter
  sprintf(PC , "%x", adresse );
  // unité de calcul
  strcpy(A,"00");
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
    char sas[TAILLE_DATA];               // sas de reception du mot
    lu = fscanf(fichier, "%s ", sas);
    if (lu != EOF){
      memoire[i++] = strdup(sas);
      }
    }
  // fermeture du flux
  fclose(fichier);
};

/*  fonction: hexaToInt()
    objectif: 
      - traduit un hexadecimal en int
    parametres: 
      - un hexa (l'operande a traduire)
    retour: 
      - un entier */
int hexaToInt(Hexa h[TAILLE_DATA] ){ 
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
  Hexa value[TAILLE_DATA];
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
  case 32: sprintf(A,"%'.02ld",  (strtol(A, NULL, 10) + strtol(memoire[hexaToInt(PC)], NULL, 10 ))); strcpy(lib, "ADD #"); break;
  // ADD α  60
  case 96: sprintf(A,"%'.02ld",  (strtol(A, NULL, 10) + strtol(memoire[hexaToInt(memoire[hexaToInt(PC)])], NULL, 10))); strcpy(lib, "ADD α "); break;
  // ADD *α E0
  case 224: sprintf(A,"%'.02ld",  (strtol(A, NULL, 10) + strtol(memoire[hexaToInt(memoire[hexaToInt(memoire[hexaToInt(PC)])])], NULL, 10))); strcpy(lib, "ADD *α"); break;
  // SUB #  21
  case 33: sprintf(A,"%'.02ld",  (strtol(A, NULL, 10) - strtol(memoire[hexaToInt(PC)], NULL, 10 ))); strcpy(lib, "SUB #"); break;
  // SUB α  61
  case 97: sprintf(A,"%'.02ld",  (strtol(A, NULL, 10) - strtol(memoire[hexaToInt(memoire[hexaToInt(PC)])], NULL, 10))); strcpy(lib, "SUB α");break;
  // SUB *α E1
  case 225: sprintf(A,"%'.02ld",  (strtol(A, NULL, 10) - strtol(memoire[hexaToInt(memoire[hexaToInt(memoire[hexaToInt(PC)])])], NULL, 10))); strcpy(lib, "SUB *α");break;
  //
  // LOGIQUE
  //
  // NAND #  22
  case 34: sprintf(A,"%'.02ld",  ~(strtol(A, NULL, 10) & strtol(memoire[hexaToInt(PC)], NULL, 10 ))); strcpy(lib, "NAND #");break;
  // NAND α  62
  case 98: sprintf(A,"%'.02ld",  ~(strtol(A, NULL, 10) & strtol(memoire[hexaToInt(memoire[hexaToInt(PC)])], NULL, 10 ))); strcpy(lib, "NAND α");break;
  // NAND *α E2
  case 226: sprintf(A,"%'.02ld",  ~(strtol(A, NULL, 10) & strtol(memoire[hexaToInt(memoire[hexaToInt(memoire[hexaToInt(PC)])])], NULL, 10 ))); strcpy(lib, "NAND *α");break;
  //
  //  TRANSFERTS
  //
  // LOAD #  00
  case 0: strcpy(A, memoire[hexaToInt(PC)]); strcpy(lib, "LOAD #");break;
  // LOAD α  40
  case 64: strcpy(A, memoire[hexaToInt(memoire[hexaToInt(PC)])]); strcpy(lib, "LOAD α"); break; 
  // LOAD *α C0
  case 192: strcpy(A, memoire[hexaToInt(memoire[hexaToInt(memoire[hexaToInt(PC)])])]); strcpy(lib, "LOAD *α"); break;
  // STORE α  48
  case 72: strcpy(memoire[hexaToInt(memoire[hexaToInt(PC)])], A); strcpy(lib, "STORE α"); break;
  // STORE *α C8
  case 200: strcpy(memoire[hexaToInt(memoire[hexaToInt(memoire[hexaToInt(PC)])])], A); strcpy(lib, "STORE *α"); break;
  //
  // ENTREE / SORTIES
  //
  // IN α  49
  case 73: printf("\n\nveuillez entrer une donnée: ") ; scanf("%s", memoire[hexaToInt(memoire[hexaToInt(PC)])]) ; strcpy(lib, "IN α "); break;
  // IN *α C9
  case 201: printf("\n\nveuillez entrer une donnée: ") ; scanf("%s", memoire[hexaToInt(memoire[hexaToInt(memoire[hexaToInt(PC)])])]) ; strcpy(lib, "IN *α"); break;
  // OUT α 41
  case 65: printf("\n\nValeur de sortie : %s\n", memoire[hexaToInt(memoire[hexaToInt(PC)])]); strcpy(lib, "OUT α "); break;
  // OUT *α C1
  case 193: printf("\n\nValeur de sortie : %s\n", memoire[hexaToInt(memoire[hexaToInt(memoire[hexaToInt(PC)])])]); strcpy(lib, "OUT *α"); break;
  // 
  // BRANCHEMENT INCONDITIONNEL
  //
  // JUMP α 10
  case 16: strcpy(PC, memoire[hexaToInt(PC)]); return 0; strcpy(lib, "JUMP α"); break;
  // 
  // BRANCHEMENT CONDITIONNEL
  //
  // BRN α 11
  case 17: if (hexaToInt(A) < 0) { strcpy(PC, memoire[hexaToInt(PC)]) ; return 0;} ; strcpy(lib, "BRN α"); break;
  // BRZ α 12
  case 18: if (hexaToInt(A) == 0) { strcpy(PC, memoire[hexaToInt(PC)]) ; return 0;} ; strcpy(lib, "BRZ α "); break;
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
  printf("\nPC: %s \t | A: %s \t| %s %s \t    ? " , PC, A, lib , memoire[hexaToInt(PC)]); 
}