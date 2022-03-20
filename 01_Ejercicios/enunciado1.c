#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacion.h"

int main(int argc, char *argv[]) { 
	double tiempoInicial, tiempoFinal, tiempoMinimo = 10*CLOCKS_PER_SEC, tiempo;
	int *vector, *vectorOrdenado, rango = 100000, i, repeticiones, numVectores, aleatorio;
	FILE *f;
        
	if (argc != 2) {
        printf("\n Uso: ./ejercicio <numero de vectores diferentes>\n\n");
        return -1;
    } else {
		numVectores = atoi(argv[1]); 
	} 

	f = fopen("enunciado1.txt", "w+");
	fprintf(f, "RESULTADOS EJECUCION");

	for(i = 0; i < numVectores; i++) {
		repeticiones = 0;
		aleatorio = rand()%10000;

		vector = crearVector(aleatorio, rango);

		tiempoInicial = tiempoFinal = (double)clock();

		while (tiempoFinal-tiempoInicial < tiempoMinimo) { 
			vectorOrdenado = ordenarBurbuja(vector, aleatorio);
			free(vectorOrdenado);	  
			repeticiones++;
			tiempoFinal = (double)clock();
		}

		tiempo =  (tiempoFinal - tiempoInicial) / (double)CLOCKS_PER_SEC/repeticiones;

		fprintf(f,"\n\nn           ;tiempoMedio;  repeticiones\n");
		fprintf(f, " %d ;%g ; %d \n", aleatorio, tiempo, repeticiones);
		free(vector);
	}

	fclose(f);
	return 0;
}