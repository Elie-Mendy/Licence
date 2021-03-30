/*
Nom: MENDY
Prenom: Elie
n°etudiant: 19004664


Ecrivez et testez une fonction spawn qui permet
de lancer une commande avec un nombrevariable d’arguments.
*/


// IMPORTS DE BIBLIOTEQUES
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>   // import de la methode wait
# include <assert.h>


int spawn (char * fichier, char * arg[]);

int main(int argc, char const *argv[]) {

  int t;
  int tt;
  int etat;

  char * tab[] = {"echo", "juste", "un", "petit", "test", NULL};

  t = spawn(tab[0], tab);
  if (t < 0){
    perror("fork");
  }

  tt = wait(&etat);
  assert (tt == t);

  return 0;
}


int spawn (char * fichier, char * arg[]){


  int t;
  t = fork();
  // ERREUR fork
  if (t < 0){
    exit(1);
  }

  // ENFANT
  if(t == 0) {
    execvp(fichier ,arg);
    // ERREUR execl
    exit(1);
  }

  // PARENT
  return t;
}
