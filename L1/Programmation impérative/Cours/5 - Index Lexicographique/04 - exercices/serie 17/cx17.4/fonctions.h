
// imprime un message d'erreur sur le flux fprintf
void usage(char * message);

// LECTURE D'UNE STOPLIST
void lire_stoplist(char * liste);


// INDEXATION D'UNE LIGNE DE TEXTE
void indexe( char * ligne, idx ref);

// EXCLUSION D'UN MOT (si présent dans la stoplist)
int exclure(str mot);

// RECUPERATION DE L'INDICE (mot indéxé)
int indice(str mot);

// AJOUT d'UN NOUVEAU MOT
void ajoute_mot(idx x, str mot, idx ref);


// AJOUT d'UNE REF (mot existant)
void ajoute_ref(idx x, idx ref);

// COMPARAISON DE DEUX CHAINES
bool pareil(str x, str y);

// FOCNTION DE TRI DE DEUX MOTS
int compare(ndex *, ndex *);

// AFFICHAGE DES VALEURS DE L'INDEX
void dump(idx k);
