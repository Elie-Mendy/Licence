

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

// definition de types supplementaires
typedef char Hexa ;                          
typedef char * str ;               

// inclusion des headers
void usage(str message);
void loadProgram(int location, char * nomFichier);
int hexaToInt(Hexa h[3] );
void intToHexa(Hexa * registre , int code );
void instruction(int code) ;
void incrementerPC(); 
void runInstruction();
void runCommand();

// Ressources de l'ordinateur
Hexa A[3];                 
Hexa PC[3];         
Hexa * memoire[256];         
   
// structures de données de la boucle d'evaluation
char saisieUser[4096];                            
str commande[10];                              
int runMode = 0;  // 1 pour mode run  - 0 pour mode stepper                                 

int main(int argc, char  *argv[]) {
  // test du nombre d'arguments
  if (argc < 2) usage("Erreur : manque un argument sur la ldc");

  printf("         ORDINATEUR EN PAPIER  - serie 25 \n");

  // chargement du bootstrap
  loadProgram(0, "bootstrap_loader");
  strcpy(A,"00");

  // saisie utilisateur de l'adresse
  // de la première instruction du programme
  printf("\nEntrez l'adresse de la première instruction du programme : ");

  int location  = 0; 
  scanf("%x", &location);  
  sprintf(PC , "%x", location );

  // chargement du programme
  loadProgram(location, argv[1]);

  // message pour l'utilisateur 
  printf("\n\tListe des commandes disponibles:\n\
            \t--> next  : execute l'instruction suivante\n\
            \t--> run   : active l'execution automatique des instrutions suivantes\n\
            \t--> quit  : met fin a l'execution du programme\n\
            \t--> print : permet d'afficher la valeur d'une case memoire \n\t\t\t\t(exemple utilisation: 'print 1C')\n\n\n");

  // execution du programme 
  while(getchar() != '\n'); // vidage du buffer
  do{     
      // si mode stepper                
      if (!runMode) {        
        // attente d'une saisie utilisateur  
        printf(" -? ");
        if (!fgets(saisieUser, 4096, stdin)) usage("Erreur : impossible de lire la commande");

        // découpage de la saisie utilisateur
        str mot = strtok(strdup(saisieUser), " \n");
        int i = 0;
        while (i < 4  && mot){  
          commande[i++] =  strdup(mot);  
          mot = strtok(NULL, " \n"); 
        }

        // gestion d'une saisie vide
        if (i < 1) continue;
        
        // lancement de la commande
        runCommand();
      }
      // si mode run  
      else runInstruction(); 
    } while (strcasecmp(PC , "00"));  
  // pour mettre fin a l'execution du programme 
  //on prendra la valeur de PC à 00 programme quand on jump sur 00
  return 0;
}

/*  fonction: usage()
    objectif: impression de messages d'erreur (sur flux stderr)
    parametres: une string (le messages à renvoyer)*/
void usage(str message) { fprintf(stderr, "Usage : %s\n", message), exit(1) ;}


/*  fonction: loadProgram()
    objectif: 
      - ecrit le programme dans la mémoire 
      - sans passer par le bootstrap manuel
    parametres: 
      - un entier 
        (l'adresse de la premiere instruction du programme en memoire)
      - le nom du programme a charger*/
