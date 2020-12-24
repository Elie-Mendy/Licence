
; modification de la variable d'environnement
(setq *print-circle* t)

(setq liste1 '((a (d) b) (e (h g) . i) e f))
(setq liste2 '(((g e (f) a i b d)) (e . h)))
(setq liste3 '(e ((a b f d) . d) (h g) (i)))
(setq liste4 '(((f) e ((e) (h i . g)) (b . a) d)))
(setq liste5 '(i ((a) f h b . d) (d (g)) e))


(rplacd (cdr (cadadr liste1)) (cadr liste1))
(rplacd (cdr liste2) (cddaar liste2))
(rplacd (cdddr liste3) (cdr liste3))
(rplacd (car (caddar liste4)) (cddar liste4))
(rplacd (caadr liste5) (cdr (cddadr liste5)))


(print liste1)

(print liste2)

(print liste3)

(print liste4)

(print liste5)
