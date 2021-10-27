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
    printf("Seleccione una estrategia de busqueda:\n    Anchura (1)\n   Profundidad (2)\n");
    scanf("%d", &seleccion);
    solucionFin(busqueda(seleccion));
    return 0;
}
