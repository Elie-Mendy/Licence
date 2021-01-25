#!/usr/bin/python3
#coding : utf8

""" Programme dadditions de chiffres en representations rommaine """


# import de modules ------------------------------------------------

import sys

# definition de fonctions ------------------------------------------

def form_add(sub):
    """ transformation d'une representation en chiffre rommain
    vers la forme additive """
    add=""



    #900
    cm = sub.find("CM")
    if cm >= 0 :
        add += sub[:cm] + "DCCCC"
        sub = sub[cm+2:]

    #400
    cd = sub.find("CD")
    if cd >= 0 :
        add += sub[:cd] + "CCCC"
        sub = sub[cd+2:]

    #90
    xc = sub.find("XC")
    if xc >= 0 :
        add += sub[:xc] + "LXXXX"
        sub = sub[xc+2:]
    #40
    xl = sub.find("XL")
    if xl >= 0 :
        add += sub[:xl] + "XXXX"
        sub = sub[xl+2:]
    #9
    ix = sub.find("IX")
    if ix > -1 :
        add += sub[:ix] + "VIIII"
        sub = sub[ix+2:]
    #4
    iv = sub.find("IV")
    if iv >= 0 :
        add += sub[:iv] + "IIII"
        sub = sub[iv+2:]
    if (cm == cd == xc == xl == ix == iv == -1):
        add = sub
    else : add += sub

    return add

def sort_symboles(nb_rom):

    """ tri les symboles d'un nombre romain
    par ordre de grandeur """

    nb_trie= ""
    dico_symboles = {
        "M" : 0,
        "D" : 0,
        "C" : 0,
        "L" : 0,
        "X" : 0,
        "V" : 0,
        "I" : 0,
        }
    for lettre in nb_rom:
        dico_symboles[lettre] += 1
    for key, value in dico_symboles.items():
        while value > 0:
            nb_trie += key
            value -= 1

    return nb_trie

def combine_DLV(nb):
    """ combine les symboles "D" , "L" , "V"
    vers ordre de grandeur supérieur si doublon """

    nb_combine = ""

    #DD
    dd = nb.find("DD")
    if dd >= 0 :
        nb_combine += nb[:dd] + "M"
        nb = nb[dd+2:]

    #LL
    ll = nb.find("LL")
    if ll >= 0 :
        nb_combine += nb[:ll] + "C"
        nb = nb[ll+2:]

    #VV
    vv = nb.find("VV")
    if vv >= 0 :
        nb_combine += nb[:vv] + "X"
        nb = nb[vv+2:]

    nb_combine += nb
    return nb_combine

def form_sous(add):
    """ transformation d'une representation en chiffre romain(additive)
    vers la forme soustractive """

    symboles = {
        "M" : 0,
        "D" : 0,
        "C" : 0,
        "L" : 0,
        "X" : 0,
        "V" : 0,
        "I" : 0,
        }

    sub = ""
    for lettre in add:
        symboles[lettre] += 1

    unite = symboles["I"] + symboles["V"] * 5
    dizaines = symboles["X"] *10 + symboles["L"] * 5
    centaines = symboles["C"] *100+ symboles["D"] *5
    milliers = symboles["M"] * 1000

    sub += dico_valeurs[symboles["M"] * 1000]
    sub += dico_valeurs[symboles["D"] * 500]
    sub += dico_valeurs[symboles["C"] * 100]
    sub += dico_valeurs[symboles["L"] * 50]
    sub += dico_valeurs[symboles["X"] * 10]
    sub += dico_valeurs[symboles["V"] * 5]
    sub += dico_valeurs[symboles["I"]]

    return sub


# définition de variables ------------------------------------------
chiffre_1 = sys.argv[1]
chiffre_2 = sys.argv[2]

dico_valeurs = { 1: "I", 2: "II", 3: "III", 4: "IV", 5: "V",
                6: "VI",7: "VII", 8: "VIII", 9: "IX",
                10: "X", 20: "XX", 30: "XXX", 40: "XL", 50: "L",
                60: "LX", 70: "LXX", 80: "LXXX", 90: "XC",
                100: "C", 200: "CC", 300: "CCC", 400: "CD", 500: "D",
                600: "DC",700: "DCC", 800: "DCCC", 900: "CM",
                1000: "M", 2000: "MM", 3000: "MMM", 4000: "MMMM",
                0: "" }
# script -----------------------------------------------------------

#passer sous forme additives
nb_1 = form_add(chiffre_1)
nb_2 = form_add(chiffre_2)
#concatener les deux chiffres
resultat = nb_1 + nb_2

# trier les dico_symboles
resultat = sort_symboles(resultat)

# combiner les symboles combine_DLV
resultat = combine_DLV(resultat)

# passer sous forme soustractive
resultat = form_sous(resultat)

print(chiffre_1 , " + ", chiffre_2 , " = " , combine_DLV(resultat))
