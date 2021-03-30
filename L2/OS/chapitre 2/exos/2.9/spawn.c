
/* FONCTION spawn()
  --> lance un processus qui execute le fichier
*/
int spawn (char * fichier, char * arg[]){
  int t;
  t = fork();
  // ERREUR fork
  if (t < 0){
    exit(1);
  }

  // ENFANT
  if(t == 0) {
    execvp(fichier ,arg);
    // ERREUR execl
    exit(1);
  }

  // PARENT
  return t;
}
