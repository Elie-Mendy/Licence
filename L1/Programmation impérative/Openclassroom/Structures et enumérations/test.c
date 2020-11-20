// fichier contenant les fonctions de modification de structures et d'énumérations

void initialiser(Point * point){
  (*point).x = 0;
  point -> y = 0;
}

void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}



int lire(char * chaine, int taille){
  char *pointeur = NULL;
  if (fgets(chaine, taille, stdin)){
    pointeur = strchr(chaine, '\n');
    if (pointeur)
      *pointeur = '\0';
    else
      viderBuffer();
    // retourner 1
    return 1;
  }

  viderBuffer();
  // retourner 0;
  return 0;
}


int lireLong(){
  char nombreTxt[100] = {0};
  if (lire(nombreTxt, 100))
    return strtol(nombreTxt, NULL, 10);
  else
    return 0;
}


void definirPersonne(Personne * individu){    // on passe l'adresse de la structure
  // on interroge l'user
  printf("Quel est votre nom? : ");
  // on midifie la caractéristique de la structure
  lire((*individu).nom, 50);                  // on cible (la structure a son adresse).sa_caractéristique

  printf("Quel est votre prénom? : ");
  lire((*individu).prenom, 50);

  printf("Quel est votre adresse?  : ");
  lire((*individu).adresse, 500);

  printf("Quel age avez vous ? : ");
  (*individu).age = lireLong();

  printf("Combien voullez vous miser ? : ");
  (*individu).argent = lireLong();
}
