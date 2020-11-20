#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[]) {
  char * var1 = "azerty";
  char * var2 = "azerty";
  char * var3 = "azer";
  char * var4 = "azer";

  printf("adresses de var 1 :%p %c %p\n",&*var1, *var1, &var1);
  printf("adresses de var 2 :%p %c %p\n",&*var2, *var2, &var2);

  printf("adresses de var 3 :%p %c %p\n",&*var3, *var3, &var3);
  printf("adresses de var 4 :%p %c %p\n",&*var4, *var4, &var4);
  return 0;
}
