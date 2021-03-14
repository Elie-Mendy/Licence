/* ba−echo.c
Pour afficher le contenu de la ligne de commande
*/


#include <stdio.h>

int main(int argc, char const *argv[]) {
  int i;

  printf("Programme lancé sous le nom %s avec %d arguments\n", argv[1], argc -1 );
  for (i = 1 ; i < argc ; i++ )
    printf("argument %d : %s\n", i,  argv[i]);
  return 0;
}
