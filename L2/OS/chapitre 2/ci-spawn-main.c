/* ci −spawn−main.c
Un exemple d'utilisation de la fonction spawn1
*/


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


// prototype de la fonction spawn1
int spawn1 (char * fichier, char * commande , char * arg);




int main() {
  int i;
  int t;
  int tt;
  int etat;

  for ( i = 0; i < 10 ; i++){
    t = spawn1("mon-echo", "nom-bizarre", "ceci est un argument");
    if (t < 0){
      perror("fork");
      break;
    }

    tt = wait(&etat);
    assert (tt == t);

    if (etat != 0){
      perror("exec mon-echo");
      break;
    }
  }


  return i != 10;
}

/* spawn1 --> lance un processus qui execute le fichier */
int spawn1 (char * fichier, char * commande , char * arg){
  int t;
  t = fork();
  // ERREUR fork
  if (t < 0){
    exit(1);
  }

  // ENFANT
  if(t == 0) {
    execl(fichier , commande, arg, (void *) 0);
    // ERREUR execl
    exit(1);
  }

  // PARENT
  return t;
}
