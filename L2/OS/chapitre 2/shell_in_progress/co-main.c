/*
Boucle principale du shell
*/


// IMPORTS DE BIBLIOTEQUES
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <assert.h>

// TAILLES DES DONNEES
enum {
  MaxLigne = 1024, // longueur max d'une ligne de commandes
  MaxMot = MaxLigne / 2, // nbre max de mot dans la ligne
  MaxDirs = 100, // nbre max de repertoire dans PATH
  MaxPathLength = 512, // longueur max d'un nom de fichier
};


// PROTOTYPE FONCTIONS
int decouper(char *, char*, char**, int);

// DEFINITION DU PROMPT
#define PROMPT "new shell - ?  "




// MAIN
int main(int argc, char const *argv[]) {
  // allocation des données
  char ligne[MaxLigne];           // acceuil de la ldc
  char * mot[MaxMot];             // acceuil de la ldc découpée
  char pathname[MaxPathLength];   // acceuil du nom du repertoire
  char * dirs[MaxDirs];           // acceuil des noms des repertoires de la variable $PATH
  int i;
  int tmp;


  /* DECOUPER UNE COPIE DE PATH EN REPOSITORY */
  decouper(strdup(getenv("PATH")) , ":", dirs, MaxDirs);

  /* LIRE ET TRAITER CHAQUE LIGNE DE COMMANDE */
  // --> impression du prompt
  // --> decoupage de la ldc
  // --> lancement de la commande récupérée
  // --> attente du la fin du processus enfant




  // --> impression du prompt
  for (printf(PROMPT) ; fgets(ligne, sizeof ligne, stdin) != 0 ; printf(PROMPT)) {


    // --> découpage de la ldc (saisie sur stdin)
    decouper (ligne , " \t\n", mot, MaxMot);


    // lancement de la commande récupérée
    //    * controle de ldc vide
    if (mot[0] == 0)
      continue;

    //    * controle de l'erreur fork()
    tmp = fork();
    if(tmp < 0) {
      perror("fork");
      continue;
    }

    //    * PARENT : attendre la fin de l'enfant
    if (tmp != 0) {
      while (wait(0) != tmp);
      continue;
    }


    //    * ENFANT : exec du programme
    for (i = 0; dirs[i] != 0 ; i++) {
      snprintf( pathname, sizeof pathname, "%s/%s", dirs[i], mot[0]);
      execv(pathname, mot);
    }

    // partie du programme non sensé s'executer sauf Erreur d'execv
    fprintf(stderr, "%s: not found\n", mot[0]);
    exit(1);
  }


  printf("Bye\n");
  return 0;
}



// FONCTION DECOUPER
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
