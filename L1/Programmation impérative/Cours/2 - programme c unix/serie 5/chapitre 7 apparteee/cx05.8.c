// prototype de la fonction
void putwords(const char *[]) ;
int main(int k, const char * argv[]) { putwords(argv) ; return 0 ; }



/* DEMARCHE

gcc -c cx05.8.c cx05.9.c        // creation des fichier .o
ar -r libessai.a cx05.9.o       // creation de la library
gcc -Wall cx05.8.c libessai.a -o essai     // generation de l'executable

*/
