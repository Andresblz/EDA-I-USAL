#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include "ordenacion.h"

int multiplicacionClasica(int, int);
int multiplicacionRusa(int, int);
int multiplicacionDivide(int, int);
int multiplicacionEvidente(int, int);

int maxCifras(int, int);
bool potenciaDos(int);

int main(int argc, char *argv[]) { 
	double tiempoInicial, tiempoFinal, tiempoMinimo = 10*CLOCKS_PER_SEC, tiempo;
	int *vector, *vectorOrdenado, rango = 100000, repeticiones, numEjecuciones, numRepeticiones = 0, aleatorio,
        resultado = 0, opt, multiplicador = 0, multiplicando = 0, alg = 0;
    bool num1, num2;
	FILE *f;

	f = fopen("enunciado4.txt", "w+");
	fprintf(f, "RESULTADOS EJECUCION");

    do {
        system("clear");
        printf("=======================================\n");
        printf("            CALCULO TIEMPOS            \n");
        printf("=======================================\n");
        printf("Ultimo algoritmo ejecutado: %d\n", alg);
        printf("Repeticiones: %d\n", numRepeticiones);
        printf("Multiplicando: %d\n", multiplicando);
        printf("Multiplicador: %d\n", multiplicador);
        printf("Resultado: %d\n", resultado);
        printf("=======================================\n");

        printf("\n\n 1.- Numero minimo de repeticiones");
        printf("\n 2.- Multiplicando");
        printf("\n 3.- Multiplicador");
        printf("\n\n 4.- Clasica");
        printf("\n 5.- Rusa");
        printf("\n 6.- Divide y venceras");
        printf("\n 7.- Evidente o iterativa");
        printf("\n\n 0.- Salir");

        printf("\n\nOpcion? ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                printf("\nNumero minimo de repeticiones? ");
                scanf("%d", &numRepeticiones);
                break;

            case 2:
                printf("\nMultiplicando? ");
                scanf("%d", &multiplicando);
                num1 = potenciaDos(multiplicando);
                break;

            case 3:
                printf("\nMultiplicador? ");
                scanf("%d", &multiplicador);
                num2 = potenciaDos(multiplicador);
                break;

            case 4: /* Clasica */
                if(numRepeticiones == 0 || multiplicador == 0 || multiplicando == 0) {
                    printf("\n\nIntroduzca el numero minimo de repeticiones y/o el valor de n.\n");
                    break;
                } else {
                    repeticiones = 0;
                    tiempoInicial = tiempoFinal = (double)clock();

                    while ((tiempoFinal-tiempoInicial < tiempoMinimo) || (repeticiones < numRepeticiones)) { 
                        resultado = multiplicacionClasica(multiplicando, multiplicador);
                        repeticiones++;
                        tiempoFinal = (double)clock();
                    }

                    tiempo =  (tiempoFinal - tiempoInicial) / (double)CLOCKS_PER_SEC/repeticiones;

                    fprintf(f,"\n\nAlgoritmo 1");
                    fprintf(f,"\nresultado   ;tiempoMedio;  repeticiones\n");
                    fprintf(f, " %d ;%g ; %d \n", resultado, tiempo, repeticiones);
                    alg = 1;
                }
                break;

            case 5: /* Rusa */
                if(numRepeticiones == 0 || multiplicador == 0 || multiplicando == 0) {
                    printf("\n\nIntroduzca el numero minimo de repeticiones y/o el valor de n.\n");
                    break;
                } else {
                    repeticiones = 0;
                    tiempoInicial = tiempoFinal = (double)clock();

                    while ((tiempoFinal-tiempoInicial < tiempoMinimo) || (repeticiones < numRepeticiones)) { 
                        resultado = multiplicacionRusa(multiplicando, multiplicador);
                        repeticiones++;
                        tiempoFinal = (double)clock();
                    }

                    tiempo =  (tiempoFinal - tiempoInicial) / (double)CLOCKS_PER_SEC/repeticiones;

                    fprintf(f,"\n\nAlgoritmo 2");
                    fprintf(f,"\nresultado   ;tiempoMedio;  repeticiones\n");
                    fprintf(f, " %d ;%g ; %d \n", resultado, tiempo, repeticiones);
                    alg = 2;
                }
                break;

            case 6: /* Divide y venceras */
                if(numRepeticiones == 0 || multiplicador == 0 || multiplicando == 0) {
                    printf("\n\nIntroduzca el numero minimo de repeticiones y/o el valor de n.\n");
                    break;
                } else if (num1 != num2 || num1 == false || num2 == false) {
                    printf("\n\nNo cumple condiciones necesarias\n");
                    break;
                } else {
                    repeticiones = 0;
                    tiempoInicial = tiempoFinal = (double)clock();

                    while ((tiempoFinal-tiempoInicial < tiempoMinimo) || (repeticiones < numRepeticiones)) { 
                        resultado = multiplicacionDivide(multiplicando, multiplicador);
                        repeticiones++;
                        tiempoFinal = (double)clock();
                    }

                    tiempo =  (tiempoFinal - tiempoInicial) / (double)CLOCKS_PER_SEC/repeticiones;

                    fprintf(f,"\n\nAlgoritmo 3");
                    fprintf(f,"\nresultado   ;tiempoMedio;  repeticiones\n");
                    fprintf(f, " %d ;%g ; %d \n", resultado, tiempo, repeticiones);
                    alg = 3;
                }
                break;

            case 7: /* Evidente o iterativa */
                if(numRepeticiones == 0 || multiplicador == 0 || multiplicando == 0) {
                    printf("\n\nIntroduzca el numero minimo de repeticiones y/o el valor de n.\n");
                    break;
                } else {
                    repeticiones = 0;
                    tiempoInicial = tiempoFinal = (double)clock();

                    while ((tiempoFinal-tiempoInicial < tiempoMinimo) || (repeticiones < numRepeticiones)) { 
                        resultado = multiplicacionEvidente(multiplicando, multiplicador);
                        repeticiones++;
                        tiempoFinal = (double)clock();
                    }

                    tiempo =  (tiempoFinal - tiempoInicial) / (double)CLOCKS_PER_SEC/repeticiones;

                    fprintf(f,"\n\nAlgoritmo 4");
                    fprintf(f,"\nresultado   ;tiempoMedio;  repeticiones\n");
                    fprintf(f, " %d ;%g ; %d \n", resultado, tiempo, repeticiones);
                    alg = 4;
                }
                break;

            default:
                break;
        }
    } while (opt != 0);

	fclose(f);
	return 0;
}

