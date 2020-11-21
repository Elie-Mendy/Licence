#!/usr/bin/python3
# coding: utf8


"""
Nom: MENDY      Prenom: Elie         ID: 19004664
"""



# liste non exhaustive, voir le commentaire laissé sur le readme.pdf
stoplist = "le la les un une des du de ce cet cette ces mon ton son ma ta sa notre votre leur mes tes ses nos vos en au leurs quel quelle quelles quels je tu il lui nous vous ils elle elles me te se qui que quoi ne mais ou est donc or ni car et eh".split()



""" Code issue du notebook """

def pilote(fichier, idx):
    with open(fichier, 'r', encoding='utf8') as fp:
        # on itere sur le fichier ligne par ligne
        for i, ligne in enumerate(fp):
            indexe(idx, ligne.split(), i)

def ajoute(idx, mot, ligne):
    # si le mot ne se trouve pas encore dans l'index,
    # initialise les occurences par une liste vide
    if mot not in idx:
        idx[mot] = []
    # si la ligne n'a pas encore ete enregistree pour ce mot
    if ligne not in idx[mot]:
        # on ajoute le numero de ligne correspondant au mot
        idx[mot].append(ligne + 1)

def indexe(idx, mots, ligne):
    # on itere sur les mots
    for mot in mots:
        # met obligatoirement en minuscule
        mot = mot.lower()
        # nettoyage du mot, voir ci-apres
        mot = nettoie(mot)
        # on en profite pour verifier si on veut
        # vraiment indexer ce mot
        if mot and mot not in stoplist:
            ajoute(idx, mot, ligne)




""" fonctions à definir """

def nettoie(mot):
    if "aujourd'hui" in mot: return "aujourdh'hui"
    if "'" in mot:  mot = mot.split("'")[1]     # nettoyage de l'apostrophe avant un mot
    caracteres = []                             # liste 'caracteres' servant a construire le mot nettoyé
    for lettre in mot:                          # pour chaques symboles du mot
        if lettre not in '(,.!?;\'")':               # si ce n'est pas un symbole de ponctuation
            caracteres.append(lettre)               # on ajoute ce caractere a la list 'caracteres'
    return "".join(caracteres)                  # on retourne le mot nettoyé



def presente(lst):
    debut = lst[0]          # debut d'un interval (par defaut égal a la première ligne ou se trouve le mot)
    fin = lst[0]            # fin d'un interval
    intervalle =[""]        # creation de la liste des intervalles a renvoyer

    for ligne in lst:                                          # pour chaques lignes ecrites dans la liste
        if ligne == debut:                                             # si la ligne est le début de l'interval traité
            intervalle[-1] = str(debut)                                   # on initialise un nouvel interval
        elif ligne == fin + 1:                                         # sinon si on est a la ligne qui suivante
            fin = ligne                                                   # la var 'fin' prend la valeur de 'ligne'
            intervalle[-1] = '{}-{}'.format(debut, fin)                   # on agrandi l'interval que l'on construit,
        else:                                                          # sinon
            fin  = ligne                                                  # la var 'fin' prend la valeur de 'ligne'
            debut = ligne                                                 # la var 'debut' prend la valeur de 'ligne'
            if debut == fin:                                              # si l'intervalle ne fait qu'une ligne
                intervalle.append(str(debut))                                # on l'ajoute a la liste 'intervalle' tel une chaine de caractere
            else:                                                         # si l'interval est plus consequent
                intervalle.append('{}-{}'.format(debut, fin))                # on ajoute l'intervale créé dans la liste 'intervalle' dans le format souhaité "debut-fin"

    return ", ".join(intervalle)    # on retourne la liste de nos intervales de lignes au format souhaité




def prd(idx):
    for mot in sorted(idx):
        idx[mot] = presente(idx[mot])                       # transformation de la liste des lignes par presente()
        print('\t', mot, ':', idx[mot])                     # affichage des mots du dictionaires



""" partie script """

index = {}
pilote('cigale_fourmi.txt', index)
prd(index)
