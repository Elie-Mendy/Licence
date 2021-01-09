(setq *print-circle* t)

; EXO 1
;Définir une fonction qui modifie une liste de nombres en ne gardant que les nombres plus petits qu'un nombre donné ; exemple :
(setq nombres '(15 3 5 24 2 35 5))

(defun inférieurs (nb liste)
  (cond
    ((atom liste) nil)
    ((< (car liste) nb) (rplacd liste (inférieurs nb (cdr liste))))
    ((inférieurs nb (cdr liste))) ) )


; Définir une fonction qui modifie une liste en ne gardant que les sous-listes d'une longueur supérieure ou égale à un nombre donné ; exemple :
(setq liste '((a b) c (d) (e f) (e g x) f))

(defun longueur (nb liste)
  (cond
    ((atom liste) nil)
    ((and (listp (car liste)) (>= (length (car liste)) nb)) (rplacd liste (longueur nb (cdr liste))))
    ((longueur nb (cdr liste))) ) )


; Définir une fonction qui modifie une liste pour ne garder que les éléments qui finissent par une lettre donnée ; exemple :
(setq atomes '(prendre lis nez art silence nu))

(defun finit-par (elt liste)
  (cond
    ((atom liste) nil)
    ((equal (char (string elt) 0) (char (string (car liste)) (1- (length (string (car liste))))))
      (rplacd liste (finit-par elt (cdr liste))) )
    ((finit-par elt (cdr liste))) ) )



; EXO 2
; Définir une fonction qui ramène la position d'un élément dans une liste,
; ou nil si l'élément ne figure pas dans la liste. Pour s'habituer aux conventions usuelles, le premier élément a la position 0.

(defun myposition (elt liste &optional (n 0))
  (cond
    ((atom liste) nil)
    ((equal elt (car liste)) n)
    ((myposition elt (cdr liste) (1+ n))) ) )


; Définir une fonction qui ramène le nième cdr d'une liste ; le cdr 0 (zéro) est la liste.
(defun nièmecdr (nb liste)
  (cond
    ((atom liste) nil)
    ((equal 0 nb) (car liste))
    ((nièmecdr (1- nb) (cdr liste))) ) )


; Définir une fonction qui ramène tous les atomes d'un arbre dans une unique liste plate.
; Nil n'est pas à considérer comme un atome, mais comme une liste. Réfléchissez au cas de l'atome en cdr.
(defun atomes (liste)
  (cond
    ; fin de la liste
    ((atom liste)
      (cond
        ((equal nil liste) nil)
        ((list liste)) ) )
    ; sous liste
    ((listp (car liste)) (append (atomes (car liste)) (atomes (cdr liste))))
    ; sinon
    ((cons (car liste) (atomes (cdr liste)))) ) )
