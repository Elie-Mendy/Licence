/* Fichier regrouppant les fonctions du jeu de pendu par Openclassroom */

char lireCaractere(){
  char lettre = toupper(getchar());
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
