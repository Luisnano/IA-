#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 8
#define IZQ 1
#define DER 2
#define NUM_OPERADORES 2

typedef struct
{
    int cinta [N];
    int ladoizq, ladoder;
    int robado, recuperado;
}tEstado;

tEstado *crearEstado(int cinta[]);
int esValido(unsigned op, tEstado *t);
tEstado *aplicaOperador(unsigned op, tEstado *s);
int testObjetivo (tEstado *e);