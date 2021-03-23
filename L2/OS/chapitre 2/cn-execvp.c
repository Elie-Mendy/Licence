/* cn−execvp.c
Une re−implementation de la fonction execvp
*/

#define _GNU_SOURCE // pour asprintf
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

int monexecvp(char * file, char * av[]) {
  char * p;
  char * path;
  int t;


  p = getenv("PATH");

  if (p == 0){
    execv(file, av);
    return -1;
  } else {
    p = strdup(p);
    assert(p != 0);
    for(p = strtok(p, ";"); p != 0; p = strtok(0, ";")) {
      t = asprintf(&path, "%s/%s", p , file);
      assert(t != 0);
      execv(path, av);
      free(path);
    }
    free(p);
  }
  return -1;
}


int main(int argc, char const *argv[]) {

  return 0;
}
