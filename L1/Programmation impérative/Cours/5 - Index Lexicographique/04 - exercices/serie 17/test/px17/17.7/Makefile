# definition de variables 
CC = gcc
CFLAGS = -Wall -std=gnu99

EXEC = cx17.7
SRC = cx17.7.c 

LIB = cx18.5.lib.c
LIBNAME = lib18.a

OBJ = cx18.5.lib.o

# regle all
all : $(EXEC)


# creation de l'executable
$(EXEC) : $(SRC) $(LIBNAME)
	$(CC) $(CFLsAGS) $(SRC) $(LIBNAME)  -o $(EXEC)

# Generation de la librairie
$(LIBNAME) : $(OBJ)
	ar -r $(LIBNAME) $(OBJ)
 
# Generafion du fichier objets de la librairie
$(OBJ) :  $(LIB) 
	$(CC) -o $(OBJ) -c $(LIB) 
