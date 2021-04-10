/* NOM : MENDY
 * Prenom : Elie
 * n°etudiant : 19004664

  Consigne :
  Écrire un programme recevant une chaîne de caractères sur la ligne de commande
  et affichant chaque caractère de la chaîne sur une ligne, avec deux variantes ; le
  choix des variantes étant fait à l’aide d’un #define au début du programme et d’un

  Variante 1 : utilisez le nom de la chaîne de caractères pour la parcourir ;
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//#define VAR1
#define VAR2

int main(int argc, char *argv[])
{
    if (argc < 2){
      fprintf(stderr, "usage : veuillez entrer un mot sur la ldc\n");
      exit(1);
    }

    #ifdef VAR1 // parcour de la chaine à partir de son nom
    int i = 0;
    printf("Variante 1:\n");
    while(argv[1][i]){
      printf("%c ", argv[1][i++]);
    }
    puts("");
    #endif

    #ifdef VAR2 // parcour de la chaine à partir d'un pointeur
    char * p = argv[1]; // argv1
    printf("Variante 2:\n");
    while(*p) { printf("%c ", *p++); };
    #endif
    puts("");

    return 0;
}
