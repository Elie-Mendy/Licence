/* cp−moncd.c
Pour faire un chdir ( pas trop utilisable )
*/

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>


int main(int argc, char * argv[]) {
  char * dir;
  int t;



  // PROCESSUS PARENT (gestion d'erreur exec)
  // traiter les arguments
  if ( argc < 2){     // si le nouveau chemin n'est pas donné
    dir = getenv("HOME");
    if ( dir == 0)
      dir = "/tmp";
  } else if ( argc > 2){ // si trop d'arguments
    fprintf ( stderr, "usage: %s [dir]\n", argv[0]) ;
    return 1;
  } else
    dir = argv[1];


  // faire le boulot
  t = chdir(dir) ;
  if ( t < 0){
    perror(dir) ;
  return 1;
  }
return 0;
}

/*
Solution : Parce que l’appel système chdir s’est fait dans le processus enfant. Le
répertoire courant du shell (le parent) ne change pas.*/
