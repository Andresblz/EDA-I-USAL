#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

long fibonacciRecursivo(long);
long fibonacciIterativo(long);

int main() {
    double tiempoInicial, tiempoFinal, tiempoMinimo = 10*CLOCKS_PER_SEC, tiempo;
    int opt, repeticiones;
    long num = 0, fib = 0;
    FILE *f;

    f = fopen("enunciado4.txt", "w+");
	fprintf(f, "RESULTADOS EJECUCION\n");

    do {
        system("clear");
        printf("=======================================\n");
        printf("            CALCULO TIEMPOS            \n");
        printf("=======================================\n");
        printf("Numero: %ld\n", num);
        printf("Fibonacci: %ld\n", fib);
        printf("=======================================\n");
        printf("\n\t1.- Introducir numero");
        printf("\n\t2.- Version recursiva");
        printf("\n\t3.- Version iterativa");
        printf("\n\n\t0.- Salir");

        printf("\n\nOpcion? ");
        scanf("%d", &opt);

        switch(opt) {
            case 1:
                printf("\nNumero para calcular factorial? ");
                scanf("%ld", &num);
                break;

            case 2: /* Version recursiva */
                if (num == 0) {
                    printf("\nIntroduce un numero para calcular la sucesion de Fibonacci\n");
                    break;
                } else {
                    repeticiones = 0;
                    tiempoInicial = tiempoFinal = (double)clock();

                    while (tiempoFinal-tiempoInicial < tiempoMinimo) { 
                        fib = fibonacciRecursivo(num);
                        repeticiones++;
                        tiempoFinal = (double)clock();
                    }

                    tiempo =  (tiempoFinal - tiempoInicial) / (double)CLOCKS_PER_SEC/repeticiones;
                    
                    fprintf(f, "\n\nAlgoritmo Recursivo");
                    fprintf(f, "\nTiempo medio ejecucion: %.2f/%d/%d = %f", tiempoFinal - tiempoInicial, CLOCKS_PER_SEC, repeticiones, tiempo);
                    fprintf(f, "\nResultado = %ld", fib);
                }
                break;

            case 3: /* Version iterativa */
                if (num == 0) {
                    printf("\nIntroduce un numero para calcular la sucesion de Fibonacci\n");
                    break;
                } else {
                    repeticiones = 0;
                    tiempoInicial = tiempoFinal = (double)clock();

                    while (tiempoFinal-tiempoInicial < tiempoMinimo) { 
                        fib = fibonacciIterativo(num);
                        repeticiones++;
                        tiempoFinal = (double)clock();
                    }

                    tiempo =  (tiempoFinal - tiempoInicial) / (double)CLOCKS_PER_SEC/repeticiones;
                    
                    fprintf(f, "\n\nAlgoritmo Iterativo");
                    fprintf(f, "\nTiempo medio ejecucion: %.2f/%d/%d = %f", tiempoFinal - tiempoInicial, CLOCKS_PER_SEC, repeticiones, tiempo);
                    fprintf(f, "\nResultado = %ld", fib);
                }
                break;

            default:
                break;
        }
    } while (opt != 0);

    return 0;
}

long fibonacciRecursivo(long pos) {
    if (pos < 2) return pos;
    return fibonacciRecursivo(pos-1) + fibonacciRecursivo(pos-2);
}

long fibonacciIterativo(long pos) {
    long sig = 1, act = 0, temp = 0;
    
    for(int i = 1; i <= pos; i++) {
        temp = act;
        act = sig;
        sig += temp;
    }

    return act;
}