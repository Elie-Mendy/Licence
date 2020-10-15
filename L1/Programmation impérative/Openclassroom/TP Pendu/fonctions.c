/* Fichier regrouppant les fonctions du jeu de pendu par Openclassroom */

void usage (char * message){
  printf("%s\n", message);
  exit(1);
}


char lireCaractere(){
  char lettre = toupper(getchar());
  // On lit les autres caractères mémorisés un à un jusqu'au \n (pour les effacer)
  while (getchar() != '\n') ;

  return lettre;
}

int diff(char * mot1, char * mot2){
  size_t i = 0;
  for (i = 0 ; i < strlen(mot1) ; i++){
    if (mot1[i] != mot2[i])
      return(1);
  }
  return 0;
}


int compterMots(FILE * fichier){
  int i = 0;
  char c = 0;
  do {
    c = fgetc(fichier);
    if (c == '\n')
      i++;
  } while(c != EOF);

  return i;
}

void placerCurseur(FILE * fichier, int ligne){
  rewind(fichier);
  char c = 0;
  while(ligne){
    c = fgetc(fichier);
    if (c == '\n')
      ligne --;
  }
}
