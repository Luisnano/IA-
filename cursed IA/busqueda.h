/*******************************************/
/*             BUSQUEDA.H                     */
/*                                           */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/

/*Para evitar duplicidades condicionamos la carga del modulo
#ifndef _BUSQUEDA_
#define _BUSQUEDA_
*/
#include "puzle.h"

#ifndef _tNodo_
#define _tNodo_
typedef struct NodoBusqueda_{
    tEstado *estado;
    unsigned operador;
    int costeCamino;
    int profundidad;
    int valHeuristica;
    struct NodoBusqueda_ *padre;
} tNodo;

#endif
LISTA expandir(tNodo *nodo);
LISTA expandirHeuristica(tNodo *nodo, int tipo);

LISTA insercionOrdenada(LISTA C, tNodo* nodo_a_insertar);
LISTA concatenaOrdenada(LISTA concatenada, LISTA nueva);
int existeCerrados(LISTA cerrados, tNodo* nodo);

int heuristicaMalColocada(tEstado *s);
int heuristica_manhattan(tEstado *s);

int busqueda(void);
int busquedaHeuristica(int tipo);

void solucionFin(int res);
