// fichier contenant une structure

typedef struct Point Point;
struct Point{
  int x;
  int y;
};


typedef struct Personne Personne;
struct Personne{
  char nom[50];
  char prenom[50];
  char adresse[500];

  int age;
  int argent;
};


typedef enum Volume Volume;
enum Volume{
  FAIBLE, MOYEN, FORT
};
