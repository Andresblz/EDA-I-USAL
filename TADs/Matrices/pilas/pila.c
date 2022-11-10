#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int pilaCreaVacia(Pila *p) {
    if (p == NULL) return -1;
    p->tope = -1;
    return 0;
}

int pilaVacia(Pila *p) {
    if (p == NULL || p->elemento == NULL) return -1;
    if (p->tope <= 1) return 1;
    return 0;
}

int pilaInserta(Pila *p, tipoElemento elemento) {
    if (p == NULL || p->elemento == NULL || p->tope >= (MAX - 1)) return -1;

    p->tope = p->tope+1;
    p->elemento[p->tope] = elemento;

    return 0;
}

tipoElemento pilaSuprime(Pila *p) {
    if (p == NULL || p->elemento == NULL || p->tope <= -1) return -1;

    tipoElemento valor = p->elemento[p->tope];
    p->tope = p->tope-1;

    return valor;
}