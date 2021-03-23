#include <stdio.h>
#include <unistd.h>


char * tab[] = { "commande", "arg1", "arg2", 0};

int main(int argc, char const *argv[]) {
  execv("/bin/echo", tab);
  perror("en essayant de faire execv");
  return 1;
}
