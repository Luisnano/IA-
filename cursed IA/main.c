/*******************************************/
/*             MAIN.C                      */
/*                                         */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "puzle.h"
#include "listaia.h"
#include "busqueda.h"

#define VORAZ 1
#define AESTRELLA 2

int main(){
    solucionFin(busquedaHeuristica(VORAZ)); //Usando el algoritmo voraz
    
    solucionFin(busquedaHeuristica(AESTRELLA)); //Usando el algoritmo A*
    
    return 0;
}
