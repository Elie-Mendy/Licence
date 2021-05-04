#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned idx ;                              // definition du type idx
typedef char * str;                                 // definirion du type str
typedef enum {False, True} bool ;                   // definition du type bool


#define max_mots 10000                              // nombre maximum d'éléments dans la table de mots
#define max_refs 4096                                 // nombre maximum de ref par mots
#define maximum 4096                                // nombre maximal de caractères composant un mot

// allocation d'espace pour:
char * mots[max_mots];              // --> l'index de mots
idx refs[max_mots][max_refs];       // --> la table de references associée
idx ref_libre[max_mots];            // --> la table indiquant les indices des ref_libre
char ligne[maximum];                // --> la ligne de texte a indexer
idx mot_libre = 0;                  // --> l'index indiquant le mot libre (au départ 0)

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
  // boucle d'indexation de chaque ligne
  idx i = 0;                                // i represente le numéro de ligne
  while (fgets(ligne, maximum, fichier))
    indexe(ligne, ++i);



  // fermeture du flux
  fclose(fichier);

  // affichage de l'indexe
  dump (mot_libre);

  return 0;
}









// IMPRESSION DE MESSAGE D'ERREUR (sur flux stderr)
void usage(char * message){ fprintf(stderr, "Usage : %s\n", message), exit(1) ;}


// INDEXATION D'UNE LIGNE DE TEXTE
void indexe( char * ligne, idx ref){
  // capture du premier mot et de la ligne en mémoire
  str mot = strtok(strdup(ligne), split_chars);
  // si ce n'est pas la chaine vide
  while (mot){
    int x = indice(mot);                            // verificaton de la présence du mot dans l'index
    if (x < 0)  ajoute_mot(mot_libre, mot, ref);    // ajout a la suite si nouveau mot
    else ajoute_ref (x, ref);                       // sinon ajoute juste la nouvelle ref
    mot = strtok(NULL, split_chars);                // continuer sur le mot suivant
  }
}


// RECUPERATION DE L'INDICE (mot indéxé)
int indice(str mot){
  idx i = 0;
  for (i = 0; mots[i]; i++){
    if (pareil(mot, mots[i])) return i;
  }
  return -1;
}


// AJOUT d'UN NOUVEAU MOT
void ajoute_mot(idx x, str mot, idx ref){
  mots[x] = mot;      // ajout du nouveau mot dans l'index
  refs[x][0] = ref;   // ajout de sa reference
  ++ref_libre[x];     // incrémentation de la ref libre pour ce mot
  ++mot_libre ;       // incrémentation de l'emplacement d'un nouveau mot
}


// AJOUT d'UNE REF (si mot déja indexé)
void ajoute_ref(idx x, idx ref){

  idx r = ref_libre[x];                   // recupération de l'indice de l'emplacement de nouvelle ref
  refs[x][r] = ref;                       // ajout de la nouvelle ref
  ++ref_libre[x];                         // incrémentation de la ref_libre pour ce mot
}


// COMPARAISON DE DEUX CHAINES
bool pareil(str x, str y) { return strcasecmp(x,y) ? False : True ; }

// AFFICHAGE DES VALEURS DE L'INDEX
void dump(idx k){
  idx x , z;
  for (x = 0 ; x < k ; ++x){
    if (mots[x]){
      printf("%s :", mots[x]);
      for (z = 0 ; refs[x][z] ; ++z){
        printf(" %i", refs[x][z]);
      }
      printf("\n");
    }
  }
}
