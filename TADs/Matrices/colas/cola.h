#ifndef __COLA_H
#define __COLA_H

#define MAX 100

#ifndef __TIPO_ELEMENTO
#define __TIPO_ELEMENTO
typedef int tipoElemento;
#endif

#ifndef __COLA
#define __COLA
typedef struct {
    int tamanno;
    int frente, fondo;
	tipoElemento elemento[MAX];
} Cola;
#endif

int colaCreaVacia(Cola *c);
int colaVacia(Cola *c);
int colaInserta(Cola *c, tipoElemento elemento);
tipoElemento colaSuprime(Cola *c);
void incrementarIndice(int *x);

#endif