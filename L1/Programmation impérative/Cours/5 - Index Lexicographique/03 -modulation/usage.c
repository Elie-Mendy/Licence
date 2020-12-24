#ifndef USAGE
#define USAGE

// imprime un message d'erreur sur le flux fprintf
void usage(char * message){ fprintf(stderr, "Usage : %s\n", message), exit(1) ;}

#endif