int multiplicacionClasica(int mo, int mr) {
    int resultado = 0, sumando = 0, lon = floor(log10(abs(mr))) + 1, mr1[lon];

    for(int i = 0; mr != 0; i++) {
        mr1[i] = mr % 10;
        mr /= 10;
    }

    for(int i = 0; i < lon; i++) {
        sumando = mr1[i] * mo;
        resultado += (pow(10, i) * sumando);
    }

    return resultado;
}

int multiplicacionRusa(int mo, int mr) {
    int resultado = 0;

    while (mo != 0) {
        if ((mo % 2) != 0) {
            resultado += mr;
        }
        mo /= 2;
        mr *= 2;
    }

    return resultado;
}

int multiplicacionDivide(int mo, int mr) {
    int n, s, w, x, v, y, pot, pot1;

    n = maxCifras(mo, mr);
    
    if (n == 2) {
        return multiplicacionClasica(mo, mr);
    } else {
        s = n / 2;
        pot = pow(10,s);
        pot1 = pow(10,2*s);
        w = mo / pot;
        x = mo % pot;
        v = mr / pot;
        y = mr % pot;
    }

    return (multiplicacionDivide(w,v) * pot1 +
            multiplicacionDivide(w,y) * pot +
            multiplicacionDivide(x,v) * pot +
            multiplicacionDivide(x,y));
}

int maxCifras(int mo, int mr) {
    if (mo == 0 || mr == 0) return 0;
    if (mo > mr) {
        return floor(log10(abs(mo))) + 1;
    } else {
        return floor(log10(abs(mr))) + 1;
    }
}

int multiplicacionEvidente(int mo, int mr) {
    int resultado = 0, i = mr;

    while (i >= 1) {
        resultado += mo;
        i -= 1;
    }

    return resultado;
}

bool potenciaDos(int x) {
    return (x != 0) && ((x & x - 1) == 0);
}