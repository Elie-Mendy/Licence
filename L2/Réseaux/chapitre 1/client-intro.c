/* client −intro.c */
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

int main(int ac, char *av[])
{
	struct addrinfo souhait, *info;
	int sock, t;
	char buffer[1024];
	if (ac != 3)
	{
		fprintf(stderr, "usage: %s machine port\n", av[0]);
		exit(1);
	}
	// formatter l ' adresse
	memset(&souhait, 0, sizeof souhait);
	souhait.ai_family = AF_UNSPEC;
	souhait.ai_socktype = SOCK_STREAM;
	if ((t = getaddrinfo(av[1], av[2], &souhait, &info)) != 0)
	{
		fprintf(stderr, "erreur %s sur %s:%s\n", gai_strerror(t), av[1], av[2]);
		exit(1);
	}

	// fabriquer la socket et la connecter
	try(sock = socket(info-> ai_family, info-> ai_socktype, info-> ai_protocol),
			"socket");
	try(connect(sock, info-> ai_addr, info-> ai_addrlen), "connect");
	
	// transferer
	while ((t = read(0, buffer, sizeof buffer)) > 0)
	{
		write(sock, buffer, t);
		if ((t = read(sock, buffer, sizeof buffer)) <= 0)
			break;
		write(1, buffer, t);
	}
	try(t, "read");
	exit(t < 0);
}