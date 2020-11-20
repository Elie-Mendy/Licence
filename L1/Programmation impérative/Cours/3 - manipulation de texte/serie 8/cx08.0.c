#include <stdlib.h>
#include <stdio.h>

void scan_x(char *);

int main(int argc, char const *argv[]) {
  char chaine[] = "Data";

  scan_x(chaine);

  return 0;
}


void scan_x(char * chaine){
  while (*chaine) printf("%c\n", *chaine++);
}
