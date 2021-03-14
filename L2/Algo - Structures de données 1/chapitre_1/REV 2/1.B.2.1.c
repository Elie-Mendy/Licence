/* NOM : MENDY
 * Prenom : Elie
 * n°etudiant : 19004664

  Consigne :
  Écrire un programme recevant une chaîne de caractères sur la ligne de commande
  et affichant chaque caractère de la chaîne sur une ligne, avec deux variantes ; le
  choix des variantes étant fait à l’aide d’un #define au début du programme et d’un

  Variante 1 : utilisez le nom de la chaîne de caractères pour la parcourir ;
  Variante 2 : utilisez un pointeur libre incrémenté pour parcourir la chaîne.


 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define VAR1
//#define VAR2

int main(int argc, char const *argv[])
{
    // PARTIE 1:
    #ifdef VAR1
    char * mot = "test"; // argv1
    int taille = strlen(mot), i;
    for(i = 0; i < taille ; i++){
        printf("%c ", mot[i]);
    }
    //int taille = strlen(argv[1]);
    #endif

    #ifdef VAR2
    char * p = mot; // argv1
    while(*p) { printf("%c ", *p++); };
    #endif

    char * p_chaine = "adresse";

    char chaine[] = "adresse";

    printf("\nadresse chaine : %p \nadrese pointeur : %p", p_chaine, chaine);

    // modif
    chaine[0] = 'A';
    //*p_chaine = 'A';

    printf("\nchaine : %s \nadrese p_chaine : %s", p_chaine, chaine);

    return 0;
}
