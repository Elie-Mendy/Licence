#!/usr/bin/python3
# coding : utf8

""" programme servant à comparer deux nombre
    en representation en Complement à 2 """


from sys import *

# confirmation de la saisie des deux nombre
if len(argv) < 3 :
    print("vous n'avez pas saisi deux nombres à comparer")
    exit(1)

# transformation des deux nombres en liste de bits
# (entiers 1 ou 0)
nb1 = [int(x) for x in list(argv[1])]
nb2 = [int(x) for x in list(argv[2])]


def comparaison(a,b):
    # si le bit de poid le plus fort des deux nombres n'est pas égal
    #   le nombre négatif dont ce bit = 1 est le plus petit
    # sinon c'est l'inverse
    if a[0] != b[0]:
        if a[0]  < b[0]:
            return True
        else: return False

    # pour le restant des bits
    # (partie suivant le bit de poid le plus fort)
    # on parcourt de gauche à droite les nombre en comparants les bits
    # si deux bits diffèrent :
    #    le nombre dont le bit 0 est le plus petit des deux
    for i in range (1,8):
        if a[i] != b[i]:
            if a[i] < b[i]: return False
            else : return True

    print("les deux nombres sont egaux")
    exit(0)


if comparaison(nb1, nb2):
    print(f"\n{argv[1]} > {argv[2]}\n")
else : print(f"\n{argv[1]} < {argv[2]}\n")
