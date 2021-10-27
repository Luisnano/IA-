/*******************************************/
/*             BUSQUEDA.C                     */
/*                                           */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "puzle.h"
#include "listaia.h"
#include "busqueda.h"

void solucionFin(int res){
   printf("\nFin de la busqueda\n");
    if (res)
      printf("Se ha llegado al objetivo\n");
   else
      printf("No se ha llegado al objetivo\n");
}

void dispNodo(tNodo *nodo){
    dispEstado(nodo->estado);
    printf("\n");
}

void dispCamino(tNodo *nodo){
    if (nodo->padre==NULL){
        printf("\n Desde el inicio\n");
        dispEstado(nodo->estado);
    }
    else {
        dispCamino(nodo->padre);
         dispOperador(nodo->operador); //Que movimiento se ha hecho para que yo llegue a mi estado actual
        dispEstado(nodo->estado);
    }
}

void dispSolucion(tNodo *nodo){
   printf("Profundidad=%d\n",nodo->profundidad);
   printf("Coste=%d\n",nodo->costeCamino);
   dispCamino(nodo);
}


/* Crea el nodo raÌz. */
tNodo *nodoInicial(){
   tNodo *inicial=(tNodo *) malloc(sizeof(tNodo));
   inicial->estado=estadoInicial();
   inicial->padre=NULL;
   inicial->costeCamino=0;
   inicial->profundidad=0;
   return inicial;
}

LISTA expandir(tNodo *nodo){
    unsigned op;
    LISTA sucesores=VACIA;
    tNodo *nuevo=calloc(1,sizeof(tNodo));
    tEstado *s;
    for (op=1; op<=NUM_OPERADORES;op++){
      if (esValido(op,nodo->estado)){
                        //s=(tEstado *)calloc(1,sizeof(tEstado));
          s=aplicaOperador(op,nodo->estado);
          nuevo->estado=s;
          nuevo->padre=nodo;
          nuevo->operador=op;
          nuevo->costeCamino=nodo->costeCamino + coste(op,nodo->estado);
          nuevo->profundidad=nodo->profundidad+1;
          InsertarUltimo(&sucesores,  (tNodo *) nuevo, (sizeof (tNodo)));
      }
  }
return sucesores;
}

/*
    tipo = 1 -> Voraz
    tipo = 2 -> A*
 */
LISTA expandirHeuristica(tNodo *nodo, int tipo)
{
    unsigned op;
    LISTA sucesores=VACIA;
    tNodo *nuevo=(tNodo*)calloc(1,sizeof(tNodo));
    tEstado *s;
    for(op=1; op<=NUM_OPERADORES;op++)
    {
        if(esValido(op,nodo->estado))
        {
            s=aplicaOperador(op,nodo->estado);
            nuevo->estado=s;
            nuevo->padre=nodo;
            nuevo->operador=op;
            nuevo->costeCamino=nodo->costeCamino + coste(op,nodo->estado);
            nuevo->profundidad=nodo->profundidad+1;
            if(tipo == 1 || tipo == 2)
            {
                nuevo->valHeuristica = heuristica_manhattan(s);
                if(tipo == 2)//A* = heuristica + coste real camino
                {
                    nuevo->valHeuristica += nuevo->costeCamino;
                }
            }
            InsertarUltimo(&sucesores, (tNodo*) nuevo, (sizeof (tNodo)));
        }
    }
    return sucesores;
}

LISTA insercionOrdenada(LISTA C, tNodo* nodo_a_insertar)
{
    LISTA ordenada = VACIA;
    tNodo* nodo = (tNodo*) calloc (1, sizeof(tNodo));
    
    if(esVacia(C))
    {
        InsertarUltimo(&ordenada, (tNodo*) nodo_a_insertar, sizeof(tNodo));
    }
    else
    {
        ExtraerPrimero(C, nodo, sizeof(tNodo));
        while(!esVacia(C) && nodo->valHeuristica < nodo_a_insertar->valHeuristica)
        {
            InsertarUltimo(&ordenada, (tNodo*) nodo, sizeof(tNodo));
            siguiente(&C, &C);
            if(!esVacia(C))
            {
                ExtraerPrimero(C, (tNodo*) nodo, sizeof(tNodo));
            }
        }
        InsertarUltimo(&ordenada, (tNodo*) nodo_a_insertar, sizeof(tNodo));
        ordenada= Concatenar(ordenada,C);
    }
    return ordenada;
}

