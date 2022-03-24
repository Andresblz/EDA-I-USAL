#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listaEnlazada.h"

int main(int argc, char *argv[]) {
    int numElementos, repeticiones = 0;
    double tiempoInicial, tiempoFinal, tiempoMinimo = 10*CLOCKS_PER_SEC, tiempo;
    ListaEnlazada raiz1;
    FILE *f;

    srand(time(NULL));

    if (argc > 2 || argc < 2) {
      printf("\n Uso: ./enunciado5 <número de elementos>\n\n");
      return -1;
    }
    if (argc == 2) numElementos = atoi(argv[1]);

    f = fopen("enunciado5.txt", "w+");
	  fprintf(f, "RESULTADOS EJECUCION\n");

    /* Crecion lista aleatoria */
    crearVacia(&raiz1);
    crearListaValoresAleatorios(&raiz1, numElementos);
    mostrarListaEnlazada(raiz1);

    tiempoInicial = tiempoFinal = (double)clock();

    while (tiempoFinal - tiempoInicial < tiempoMinimo) {
      invierteListaRecursivo(raiz1, &raiz1);
      repeticiones++;
      tiempoFinal = (double)clock();
    }
    tiempo =  (tiempoFinal - tiempoInicial) / (double)CLOCKS_PER_SEC / repeticiones;

    fprintf(f, "\ntiempo ; repeticiones");
    fprintf(f, "\n%f ; %d", tiempo, repeticiones);

    mostrarListaEnlazada(raiz1);
    liberarListaEnlazada(&raiz1);

    return 0;
}