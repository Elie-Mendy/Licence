(setq liste '(a b g j l o  k l o p m l o))
(print liste)

(defun garde-o (liste &aux bassine)
  (loop
    (cond
      ((atom liste) (return bassine))
      ((equal (car liste) 'o) (push (pop liste) bassine))
      ((pop liste)) ) ) )


(defun garde (elt liste &aux bassine)
  (loop
    (cond
      ((atom liste) (return bassine))
      ((equal elt (car liste)) (push (pop liste) bassine))
      ((pop liste)) ) ) )


(defun inverse (liste &aux inversed)
  (loop
    (cond
      ((atom liste) (return inversed))
      ((push (pop liste) inversed)) ) ) )
