#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

  // utilisation dans une boucle for
  // sert a grouper des instructions
  int x, y;
  for (x = 0, y= 25; x < y; x++, y--){
    printf("%i , %i\n", x , y);
  }

  // utilisation dans boucle while
  // while (condition) exp1, exp2, exp3... ;
  x = 0, y = 10;
  while(x < y) printf("%i\n", x), printf("%i\n", y--), printf("lol\n");


return 0;
}

// dans la fonction usage
void usage(char * message) {
  printf("usage :%s\n", message), exit(1);
}



/*


/!\ compilation de la virgule /!\


int main(int x, char  *A[]) {

  while (*A) printf("%p : %s\n", *A, *A++);           // mauvaise pratique
  while (*A) printf("%p : %s\n", *A, *A), A++         // bonne pratique

  return 0;
}


dans la mauvaise pratique, la variable est déja incrémentée lors de
l'appelle de l'adresse ...

c'est due a la compilation

la bonne pratique evite les mauvaise surprises au sujet de la variable A

*/
A
