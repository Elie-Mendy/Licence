
/*
  NOM: MENDY
  Prenom : Elie
  n°etudiant : 19004664

  EXERCICE cx17.7
*/



/*______________________________________________________________________________

                    INCLUDES - TYPEDEFS - DEFINES 
______________________________________________________________________________*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_mots 10000                              // nombre maximum d'éléments dans la table de mots
#define max_lignes 4096                             // nombre maximim de ligne pour un texte a indexer
#define max_refs 4096                                 // nombre maximum de ref par mots
#define maximum 4096                                // nombre maximal de caractères composant un mot
#define taille_mot 2048  

typedef unsigned idx ;                              // definition du type idx
typedef char * str;                                 // definirion du type str
typedef enum {False, True} bool ;                   // definition du type bool


// definition de nil
#define nil NULL

// Definition du type node et list
typedef struct node { void * car ; struct node * cdr ; } node , *list;
// Indication de typage à donner aux fonctions de traitement de liste
typedef enum Type {INT , STR} Type;

// definition d'un nouveau type pour emuler un index
typedef struct { str mot ; list refs ; } ndex ;

// allocation d'espace pour:
ndex mots[max_mots];                // --> la structure contenant les mots indexé et leurs references associées
char ligne[maximum];                // --> la ligne de texte a indexer
idx mot_libre = 0;                  // --> l'index indiquant le mot libre (au départ 0)
str stop[max_mots];                 // --> une table contenant les mots a exclure de l'index
list stoplist = nil;                // --> liste elastique contenant les mot a exclure
int numLignes[max_lignes];          // --> table qui acceuillera les numéro de lignes

// definition d'une liste de caractères a exclure
// on se sert de ces caractères pour découper la ligne de texte
const str split_chars =  " ().&%,;:!?/*~_-+[]{}=<>@`\"\'0123456789$€“”«»·\n\t";

// option que le programme acceptera
char option[3];

// headers des fonctions
#include "fonctions.h"      



/*______________________________________________________________________________

                                INDEXATION 
______________________________________________________________________________*/

int main(int k, char  *argv[]) {
  // options acceptées par le programme
  int indexFichier = 1; // indice par défaut fichier à indexer sur la lcd

  // test du nombre d'arguments
  if (k < 2) usage(" veuillez indiquer le nom du fichier a lire");

  // detection de l'option -s 
  if (pareil(argv[1], "-s") || pareil(argv[1], "-g")) {
    // capture de l'option
    strcpy(option, argv[1]);

    // test du nombre d'arguments
    if (k < 4) usage(" veuillez indiquer le nom du fichier a lire ainsi que la stoplist");

    // lecture des mots de la STOPLIST indiquée
    int n = lire_stoplist(argv[3]);

    // conversion de stop en liste elastique
    stoplist = arrayToList(stop, n, STR);

    indexFichier = 2;

  } else {
    // lecture des mots de la STOPLIST par défaut
    int n = lire_stoplist("stoplist.txt");

    // conversion de stop en liste elastique
    stoplist = arrayToList(stop, n, STR);
  }

  // ouverture du flux
  FILE * fichier = fopen(argv[indexFichier], "r");
  if ( ! fichier) usage(" fichier illisible");

  // boucle d'indexation de chaque ligne
  idx i = 0;                                // i represente le numéro de ligne
  while (fgets(ligne, maximum, fichier))
    indexe(ligne, ++i);

  // fermeture du flux
  fclose(fichier);
  // tri de la table
  qsort(mots, mot_libre, sizeof(ndex), compare);
  
  // affichage de l'index
  dump (mot_libre);

  return 0;
}




/*______________________________________________________________________________

                          DEFINITION FONCTIONS 
______________________________________________________________________________*/

/*  fonction: lire_stoplist()
    objectif: enregistrement des mots d'un fichier dans la table 'stop'
    parametres: une string (le nom de la stoplist ou golist)*/
int lire_stoplist(str fichierStoplist){
  int n = 0;                            // un compteur de mots

  // ouverture du flux
  FILE * fichier = fopen(fichierStoplist, "r");
  if (! fichier) usage(" stoplist illisible");

  idx i = 0;
  char lu = '\0';
  while (i < max_mots && lu != EOF){
    char sas[taille_mot];               // sas de reception du mot
    lu = fscanf(fichier, "%s ", sas);
    if (lu != EOF){
      stop[i++] = strdup(sas);
      }
      n ++;
    }
  fclose(fichier);
  return n-1;
}


