#include <stdio.h>
#include <stdlib.h>
#include <string.h>




#define max_mots 128                                // nombre maximum d'éléments dans la table de mots
#define max_refs 16                                 // nombre maximum de ref par mots
#define maximum 4096                                // nombre maximal de caractères composant un mot
#define taille_mot 1024



typedef unsigned idx ;                              // definition du type idx
typedef char * str;                                 // definirion du type str
typedef enum {False, True} bool ;                   // definition du type bool
// definition d'un nouveau type pour emuler un index
typedef struct { str mot ; idx ref_libre ; idx refs[max_refs] ; } ndex ;






// allocation d'espace pour:
ndex mots[max_mots];                // --> la structure contenant les mots indexé et leurs references associées
char ligne[maximum];                // --> la ligne de texte a indexer
idx mot_libre = 0;                  // --> l'index indiquant le mot libre (au départ 0)
char * stop[max_mots];              // --> une table contenant les mots a exclure de l'index

// definition d'une liste de caractères a exclure
// on se sert de ces caractères pour découper la ligne de texte
const str split_chars =  " ().&%,;:!?/*~_-+[]{}=<>@`\"\'0123456789$€“”«»·\n\t";



#include "fonctions.h"                              // Header des fonctions du programme






int main(int k, char const *argv[]) {

  // test du nombre d'arguments
  if (k < 2) usage(" veuillez indiquer le nom du fichier a lire");

  // ouverture du flux
  FILE * fichier = fopen(argv[1], "r");

  // test de validité des flux
  if ( ! fichier) usage(" fichier illisible");

  /* TRAITEMENT */
  // lecture des mots de la STOPLIST
  lire_stoplist("stoplist.txt");

  // boucle d'indexation de chaque ligne
  idx i = 0;                                // i represente le numéro de ligne
  while (fgets(ligne, maximum, fichier))
    indexe(ligne, ++i);


  // fermeture du flux
  fclose(fichier);

  // tri de la table
  qsort(mots, mot_libre, sizeof(ndex), compare);

  // affichage de l'indexe
  dump (mot_libre);

  return 0;
}









// IMPRESSION DE MESSAGE D'ERREUR (sur flux stderr)
void usage(char * message){ fprintf(stderr, "Usage : %s\n", message), exit(1) ;}



// LECTURE D'UNE STOPLIST
void lire_stoplist(char * liste){
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
    }
  fclose(fichier);
}




// INDEXATION D'UNE LIGNE DE TEXTE
void indexe( char * ligne, idx ref){
  // capture du premier mot et de la ligne en mémoire
  str mot = strtok(strdup(ligne), split_chars);
  // si ce n'est pas la chaine vide
  while (mot){

    int s = exclure(mot);                      // verificaton de la présence du mot dans l'index
    if (s < 0){                                     // si le mot n'est pas a exclure
      int x = indice(mot);                      // verificaton de la présence du mot dans l'index
      if (x < 0)  ajoute_mot(mot_libre, mot, ref);    // ajout a la suite si nouveau mot
      else ajoute_ref (x, ref);                       // sinon ajoute juste la nouvelle ref
    }
    mot = strtok(NULL, split_chars);                // continuer sur le mot suivant
  }
}


// EXCLUSION D'UN MOT si présent dans la stoplist
int exclure(str mot){                // modification du type
  idx i = 0;
  for (i = 0; stop[i]; i++){
    if (pareil(mot, stop[i])) return i;
  }
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
  mots[x].mot = mot;      // ajout du nouveau mot dans l'index
  mots[x].refs[0] = ref;   // ajout de sa reference
  ++mots[x].ref_libre;     // incrémentation de la ref libre pour ce mot
  ++mot_libre ;       // incrémentation de l'emplacement d'un nouveau mot
}


// AJOUT d'UNE REF (si mot déja indexé)
void ajoute_ref(idx x, idx ref){
  idx i = 0;
  int n = 0;
  for (i = 0 ; mots[x].refs[i] ; i++){
    if (mots[x].refs[i] == ref) n = 1;
  }

  if (!n){
    idx r = mots[x].ref_libre;                   // recupération de l'indice de l'emplacement de nouvelle ref
    mots[x].refs[r] = ref;                       // ajout de la nouvelle ref
    ++mots[x].ref_libre;                         // incrémentation de la ref_libre pour ce mot
  }
}

// COMPARAISON DE DEUX CHAINES
bool pareil(str x, str y) { return strcasecmp(x,y) ? False : True ; }


// FOCNTION DE TRI DE DEUX MOTS
int compare(void const *E1, void const *E2){

  ndex const * pE1 = E1;
  ndex const * pE2 = E2;

  return strcmp(pE1 -> mot, pE2 -> mot);
}

// AFFICHAGE DES VALEURS DE L'INDEX
void dump(idx k){
  idx x , z;
  for (x = 0 ; x < k ; ++x){
    printf("%s :", mots[x].mot);
    for (z = 0 ; mots[x].refs[z] ; ++z){
      printf(" %i", mots[x].refs[z]);
    }
    printf("\n");
  }
}
