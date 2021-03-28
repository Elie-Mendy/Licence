/*
NOM: MENDY
PRENOM : Elie
n°etudiant: 19004664

Programme: mon-if.c:
--> lance un premier processus, puis en lancera un second si le premier a réussi.
*/


// IMPORTS
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>   // import de la methode wait



int main(void) {

  int t;      // valeur de retour du fork
  int pid;    // contiendra la valeur de t
  int etat;   // compte rendu de wait

  // fork() copie le programme et l'execute on laisse des message pour identifier
  // l'instance du programme

  // dans le cas du processus parent
  printf("Je Suis le Processus de départ\n");


  // clonage du programme
  t = fork();

  // GESTION D'ERREUR
  if (t == -1) {
    perror("fork");
    return 1;
  } else if (t == 0){
    // PREMIER PROCESSUS ENFANT
    printf("enfant: j'attend 2 secondes\n");
    sleep(2);
    printf("enfant: je termine\n");
    return 0;
  } else {
    // PROCESSUS PARENT
    for (;;){
      pid = wait(&etat);
      if (pid == t)
        break;
      printf("parent : wait a rendu la valeur %d, j'attend encore \n", pid );
      if (pid == -1)
        perror("wait");
    }
    // lancement deuxieme processus
    t = fork();
    if (t ==1) {
      perror("fork");
      return 1;
    } else if (t == 0) {
        printf("Premier processus a bien fonctionné\n");
        sleep(2);
        printf("enfant: je termine\n");
        return 0;
    } else {
      for (;;){
        pid = wait(&etat);
        if (pid == t)
          break;
        printf("parent : wait a rendu la valeur %d, j'attend encore \n", pid );
        if (pid == -1)
          perror("wait");
      }
    }


    printf("parent : l'enfant 2 s'est terminé avec la valeur %d\n", etat );
    printf("parent : je termine\n");
  }

  return 0;
}
