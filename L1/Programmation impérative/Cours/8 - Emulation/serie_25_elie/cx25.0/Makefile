# definition de variables 
CC = gcc
CFLAGS = -Wall -g -std=gnu99

DEBUG = cx25.0.debug
NO_DEBUG = cx25.0
SRC = ordinateur_en_papier.c 


# regle all
all : $(DEBUG) $(NO_DEBUG) 


# creation de l'executable [mode DEBUG]
$(DEBUG) : $(SRC) 
	$(CC) $(CFLAGS) $(SRC) -o $(DEBUG)


# creation de l'executable [mode NODEBUG]
$(NO_DEBUG) : $(SRC) 
	$(CC) $(CFLAGS) -D NO_DEBUG $(SRC) -o $(NO_DEBUG)


