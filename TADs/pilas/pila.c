#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int pilaCreaVacia(Pila *p) {
	if (p == NULL) return -1;
	*p = NULL;
	return 0;
}

int pilaVacia(Pila *p) {
	if (p == NULL) return -1;
	return (*p == NULL);
}

int pilaInserta(Pila *p, tipoElemento elemento) {
	tipoCelda *c;

	if (p == NULL) return -1;
	if (NULL == (c = malloc(sizeof(tipoCelda)))) return -2;

	c->elemento = elemento;
	c->sig = NULL;

	if (*p == NULL) *p = c;
	else {
		c->sig = *p;
		*p = c;
	}
	return 0;
}

tipoElemento pilaSuprime(Pila *p) {
	tipoCelda *aBorrar = *p;
	tipoElemento elemento = aBorrar->elemento;

	if (p == NULL || *p == NULL) return -1;
	
	*p = (*p)->sig;
	free(aBorrar);
	return elemento;
}
