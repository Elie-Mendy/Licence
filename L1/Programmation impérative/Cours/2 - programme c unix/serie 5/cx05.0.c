#include <stdio.h>
void putwords(const char * mots[]) { while (*mots) puts(*mots++) ; }
int main(int k, const char * argv[]) { putwords(argv) ; return 0 ; }