void loadProgram(int location, char * nomFichier){  
  FILE * fichier = fopen(nomFichier, "r");
  if (! fichier) usage("Erreur : le programme est illisible ou inexistant");
  int i = location;
  char caractere = '\0';
  while (caractere != EOF && i < 256){
    char data[3];               
    caractere = fscanf(fichier, "%s ", data);
    if (caractere != EOF){
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


/*  fonction: instruction()
    objectif: 
      - prend en compte l'op-code entré en parametre 
      - execute l'instruction associé (voir page 111)
    parametres: 
      - un entier (le code associé a une fonction)*/
void instruction(int code) {
  switch (code){
  // branchements           [JUMP, BRN@ , BRZ@]
  //                        [ 17 ,  18  ,  19 ]
  case 16: strcpy(PC, memoire[hexaToInt(PC)]);  break;
  case 17: if (hexaToInt(A) < 0) { strcpy(PC, memoire[hexaToInt(PC)]); break; } ; incrementerPC(); break;
  case 18: if (hexaToInt(A) == 0) { strcpy(PC, memoire[hexaToInt(PC)]); break; } ; incrementerPC(); break;
  
  // entrée / sorties       [ IN @, IN *@, OUT @,OUT*@]
  //                        [ 73  , 201  ,  65  , 193 ]
  case 73: printf("\n\n ==> Entrez une donnée: ") ; scanf("%s", memoire[hexaToInt(memoire[hexaToInt(PC)])]) ; while(getchar() != '\n'); incrementerPC(); break;
  case 201: printf("\n\n ==> Entrez une donnée: ") ; scanf("%s", memoire[hexaToInt(memoire[hexaToInt(memoire[hexaToInt(PC)])])]) ; while(getchar() != '\n');incrementerPC(); break;
  case 65: printf("\n\nSortie : %s\n", memoire[hexaToInt(memoire[hexaToInt(PC)])]); incrementerPC(); break;
  case 193: printf("\n\nSortie : %s\n", memoire[hexaToInt(memoire[hexaToInt(memoire[hexaToInt(PC)])])]); incrementerPC(); break;
  
  // transfert de données   [LOAD,LOAD@,LOAD*@,STORE@,STORE*@]
  //                        [ 00 ,  64 , 192  ,  72  ,  200  ]
  case 0: strcpy(A, memoire[hexaToInt(PC)]); incrementerPC(); break;
  case 64: strcpy(A, memoire[hexaToInt(memoire[hexaToInt(PC)])]); incrementerPC(); break; 
  case 192: strcpy(A, memoire[hexaToInt(memoire[hexaToInt(memoire[hexaToInt(PC)])])]);  incrementerPC(); break;
  case 72: strcpy(memoire[hexaToInt(memoire[hexaToInt(PC)])], A); incrementerPC(); break;
  case 200: strcpy(memoire[hexaToInt(memoire[hexaToInt(memoire[hexaToInt(PC)])])], A); incrementerPC(); break;
  
  // calculs arithmétiques  [ADD,ADD@,ADD*@,SUB,SUB@,SUB*@]
  //                        [ 32, 96 , 224 , 33, 97 , 225 ]
  case 32: sprintf(A,"%'.02ld",  (strtol(A, NULL, 10) + strtol(memoire[hexaToInt(PC)], NULL, 10 ))); incrementerPC(); break;
  case 96: sprintf(A,"%'.02ld",  (strtol(A, NULL, 10) + strtol(memoire[hexaToInt(memoire[hexaToInt(PC)])], NULL, 10))); incrementerPC(); break;
  case 224: sprintf(A,"%'.02ld",  (strtol(A, NULL, 10) + strtol(memoire[hexaToInt(memoire[hexaToInt(memoire[hexaToInt(PC)])])], NULL, 10))); incrementerPC(); break;
  case 33: sprintf(A,"%'.02ld",  (strtol(A, NULL, 10) - strtol(memoire[hexaToInt(PC)], NULL, 10 ))); incrementerPC(); break;
  case 97: sprintf(A,"%'.02ld",  (strtol(A, NULL, 10) - strtol(memoire[hexaToInt(memoire[hexaToInt(PC)])], NULL, 10))); incrementerPC(); break;
  case 225: sprintf(A,"%'.02ld",  (strtol(A, NULL, 10) - strtol(memoire[hexaToInt(memoire[hexaToInt(memoire[hexaToInt(PC)])])], NULL, 10))); incrementerPC(); break;
  
  // connecteurs logiques   [NAND,NAND@,NAND*@,]
  //                        [ 34 , 98  , 226   ]
  case 34: sprintf(A,"%'.02ld",  ~(strtol(A, NULL, 10) & strtol(memoire[hexaToInt(PC)], NULL, 10 ))); incrementerPC(); break;
  case 98: sprintf(A,"%'.02ld",  ~(strtol(A, NULL, 10) & strtol(memoire[hexaToInt(memoire[hexaToInt(PC)])], NULL, 10 ))); incrementerPC(); break;
  case 226: sprintf(A,"%'.02ld",  ~(strtol(A, NULL, 10) & strtol(memoire[hexaToInt(memoire[hexaToInt(memoire[hexaToInt(PC)])])], NULL, 10 ))); incrementerPC(); break;
  
  // sortie si erreur de code operatoire
  default:
    usage("Erreur: un microcode erronné a été evalué");
    break;
  } 
}

/*  fonction: incrementerPC()
    objectif: 
      - increpenter la valeur contenu dans le regitre PC*/
void incrementerPC(){ 
  int pc = hexaToInt(PC);
  pc ++;
  intToHexa(PC , pc);
};


void runInstruction() {
  // récuperation du code de l'opération 
  int code = hexaToInt(memoire[hexaToInt(PC)]);

  // execution de l'opération
  incrementerPC();
  instruction(code);

  // affichage des valeurs de PC et A
  if(!runMode) printf("\n\tPC: %s \t\t A: %s  \n\n" , PC, A); 
  else printf("\tPC: %s \t\t A: %s\n" , PC, A); 

  // attente de la asisie de la touche [Enter]
  //stepper();
}

void runCommand() {
  if (strcasecmp(commande[0], "next") == 0) runInstruction();
  else if (commande[0] && strcasecmp(commande[0], "print") == 0 && commande[1]) printf("memoire[%s] : %s \n", commande[1], memoire[hexaToInt(commande[1])] ) ; 
  else if (strcasecmp(commande[0], "run") == 0) runMode = 1; 
  else if (strcasecmp(commande[0], "quit") == 0) { printf("\n\n\tFin de l'execution du programme\n\n") ; exit(1); }
  else { printf("La commande n'est pas connue \n");}
}

