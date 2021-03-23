/* cg−exec−simple.c
Un execl tout simple
*/

#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {

  int t; // prendra la valeur de retour de execl

  // execution d'une commande (ici echo) + mort du processus parent
  // le parent est remplacé par le fils
  t = execl("/bin/echo", "commande", "arg1", "arg2", NULL);

  // si execl renvoi -1 ... il a u une erreur
  if (t < 0){
    // on affiche donc un message
    perror("execl");
    return -1;
  } else {
    // sinon c'est que tout a fonctionné
    // MAIS CETTE PARTIR DU CODE NE SERA JAMAIS LU...
    // (remplacement du processus parent par l'ENFANT)
    printf("l'execl a fonctionné, ce message ne sera jamais affiché\n");
    return 0;
  }
}
