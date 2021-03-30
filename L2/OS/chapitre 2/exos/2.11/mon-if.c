/*
NOM: MENDY
PRENOM : Elie
n°etudiant: 19004664

Programme: mon-if.c:
--> lance un premier processus, puis en lancera un second si le premier a réussi.
*/



#define MAX_PARAM 1000  // nb de parametre autorisé pour une commande


// IMPORTS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>


// prototypes des fonctions
int spawn1 (char * fichier, char * arg[]);
int decouper (char * ligne, char * separ, char * mot[], int maxmot);
void usage(char * message);
void error(char * message);




int main(int argc, char * argv[]) {

  // controle du nombre d'arguments sur la ldc
  if (argc < 3) {
    usage("veuillez entrer deux commandes sur la ldc");
    exit(1);
  }

  // definition des variable qui acceuilleront les PID
  int t;
  int tt;
  int etat;


  // Parsing du premier processus
  char * p1[MAX_PARAM];
  decouper(argv[1], " ", p1, MAX_PARAM);

  // Parsing du deuxieme processus
  char * p2[MAX_PARAM];
  decouper(argv[2], " ", p2, MAX_PARAM);



  // LANCEMENT DU PREMIER PROCESSUS
  t = spawn(p1[0], p1);
  if (t < 0){
    error("fork - premier processus");
  }

  tt = wait(&etat);
  assert (tt == t);

  if (etat != 0){
    error("exec - le premier processus ne s'est pas bien terminé");
    exit(1);
  }

  // LANCEMENT DU DEUXIEME PROCESSUS
  t = spawn(p2[0], p2);
  if (t < 0){
    error("fork - deuxieme processus");
  }

  tt = wait(&etat);
  assert (tt == t);

  if (etat != 0){
    error("exec - deuxieme processus");
    exit(1);
  }

  return 0;

}




/* FONCTION spawn1()
  --> lance un processus qui execute le fichier
*/
int spawn (char * fichier, char * arg[]){
  int t;
  t = fork();
  // ERREUR fork
  if (t < 0){
    exit(1);
  }

  // ENFANT
  if(t == 0) {
    execvp(fichier ,arg);
    // ERREUR execl
    exit(1);
  }

  // PARENT
  return t;
}


/* FONCTION DECOUPER:
  --> découpe une chaine selon un/des séparateurs
  --> remplie un vecteur de chaines de caractere
*/
int decouper (char * ligne, char * separ, char * mot[], int maxmot) {
  int i;

  mot[0] = strtok(ligne, separ);
  for (i = 1; mot[i-1] != 0 ; i++ ) {
    if (i == maxmot) {
      fprintf(stderr, "Erreur dans la fonction découper : trop de mots\n");
      mot[i-1] = 0;
      break;
    }

    mot[i] = strtok(NULL, separ);
  }
  return i;
}


/* FONCTION usage():
  --> renvoi une indication d'usage à l'utilisateur
*/
void usage(char * message) { fprintf(stderr, "usage: %s\n", message); exit(1);}


/* FONCTION error():
  --> renvoie un message d'erreur
  --> remplace perror() pour eviter le ":Success" en console
*/
void error(char * message) { fprintf(stderr, "error: %s\n", message); exit(1);}
