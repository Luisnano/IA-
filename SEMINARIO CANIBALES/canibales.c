#include "canibales.h"

//Vamos apasarle los valores que quiera el usuario para crear el problema inicial
tEstado *crearEstado(int c_izq, int m_izq, int c_der, int m_der){

    tEstado *nuevo = malloc(sizeof(tEstado));
    //Rellenamos el estado nuevo con el que vamos a trabajar
    nuevo -> c_izq = c_izq;
    nuevo -> m_izq = m_izq;
    nuevo -> c_der = c_der;
    nuevo -> m_der = m_der;

}

int esValido(unsigned op, tEstado *e){

    int valido = 0;
    switch (op)
    {
    case C1_DER:
        valido = (e->barca == IZQ && e->c_izq > 0 && e->m_der >= e->c_der+1);
        break;
    case C2_DER:
        valido = (e->barca == IZQ && e->c_izq > 0 && e->m_der >= e->c_der+2);
        break;

    //TERMINAR EL RESTO DE CASOS
    default:
        break;
    }
}

tEstado *aplicaOperador(unsigned op, tEstado *e){

    tEstado *s = malloc(sizeof(tEstado));

    memcpy(s, e, sizeof(tEstado));

    switch (op)
    {
    case C1_DER:
        s->c_izq --;
        s->barca = DER;
        s->c_der ++;
        break;
    //TERMINAR EL RSTO DE OPERACIONES
    default:
        break;
    }

}

int testObjetivo(tEstado *e){

    //MORTYYYYYYYYYYYYYYY HAY QUE ACOTAR ME CAGO EN DIOOOOOOOOOOOOO
    return e->c_der == 3 && e->m_der == 3;

}





