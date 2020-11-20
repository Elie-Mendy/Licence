/* récap des fonctions utilisable sur les chaines */

// bibliotèque
#include <string.h>

int main(int argc, char const *argv[]) {

  char chaine[] = "Texte de test pour voir";
  // cherche un caractere -> renvoi pointeur            strchr(chaine, 'caractere')
  printf("%s\n", strchr(chaine, 'x'));


  // chercher le premier des caractères suivant         strpbrk(chaine, "caractereS")
  printf("%s\n", strpbrk(chaine, "zbs") );


  // cherche une chaine dans une chaine                 strstr(chaine, "chaine")
  printf("%s\n", strstr(chaine, "pour") );


  char texte[100] = {0};

  // ecriture dans une chaine                           sprintf(chaine, "chaine de format %d %c %s", args...)
  sprintf(texte, "bonjour je fais juste un %s", chaine);
  printf("%s\n", texte );



  // concatener une chaine A apres une chaine B         strcat(A, B)
  char nom[] = "Mendy";
  char particule[] = " Premier";
  char prenom[] = "Elie";

  strcat(nom, particule);
  printf("Bonjour je suis %s %s\n", prenom, nom);


  // comparer deux chaines                               strcmp(A, B)
  // renvoi 0 si les mots sont identique , 1 si il y a unedifférence
  char mot1[] = "test";
  char mot2[] = "test";
  char mot3[] = "taste";

  if (strcmp(mot1, mot2)) printf("mot un est différent à mot 2\n");
  else printf("mot 1 est similaire à mot  2\n");

  if (strcmp(mot1, mot3)) printf("mot 1 est carrément différent de mot 3 par contre");
  return 0;
}
