# definition de variables 
CC = gcc
CFLAGS = -Wall -std=gnu99

EXEC = cx17.8
SRC = cx17.8.c

LIB = cx18.5.lib.c
LIBNAME = lib18.so
LDFLAGS = -fpic -shared


# regle all
all : $(EXEC)



# creation de l'executable
$(EXEC) : $(SRC) $(LIBNAME)
	$(CC) $(CFLAGS) $(SRC) $(LIBNAME)  -o $(EXEC)


# Generation de la librairie
$(LIBNAME) : $(LIB)
	$(CC) $(CFLAGS) $(LDFLAGS) $(LIB) -o $(LIBNAME)
 

# au lancement 
# LD_LIBRARY_PATH=. cx17.8 indexe-moi.texte 
