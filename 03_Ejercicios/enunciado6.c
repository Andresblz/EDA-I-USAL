#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

long potenciaRecursivo(int, int);
long potenciaIterativo(int, int);

int main() {
    double tiempoInicial, tiempoFinal, tiempoMinimo = 10*CLOCKS_PER_SEC, tiempo;
    int opt, repeticiones, pot = 0, num = 0;
    long res = 0;
    FILE *f;

    f = fopen("enunciado6.txt", "w+");
	fprintf(f, "RESULTADOS EJECUCION\n");

    do {
        system("clear");
        printf("=======================================\n");
        printf("            CALCULO TIEMPOS            \n");
        printf("=======================================\n");
        printf("Numero: %d\n", num);
        printf("Potencia: %d\n", pot);
        printf("Resultado: %ld\n", res);
        printf("=======================================\n");
        printf("\n\t1.- Introducir numero");
        printf("\n\t2.- Introducir exponente");
        printf("\n\t3.- Version recursiva");
        printf("\n\t4.- Version iterativa");
        printf("\n\n\t0.- Salir");

        printf("\n\nOpcion? ");
        scanf("%d", &opt);

        switch(opt) {
            case 1:
                printf("\nNumero para calcular factorial? ");
                scanf("%d", &num);
                break;

            case 2:
                printf("\nNumero del exponente? ");
                scanf("%d", &pot);
                break;

            case 3: /* Version recursiva */
                if (num == 0 || pot == 0) {
                    printf("\nIntroduce un numero y/o el exponente.\n");
                    break;
                } else {
                    repeticiones = 0;
                    tiempoInicial = tiempoFinal = (double)clock();

                    while (tiempoFinal-tiempoInicial < tiempoMinimo) { 
                        res = potenciaRecursivo(num, pot);
                        repeticiones++;
                        tiempoFinal = (double)clock();
                    }

                    tiempo =  (tiempoFinal - tiempoInicial) / (double)CLOCKS_PER_SEC/repeticiones;
                    
                    fprintf(f, "\n\nAlgoritmo Recursivo");
                    fprintf(f, "\nTiempo medio ejecucion: %.2f/%d/%d = %f", tiempoFinal - tiempoInicial, CLOCKS_PER_SEC, repeticiones, tiempo);
                    fprintf(f, "\nResultado = %ld", res);
                }
                break;

            case 4: /* Version iterativa */
                if (num == 0 || pot == 0) {
                    printf("\nIntroduce un numero y/o el exponente.\n");
                    break;
                } else {
                    repeticiones = 0;
                    tiempoInicial = tiempoFinal = (double)clock();

                    while (tiempoFinal-tiempoInicial < tiempoMinimo) { 
                        res = potenciaIterativo(num, pot);
                        repeticiones++;
                        tiempoFinal = (double)clock();
                    }

                    tiempo =  (tiempoFinal - tiempoInicial) / (double)CLOCKS_PER_SEC/repeticiones;
                    
                    fprintf(f, "\n\nAlgoritmo Iterativo");
                    fprintf(f, "\nTiempo medio ejecucion: %.2f/%d/%d = %f", tiempoFinal - tiempoInicial, CLOCKS_PER_SEC, repeticiones, tiempo);
                    fprintf(f, "\nResultado = %ld", res);
                }
                break;

            default:
                break;
        }
    } while (opt != 0);

    return 0;
}

long potenciaRecursivo(int num, int pot) {
    if (pot == 0) return 1;
    else if (pot > 0) return num * potenciaRecursivo(num, pot-1);
    else if (pot < 0) return (1 / num) * potenciaRecursivo(num, pot+1);
}

long potenciaIterativo(int num, int pot) {
    long res = 1;

    for(int i = 1; i <= pot; i++) res *= num;

    return res;
}