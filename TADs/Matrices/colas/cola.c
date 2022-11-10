#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

int colaCreaVacia(Cola *c) {
    if (c == NULL) return -1;
    c->tamanno = c->frente = 0;
    c->fondo = MAX-1;
    return 0;
}

int colaVacia(Cola *c) {
    if (c == NULL || c->elemento == NULL) return -1;
    return 0;
}

int colaInserta(Cola *c, tipoElemento elemento) {
    if (c == NULL || c->elemento == NULL || c->tamanno >= MAX-1) return -1;

    incrementarIndice(&c->fondo);
    c->elemento[c->fondo] = elemento;
    c->tamanno = c->tamanno+1;

    return 0;
}

tipoElemento colaSuprime(Cola *c) {
    if (c == NULL || c->elemento == NULL || !c->tamanno) return -1;

    tipoElemento valor = c->elemento[c->frente];
    incrementarIndice(&c->frente);
    c->tamanno = c->tamanno-1;

    return valor;
}

void incrementarIndice(int *x) {
    if (x >= MAX) *x = 0;
    *x = *x+1;
}