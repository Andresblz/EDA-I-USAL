#ifndef __LISTAENLAZADA_H__
#define __LISTAENLAZADA_H__

typedef int tipoInfo;
typedef tipoInfo *tipoInfoRef;

typedef struct tipoNodo{
    tipoInfo info;
    struct tipoNodo *sig;
}tipoNodo;

typedef tipoNodo *tipoNodoRef;
typedef tipoNodo *ListaEnlazada;
typedef ListaEnlazada *ListaEnlazadaRef;

int crearVacia(ListaEnlazadaRef raiz);
int estaVacia(ListaEnlazada raiz);
tipoNodoRef creaNodo(tipoInfoRef info);
int liberarListaEnlazada(ListaEnlazadaRef raiz);

void invierteListaRecursivo(tipoNodoRef root, tipoNodoRef *indice);
int eliminarNodo(ListaEnlazadaRef raiz, tipoNodoRef pos);

int mostrarListaEnlazada(ListaEnlazada raiz);
int crearListaValoresAleatorios(ListaEnlazadaRef raiz, int numNodos);

#endif
