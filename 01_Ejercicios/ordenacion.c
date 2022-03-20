#include <stdlib.h>
#include "ordenacion.h"

int *crearVector (int numElementos, int rango) {
  int *vector, i;

  vector = malloc(numElementos * sizeof(int));
  for (i = 0; i < numElementos; i++) vector[i] = rand()%rango ;

  return vector;
}

int *ordenarBurbuja (int *vector, int numElementos) { 
  int *nuevo, i, j;

  nuevo = (int *)malloc(numElementos * sizeof(int));

  for (i = 0; i < numElementos; i++)
    nuevo [i] = vector [i];

    for (i = 0; i < numElementos; i++) {
      for (j = 0; j < numElementos-1-i; j++){
        if (nuevo [j] > nuevo [j+1]) {
          intercambiar(&(nuevo[j]), &(nuevo[j+1]));
        }
      }
    }

  return nuevo;
}

void intercambiar (int *x, int *y) {
  int temp;

  temp = *x;
  *x = *y;
  *y = temp;
}