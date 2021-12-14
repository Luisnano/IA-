(deffacts inicio
    (ciudad A norte D)
    (ciudad A oeste B)
    (ciudad B norte E) 
    (ciudad B oeste C) 
    (ciudad C norte F)
    (ciudad D norte G)
    (ciudad D oeste E) 
    (ciudad E norte H)
    (ciudad E oeste F)
    (ciudad F norte I)
    (ciudad G oeste H)
    (ciudad H oeste I));; fin deffacts

(defrule sur
    (ciudad ?x norte ?y)
    => (assert (ciudad ?y sur ?x))
)

(defrule este
    (ciudad ?x oeste ?y)
    => (assert (ciudad ?y este ?x))
)

(defrule t.norte
    (and(ciudad ?x norte ?y)(ciudad ?y norte ?z))
    => (assert (ciudad ?x norte ?z))
)
(defrule t.sur
    (and(ciudad ?x sur ?y)(ciudad ?y sur ?z))
    => (assert (ciudad ?x sur ?z))
)
(defrule t.este
    (and(ciudad ?x este ?y)(ciudad ?y este ?z))
    => (assert (ciudad ?x este ?z))
)
(defrule t.oeste
    (and(ciudad ?x oeste ?y)(ciudad ?y oeste ?z))
    => (assert (ciudad ?x oeste ?z))
)

(defrule noreste
    (and(ciudad ?z sur ?y)(ciudad ?x oeste ?z))
    => (assert(ciudad ?y noreste ?x))
)
(defrule noroeste
    (and(ciudad ?z sur ?y)(ciudad ?x este ?z))
    => (assert(ciudad ?y noroeste ?x))
)
(defrule sureste
    (and(ciudad ?z norte ?y)(ciudad ?x oeste ?z))
    => (assert(ciudad ?y sureste ?x))
)
(defrule suroeste
    (and(ciudad ?z norte ?y)(ciudad ?x este ?z))
    => (assert(ciudad ?y suroeste ?x))
)

(defrule	inicio
?f1	<-(situacion	?x	?y)
(ubicacion	?x ?u ?y)
=>
(printout t	?x	"esta al " ?u  " de	"	?y	crlf)
(retract	?f1)
)