/*  fonction: indexe()
    objectif: indexe une ligne de texte
    parametres: 
      - une string (la ligne)
      - un idx (la référence de la ligne à indexer)*/
void indexe( str ligne, idx ref){
  // notation du numéro de ligne
  numLignes[ref] = ref;
  // capture du premier mot et de la ligne en mémoire
  str mot = strtok(strdup(ligne), split_chars);
  // si ce n'est pas la chaine vide
  while (mot){
    int s = exclure(mot);                           // verificaton de la présence du mot dans l'index
    if (s < 0){                                     // si le mot n'est pas a exclure
      
      int x = indice(mot);                          // verificaton de la présence du mot dans l'index
      if (x < 0) ajoute_mot(mot_libre, mot, ref);       // ajout a la suite si nouveau mot
      else ajoute_ref (x, ref);                         // sinon ajoute juste la nouvelle ref
    }
    mot = strtok(NULL, split_chars);                    // continuer sur le mot suivant
  }
}


/*  fonction: exclure()
    objectif: 
      - verifie la presence d'un mot dans la stoplist/golist
      - indiquer si ce mot est a exclure
    parametres: 
      - une string (le mot a controler)*/
int exclure(str mot){                
  // exclusion des mots de moins de deux lettres
  if (strlen(mot) < 2) return 1;
  if (pareil(option, "-g")){         // detection de l'option -g
    if (in(mot , stoplist, STR))        // si on utilise une goliste
      return -1;                        // on ne garde que les mots qui sont dedans
    else 
      return 1;
  } else {                              // si on utilise une stoplist
    if (in(mot , stoplist, STR))        // on exclue les mots en faisant partie
      return 1;
    else 
      return -1;
  }
}



/*  fonction: indice()
    objectif: recupere l'indice d'un mot s'il est dans l'index
    parametres: une string (le mot a controler)*/
int indice(str mot){                
  idx i = 0;
  for (i = 0; mots[i].mot; i++){
    if (pareil(mot, mots[i].mot)) return i;
  }
  return -1;
}


/*  fonction: ajoute_mot()
    objectif: ajoute un nouveau mot dans l'indexe
    parametres: 
      - un idx (l'indice du mot dans l'index)
      - une string (le mot a controler)
      - un idx (la référence de la ligne sur lequel il apparait)*/
void ajoute_mot(idx x, str mot, idx ref){
  mots[x].mot = mot;                          // ajout du nouveau mot dans l'index
  mots[x].refs = cons(&numLignes[ref], nil);  // ajout de sa reference
  ++mot_libre ;                               // incrémentation de l'emplacement d'un nouveau mot
}


/*  fonction: ajoute_ref()
    objectif: ajoute une nouvelle ref dans la liste des ref d'un mot
    parametres: 
      - un idx (l'indice du mot dans l'index)
      - un idx (la référence de la ligne sur lequel il apparait)*/
void ajoute_ref(idx x, idx ref){
  // verification de la présence de la ref dans la liste refs
  int n = in(&ref , mots[x].refs, INT);
  // ajout de la nouvelle ref
  if (!n){
    mots[x].refs = cons(&numLignes[ref], mots[x].refs);       // ajout de la nouvelle ref
  }
}


/*  fonction: compare()
    objectif: renvoie l'ordre de trie de deux mots 
    parametres: 
      - l'adresse de la premiere structure
      - l'adresse de la deuxieme structure*/
int compare(void const *E1, void const *E2){
  ndex const * pE1 = E1;
  ndex const * pE2 = E2;
  return strcmp(pE1 -> mot, pE2 -> mot);
}


/*  fonction: dump()
    objectif: affichage formaté des valeurs de l'index 
    parametres: 
      - un idx (l'index de fin de l'index)*/
void dump(idx k){
  idx x;
  for (x = 0 ; x < k ; ++x){
    printf("___________________________");
    printf("\n%s :\n", mots[x].mot);
    // affichage des references
    putlist(mots[x].refs, INT);
    printf("\n");
  }
}


