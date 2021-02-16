
// MESSAGE D'ERREUR (sur flux stderr)
void usage(char * message);

// CONSTRUCTION D'UNE LISTE
list cons(char * car, list L);

// AFFICHAGE D'UNE LISTE (a l'endroit)
void putlist(list L);

// RENVOI LA TAILLE D'UNE LISTE
int length(list L);

// CONVERSION Table en Liste
list table_to_list(char **);

// CONVERSION List en Table
char ** list_to_table(list);
