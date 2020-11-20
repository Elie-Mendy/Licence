/* structures utilisées dans le tp perso sur la saisie de texte sécurisée */

typedef enum Archetype Archetype;
enum Archetype{
  MAGICIEN, GUERRIER, ARCHER
};


typedef struct Joueur Joueur;   // creation d'un alias
struct Joueur{                  // definition de la structure
  char nom[50];
  char prenom[50];
  int age;
  Archetype classe;
};                               // tres important le ';'
