/*
Nom: MENDY
Prenom: Elie
n°etudiant: 19004664

Ecrivez une commande mon-if qui lance un premier
processus, puis en lancera un second si le premier a réussi
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


  printf("P1 : Je Suis le Processus de départ\n");


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
    if (tt == -1) {
      perror("fork");
      return 1;
    }

    // ENFANT P3
    else if  (tt == 0) {
      printf("\t\tP3: j'attend 10 secondes\n");
      sleep(10);
      printf("\t\tP3: je termine\n");
      return 0;
    }

    else {
      printf("\tP2: j'attend 20 secondes\n");
      sleep(20);
      printf("\tP2: je termine\n");
      return 0;
    }
  }

  // PARENT P1
  else {
    // in s'agit du processus parent
    for (;;){
      pid = wait(&etat);
      if (pid == t)
        break;
      printf("P1: wait a rendu la valeur %d, j'attend encore \n", pid );
      if (pid == -1)
        perror("wait");

    }

    printf("P1: l'enfant s'est terminé avec la valeur %d\n", etat );
    printf("P1: je termine\n");
  }

  return 0;
}
