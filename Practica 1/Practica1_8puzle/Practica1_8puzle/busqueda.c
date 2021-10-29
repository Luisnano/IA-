/*******************************************/
/* 		    BUSQUEDA.C                     */
/*						                   */
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
         dispOperador(nodo->operador);
        dispEstado(nodo->estado);
    }
}

void dispSolucion(tNodo *nodo){
   printf("Profundidad=%d\n",nodo->profundidad);
   printf("Coste=%d\n",nodo->costeCamino);
   dispCamino(nodo);
}


/* Crea el nodo ra�z. */
tNodo *nodoInicial(){
   tNodo *inicial=(tNodo *) malloc(sizeof(tNodo));
   inicial->estado=estadoInicial();
   inicial->padre=NULL;
   inicial->costeCamino=0;
   inicial->profundidad=0;
   return inicial;
}
//------------------------------------PROBLEMA 1 PRACTICA 3-----------------------------------------
//Funcion heuristica que devuelve el numero de fichas mal colocadas.
int funcion_heuristica (tEstado *estado, tEstado *objetivo){
    int mal_colocadas = 0;
    int i, j;
    for (i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if(estado->celdas[i][j] != objetivo->celdas[i][j]){
                ++mal_colocadas;
            }
        }
    }
    return mal_colocadas;
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
//------------------------------PROBLEMA 2 PRACTICA 3----------------------------
            nuevo->valHeuristica = funcion_heuristica(nodo->estado, nuevo->estado);
            InsertarUltimo(&sucesores,  (tNodo *) nuevo, (sizeof (tNodo)));
      }
  }
return sucesores;
}

//--------------------------------PROBLEMA 3 PRACTICA 3-------------------------------------
LISTA lista_ordenada(LISTA abiertos, LISTA sucesores){
    LISTA ordenada = Concatenar(abiertos, sucesores);
    //Primero tenemos que crear una funcion que intercambie los nodos que nosotros queremos de sitio
    //La creamos en listaia
    for (int i = 0; i < sizeof(ordenada); i++){
        for (int j = i + 1; j < (sizeof(ordenada))-1; j++){
            if (ordenada->nodo > ordenada->next){
                ordenada = cambia_posicion(ordenada, i, j);
            }
        }
    }

    

}


/* PERUVIAN CODE
int estado_repetido(LISTA cerrados, tNodo* nodo)
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
            //siguiente(&actual, &actual);
            actual = actual->next;
        }
    }
    return res;
}
*/

int busqueda(int s){
    int objetivo=0, visitados=0;
    tNodo *Actual=(tNodo*) calloc(1,sizeof(tNodo));
    tNodo *Inicial=nodoInicial();

    LISTA Abiertos= VACIA;
    LISTA Sucesores= VACIA;
    LISTA Cerrados = VACIA;
    InsertarPrimero(&Abiertos,(tNodo*) Inicial,sizeof(tNodo));
    //BUSQUEDA EN ANCHURA
    if (s==1){
        while (!esVacia(Abiertos) && !objetivo){
            Actual=(tNodo*) calloc(1,sizeof(tNodo));
            ExtraerPrimero(Abiertos,Actual, sizeof(tNodo));
            EliminarPrimero(&Abiertos);
            objetivo=testObjetivo(Actual->estado);
            ++visitados;     //Con esto añadimos 1 al numero de nodos visitados
            if (!objetivo){
                Sucesores = expandir(Actual);
                Abiertos=Concatenar(Abiertos,Sucesores);
            }
        }
    //BUSQUEDA EN PROFUNDIDAD
    }
    if(s==2){
        while (!esVacia(Abiertos) && !objetivo){
            printf("While busqueda\n");
            Actual=(tNodo*) calloc(1,sizeof(tNodo));
            ExtraerPrimero(Abiertos,Actual, sizeof(tNodo));
            EliminarPrimero(&Abiertos);
            objetivo=testObjetivo(Actual->estado);
            ++visitados;     //Con esto añadimos 1 al numero de nodos visitados
            if (!objetivo){
                printf("If busqueda\n");
                //Sucesores = expandir(Actual); 
                //Abiertos=Concatenar(Abiertos,Sucesores);
                Sucesores = expandir(Actual);
                Abiertos=Concatenar(Sucesores,Abiertos);
                
            }
        }//while
    }
    if(s==3){
        int limite;
        printf("Introduzca el limite deseado: \n");
        scanf("%d", &limite);
         while (!esVacia(Abiertos) && !objetivo && limite != 0){
            printf("While busqueda\n");
            Actual=(tNodo*) calloc(1,sizeof(tNodo));
            ExtraerPrimero(Abiertos,Actual, sizeof(tNodo));
            EliminarPrimero(&Abiertos);
            objetivo=testObjetivo(Actual->estado);
            ++visitados;     //Con esto añadimos 1 al numero de nodos visitados
            if (!objetivo){
                printf("If busqueda\n");
                //Sucesores = expandir(Actual); 
                //Abiertos=Concatenar(Abiertos,Sucesores);
                Sucesores = expandir(Actual);
                Abiertos=Concatenar(Sucesores,Abiertos);
                
            }
            --limite;        //Decrementamos el limite
        }//while

    }
   
    printf("\nVisitados= %d\n", visitados);
    if (objetivo)
    dispSolucion(Actual);
    free(Sucesores);
    free(Inicial);
    free(Actual);
    return objetivo;
}

