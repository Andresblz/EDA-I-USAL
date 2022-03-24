#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double factorialRecursivo(double);
double factorialIterativo(double);

int main() {
    double tiempoInicial, tiempoFinal, tiempoMinimo = 10*CLOCKS_PER_SEC, tiempo;
    int opt, repeticiones;
    double num = 0, fact = 0;
    FILE *f;

    f = fopen("enunciado3.txt", "w+");
	fprintf(f, "RESULTADOS EJECUCION\n");

    do {
        system("clear");
        printf("=======================================\n");
        printf("            CALCULO TIEMPOS            \n");
        printf("=======================================\n");
        printf("Numero: %.f\n", num);
        printf("Factorial: %.f\n", fact);
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
                scanf("%lf", &num);
                break;

            case 2: /* Version recursiva */
                if (num == 0) {
                    printf("\nIntroduce un numero para calcular el factorial\n");
                    break;
                } else {
                    repeticiones = 0;
                    tiempoInicial = tiempoFinal = (double)clock();

                    while (tiempoFinal-tiempoInicial < tiempoMinimo) { 
                        fact = factorialRecursivo(num);
                        repeticiones++;
                        tiempoFinal = (double)clock();
                    }

                    tiempo =  (tiempoFinal - tiempoInicial) / (double)CLOCKS_PER_SEC/repeticiones;
                    
                    fprintf(f, "\n\nAlgoritmo Recursivo");
                    fprintf(f, "\nTiempo medio ejecucion: %.2f/%d/%d = %f", tiempoFinal - tiempoInicial, CLOCKS_PER_SEC, repeticiones, tiempo);
                    fprintf(f, "\nResultado = %.f", fact);
                }
                break;

            case 3: /* Version iterativa */
                if (num == 0) {
                    printf("\nIntroduce un numero para calcular el factorial\n");
                    break;
                } else {
                    repeticiones = 0;
                    tiempoInicial = tiempoFinal = (double)clock();

                    while (tiempoFinal-tiempoInicial < tiempoMinimo) { 
                        fact = factorialIterativo(num);
                        repeticiones++;
                        tiempoFinal = (double)clock();
                    }

                    tiempo =  (tiempoFinal - tiempoInicial) / (double)CLOCKS_PER_SEC/repeticiones;
                    
                    fprintf(f, "\n\nAlgoritmo Iterativo");
                    fprintf(f, "\nTiempo medio ejecucion: %.2f/%d/%d = %f", tiempoFinal - tiempoInicial, CLOCKS_PER_SEC, repeticiones, tiempo);
                    fprintf(f, "\nResultado = %.f", fact);
                }
                break;

            default:
                break;
        }
    } while (opt != 0);

    return 0;
}

double factorialRecursivo(double n) {
    if (n <= 1) return 1;
    return n * factorialRecursivo(n-1);
}

double factorialIterativo(double n) {
    double factorial = 1;

    for(int i = 1; i <= n; i++) factorial *= i;

    return factorial;
}