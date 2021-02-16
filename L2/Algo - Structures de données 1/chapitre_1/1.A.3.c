/* NOM : MENDY
 * Prenom : Elie
 * n°etudiant : 19004664

   Consigne :
  Écrivez un programme qui lit une suite d’adresses dans un fichier et les met dans
  une table de structures. Combinez le résultat des deux programmes précédents.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// AGREGAT : éléments constritutifs d'une adresse postale
typedef struct Adresse Adresse;
struct Adresse {
  int num;
  char voix[20];
  char nom_rue[100];
  char ville[50];
  int cp;
};


// prototype de la fonction carte_de_visite()
void carte_de_visite(Adresse );


int main(int argc, char const *argv[]) {
  // INITIALISATION D'UNE TABLE DE 5 ADRESSEs
  Adresse  a[5] = {0};
  int i;
  /*========================================================================
                      OUVERTURE d'UN FICHIER EN LECTURE
  =========================================================================*/
  FILE * fichier = fopen("data_1.A.3", "r");
  if (!fichier) exit(1);

  /*========================================================================
                      LECTURE ET REMPLISSAGE DES TABLES
  =========================================================================*/
  for (i = 0 ; i < 5 ; i++){
    fscanf(fichier, "%i", &a[i].num);
    fscanf(fichier, "%s\n", a[i].voix);
    fgets(a[i].nom_rue, 100, fichier);
    char * fin_chaine  = strchr(a[i].nom_rue, '\n');   // suppression du '\n' causé par fgets
    *fin_chaine = '\0';
    fscanf(fichier, "%s", a[i].ville);
    fscanf(fichier, "%i", &a[i].cp);
  }


  /*========================================================================
                    AFFICHAGE DES CARTES DE VISITE
  =========================================================================*/
  for (i = 0 ; i < 5 ; i++){
    printf("\n\nAffichage de l'adresse n°%i\n", i + 1);
    carte_de_visite(a[i]);
  }

  return 0;
}



// fonction présentant la carte
// de visite d'une adresse donnée
void carte_de_visite(Adresse a){
  printf("%i\n", a.num);
  printf("%s\n", a.voix);
  printf("%s\n", a.nom_rue);
  printf("%s\n", a.ville);
  printf("%i\n", a.cp);
}
