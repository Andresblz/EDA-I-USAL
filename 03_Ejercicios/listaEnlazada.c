#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "listaEnlazada.h"

int crearVacia(ListaEnlazadaRef raiz) {
    *raiz = NULL;
    return 0;
}

int estaVacia(ListaEnlazada raiz) {
    return (raiz == NULL);
}

tipoNodoRef creaNodo(tipoInfoRef info) {
    tipoNodoRef nuevo;
    if (NULL == (nuevo = (tipoNodoRef) malloc(sizeof(tipoNodo)))) {
        #ifdef DEBUG
        fprintf(stderr, "Error: reserva memoria\n");
        #endif
    } else {
        nuevo->info = *info;
        nuevo->sig = NULL;
    }
    return nuevo;
}

int liberarListaEnlazada(ListaEnlazadaRef raiz) {
    tipoNodoRef aborrar, aux;
    
    if (estaVacia(*raiz))
        return -1;
    else {
        aux = *raiz;
        while (aux != NULL) {
            aborrar = aux;
            aux = aux->sig;
            free (aborrar);
        }
        *raiz = NULL;
        return 0;
    }
}

int insertarNodo(ListaEnlazadaRef raiz, tipoInfoRef info) {
    tipoNodoRef nuevo, indice;

    if(NULL == (nuevo = creaNodo(info))) return -1;

    nuevo->info = *info;
    nuevo->sig = NULL;

    indice = *raiz;
    if(indice == NULL) *raiz = nuevo;
    else{
        while(indice->sig != NULL) indice = indice->sig;
        indice->sig = nuevo;
    }
    return 0;
}

void invierteListaRecursivo(tipoNodoRef root, tipoNodoRef *indice) {
    if (root->sig == NULL) {
        *indice = root;
        return;
    } else {
        invierteListaRecursivo(root->sig, indice);
        root->sig->sig = root;
        root->sig = NULL;
    }
}

int mostrarListaEnlazada(ListaEnlazada raiz) {
	tipoNodoRef aImprimir;
	int res = 0, i = 0;
	
	printf("%-14s%-10s\n","  Posicion", "Valor");
	printf("%-14s%-10s\n","  ==========", "======");

	aImprimir = raiz;
	while (aImprimir != NULL) {
		printf("\t%3d)\t%7d\n", i++, aImprimir->info);
		aImprimir = aImprimir->sig;
	}
	return res;
}

int crearListaValoresAleatorios(ListaEnlazadaRef raiz, int numNodos) {
	int i;
	tipoInfo temp;
	
	if (estaVacia(*raiz)) {
		srand(time(NULL));
		for (i = 0; i < numNodos; i++) {
            temp = rand()%100;
            insertarNodo(raiz, &temp);
		}
		return 0;
	}
	return -1;
}
