#!/usr/bin/python3
# coding: utf-8


"""
        RAPPEL DES REGLES DE NUMEROTATATION ROMAINE

1 - Un nombre en chiffres romains se lit de gauche à droite ;

2 - Un même symbole n'est pas employé quatre fois de suite (sauf M);

3 - Tout symbole qui precede un symbole de valeur supérieure ou égale
    s'ajoute à celui ci (exemple : 6 s'écrit VI)

4 - Tout symbole qui précède un symbole de valeur supérieure
    se sousrtait à ce dernier ;
        (exemple : 9 s'ecrit IX)
        (exemple : 40 s'écrit XL)
        (exemple : 49 s'écrit XLIV)

5 - Les symboles sont groupés par ordre décroissant, sauf pour les valeurs
    à retrancher selon la règle précédente
        (exemple : 1030 s'écrit MXXX)

sources:
http://www.raoulblanchard.fr/wp-content/uploads/2017/06/Article_Oma%C3%AFma_Sol%C3%A8ne_Victoire_In%C3%A8s.pdf
https://fr.wikipedia.org/wiki/Num%C3%A9ration_romaine#Modes_de_repr%C3%A9sentation
"""

# definition de la fonctions convertir -------------

def convertir(nombre):
    """ fonction appelée pour traiter la conversion d'un chiffre
        en chiffre romain selon sa position en representation arabes """


    # inverser la chaine pour commencer par le traitement des unitées
    nombre = "".join(reversed(nombre))
    # initialisation du nombre à renvoyer
    num_rommain = []

    # parcour du nombre pour le convertir
    for i , nb in enumerate(nombre, 1) :

        if i == 1 :#  --> resolution des unitées
            # si zero - passe
            if nb == "0" : pass
            # sinon si nb < 3 : on écrit n fois "I"
            if nb <= "3":
                for i in range(int(nb)): num_rommain.insert(0, "I")
            # sinon si nb = 4 : on écrit "IV"
            elif nb == "4" : num_rommain.insert(0, "IV")

            # sinon si nb < 8 : on soustrait 5 à nb , "V" + "I" fois nb
            elif nb <= "8" :
                for i in range(int(nb) - 5): num_rommain.insert(0, "I")
                num_rommain.insert(0, "V")
            # sinon si nb = 9 : on écrit "CM" - ecrire "IX"
            elif nb == "9" : num_rommain.insert(0, "IX")



        elif i == 2 : # --> resolution des dizaines
            # si zero - passe
            if nb == "0" : pass
            # sinon si nb < 3 : on écrit n fois "X"
            elif nb <= "3":
                for i in range(int(nb)): num_rommain.insert(0, "X")
            # sinon si nb = 4 : on écrit "XL"
            elif nb == "4" : num_rommain.insert(0, "XL")
            # sinon si nb < 8 : on soustrait 5 à nb , "L" + "X" fois nb
            elif nb <= "8" :
                for i in range(int(nb) - 5): num_rommain.insert(0, "X")
                num_rommain.insert(0, "L")
            # sinon si nb = 9 : on écrit "CM" - ecrire "XC"
            elif nb == "9" : num_rommain.insert(0, "XC")



        elif i == 3 : # --> resolution des centaines
            # si nb = 0: on passe
            if nb == "0" : pass
            # sinon si nb < 3 : on écrit n fois "C"
            if nb <= "3":
                for i in range(int(nb)): num_rommain.insert(0, "C")
            # sinon si nb = 4 : on écrit "CD"
            elif nb == "4" : num_rommain.insert(0, "CD")
            # sinon si nb < 8 : on soustrait 5 à nb , "D" + "C" fois nb
            elif nb <= "8" :
                for i in range(int(nb) - 5): num_rommain.insert(0, "C")
                num_rommain.insert(0, "D")
            # sinon si nb = 9 : on écrit "CM" - ecrire "CM"
            elif nb == "9" : num_rommain.insert(0, "CM")



        elif i == 4 : # --> résolution des milliers
            # on écrit nb fois "M" (4 maxi)
            if int(nb) > 4 : return "on ne peut exprimer ce chiffre par la numerotation romaine\nle chiffre maximal est 4999 \n\n-->soit la representation suivante: MMMMCMXCIX\n\n"
            else :
                for i in range(int(nb)) : num_rommain.insert(0, "M")


    print("\n"+"".join(num_rommain))




# script -------------------------------------------

nombre = input("veuillez saisir un nombre à convertir en chiffres romains: ")
convertir(nombre)
