# definition de variables 
CC = gcc
CFLAGS = -Wall -g -std=gnu99

DEBUGGEUR = cx25.1
SRC = ordinateur_en_papier.c 


# regle all
all : $(DEBUGGEUR) 


# creation de l'executable [mode DEBUG]
$(DEBUGGEUR) : $(SRC) 
	$(CC) $(CFLAGS) $(SRC) -o $(DEBUGGEUR)
