/* cd−fork−wait.c
lancer un processus, attendre qu'il se termine
*/


// IMPORTS DE BIBLIOTEQUES
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
#include <sys/wait.h>   // import de la methode wait



// MAIN
int main(void) {

  int t;      // valeur de retour du fork
  int tt;
  int pid;    // contiendra la valeur de t si le
  int etat;   // compte rendu de wait


  printf("Je Suis le Processus de départ\n");


  // lancement du premier pricessus P2
  t = fork();

  // ERREUR
  if (t == -1) {                                                                          // si forkl renvoi -1 --> ERROR
    perror("fork");
    return 1;
  }

  // ENFANT P2
  else if (t == 0){

    // lancement du deuxieme processus P3
    tt = fork();
    // ERREUR
    if (tt == -1) {                                                                          // si forkl renvoi -1 --> ERROR
      perror("fork");
      return 1;
    }

    // ENFANT P3
    else if  (tt == 0) {
      printf("P3: j'attend 10 secondes\n");                                              // si fork renvoi 0 --> Processus ENFANT
      sleep(10);
      printf("enfant: je termine\n");
      return 0;
    }

    else {
      printf("enfantP2: j'attend 20 secondes\n");                                              // si fork renvoi 0 --> Processus ENFANT
      sleep(20);
      printf("enfant: je termine\n");
      return 0;
    }
  }

  // PARENT P1
  else {
    // in s'agit du processus parent
    for (;;){                                                                            // sinon il renvoi le PID du PARENT
      pid = wait(&etat);
      if (pid == t)
        break;
      printf("parent : wait a rendu la valeur %d, j'attend encore \n", pid );
      if (pid == -1)
        perror("wait");

    }

    printf("parent : l'enfant s'est terminé avec la valeur %d\n", etat );
    printf("parent : je termine\n");
  }

  return 0;
}
