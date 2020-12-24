; EXO 1 : Définir une fonction qui compte, à partir d'une liste de nombres,
; le nombre de nombres plus petits ou égaux qu'un nombre donné ;


(defun inférieurs (nb liste)
  (cond
    ((atom liste) 0)
    ((<= (car liste) nb) (1+ (inférieurs nb (cdr liste))))
    ((inférieurs nb (cdr liste))) ) )


; EXO 2 Définir une fonction qui construit, à partir d'une liste de nombres, la liste des nombres plus petits ou égaux qu'un nombre donné ; exemple
(defun inférieur (nb liste)
  (cond
    ((atom liste) nil)
    ((<= (car liste) nb) (cons (car liste) (inférieur nb (cdr liste))))
    ((inférieur nb (cdr liste))) ) )


; EXO 3 A. Définir une fonction qui construit, à partir d'une liste incluant des sous-listes, la liste des sous-listes commençant par un nombre ;
(defun nombre (liste)
  (cond
    ((atom liste) nil)
    ((and (listp (car liste)) (numberp (caar liste))) (cons (car liste) (nombre (cdr liste))))
    ((nombre (cdr liste))) ) )


;EXO 4 Définir une fonction qui construit, à partir d'une liste, une liste sans les éléments qui commencent par une lettre donnée ;
(defun élimine (elt liste)
  (cond
    ((atom liste) nil)
    ((equal (char (string elt) 0) (char (string (car liste)) 0)) (élimine elt (cdr liste)))
    ((cons (car liste) (élimine elt (cdr liste)))) ) )


; EXO 5 Définir une fonction qui compte, dans une liste, le nombre d'éléments ne commençant pas par une lettre donnée ;
(defun autres (elt liste)
  (cond
    ((atom liste) 0)
    ((equal (char (string elt) 0) (char (string (car liste)) 0)) (autres elt (cdr liste)))
    ((1+ (autres elt (cdr liste)))) ) )
