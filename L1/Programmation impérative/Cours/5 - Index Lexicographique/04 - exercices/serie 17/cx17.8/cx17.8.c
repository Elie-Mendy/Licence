#include <stdio.h>
#include <stdlib.h>
#include <string.h>




#define max_mots 128                                // nombre maximum d'éléments dans la table de mots
#define max_lignes 4000                             // nombre maximim de ligne pour un texte a indexer
#define max_refs 20                                 // nombre maximum de ref par mots
#define maximum 4096                                // nombre maximal de caractères composant un mot
#define taille_mot 1024




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
char * stop[max_mots];              // --> une table contenant les mots a exclure de l'index
list stoplist = nil;                // --> liste elastique contenant les mot a exclure
int numLignes[max_lignes];          // --> table qui acceuillera les numéro de lignes

// definition d'une liste de caractères a exclure
// on se sert de ces caractères pour découper la ligne de texte
const str split_chars =  " ().&%,;:!?/*~_-+[]{}=<>@`\"\'0123456789$€“”«»·\n\t";



#include "fonctions.h"                              // Header des fonctions du programme






int main(int k, char const *argv[]) {

  // test du nombre d'arguments
  if (k < 2) usage(" veuillez indiquer le nom du fichier a lire");

  // ouverture du flux
  FILE * fichier = fopen(argv[1], "r");
  if ( ! fichier) usage(" fichier illisible");




  /* TRAITEMENT */
  // lecture des mots de la STOPLIST
  int n = lire_stoplist("stoplist.txt");
  // conversion de stop en liste elastique
  stoplist = arrayToList(stop, n, STR);


  // boucle d'indexation de chaque ligne
  idx i = 0;                                // i represente le numéro de ligne
  while (fgets(ligne, maximum, fichier))
    indexe(ligne, ++i);


  // fermeture du flux
  fclose(fichier);
  // tri de la table
  qsort(mots, mot_libre, sizeof(ndex), compare);

  dump (mot_libre);

  return 0;
}


// LECTURE D'UNE STOPLIST
int lire_stoplist(str liste){
  int n = 0;                      // un compteur de mots
  // ouverture du flux
  FILE * fichier = fopen(liste, "r");
  if (! fichier) usage(" stoplist illisible");

  idx i = 0;
  char lu = '\0';
  while (i < max_mots && lu != EOF){
    char sas[taille_mot];                          // sas de reception du mot
    lu = fscanf(fichier, "%s ", sas);
    if (lu != EOF){
      stop[i++] = strdup(sas);
      }
      n ++;
    }
  fclose(fichier);
  return n-1;
}

// INDEXATION D'UNE LIGNE DE TEXTE
void indexe(str ligne, idx ref){
  // notation du numéro de ligne
  numLignes[ref] = ref;
  // capture du premier mot et de la ligne en mémoire
  str mot = strtok(strdup(ligne), split_chars);
  // si ce n'est pas la chaine vide
  while (mot){

    int s = exclure(mot);                       // verificaton de la présence du mot dans l'index
    if (s < 0){                                 // si le mot n'est pas a exclure
      int x = indice(mot);                      // verificaton de la présence du mot dans l'index
      if (x < 0) ajoute_mot(mot_libre, mot, ref);   // ajout a la suite si nouveau mot
      else ajoute_ref (x, ref);                     // sinon ajoute juste la nouvelle ref
    }
    mot = strtok(NULL, split_chars);                // continuer sur le mot suivant
  }
}

// EXCLUSION D'UN MOT si présent dans la stoplist
int exclure(str mot){                // modification du type
  
  char maj[taille_mot];
  strcpy(maj , mot);

  if (in(maj , stoplist, STR)){
    
    return 1;
  }
  // exclusion des mots de moins de deux lettres
  if (strlen(mot) < 2) return 1;
  
  return -1;
}

// RECUPERATION DE L'INDICE d'un mot dans une table donnée
int indice(str mot){                // modification du type
  idx i = 0;
  for (i = 0; mots[i].mot; i++){
    if (pareil(mot, mots[i].mot)) return i;
  }
  return -1;
}

// AJOUT d'UN NOUVEAU MOT
void ajoute_mot(idx x, str mot, idx ref){
  mots[x].mot = mot;              // ajout du nouveau mot dans l'index
  mots[x].refs = cons(&numLignes[ref], nil);  // ajout de sa reference
  ++mot_libre ;                   // incrémentation de l'emplacement d'un nouveau mot
}

// AJOUT d'UNE REF (si mot déja indexé)
void ajoute_ref(idx x, idx ref){
  // verification de la présence de la ref dans la liste refs
  int n = in(&ref , mots[x].refs, INT);

  if (!n){
    mots[x].refs = cons(&numLignes[ref], mots[x].refs);       // ajout de la nouvelle ref
  }
}

// COMPARAISON DE DEUX CHAINES
bool pareil(str x, str y) { return strcasecmp(x,y) ? False : True ; }


// FOCNTION DE TRI DE DEUX STR
int compare(void const *E1, void const *E2){

  ndex const * pE1 = E1;
  ndex const * pE2 = E2;

  return strcmp(pE1 -> mot, pE2 -> mot);
}


// AFFICHAGE DES VALEURS DE L'INDEX
void dump(idx k){
  idx x;
  for (x = 0 ; x < k ; ++x){
    printf("%s :", mots[x].mot);
    // affichage des references
    putlist(mots[x].refs, INT);
    printf("\n");
  }
}

