void scan_r(char * chaine){
  while(*chaine) printf("%c\n", *chaine++ );
}


int size_r(char * chaine){
  int i = 0;
  while (*chaine++) i++;
  return i;
}


void usage(char * message){
  printf("%s\n",  message);
  exit(1);
}
