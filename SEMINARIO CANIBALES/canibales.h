//MOVIMIETNTOS A LA DERECHA
#define C1_DER 1
#define C2_DER 2
#define M1_DER 3
#define M2_DER 4
#define C1M1_DER 5

//MOVIMIENTOS A LA IZQUIERDA
#define C1_IZQ 6
#define C2_IZQ 7
#define M1_IZQ 8
#define M2_IZQ 9
#define C1M1_IZQ 10

#define NUM_OPERADORES 10

#define IZQ -1
#define DER 1

//tEstado que tiene los valores iniciales del problema
typedef struct {
    int c_izq, m_izq, c_der, m_der, barca;
} tEstado;

//Cabeceras de funciones
tEstado *crearEstado(int c_izq, int m_izq, int c_der, int m_der);
int testObjetivo(tEstado *e);
tEstado *aplicaOperador(unsigned op, tEstado *e);
