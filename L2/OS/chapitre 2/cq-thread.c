/* cq−thread.c
Simple creation de threads
*/


// IMPORTS

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>   // pour sleep
#include <assert.h>
#include <pthread.h> // indiquer explicitement a la compilation la ligne ci dessous
                     // gcc -g -Wall cq-thread.c -lpthread


enum {
  Nthread = 3,
  Nfois = 10,
};


// fonction qui ...
static void * foo(void * arg) {
  // declaration de variables
  int i;
  int t;
  char * name = arg;

  for ( i = 0 ; i < Nfois ; i++) {
    t = rand() %5;
    printf("%s: je dors %d secondes\n", name, t );
    sleep(t);
  }
  printf("%s j'ai fini , merci\n", name);
  return arg;
}


int main() {

  static char * name[Nthread] = { "thread 0", "thread 1", "thread 2" };
  pthread_t id[Nthread];
  void * junk[Nthread];
  int i;

  printf("main: creation de %d threads\n", Nthread );
  for(i = 0; i < Nthread; i++)
    pthread_create(&id[i], 0, foo, name[i]);

  printf( "On attend la fin des trois threads\n");
    for( i = 0; i < Nthread; i++){
      pthread_join(id[i], &junk[i]);

      // allocation d'un pointeur pour caster junk[i]
      char * p = junk[i];
      printf( "main: %s est termine\n", p) ;
  }
  return 0;
}
