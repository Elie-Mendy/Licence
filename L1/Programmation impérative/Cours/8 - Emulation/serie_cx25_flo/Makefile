# definition de variables 
CC = gcc
CFLAGS = -Wall -std=gnu99

AUTO = op_auto
STEPPER = op_stepper
NO_DEBUG = op_nodebug
SRC = ordinateur_en_papier.c 


# regle all
all : $(AUTO) $(STEPPER) $(NO_DEBUG) 


# creation de l'executable [mode AUTO]
$(AUTO) : $(SRC) 
	$(CC) $(CFLAGS) $(SRC) $(LIBNAME)  -o $(AUTO)


# creation de l'executable [mode STEPPER]
$(STEPPER) : $(SRC) 
	$(CC) $(CFLAGS) -D STEPPER $(SRC) -o $(STEPPER)


# creation de l'executable [mode NODEBUG]
$(NO_DEBUG) : $(SRC) 
	$(CC) $(CFLAGS) -D NO_DEBUG $(SRC) $(LIBNAME)  -o $(NO_DEBUG)
