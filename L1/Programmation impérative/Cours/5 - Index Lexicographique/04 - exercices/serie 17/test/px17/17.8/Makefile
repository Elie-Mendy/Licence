# definition de variables 
CC = gcc
CFLAGS = -Wall

EXEC = cx17.8
SRC = cx17.8.c

LIB = cx18.5.lib.c
LIBNAME = lib18.so
LDFLAGS = -fpic -shared


# regle all
all : $(EXEC)



# creation de l'executable
# 	gcc -Wall cx17.8.c lib18.so  -o cx17.8
$(EXEC) : $(SRC) $(LIBNAME)
	$(CC) $(CFLAGS) $(SRC) $(LIBNAME)  -o $(EXEC)


# Generation de la librairie
# 	gcc -Wall -fpic -shared cx18.5.lib.c -o lib18.so
$(LIBNAME) : $(LIB)
	$(CC) $(CFLAGS) $(LDFLAGS) $(LIB) -o $(LIBNAME)
 

# au lancement 
# LD_LIBRARY_PATH=. cx17.8 indexe-moi.texte 
