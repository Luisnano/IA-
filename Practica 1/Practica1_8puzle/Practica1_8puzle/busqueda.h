/*******************************************/
/* 		    BUSQUEDA.H                     */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/


#ifndef _tNodo_
#define _tNodo_
typedef struct NodoBusqueda_{
    tEstado *estado; //Estado en el que se encuentra la busqueda
    unsigned operador; //Operacion que se ha elegido hacer en este nodo
    int costeCamino; //Coste del camino a seguir
    int profundidad; //Profundidad en la que se encuentra el nodo
    int valHeuristica; 
    struct NodoBusqueda_ *padre; //Nodo anterior al cual nos encontramos
} tNodo;

#endif

int busqueda(int);
void solucionFin(int res);
LISTA lista_ordenada(LISTA abiertos, LISTA sucesores)
