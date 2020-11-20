#! /usr/bin/env python3

""" prototype d'indexation de texte """

dico = {}


with open("texte.txt", "r") as fichier :
    for (i , ligne) in enumerate(fichier):
        for mot in ligne.split():
            if dico.get(mot):
                if i+1 not in dico[mot]:
                    dico[mot] += [i + 1]
            else :
                dico[mot] = [i + 1]

    for mot in sorted(dico):
        print(f"{mot} : {dico[mot]}")


# manque ajout de la stopliste ...
# manque suppréssion de la ponctuation
# blablabla
