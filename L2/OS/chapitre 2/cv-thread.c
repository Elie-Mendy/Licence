/* cv−thread.c
Des threads simplifies a l ' extreme
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Ctxt Ctxt

enum {
  StackSize = 1024, // taille de la pile
};

struct Ctxt {
  int ebp;      // frame pointer
  int esp;      // stack pointer
  int edi, esi, ebx;    // registre a sauver : edi, esi,
                        // ebx eax, edx ont été sauvé par l'appelante
  char * name ; // purement informatid
  int stack[StackSize] ;  // de l'espace pour la pile
};

Ctxt ctxt[2];   // deux threads
Ctxt * curthread;   // le thread courant
Ctxt original;      // le thread original

void save(Ctct*);   // en assembleur dans swtch.s
void restore(Ctxt*);


void sched(void);   // dans la suite du code
