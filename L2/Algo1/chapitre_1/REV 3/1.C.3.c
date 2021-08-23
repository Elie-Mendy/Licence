/* NOM : MENDY
 * Prenom : Elie
 * n°etudiant : 19004664

  Consigne :
  Définir en C, à l’aide de #define, caar et cadr. Construisez une liste pour les
  tester et afficher leur résultat.
 */

//IMPORTS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// desambiguiser
#define caar(doublet) car((list)car(doublet))
#define cadr(doublet) car(cdr(doublet))

// definition de nil
#define nil NULL

// Definition du type Doublet et list
typedef struct Doublet
{
	void *car;
	struct Doublet *cdr;
} Doublet, *list;
// Indication de typage à donner aux fonctions de traitement de liste
typedef enum Type
{
	INT,
	MOTS
} Type;

// prototype desfonctions
void usage(char *);
list cons(void *car, list cdr);
void *car(list);
void *cdr(list);

int main(int argc, char *argv[])
{
	if (argc < 5)
		usage("veuillez entrer 4 mots a inserrer sur la ldc");

	list L1 = nil;
	list L2 = nil;

	for (int i = 1; i < 3; i++)
	{
		L1 = cons(argv[i], L1);
		L2 = cons(argv[i + 2], L1);
	}

	L1 = cons(L2, L1);
	printf("%s\n", (char *)caar(L1));
	printf("%s\n", (char *)cadr(L1));
	return 0;

	return 0;
}

// CONSTRUCTION D'UN DOUBLET
list cons(void *car, list cdr)
{
	list L = malloc(sizeof(Doublet));
	if (!L)
		usage("espace insufisant");

	L-> car = car;
	L-> cdr = cdr;

	return L;
}

void *car(list L)
{
	return L->car;
}

void *cdr(list L)
{
	return L->cdr;
}


// IMPRESSION DE MESSAGE D'ERREUR (sur flux stderr)
void usage(char *message) { fprintf(stderr, "Usage : %s\n", message), exit(1); }
