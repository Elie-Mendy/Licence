#! /usr/bin/env python3
""" ENNONCE :

Écrire un programme pour multiplier deux nombres représentés en base 10 et en
virgule flottante entre eux. Penser à normaliser le résultat
de façon à n’avoir qu’un seul chiffre à gauche de la virgule dans le résultat.
"""
# IMPORT DE MODULES
import re


# Liste d'exemles
exemples = (
    "1 x 10^0" ,
    "2.1 x 10^8" ,
    "4.9 x 10^-8" ,
    "57.6 x 10^885",
    "8 x 10^8",
    "9586 x 10^-7856")



# DEFINITION DE FONCTIONS:
def exemple():
    print("\nCi dessous une liste d'exemple traduisant le format :")
    print("(ce format suit l'expression régulière suivante) -->    [0-9.]+ x 10\^-?[0-9]+\n")
    for exemple in exemples: print("\t"+exemple)
    print("\n\n")


def formattage(m, e):
    """ fonction appelée pour formater le résultat de la multiplication
    on souhaite obtenir le résultat sous une notation scientifique """

    # decoute de la mantisse
    if "." in m:
        a, b = m.split(".")
        # a constitue la partie entière de la mantisse
        # b constitue la partie décimale de la mantisse
    else:
        a = m
        b = 0


    # traitement de l'exposant
    e += (len(a) - 1)




    b = list(a[1:] + b)                     # convertion en liste de la partie fractionnelle
    a = int(a[0])                           # la partie entière de la mantisse sera le chiffre de rang le plus elevé


    # décalage à droite si la mantisse est inférieur à 1
    if a == 0:
        while b[0] == '0':        # tant qu'on parcour des zero dans b
            b.pop(0)                 # on les supprime
            e -= 1                   # on décrémente l'exposant

        a = int(b[0])             # a prend la valeur du premier chiffre
        b = b[1:]                 # b prend la valeur de la suite de la liste
        e -= 1                    # on décrémente l'exposant

    # arrondissement
    if len(b) > 1:                          # si la partie fractionnelle comporte plus d'un chiffre
        if int(b[1]) > 5:                       # et si le deuxieme chiffre est plus grand que 5
            if int(b[0]) < 9 :                      # alors si le premier est inférieur à 9
                b = str(int(b[0]) + 1)                  # on l'incrémente de 1
            else :                                  # sinon (si le premier est un neuf )
                a += 1                                  # on incrémente a de 1
                b = str('0')                              # on met le premier chiffre de la partie fractionnelle a 0



    new_mantisse = str(a) + "." + b[0]
    # on retourne le résultat
    return f"{new_mantisse} x 10^{e}"








# SAISIE DE DEUX NOMBRES SELON UN FORMAT
# (format précisé dans l'aide [0-9.]+ x 10\^-?[0-9]+)
print("\n\nMultiplication de deux nombre en base 10 représentés en virgule flottantes")
print("(pour mieux comprendre le format attendu veuillez tapper  'format' )\n");

print("\n\nveuillez saisir le premier nombre:")
n1 = input("\tnombre 1 = ")

# verification du format
while not re.fullmatch("[0-9.]+ x 10\^-?[0-9]+", n1):
    # affiche une aide si l'utilisateur le demande
    if n1 == 'format' :
        exemple()
        print("\n\nveuillez réécrire le premier nombre :")
        n1 = input("\tnombre 1 = ")
        continue

    # si le format est incorrect, l'utilisateur doit ressaisir le nombre
    print("\n\nformat saisi incorrect, veuillez réécrire le premier nombre:")
    n1 = input("\tnombre 1 = ")


print("\n\nveuillez saisir le deuxieme nombre:")
n2 = input("\tnombre 2 = ")
while not re.fullmatch("[0-9.]+ x 10\^-?[0-9]+", n1):
    # affiche une aide si l'utilisateur le demande
    if n2 == 'format' :
        exemple()
        print("\n\nveuillez réécrire le deuxième nombre :")
        n2 = input("\tnombre 2 = ")
        continue

    # si le format est incorrect, l'utilisateur doit ressaisir le nombre
    print("\n\nformat saisi incorrect, veuillez réécrire le deuxieme nombre:")
    n2 = input("\tnombre 2 = ")






# récupération des mantisses et exposants des nombres 1 et 2
m1 , e1 = n1.split(sep=' x 10^')
m2 , e2 = n2.split(sep=' x 10^')


# détermination mathématique du résultat
mantisse = str(float(m1) * float(m2))   # mantisse dans une chaine
exposant = int(e1) + int(e2)            # exposant en tant qu'entier


# formatage du résultat
print(f"\n\nnombre 1  x nombre 2    =     {formattage(mantisse, exposant)}\n\n")
