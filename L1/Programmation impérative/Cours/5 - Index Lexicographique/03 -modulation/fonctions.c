
#include "fonctions.h"


// INDEXATION D'UNE LIGNE DE TEXTE
void indexe( char * ligne, idx ref){
  // capture du premier mot et de la ligne en mémoire
  str mot = strtok(ligne, split_chars);

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
  for (i = 0; mots[i]; i++)
    if (pareil(mot, mots[i])) return i;
  return -1;
}


// AJOUT d'UN NOUVEAU MOT
void ajoute_mot(idx x, str mot, idx ref){
  mots[x] = mot;      // ajout du nouveau mot dans l'index
  refs[x][0] = ref;   // ajout de sa reference
  ++ref_libre[x];     // incrémentation de la ref libre pour ce mot
  ++mot_libre ;       // incrémentation de l'emplacement d'un nouveau mot
}


// AJOUT d'UNE REF (mot existant)
void ajoute_ref(idx x, idx ref){
  idx r = ref_libre[x];                   // recupération de l'indice de l'emplacement de nouvelle ref
  refs[x][r] = ref;                       // ajout de la nouvelle ref
  ++ref_libre[x];                         // incrémentation de la ref_libre pour ce mot
}


// COMPARAISON DE DEUX CHAINES
bool pareil(str x, str y) { return strcasecmp(x,y) ? False : True ;}



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
