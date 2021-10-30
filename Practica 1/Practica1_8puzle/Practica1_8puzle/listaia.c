/*******************************************/
/*             LISTAIA .C                  */
/*                                         */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaia.h"

int esVacia( LISTA c){
    return (c==VACIA);
}//esVacia

void InsertarPrimero(LISTA *c, void *n, int size){
    LISTA p=(LISTA ) malloc(sizeof(LISTA)+size);
    memcpy((void *)p->nodo,(void*)n, size);
    p->next=(*c);
    *c=p;
}//InsertarPrimero


void ExtraerPrimero(LISTA c, void *n, int size){
    memcpy((void *) n, (void *) c->nodo,size);
};//Extraer primer elemento


void EliminarPrimero(LISTA *c){
    LISTA p;
    p=*c;
    *c=p->next;
    free(p);
}//Eliminar primer elemento de la lista

void InsertarUltimo(LISTA *c, void *n, int size){
    LISTA p=malloc(sizeof(LISTA)+size);
    LISTA aux=VACIA;
    //creando el nodo
    memcpy((void*)(p->nodo),(void *) n, size);
    p->next=NULL;
    if (esVacia(*c)){
        *c=p;
    }
    else{
        aux=*c;
        while (aux->next!=NULL){
            aux=aux->next;
        }
        aux->next=p;
    }
}//InsertarUltimo

LISTA cambia_posicion(LISTA lista_pasada, int n, int m){
    //UsAMOS UN AUXILIAR PARA CAMBIAR LAS POSICIONES
    LISTA lista_auxiliar = lista_pasada;
    lista_auxiliar->nodo[n] = lista_pasada->nodo[m];
    lista_pasada->nodo[m] = lista_pasada->nodo[n];
    lista_pasada->nodo[n] = lista_auxiliar->nodo[n];
    //lista_pasada
    return lista_pasada;

}

LISTA Concatenar(LISTA c,LISTA p){
    LISTA aux;
    if (esVacia(c)){
        c= p;
    }else {
        aux=c;
        while (aux->next!= NULL) {
            aux = aux->next;
        }
        aux->next=p;
    }
    return c;
}//Concatenar

