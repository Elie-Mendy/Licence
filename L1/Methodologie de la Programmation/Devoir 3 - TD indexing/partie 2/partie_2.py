#!/usr/bin/python3
# coding: utf8




"""
Nom: MENDY        Prenom: Elie         ID: 19004664
"""



# import de modules -----------------------------------------------
import requests


# definition de fonctions -----------------------------------------
def prd(idx):
    """ présentation du dictionnaire dans un fichier """

    with open('index.txt', 'w') as fichier:
        for mot in sorted(idx):
            fichier.write("\t {}:\n".format(mot))

            for lien in idx[mot]:
                fichier.write(" --> {}\n".format(lien))
            fichier.write("\n\n\n")



            #fichier.write("{} :\t{}\n".format(mot, idx[mot]))



def parcourir(biblioteque, limite):
    """ fonction utilisée pour gérer
        le parcours des pages web """

    i = 0
    while i < limite:
        if biblioteque[i] not in stop_url:                  # exception si url déja parcouru
            print(i+1, "\t:",biblioteque[i])                # affichage console des pages indexées
            pilote(biblioteque[i], index)                   # indexage
            i += 1                                          # nombre de repetitions - 1



def pilote(url, idx):
    """ fonction qui définit l'odre d'executions
        des autres sous fonction du programme
        TD_indexing_partie_2"""

    stop_url.append(url)                                    # ajout de l'url à la stopliste d'url
    c = requests.get(url)                                   # capture de la page
    contenu = c.text                                        # capture du contenu texte de la page
    extraire_liens(contenu)                                 # extraction des liens de la page
    contenu = nettoie_page(contenu)                         # nettoyage des balises html

    for ligne in contenu.split('\n'):                       # indexage des mots de la page web
        indexe(idx, ligne.split(), url)



def extraire_liens(page):
    """ fonction utilisée pour l'extractions
        des liens présent sur une page web """

    for ligne in page.split('\n'):
        x = ligne.find('href=')                                                 # utilisation de find() pour chercher un lien
        if x < 0 : pass
        ref = ligne[x+6:].split('"')[0]                                         # capture du lien dans la variable ref
        if "/css" in ref: continue
        if ref.startswith('https:') and ref not in biblioteque_liens:           # ajout du lien dans la bibliotèque de liens
            biblioteque_liens.append(ref)



def nettoie_page(page):
    """ fonction utilisée pour le nettoyage
        du contenu d'une page web """
    page = nettoie_js(page)
    page = nettoie_css(page)
    tag = False                                             # initialisation d'un tag
    page_nettoyee = ""
    for c in page:
        if c == '<': tag = True                             # caractere = '<'     tag on
        elif c == '>':                                      # caractere = '>'
            tag = False                                         # tag off
            page_nettoyee += " "                                # on ajoute un espace au début du contenu à ajouter
                                                                # pour eviter la concatenation de deux mots
        if not tag: page_nettoyee += c                      # not tag
    return page_nettoyee



def nettoie_js(page):
    """ fonction appellée pour nettoyer les scripts js """

    page_nettoyee = ""
    début = page.find("<script")                                                #on identifie le début d'une balise <script>
    while début > 0:                                                            #tant que la page contient une balse <script>
        fin = page.find("</script>")                                                # on identifie la fin du script
        page_nettoyee += page[:début]                                               # on ajoute le contenu de la page avant le script au contenu de la page nettoyee
        page = page[fin+9:]                                                         # on remplace le contenu de la page par le contenu qui suit le scripts
        début = page.find("<script")                                                # on recherche le script suivant
    page_nettoyee += page                                                       # on ajoute le contenu restant à la page nettoyee
    return page_nettoyee                                                        # on retourne la page nettoyee


def nettoie_css(page):
    """ fonction appellée pour nettoyer les scripts css"""

    page_nettoyee = ""
    début = page.find("<style")                                 # on identifie le début d'une balise <style>
    while début > 0:                                            # tant que la page contient une balise <style>
        fin = page.find("</style>")                                 # on identifie la fin du bloc style
        page_nettoyee += page[:début]                               # on ajoute le contenu de la page avant le bloc style au contenu de la page nettoyee
        page = page[fin+8:]                                         # on remplace le contenu de la page par le contenu qui suit le bloc style
        début = page.find("<style")                                 # on recherche le bloc style suivant
    page_nettoyee += page                                       # on ajoute le contenu restant à la page nettoyee
    return page_nettoyee                                        # on retourne la page nettoyee


def indexe(idx, mots , url):
    """ fonction appellée pour l'indexage d'une page web """

    for mot in mots:
        mot = mot.lower()                                                          # met obligatoirement en minuscule
        mot = nettoie(mot)                                                      # nettoyage du mot, voir ci-apres
        if mot and len(mot) < 2 and mot not in uniq_letter: continue            # si le mot ne fait qu'une lettre on s'assure qu'il
                                                                                # fait parti des mots d'une seul lettre
        if mot and mot not in stoplist:                                         # on en profite pour verifier si on veut vraiment indexer ce mot
            ajoute(idx, mot, url)



def nettoie(mot):
    """fonction utilisée pour le nettoyage du mot"""

    if "'" in mot:  mot = mot.split("'")[1]                 # gestion de l'apostrophe
    if "’" in mot:  mot = mot.split("’")[1]
    caracteres = []                                         # liste 'caracteres' servant a construire le mot nettoye
    for lettre in mot:                                      # pour chaques symboles du mot
        if lettre not in stop_caractere:                         # si ce n'est pas un symbole de ponctuation
            caracteres.append(lettre)                               # on ajoute ce caractere a la list 'caracteres'
    return "".join(caracteres)                              # on retourne le mot nettoye



def ajoute(idx, mot, url):
    """ fonction appellée pour l'ajout
        du mot dans le dictionnaire"""

    if mot not in idx:                                                          # si le mot ne se trouve pas encore dans l'index,
        idx[mot] = []                                                               # initialise les occurences par une liste vide
    if url not in idx[mot]:                                                     # si la ligne n'a pas encore ete enregistree pour ce mot
        idx[mot].append(url)                                                        # on ajoute le numero de ligne correspondant au mot









# declaration des variables ------------------------------------

index = {}
stop_url = []
biblioteque_liens = ["https://fr.wiktionary.org/wiki/programmation"]
uniq_letter = "aôy".split()
nb_indexage = int(input('veuillez indiquer le nombre de pages maximum a indexer \n(le resultat sera ecrit dans le fichier "index.txt"): \t'))
stop_caractere = "().&%,;:!?/*\#~_-+[]{}=<>@\`\"\'0123456789$€\“\”\«\»\|·"

## lecture des fichiers------------------------------------------

with open("stoplist.txt", "r") as fichier:
    stoplist = fichier.read().split()




# script--------------------------------------------------------

parcourir(biblioteque_liens, nb_indexage)

prd(index)  # ecriture du dictionnaire dans le fichier






""" OPTIONS """

""" récupération de la liste des liens collectés dans un fichier """
#with open('liens_parcourus.txt', "w") as fichier:
#    for lien in stop_url:
#        fichier.write("{}\n".format(lien))

""" récupération de la liste des pages parcourues dans un fichier """
#with open('bibliothèque_liens.txt', "w") as fichier:
#    for lien in biblioteque_liens:
#        fichier.write("{}\n".format(lien))
