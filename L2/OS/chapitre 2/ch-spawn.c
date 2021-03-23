/* ch−spawn.c
Une fonction pour lancer un programme dans un nouveau proc.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


/* spawn1 --> lance un processus qui execute le fichier */
int spawn1 (char * fichier, char * commande , char * arg){
  int t;


  t = fork();
  // ERREUR fork
  if (t < 0) {
    exit(1);
  }

  // ENFANT
  if( t == 0) {
    execl(fichier , commande, arg, (void *) 0);
    // ERREUR execl
    exit(1);
  }

  // PARENT
  return t;
}
