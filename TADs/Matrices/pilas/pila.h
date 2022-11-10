#ifndef __PILA_H
#define __PILA_H

#define MAX 100

#ifndef __TIPO_ELEMENTO
#define __TIPO_ELEMENTO
typedef int tipoElemento;
#endif

#ifndef __PILA
#define __PILA
typedef struct { 
	int tope;
    tipoElemento elemento[MAX]; 
} Pila;
#endif

int pilaCreaVacia(Pila *p);
int pilaVacia(Pila *p);
int pilaInserta(Pila *p, tipoElemento elemento);
tipoElemento pilaSuprime(Pila *p);

#endif