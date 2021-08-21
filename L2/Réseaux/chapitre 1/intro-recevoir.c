#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <netdb.h>
#include <unistd.h>
#include <ctype.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <assert.h>

/* try −− verifie qu'un appel systeme s'est bien passe */
void try(int resultat, char *name)
{
    if (resultat < 0)
    {
        perror(name);
        exit(1);
    }
}

/* traiter −− recevoir un fichier */
char *traiter(char in[], int ln)
{
    static int compte;
    static char reponse[20];

    try(write(1, in, ln), "write");
    compte += ln;
    snprintf(reponse, sizeof reponse, "%d\n", compte);
    return reponse;
}

int main(int ac, char *av[])
{
    struct addrinfo souhait, *info;
    int guichet, data, t;
    char buffer[1024], *reponse;

    if (ac != 2)
    {
        fprintf(stderr, "usage: %s port\n", av[0]);
        exit(1);
    }

    // formatter l ' adresse
    memset(&souhait, 0, sizeof souhait);
    souhait.ai_family = AF_UNSPEC;
    souhait.ai_socktype = SOCK_STREAM;
    souhait.ai_flags = AI_PASSIVE;
    if ((t = getaddrinfo(0, av[1], &souhait, &info)) != 0)
    {
        fprintf(stderr, "erreur %s sur le port %s\n", gai_strerror(t), av[1]);
        exit(1);
    }

    // fabriquer la socket et y obtenir une connexion (sur une autre socket)
    try(guichet = socket(info->ai_family, info->ai_socktype, info->ai_protocol),
        "socket");
    try(bind(guichet, info->ai_addr, info->ai_addrlen), "bind");
    try(listen(guichet, 1), "listen ");
    try(data = accept(guichet, 0, 0), "accept");
    try(close(guichet), "close");

    // lire , traiter , répondre
    while ((t = read(data, buffer, sizeof buffer)) > 0)
    {
        reponse = traiter(buffer, t);
        try(write(data, reponse, strlen(reponse)), "write");
    }

    try(t, "read");
    exit(0);
}
