void usage(char * message){
  printf("usage : %s\n", message );
  exit(1);
}
//  retour d'une valeur logique
int option_i(char * mot){
  return (mot[0] == '-' && mot[1] == 'i' && strlen(mot) == 2);
}


// affichage d'une liste de mots
void afficher(char * liste[]){
  while(*++liste){ printf("%s\n", *liste);};
}



void retourner(char * liste[], int nb){
  while(--nb && nb > 0){
    if ( ! option_i(liste[nb]))
      printf("%s\n", liste[nb]);
  }
}
