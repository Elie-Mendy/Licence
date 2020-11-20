void viderBuffer(){
  // definir un caractere
  char c = '\0';
  do {
    c = getchar(); // lecture en boucle d'un caractere dans le buffer
  } while(c != EOF && c != '\n'); // jusqu'a epuisement des caracteres
}





int lire(char * chaine, int taille){   // le but est de supprimer le '\n' en fin de saisie
  // initialisation d'un pointeur
  char * pointeur = NULL;
  if (fgets(chaine , taille, stdin)){
    // si la saisie est reussi
    // on recupére l'adresse du dernier caractères
    pointeur = strchr(chaine, '\n');
    // s'il a été trouvé: on remplace la valeur par '\0'
    if (pointeur)
      *pointeur = '\0';
    else
    // on vide le buffer
      viderBuffer();
    // on retourne une info de reussite
    return 1;
  }

  // si la saisie a échoué! on vide le buffer
  viderBuffer();
  //et on retourne0
  return 0;
}




int lireLong(){
  // on alloue un espace de saisie pour le nombreTxt
  char nombreTxt[100] = {0};

  // si la saisie utilisateur réussie :
  if (lire(nombreTxt, 100))
    // on retourne sous forme d'entier
    return strtol(nombreTxt, NULL, 10);

  // sinon on retourn 0;
  return 0;
}




void initialiser(Point * point){
  (*point).x = 0;
  point->y = 0;
}

void definirPersonne(Personne * individu){    // on passe l'adresse de la structure
  // on interroge l'user
  printf("Quel est votre nom? : ");
  // on midifie la caractéristique de la structure
  lire((*individu).nom, 50);                  // on cible (la structure a son adresse).sa_caractéristique

  printf("Quel est votre prenom? : ");
  lire((*individu).prenom, 50);

  printf("Quel est votre age? : ");
  individu->age = lireLong();

  printf("Quel est votre adresse? : ");
  lire((*individu).adresse, 50);

  printf("Quel est votre compte en banque? : ");
  individu->argent = lireLong();
}
