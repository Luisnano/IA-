(deftemplate coche
        (slot modelo (allowed-values modelo1 modelo2 modelo3 modelo4 modelo5))
        (slot precio)
        (slot tam_maletero (allowed-values pequenyo mediano grande))
        (slot caballos)
        (slot ABS (allowed-values si no))
        (slot consumo))

(deftemplate respuesta
        (slot precio (default 13000))
        (slot tam_maletero (default grande))
        (slot caballos (default 80))
        (slot ABS (default si))
        (slot consumo (default 8.0)))


;METERLO DE FORMA MANUAL
;(assert (coche (modelo modelo1)	(precio	12000)	(tam_maletero	pequenyo)	(caballos	65)  (ABS    no) (consumo 4.7)))
;(assert (coche (modelo modelo2)	(precio	12500)	(tam_maletero	pequenyo)	(caballos	80)  (ABS    si) (consumo 4.9)))
;(assert (coche (modelo modelo3)	(precio	13000)	(tam_maletero	mediano)	(caballos	100) (ABS    si) (consumo 7.8)))
;(assert (coche (modelo modelo4)	(precio	14000)	(tam_maletero	grande)	    (caballos	125) (ABS    si) (consumo 6.0)))
;(assert (coche (modelo modelo5)	(precio	15000)	(tam_maletero	pequenyo)	(caballos	147) (ABS    si) (consumo 8.5)))

(defrule inicial
=>
(printout t "Escriba el precio que desea gastar:")
(bind ?precio (read))
(printout t "Escriba el tamanyo del maletero:")
(bind ?tamanyo (read))
(printout t "Escriba los caballos:")
(bind ?caballos (read))
(printout t "Escriba si quiere abs:")
(bind ?abs (read))
(printout t "Escriba el consumo:")
(bind ?consumo (read))
(assert (respuesta ?precio ?tamanyo ?caballos ?abs ?consumo))
)

;VAMOS A EMPEZAR A HACER LAS RULES

(defrule modelo1
    (respuesta ?precio <=12000)
    (respuesta ?tamanyo <=pequenyo)
    (respuesta ?caballos <=65)
    (respuesta ?abs = no)
    (respuesta ?consumo <=4.7)
    =>
    (printout t "Para usted el modelo 1 es el mas idoneo")
)
(defrule modelo2
    (respuesta ?precio <=12500)
    (respuesta ?tamanyo <=pequenyo)
    (respuesta ?caballos <=80)
    (respuesta ?abs = si)
    (respuesta ?consumo <=4.9)
    =>
    (printout t "Para usted el modelo 1 y 2 es el mas idoneo")
)
(defrule modelo3
    (respuesta ?precio <=13000)
    (respuesta ?tamanyo <=mediano)
    (respuesta ?caballos <=100)
    (respuesta ?abs = si)
    (respuesta ?consumo <=7.8)
    =>
    (printout t "Para usted el modelo 1, 2 y 3 es el mas idoneo")
)
(defrule modelo4
    (respuesta ?precio <=14000)
    (respuesta ?tamanyo <=grande)
    (respuesta ?caballos <=125)
    (respuesta ?abs = si)
    (respuesta ?consumo <=6.0)
    =>
    (printout t "Para usted el modelo 1, 2, 3 y 4 es el mas idoneo")
)
(defrule modelo5
    (respuesta ?precio <=15000)
    (respuesta ?tamanyo <=pequenyo)
    (respuesta ?caballos <=147)
    (respuesta ?abs = si)
    (respuesta ?consumo <=8.5)
    =>
    (printout t "Es usted rico, enhorabuena, comprese el que quiera")
)
; |,\/,| |[_' |[_]) |[_]) \\//
; ||\/|| |[_, ||'\, ||'\,  ||

;             ___ __ __ ____  __  __  ____  _  _    __    __
;            // ' |[_]| |[_]) || ((_' '||' |,\/,|  //\\  ((_'
;            \\_, |[']| ||'\, || ,_))  ||  ||\/|| //``\\ ,_))
                                                               

;                                          ,;7,
;                                        _ ||:|,
;                      _,---,_           )\'  '|
;                    .'_.-.,_ '.         ',')  j
;                   /,'   ___}  \        _/   /
;       .,         ,1  .''  =\ _.''.   ,`';_ |
;     .'  \        (.'T ~, (' ) ',.'  /     ';',
;     \   .\(\O/)_. \ (    _Z-'`>--, .'',      ;
;      \  |   I  _|._>;--'`,-j-'    ;    ',  .'
;     __\_|   _.'.-7 ) `'-' "       (      ;'
;   .'.'_.'|.' .'   \ ',_           .'\   /
;   | |  |.'  /      \   \          l  \ /
;   | _.-'   /        '. ('._   _ ,.'   \i
; ,--' ---' / k  _.-,.-|__L, '-' ' ()    ;
;  '._     (   ';   (    _-}             |
;   / '     \   ;    ',.__;         ()   /
;  /         |   ;    ; ___._._____.: :-j
; |           \,__',-' ____: :_____.: :-\
; |               F :   .  ' '        ,  L
; ',             J  |   ;             j  |
;   \            |  |    L            |  J
;    ;         .-F  |    ;           J    L
;     \___,---' J'--:    j,---,___   |_   |
;               |   |'--' L       '--| '-'|
;                '.,L     |----.__   j.__.'
;                 | '----'   |,   '-'  }
;                 j         / ('-----';
;                { "---'--;'  }       |
;                |        |   '.----,.'
;                ',.__.__.'    |=, _/
;                 |     /      |    '.
;                 |'= -x       L___   '--,
;           snd   L   __\          '-----'
;                  '.____)