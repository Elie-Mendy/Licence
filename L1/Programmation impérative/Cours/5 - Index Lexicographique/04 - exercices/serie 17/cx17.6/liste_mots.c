/* Fichier rassemblant l'implétentation d'une structure de liste elastique
 * pouvant contenir des ===>  CHAINES DE CARACTERES  <===
 * comprenant les fonctions suivantes :
    - construction de liste d'entiers
    - renvoyer la taille d'une liste d'entiers
    - controler la présence d'un entier dans une liste d'entiers
    - afficher le contenu d'une liste d'entiers
    */



// CONSTRUCTION D'UNE LISTE
stp cons_w(char * car, stp L){
  stp new = malloc(sizeof(wd_list));
  if (!new) usage("cons : manque de RAM") ;
  new -> car = car;
  new -> cdr = L;
  return new; }

// FONCTION 'IN'
// vérifie la présence d'une ref dans une liste
// affichage des valeurs de la liste
int in_w(char* mot ,stp L){
  while(L){
    if (strcmp(L -> car, mot) == 0) return 1;
    L = L->cdr;
  }
  return 0;
}

// RENVOI LA TAILLE D'UNE LISTE
int length_w(stp L){
  int n = 0;
  if (L->car) n++;
  while (L->cdr){
    L = L->cdr;
    n++;
    }
    return n;
  }


// AFFICHAGE D'UNE LISTE (a l'endroit)
void putlist_w(stp L){
  // recuperation de la taille de la liste
  int n = length_w(L), i;

  // allocation dynalique d'un vecteur qui contiendra les elements de la liste
  char **v;
  v = malloc(n * sizeof(char *));
  if (! v) usage("usage : impossible d'allouer l'espace en mémoire pour stoquer les éléments de la liste");

  // boucle de lecture de la liste
  for (i = n -1 ; i >= 0 ; i--){
    v[i] = L-> car;
    L = L-> cdr;
  }
  // affichage des elements récupérés
  for( i = 0 ; i < n; i++){
    printf("%i : %s\n",i+1,v[i]);
  }
  puts("");

}



// CONVERSION Table en Liste
stp table_to_list_w(char * table[]){
  // definition d'une liste vide
  stp L = nil;
  // recuperation de la taille du tableau
  int n = 0;
  while(table[n]) n++;
  // remplissage de la liste
  int i = 0;
  for (i = 0 ; i < n  ;i++){
    L = cons_w(table[i], L);

  }

  return L;
}
