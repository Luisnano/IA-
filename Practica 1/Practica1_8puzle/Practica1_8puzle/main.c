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

int main(){
    int seleccion;
    while (seleccion != 1 && seleccion != 2 && seleccion != 3){
        printf("Seleccione una estrategia de busqueda:\n    Anchura (1)\n   Profundidad (2)\n   Limitada (3)\n");
        scanf("%d", &seleccion);
    }
    solucionFin(busqueda(seleccion));
    return 0;
}
