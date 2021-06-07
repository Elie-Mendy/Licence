
/*
  NOM: MENDY
  Prenom : Elie
  n°etudiant : 19004664

  EXERCICE cx17.6
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
int numLignes[max_lignes];          // --> table qui acceuillera les numéro de ligne

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

/*  fonction: usage()
    objectif: impression de messages d'erreur (sur flux stderr)
    parametres: une string (le messages à renvoyer)*/
void usage(str message) { fprintf(stderr, "Usage : %s\n", message), exit(1) ;}


/*  fonction: lire_stoplist()
    objectif: enregistrement des mots d'un fichier dans la table 'stop'
    parametres: une string (le nom de la stoplist ou golist)*/
int lire_stoplist(str fichierStoplist) {
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
void indexe(str ligne, idx ref) {
  // notation du numéro de ligne
  numLignes[ref] = ref;
  // capture du premier mot et de la ligne en mémoire
  str mot = strtok(strdup(ligne), split_chars);
  // si ce n'est pas la chaine vide
  while (mot){
    int s = exclure(mot);                         // verificaton de la présence du mot dans l'index
    if (s < 0){                                   // si le mot n'est pas a exclure
      int x = indice(mot);                        // verificaton de la présence du mot dans l'index
      if (x < 0) ajoute_mot(mot_libre, mot, ref);     // ajout a la suite si nouveau mot
      else ajoute_ref (x, ref);                       // sinon ajoute juste la nouvelle ref
    }
    mot = strtok(NULL, split_chars);                  // continuer sur le mot suivant
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
  // si c'est une nouvelle ref, on l'ajoute
  if (!n){
    mots[x].refs = cons(&numLignes[ref], mots[x].refs);
  }
}

/*  fonction: pareil()
    objectif: compare deux mots
    parametres:
      - une string (le premier mot)
      - une string (le deuxieme mot)*/
bool pareil(str x, str y) { return strcasecmp(x,y) ? False : True ; }


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


/*______________________________________________________________________________

                    FONCTIONS DE GESTION DES LISTES
______________________________________________________________________________*/

/*  fonction: cons()
    objectif: construit un doublet
    parametres:
      - l'adresse du car
      - l'adresse de la list cdr*/
list cons(void * car, list cdr){
  list L = malloc(sizeof(node));
  if (!L) usage("espace insufisant");

  L -> car = car;
  L -> cdr = cdr;

  return L;
}


/*  fonction: in()
    objectif: verifie la présence d'un element dans une liste
    parametres:
      - l'adresse de l'element à identifier
      - la liste a parcourir
      - le type de l'element*/
int in(void * elt  ,list L, Type t){
  if (t == INT){
    int * P = malloc(sizeof(int));  // allocation d'un pointeur
    int * C = malloc(sizeof(int));  // allocation d'un pointeur qui prendra le car
    P = elt;
    while(L){
      C = L -> car;
      if (*C == *P) return 1;
      L = L->cdr;
    }
  } else {
    char * P = malloc(sizeof(char));  // allocation d'un pointeur
    char * C = malloc(sizeof(char));  // allocation d'un pointeur qui prendra le car
    P = elt;
    while(L){
      C = L -> car;
      if (! strcasecmp(C, P)) return 1;
      L = L->cdr;
    }
  }
  return 0;
}

/*  fonction: length()
    objectif: renvoi la taille d'une liste
    parametres: la liste a parcourir*/
int length(list L){
  int n = 0;
  if (L->car) n++;
  while (L->cdr){
    L = L->cdr;
    n++;
    }
    return n;
  }



  /*  fonction: putlist()
    objectif: affiche le contenu d'une liste verifie
    parametres:
      - la liste a parcourir
      - le type des élements qu'elle contient*/
  void putlist(list L, Type t){
    // récupération de la taillede la liste
    int nb = length(L);
    // création d'un Pointeur sur une liste
    list Copy = nil;

    if (t == INT){
      int * P = malloc(sizeof(int));  // allocation d'un pointeur

      while (nb--){
        int i = 0;
        // Copie de la liste L
        Copy = L;
        // parcour de la liste Copy
        while(i++ <= nb){
          //L = L->cdr;
          P = Copy->car;
          Copy = Copy->cdr;
        }
        // affichage de la valeur
        printf("%i ", *P);
      }

    } else {
      str P = malloc(sizeof(char));  // allocation d'un pointeur

      while (nb--){
        int i = 0;
        // Copie de la liste L
        Copy = L;
        // parcour de la liste Copy
        while(i++ <= nb){
          //L = L->cdr;
          P = Copy->car;
          Copy = Copy->cdr;
        }
        // affichage de la valeur
        printf("%s ", P);
      }
    }
  }


/*  fonction: arrayToList()
  objectif: affiche le contenu d'une liste verifie
  parametres:
    - l'adresse du tableau à parcourir
    - la liste a parcourir
    - le type des élements du tableau*/
list arrayToList(void * tab , int taille, Type t){
  // definition d'une liste
  list L = nil;

  if (t == INT){
    // definition d'un pointeur type
    int *p = tab;
    // recuperation des entiers
    int n = 0;
    while(n++ < taille){
        // printf("%i ", *p++);
        L = cons(p++, L);
    }

  } else {
    // definition d'un pointeur type
    str * p = tab;
    // recuperation des mots
    int n = 0;
    while(n++ < taille){
        // printf("%i ", *p++);
        L = cons(*p++, L);
    }
  }
  return L;
}
