#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int algoritmoRecursivo(int *, int, int);
int *crearVector(int, int);

int main(int argc, char *argv[]) {
    double tiempoInicial, tiempoFinal, tiempoMinimo = 10*CLOCKS_PER_SEC, tiempo;
    int valorDevuelto, *mat, repeticiones = 0, rango = 1000, numElementos;
    FILE *f;

    if (argc > 2 || argc < 2) {
      printf("\n Uso: ./enunciado7 <número de elementos>\n\n");
      return -1;
   }
   if (argc == 2) numElementos = atoi(argv[1]);

    mat = crearVector(numElementos, rango);

    f = fopen("enunciado7.txt", "w+");
	fprintf(f, "RESULTADOS EJECUCION\n");

    tiempoInicial = tiempoFinal = (double)clock();

    while (tiempoFinal-tiempoInicial < tiempoMinimo) { 
        valorDevuelto = algoritmoRecursivo(mat, 0, numElementos-1);
        repeticiones++;
        tiempoFinal = (double)clock();
    }

    tiempo =  (tiempoFinal - tiempoInicial) / (double)CLOCKS_PER_SEC/repeticiones;
                    
    for(int i = 0; i < numElementos; i++) fprintf(f, "\t%d", mat[i]);
    fprintf(f, "\nTiempo medio ejecucion: %.2f/%d/%d = %f", tiempoFinal - tiempoInicial, CLOCKS_PER_SEC, repeticiones, tiempo);
    fprintf(f, "\nResultado = %d", valorDevuelto);

    free(mat);

    return 0;
}

int algoritmoRecursivo(int *vector, int base, int tope) {
    int aux1, aux2;

    if (base == tope) return(vector[base]);
    else {
        aux1 = algoritmoRecursivo(vector, base, (base+tope)/2);
        aux2 = algoritmoRecursivo(vector, ((base+tope)/2)+1, tope);
        if (aux1 > aux2) return aux1;
        else return aux2;
    }
}

int *crearVector (int numElementos, int rango) {
  int *vector, i;
  srand(time(NULL));

  vector = malloc(numElementos * sizeof(int));
  for (i = 0; i < numElementos; i++) vector[i] = rand()%rango ;

  return vector;
}