/*******************************************/
/* 		      PUZLE.C                      */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "puzle.h"


tEstado *crearEstado(int puzle[N][N])
{
   tEstado *estado = (tEstado *) malloc(sizeof(tEstado));
   int i, j, ficha;

   for (i=0;i<N;i++)
      for (j=0;j<N;j++)
      {
         ficha=puzle[i][j];
         estado->celdas[i][j]=ficha;
         estado->fila[ficha]=i;
         estado->col[ficha]=j;
      }
   return estado;
}


tEstado *estadoInicial()
{
   return crearEstado(puzle_inicial);
}


tEstado *estadoObjetivo()
{
   return crearEstado(puzle_final);
}

int coste(unsigned op, tEstado *estado)
{
   return 1;
}

/* VISUALIZACI�N DE ESTADOS Y OPERADORES*/


void dispEstado(tEstado *estado)
{
   int i,j;

   for (i=0; i<N; i++)
   {
      for (j=0; j<N; j++)
         printf("%d",estado->celdas[i][j]);
      printf("\n");
   }
   printf("\n");
}


void dispOperador(unsigned op)
{
   switch(op)
   {
      case ARRIBA:    printf("Movimiento ARRIBA:\n"); break;
      case ABAJO:     printf("Movimiento ABAJO:\n"); break;
      case IZQUIERDA: printf("Movimiento IZQUIERDA:\n"); break;
      case DERECHA:   printf("Movimiento DERECHA:\n"); break;
   }
}

// FUNCIONES QUE SE HAN DE IMPLEMENTAR EN LA PRACTICA 1

// Funci�n auxiliar para comprobar si dos puzles tienen las fichas colocadas en el mismo orden en el tablero
int iguales(tEstado *s, tEstado *t)  //
{
   int i; 
   int j;
   int booleano = 1;
   for (i=0; i<N; i++){
      for (j=0;j<N; j++){
         if (s->celdas[i][j] == t->celdas[i][j]){
            booleano = 0;
         }
      }
   }
   return booleano;
}


int testObjetivo(tEstado *estado)
{
   int booleano=1;
   for ( int i=0; i<N && booleano!=0 ;i++ ){
       for ( int j=0; j<N && booleano!=0 ; j++){
           if (estado->celdas[i][j] != puzle_final[i][j])
           {
               booleano=0;
           }
       }
   }
   return booleano;
}


int esValido(unsigned op, tEstado *estado)
{
   int valido=0;
    switch(op){
        case ARRIBA:
            valido = (estado->fila[0]>0);
        break;
        case ABAJO:
            valido = (estado->fila[0]<N-1);
        break;
        case IZQUIERDA:
            valido = (estado->col[0]);
        break;
        case DERECHA:
            valido = (estado->col[0]<N-1);
        break; 
        default: 
        break;
    }
    return valido;
return 0;
}


tEstado *aplicaOperador(unsigned op, tEstado *s)
{
     tEstado *nuevo= (tEstado *) malloc(sizeof(tEstado));
    memcpy(nuevo, s,sizeof(tEstado));  
    //COMPLETAR
      int ficha;
    switch(op)
    {
        case ARRIBA: 
        
            ficha = s->celdas[s->fila[0]-1][s->col[0]]; 
            nuevo->fila[0]--;
            nuevo->fila[ficha]++; 
        break;

        case ABAJO: 
            ficha = s->celdas[s->fila[0]+1][s->col[0]]; 
            nuevo->fila[0]++; 
            nuevo->fila[ficha]--; 
        break;

        case IZQUIERDA: 
            
            ficha = s->celdas[s->fila[0]][s->col[0]-1]; 
            nuevo->col[0]--; 
            nuevo->col[ficha]++;
        break;
        case DERECHA:  
            ficha = s->celdas[s->fila[0]][s->col[0]+1]; 
            nuevo->col[0]++; 
            nuevo->col[ficha]--;
        break;
    }
    nuevo->celdas[nuevo->fila[0]][nuevo->col[0]] = 0;
    nuevo->celdas[nuevo->fila[ficha]][nuevo->col[ficha]] = ficha;

    return nuevo;
}




