/* NOM : MENDY
 * Prenom : Elie
 * n°etudiant : 19004664

  Consigne :
  Écrire un programme qui alloue un pointeur sur une chaîne de caractères
  constante construite avec l’opérateur ”...” et une table sur la même chaîne. Com-
  parez les adresses des données (constante et variable). Tentez de modifier la chaîne
  dans les deux cas. Expliquez ce que vous avez observé.
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(int argc, char const *argv[])
{
  // allocation d'un pointeur et declaration d'une table de caracteres
  char * p_chaine = "chaine";
  char chaine[] = "chaine";

  // affichage des adresses
  printf("adresse chaine : %p \nadrese pointeur : %p\n\n", p_chaine, chaine);

  // modification
  chaine[0] = 'C';
  //*p_chaine = 'C';      // erreur de segmentation impossible de modifier une valeur --> read-only


  printf("chaine modifiée: %s\np_chaine non modifié: %s\n", chaine, p_chaine);

  return 0;
}
