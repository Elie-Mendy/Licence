#include <stdio.h>
#include <stdlib.h>

#define max_mots 128                                // nombre maximum d'éléments dans la table de mots
#define max_refs 16                                 // nombre maximum de ref par mots
#define maximum 4096                                // taille d'acceuil d'une ligne

typedef unsigned idx ;                              // definition du type idx
typedef char * str;                                 // definirion du type str


int main(int argc, char const *argv[]) {


  char * mots[max_mots];                            // table de max_mots
  idx mot_libre = 0;                                // index du premier mot libre
  idx refs[max_mots][max_refs];                     // matrice de max_mots par max max_refs
  idx ref_libre[max_mots];                          // table de max_mots


  return 0;
}
