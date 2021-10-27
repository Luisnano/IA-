#include "ladrones.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//Inicializamos la cinta de la estructura tEstado usando una que le pasamos por valor.
tEstado *crearEstado(int cinta[N]){
    tEstado *e = (tEstado*)malloc(sizeof(tEstado));
    for (int i = 0; i<N; i++){
        e->cinta[i] = cinta[i];
    }
    e->ladoizq = 0;
    e->ladoder = N - 1;
    e->recuperado = 0;
    e->robado = 0;
    return e;
}


//Comenzamos el esValido para ver si una operacion que queremos hacer es valida.
int esValido(unsigned op, tEstado *t){
    int valido = 0;
    if (op == DER || op == IZQ){
        if (N%2 == 0){//Si la cinta es PAR
            valido = (t->ladoizq < t->ladoder); //ASIGNACION BOOLEANA, si es verdad pone valido a 1.
        }else{//Si la cinta es IMPAR
            valido = (t->ladoizq < t->ladoder-1);
        }//if_else
    }//if
    return valido;
}

//Veamos ahora el aplicaOperador
tEstado *aplicaOperador(unsigned op, tEstado *s)
{
    tEstado *nuevo= (tEstado *) malloc(sizeof(tEstado));
    memcpy(nuevo, s,sizeof(tEstado)); 
    int bolsa, alarma;
    switch (op)
    {
    case IZQ:
        bolsa = s->cinta[0];                //Nos quedamos con el contenido de la casilla izquierda
        alarma = s->cinta[N-1];             //La seguridad se queda con el de la derecha
        nuevo->ladoizq = s->ladoizq++;      //Actualizamos como se queda la cinta
        nuevo->ladoder = s->ladoder--;
        break;

    case DER:
        bolsa = s->cinta[N-1];              //Nos quedamos con el contenido de la casilla derecha
        alarma = s->cinta[N-2];             //La seguridad se queda con el de la IZQUIERDA DEL NUESTRO
        nuevo->ladoder = s->ladoder - 2;
        break;
    
    }//switch
    //Hay que actualizar la cinta pero no se como
    nuevo->recuperado = alarma;
    nuevo->robado = bolsa; 

}

int testObjetivo (tEstado *e){
    int objetivo = 0;
    if (N%2 == 0){
        objetivo = (e->ladoizq < e->ladoder) && (e->robado > e->recuperado);
    }else{
        objetivo = (e->ladoder == e->ladoizq) && (e->robado > e->recuperado);
    }
    return objetivo;
}