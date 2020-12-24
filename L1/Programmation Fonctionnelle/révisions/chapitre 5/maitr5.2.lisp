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
