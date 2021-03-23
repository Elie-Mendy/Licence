/* ce−pidmax1.c
Trouver le PID maximum (programme faux)
*/
#include <stdio.h>
#include <unistd.h>


int main(int argc, char const *argv[]) {
  int oldpid = 0;
  int newpid;


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
    }

    oldpid = newpid;

  }
  return 0;
}
// enfant : ne rien faire
