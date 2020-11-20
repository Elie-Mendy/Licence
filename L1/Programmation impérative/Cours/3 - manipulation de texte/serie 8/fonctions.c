void scan_r(char * chaine){
  while (*chaine) printf("%c\n", *chaine++);
}

unsigned int size_x(char * chaine){
  unsigned int taille = 0;
  while(*chaine++) taille++;
  return taille;
}


void usage(char * message) { printf("usage : %s\n", message ); exit (1);}
