/*******************************************/
/*               PUZLE.C                      */
/*                                           */
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
         ficha=puzle[i][j];             //Cojo la ficha
         estado->celdas[i][j]=ficha;    //Pongo la ficha en el tablero
         estado->fila[ficha]=i;         //Fila en la que esta la ficha
         estado->col[ficha]=j;          //Columna en la que esta la ficha
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
   return 1;    //Coste definido a 1
}

/* VISUALIZACI”N DE ESTADOS Y OPERADORES*/


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

// FunciÛn auxiliar para comprobar si dos puzles tienen las fichas colocadas en el mismo orden en el tablero
int iguales(tEstado *s, tEstado *t)  //
{
    int i,j,iguales = 1;
/*Opción 1: Dos puzles son iguales si el contenido del tablero(celdas) es el mismo*/
    for(i=0;i<N && iguales;i++)
    {
        for(j=0;j<N && iguales;j++)
        {
            iguales &= (s->celdas[i][j]==t->celdas[i][j]);
            //iguales= iguales & 1 -> iguales= 1 & 1 -> iguales=1
            //iguales= iguales & 0 -> iguales= 1 & 0 -> iguales=0
        }
    }
/* Opción 2: Dos puzles son iguales si sus fichas ocupan la misma posición, es decir, misma fila y columna
    
 for(i=0; i<N*N && iguales; i++)
 {
    iguales &= (s->fila[i] == t->fila[i] && s->col[i] == t->col[i]);
 }
 */
return iguales;
}


int testObjetivo(tEstado *estado)
{
    //Opción 1: Usando la funcion int iguales(*tEstado,*tEstado)
    //return iguales(estado,estadoObjetivo());
    
    //Opción 2: Usando el tablero final
    int i,j,res=1;
    for(i=0;i<N && res;i++)
    {
        for(j=0;j<N && res;j++)
        {
            res &= (estado->celdas[i][j] == puzle_final[i][j]);
        }
    }
    return res;
}

//Comprueba si un operador se puede aplicar a un determinado tablero
int esValido(unsigned op, tEstado *estado)
{
    int valido = 0;
    
    switch (op) {
        case ARRIBA:
            valido=(estado->fila[0] != 0); //Falso solo si primera fila
            break;
        case DERECHA:
            valido=(estado->col[0] != N-1); //Falso solo si ultima columna
            break;
        case ABAJO:
            valido=(estado->fila[0] != N-1); //Falso solo si ultima fila
            break;
        case IZQUIERDA:
            valido=(estado->col[0] != 0); //Falso solo si primera columna
            break;
        default:
            break;
    }
    return valido;
}


tEstado *aplicaOperador(unsigned op, tEstado *estado)
{
    tEstado *nuevo= (tEstado *) malloc(sizeof(tEstado));
    memcpy(nuevo, estado,sizeof(tEstado));  // Hace una copia del estado
    
    //Posicion origen del hueco
    int fila_origen_hueco = estado->fila[0];
    int col_origen_hueco = estado->col[0];
    
    //Posicion destino del hueco en funcion del operador
    int fila_destino_hueco = 0, col_destino_hueco = 0;
    
      switch(op){
          case ARRIBA:
              fila_destino_hueco = fila_origen_hueco-1;
              col_destino_hueco = col_origen_hueco;
              break;
              
          case DERECHA:
              fila_destino_hueco = fila_origen_hueco;
              col_destino_hueco = col_origen_hueco+1;
              break;
              
          case ABAJO:
              fila_destino_hueco = fila_origen_hueco+1;
              col_destino_hueco = col_origen_hueco;
              break;
              
          case IZQUIERDA:
              fila_destino_hueco = fila_origen_hueco;
              col_destino_hueco = col_origen_hueco-1;
              break;
              
          default:
              printf("Operador Invalido \n");
              break;
      }
    /** Movimiento del hueco **/
    //Donde estaba el hueco pongo la ficha
    nuevo->celdas[fila_origen_hueco][col_origen_hueco] = nuevo->celdas[fila_destino_hueco][col_destino_hueco];
    nuevo->fila[nuevo->celdas[fila_destino_hueco][col_destino_hueco]] = fila_origen_hueco;
    nuevo->col[nuevo->celdas[fila_destino_hueco][col_destino_hueco]] = col_origen_hueco;
    
    //Donde estaba la ficha pongo el hueco
    nuevo->celdas[fila_destino_hueco][col_destino_hueco] = 0;
    nuevo->fila[0] = fila_destino_hueco;
    nuevo->col[0] = col_destino_hueco;
    
    return nuevo;
}


