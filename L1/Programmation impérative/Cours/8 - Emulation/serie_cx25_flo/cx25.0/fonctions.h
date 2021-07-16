
void usage(str message);
void initialiserRegistres(int adresse);
void chargerProgramme(int adresse, char * fileName);
int hexaToInt(Hexa h[TAILLE_DATA] );
void intToHexa(Hexa * registre , int code );
int executer(int code) ;
void incrementerPC();
void afficherRegistre();