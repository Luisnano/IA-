;######################################
;PRACTICA 10 DE INTELIGENCIA ARTIFICIAL
;Realizada por:
;   Luis Fernando Torres Moya
;######################################


;Vamos a empezar definiendo los templates para los datos que vamos a utilizar

(deftemplate usuario
    (slot dni)
    (slot pin)
    (slot dinero_a_otener (default 0))
)

(deftemplate tarjeta
    (slot pin)
    (slot dni)
    (slot n_intentos (default 0))
    (slot limite_dinero (default 0))
    (slot expiracion (default 0))
    (slot validada (allowed-values si no))
)

(deftemplate cuenta
    (slot dni)
    (slot saldo)
    (slot estado (allowed-values enPantalla dineroEntregado inicial superaLimite sinSaldo))
)

;Necesitamos un par de variables globales

(defglobal ?*ANNO=2020)

(defglobal ?*LIMITE1=900)
(defglobal ?*LIMITE2=500)

;Ahora nos ponemos a definir las 8 reglas

;-------------------FUNCIONES ARITMETICAS AUXILIARES------------------------------------------------------------------------------------
(deffunction resta_1 (?num)
    (if (> ?num 0) then 
        (bind ?res ?num-1)
    )
    (return ?res)
)

(deffunction resta_elementos (?num1 ?num2)
    (if (< ?num1 ?num2) then
        (bind ?res invalido)
    )
    else(
        (bind ?res ?num1-?num2)
    )
    (return ?res)
)
;-------------------REGLAS DE VALIDACION DE LA TARJETA----------------------------------------------------------------

(defrule supera_intentos
    (n_intentos ?ni)
=>
    (if (< ?ni ?*LIMITE1) then
        (printout t "LIMITE DE INTENTOS SUPERADO")
    )    
)
(defrule pin_invalido
    (n_intentos ?ni)
    (pin ?p)
=> 
    (if (= ?p usuario.pin) then 
        (assert ?ni + 1)
        (printout t "PIN DE USUARIO INVALIDO") 
    )
)


;-------------------REGLAS DE COMPROBACION DE SALDO Y ENTREGA DE DINERO-----------------------------------------------

(defrule muestra_saldo
    (tarjeta ?validada si)
    (cuenta ?saldo)
=> 
    (assert cuenta ?estado enPantalla)
    (printout t "El saldo es de:" ?saldo)
)

(defrule saldo_no_suficiente
    (cuenta ?saldo)
    (usuario ?dinero_a_otener)
=>
    (if(< ?saldo ?dinero_a_otener) then
        (printout t "El saldo de la cuenta es insuficiente"))
)

(defrule compruea_limite1 
    (cuenta ?saldo)
=>
    (if (> ?saldo ?*LIMITE1) then 
        (printout t "Ha superado el limite de saldo")
        (assert cuenta ?estado superaLimite)
    )
)

(defrule compruea_limite2 
    (cuenta ?saldo)
=>
    (if (> ?saldo ?*LIMITE2) then 
        (printout t "Ha superado el limite de saldo")
        (assert cuenta ?estado superaLimite)
    )
)

(defrule entrega_dinero
    (cuenta ?saldo)
    (usuario ?dinero_a_otener)
=>
    (assert cuenta ?saldo (?saldo - ?dinero_a_otener))
)

;-------------------------------INTERFAZ DEL CAJERO----------------------------------
(defrule cajero
=>
(printout t "----------WELCOME TO UNITED BANK OF MONEY----------" crlf)
(printout t "                                                   " crlf)
(printout t "                 ESCRIBA SU DNI=> ")
(bind ?dni (read))
(printout t crlf "                                                   " )
(printout t crlf "                 ESCRIBA SU PIN=> ")
(bind ?pin (read))
(printout t crlf "                                                   " )
(printout t crlf "                 ESCRIBA EL DINERO QUE DESEA OBTENER=> ")
(bind ?dinero_a_otener (read))

(assert (usuario ?dni ?pin ?dinero_a_otener))
)