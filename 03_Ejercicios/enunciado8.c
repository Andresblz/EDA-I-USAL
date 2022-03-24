#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int algoritmoRecursivo(int *, int, int, int);
int *crearVector(int, int);

int main(int argc, char *argv[]) {
    int valorDevuelto, *vect, rango = 1000, numElementos;
    FILE *f;

    if (argc > 2 || argc < 2) {
      printf("\n Uso: ./enunciado8 <número de elementos>\n\n");
      return -1;
    }
    if (argc == 2) numElementos = atoi(argv[1]);

    vect = crearVector(numElementos, rango);

    for(int i = 0; i < numElementos; i++) printf("%8d", vect[i]);

    f = fopen("enunciado8.txt", "w+");
	  fprintf(f, "RESULTADOS EJECUCION\n");

    valorDevuelto = algoritmoRecursivo(vect, numElementos, 0, numElementos);
                    
    for(int i = 0; i < numElementos; i++) fprintf(f, "\t%d", vect[i]);
    fprintf(f, "\nResultado = %d", valorDevuelto);

    free(vect);
    return 0;
}

int algoritmoRecursivo(int *vector, int num, int base, int tope) {
    int k = (base + tope) / 2;

    if ((k == 1 || vector[k-1] <= vector[k]) && (k == num || vector[k+1] <= vector[k])) return k;
    else if (k > 1 && vector[k-1] > vector[k]) return algoritmoRecursivo(vector, tope, base, k-1);
    else return algoritmoRecursivo(vector, tope, k+1, tope);
}

int *crearVector (int numElementos, int rango) {
  int *vector, i;
  srand(time(NULL));

  vector = malloc(numElementos * sizeof(int));
  for (i = 0; i < numElementos; i++) vector[i] = rand()%rango ;

  return vector;
}