/* fichier regrouppant les fonctions créées dans l'exercice sur les tableaux OC */


// EXECICE 1:
int sommeTableau(int * tab, int taille){
  int i = 0, result = 0;
  for (i = 0; i < taille ; i++)
    result += tab[i];
  return result;
}

// EXERCICE 2:
int moyenneTableau(int * tab, int taille){
  return sommeTableau(tab, taille) / taille;
}

// EXERCICE 3:
void copierTableau(int * tab , int * copie, int taille){
  int i;
  for ( i = taille-1; i >= 0 ; i -- )
    copie[i] = tab[i];
}


// EXERCICE 4:
int maximumTableau(int * tab, int taille){
  int i, max = 0;
  for (i = 0 ; i < taille ; i++){
    if (tab[i] > max) max = tab[i];
  }
  return max;
}


// EXERCICE 5:
void trierTableau(int * tab, int taille){
  // condition de tri
  int tri = 0;
  int i = 0;
  int tmp = 0;

  while (tri = 0){
    tri = 1;
    for (i = 0 ; i < taille ; i++){
      if (tab[i] > tab[i+1]){
        tmp = tab[i+1];
        tab[i+1] = tab[i];
        tab[i] = tmp;
        tri = 0;
      }
    }
    taille --;
  }
}