LISTA concatenaOrdenada(LISTA concatenada, LISTA nueva)
{
    LISTA aux = nueva;
    tNodo* nodo= (tNodo*) calloc (1, sizeof(tNodo));
    
    while(!esVacia(aux))
    {
        ExtraerPrimero(aux, nodo, sizeof(tNodo));
        concatenada= insercionOrdenada(concatenada,nodo);
        siguiente(&aux, &aux);
    }
    return concatenada;
}

int existeCerrados(LISTA cerrados, tNodo* nodo)
{
    int res=0;
    tNodo * aux= (tNodo*) calloc (1,sizeof(tNodo));
    LISTA actual = cerrados;
    
    while(!esVacia(actual) && !res)
    {
        ExtraerPrimero(actual,aux,sizeof(tNodo));
        if(iguales(aux->estado, nodo->estado))
        {
            res=1;
        }
        else
        {
            siguiente(&actual, &actual);
        }
    }
    return res;
}


int heuristicaMalColocada(tEstado *s)
{
    int i,cont=0;
    tEstado* objetivo= estadoObjetivo();
    for(i = 0; i < N*N; i++)
    {
        if(!(s->col[i] == objetivo->col[i] && s->fila[i] == objetivo->fila[i]))
        {
            cont++;
        }
    }
    return cont;
}

int heuristica_manhattan(tEstado *s)
{
    int cont=0,i;
    tEstado *objetivo= estadoObjetivo();
    
    for(i=0;i<N*N;i++)
    {
            cont += (abs(s->col[i] - objetivo->col[i]) + abs(s->fila[i] - objetivo->fila[i]));
    
    }
    return cont;
}

int busqueda(){
    int objetivo=0, visitados=0;
    tNodo *Actual=(tNodo*) calloc(1,sizeof(tNodo));
    tNodo *Inicial=nodoInicial();

    LISTA Abiertos= VACIA;
    LISTA Sucesores= VACIA;
    InsertarPrimero(&Abiertos,(tNodo*) Inicial,sizeof(tNodo));
    while (!esVacia(Abiertos) && !objetivo){
        Actual=(tNodo*) calloc(1,sizeof(tNodo));
        ExtraerPrimero(Abiertos,Actual, sizeof(tNodo));
        EliminarPrimero(&Abiertos);
        objetivo=testObjetivo(Actual->estado);
        if (!objetivo){
            Sucesores = expandir(Actual);
            Abiertos=Concatenar(Abiertos,Sucesores);//Anchura
            //Abiertos=Concatenar(Sucesores,Abiertos);//Profundidad
      }
   }//while
   
    printf("\nVisitados= %d\n", visitados);
    if (objetivo)
        dispSolucion(Actual);
    free(Sucesores);
    free(Inicial);
    free(Actual);
    return objetivo;
}

/*
    tipo 1 -> Voraz
    tipo 2 -> A*
 */
int busquedaHeuristica(int tipo){
    int objetivo=0, visitados=0;
    tNodo *Actual=(tNodo*) calloc(1,sizeof(tNodo));
    tNodo *Inicial=nodoInicial();

    LISTA Abiertos= VACIA;
    LISTA Cerrados= VACIA;
    LISTA Sucesores= VACIA;
    InsertarPrimero(&Abiertos,(tNodo*) Inicial,sizeof(tNodo));
    
    while (!esVacia(Abiertos) && !objetivo)
    {
        Actual=(tNodo*) calloc(1,sizeof(tNodo));
        
        ExtraerPrimero(Abiertos,Actual, sizeof(tNodo));
        EliminarPrimero(&Abiertos);
        
        objetivo=testObjetivo(Actual->estado);
        visitados++;
        if (!objetivo && !existeCerrados(Cerrados, Actual))
        {
            InsertarPrimero(&Cerrados, (tNodo*)Actual,sizeof(tNodo));
            
            Sucesores = expandirHeuristica(Actual,tipo);
            Abiertos=concatenaOrdenada(Abiertos,Sucesores);
      }
   }//while
   
    printf("\nVisitados= %d\n", visitados);
    if (objetivo)
        dispSolucion(Actual);
    free(Sucesores);
    free(Inicial);
    free(Actual);
    free(Cerrados);
    
    return objetivo;
}
