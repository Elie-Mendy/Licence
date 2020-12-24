(setq liste '(a b g j l o  k l o p m l o))
(print liste)



; une fonction qui recupère tout les o d'une liste
(defun garde-o (liste)
  (cond
    ((atom liste) nil)
    ((equal (car liste) 'o) (cons (car liste) (garde-o (cdr liste))))
    ((garde-o (cdr liste))) ) )



; une fonction qui récupère toutes les occurences d'un élément dans une liste
(defun garde (elt liste)
  (cond
    ((atom liste) nil)
    ((equal (car liste) elt) (cons (car liste) (garde elt (cdr liste))))
    ((garde elt (cdr liste))) ) )


; une fonction qui élimine les o
(defun elimine-o (liste)
  (cond
    ((atom liste) nil)
    ((equal (car liste) 'o) (elimine-o (cdr liste)))
    ((cons (car liste) (elimine-o (cdr liste)))) ) )

; une fonction qui élimine toutes les occurences d'un élément donné dans une liste
(defun elimine (elt liste)
  (cond
    ((atom liste) nil)
    ((equal (car liste) elt) (elimine elt (cdr liste)))
    ((cons (car liste) (elimine elt (cdr liste)))) ) )
