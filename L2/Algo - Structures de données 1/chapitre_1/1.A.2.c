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
  char voix[8];
  char nom_rue[100];
  char ville[50];
  int cp;
};


// prototype de la fonction carte_de_visite()
void carte_de_visite(Adresse );


int main(int argc, char const *argv[]) {
  // INITIALISATION D'UNE ADRESSE
  Adresse a;

  /*========================================================================
                      OUVERTURE d'UN FICHIER EN LECTURE
  =========================================================================*/
  FILE * fichier = fopen("data_1.A.2", "r");
  if (!fichier) exit(1);

  /*========================================================================
                      LECTURE ET REMPLISSAGE DES TABLES
  =========================================================================*/
  fscanf(fichier, "%i", &a.num);
  fscanf(fichier, "%s\n", a.voix);
  fgets(a.nom_rue, 100, fichier);
  char * fin_chaine  = strchr(a.nom_rue, '\n');   // suppression du '\n' causé par fgets
  *fin_chaine = '\0';
  fscanf(fichier, "%s", a.ville);
  fscanf(fichier, "%i", &a.cp);


  /*========================================================================
                    AFFICHAGE DE LA CARTE DE VISITE
  =========================================================================*/
  carte_de_visite(a);

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
