#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <sys/wait.h>


enum {
  Nfois = 100 * 1000,
};

int main(void) {
  int newpid;
  int t;
  int etat;
  int i;

  // creation de 100 000 processus()
  for (i = 0; i < Nfois ; i++){
    newpid = fork();


    // ENFANT
    if (newpid == 0){
      // ne rien faire
      return 0;
    }

    // PARENT
    // attendre la fin de l'enfant
    assert (newpid > 0);
    t = wait(&etat);

    // en s'assurant qu'il n'y ai pas d'erreur
    // chez l'enfant sinon il n'est pas compté
    assert (t >= newpid);
  }

  return 0;
}
