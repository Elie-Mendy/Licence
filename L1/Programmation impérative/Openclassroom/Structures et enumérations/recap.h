
typedef enum Classe Classe;
enum Classe{
  PAUVRE,MOYENNE,RICHE
};

typedef struct Personne Personne;
struct Personne{
  char nom[100];
  char prenom[100];
  char adresse[1000];

  int age;
  Classe classe;
};
