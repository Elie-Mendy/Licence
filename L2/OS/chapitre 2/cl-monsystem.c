/* cl −monsystem.c
Une re−implementation de la fonction system
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int monsystem(char * command) {
  int pid;
  int x;
  int etat;

  pid = fork();
  // ERREUR
  if ( pid < 0) {
    perror("fork");
    return -1;
  }

  // PARENT
  if (pid != 0) {
    for(;;) {
      x = wait(&etat);
      if (x == pid)
        return etat;
    }
  }

  // ENFANT
  execl( "/bin/sh", "sh", "-c", command, NULL);
  perror("execl") ;
  return -1;
}



#ifdef TEST // gcc -g -Wall -DTEST <nom du programme.c> -o <nom de la sortie>
int main(int argc, char *argv[]) {
  int i;

  for (i = 1 ; i < argc ; i++) {
    printf("la commande %d donne %d\n", i ,monsystem(argv[i]));
  }
  return 0;
}
#endif
