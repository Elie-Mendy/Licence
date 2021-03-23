/* ce−pidmax1.c
Trouver le PID maximum (programme faux)
*/
#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <sys/wait.h>


int main(void) {
  int oldpid = 0;
  int newpid;
  int t;
  int etat;


  for (;;){
    newpid = fork();   // si 0 -> enfant / sinon PARENT / sinon ERROR
    // ENFANT
    if (newpid == 0) {
      // ne rien faire
      return 0;
    }

    // PARENT
    // quand next pid est plus petit que old --> PID max atteint
    if (newpid < oldpid){
      printf("Le PID max semble etre %d\n", oldpid );
      return 0;
    }
    t = wait(&etat);
    assert(t >=0);    // aucune prise en compte tant que le processus lancé n'est pas correct
    oldpid = newpid;

  }
  return 0;
}

/* sinon taper la commande : cat /proc/sys/kernel/pid_max  */
