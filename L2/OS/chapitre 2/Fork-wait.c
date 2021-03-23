/* cd−fork−wait.c
lancer un processus, attendre qu'il se termine
*/
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
#include <sys/wait.h>   // import de la methode wait


int main(void) {

  int t;      // valeur de retour du fork
  int pid;    // contiendra la valeur de t si le
  int etat;   // compte rendu de wait

  // fork() copie le programme et l'execute on laisse des message pour identifier
  // l'instance du programme

  // dans le cas du processus parent
  printf("Je Suis le Processus de départ\n");


  // clonage du programme
  t = fork();

  // gestion des cas possibles
  if (t == -1) {                                                                          // si forkl renvoi -1 --> ERROR
    perror("fork");
    return 1;
  } else if (t == 0){
    // il s'agit de l'enfant
    printf("enfant: j'attend 5 secondes\n");                                              // si fork renvoi 0 --> Processus ENFANT
    sleep(5);
    printf("enfant: je termine\n");
    return 0;
  } else {
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
