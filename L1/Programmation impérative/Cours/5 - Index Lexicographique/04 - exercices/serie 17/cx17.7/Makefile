# definition de variables 
CC = gcc
CFLAGS = -Wall

EXEC = cx17.7
SRC = cx17.7.c 

LIB = cx18.5.lib.c
LIBNAME = lib18.a

OBJ = cx18.5.lib.o

# regle all
all : $(EXEC)


# creation de l'executable
# 	gcc -Wall cx18.5.o lib18.a -o cx17.7
$(EXEC) : $(SRC) $(LIBNAME)
	$(CC) $(CFLsAGS) $(SRC) $(LIBNAME)  -o $(EXEC)


# Generation de la librairie
# 	ar -r lib18.a cx18.5.lib.o
$(LIBNAME) : $(LIB)
	$(CC) $(CFLAGS) $(LDFLAGS) $(LIB) -o $(LIBNAME)
 

# Generafion du fichier objets de la librairie
$(OBJ) : %.c $(LIB) 
	$(CC) -o $(OBJ) -c $(LIB) 
