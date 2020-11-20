/* fonctions utilisés dans le tp perso sur la saisie de texte */

void usage(char * message){
  printf("%s\n",  message);
  exit(1);
}

void viderBuffer(){
  char c = 0;
  do {
    c = getchar();
  } while(c != EOF && c != '\n');
}


int lire(char * chaine, int taille){
  // on initialise un pointeur
  char * pointeur = NULL;
  // si la saisie reussi
  if (fgets(chaine, taille, stdin)){
    // on cherche le caractère '\n' pour le remplacer par '\0'
    pointeur = strchr(chaine, '\n');
    if (pointeur)
      *pointeur = '\0';
    else
      viderBuffer();
    // si tout est ok :
    return 1;

  }
  // si saisie n'a pas reussi:
  viderBuffer();
  return 0;
}


int lireLong(){
  char nb[100];
  if (lire(nb, 100))
    return strtol(nb, NULL , 10);
  else
    return 0;
}

void definirJoueur(Joueur * player){
  // demander un info à l'user
  printf("Quel est le nom de votre personnage? : ");
  // lire sa saisie de l'user
  lire(player->nom, 50);

  printf("Quel est le prenom de votre personnage ? ");
  lire(player->prenom, 50);

  printf("Quel age a votre personnage ? ");
  player->age = lireLong();


  printf("Quelle est la classe de votre personnage ? \n");
  printf("Magicien : 1\n");
  printf("Guerrier : 2\n");
  printf("Archer   : 3\n");

  player->classe = lireLong() - 1;
}
