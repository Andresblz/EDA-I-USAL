#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "ordenacion.h"

int main(int argc, char *argv[]) { 
	double tiempoInicial, tiempoFinal, tiempoMinimo = 10*CLOCKS_PER_SEC, tiempo;
	int *vector, *vectorOrdenado, rango = 100000, repeticiones, numEjecuciones, numRepeticiones = 0, aleatorio,
        i, j, k, c, x, opt, n = 0, num = 0;
	FILE *f;

	f = fopen("enunciado3.txt", "w+");
	fprintf(f, "RESULTADOS EJECUCION");

    do {
        system("clear");
        printf("=======================================\n");
        printf("            CALCULO TIEMPOS            \n");
        printf("=======================================\n");
        printf("Ultimo algoritmo ejecutado: %d\n", num);
        printf("Repeticiones: %d\n", numRepeticiones);
        printf("Valor de n: %d\n", n);
        printf("=======================================\n");

        printf("\n\n 1.- Numero minimo de repeticiones");
        printf("\n 2.- Valor de n");
        printf("\n\n 3.- Ejecutar algoritmo 1");
        printf("\n 4.- Ejecutar algoritmo 2");
        printf("\n 5.- Ejecutar algoritmo 3");
        printf("\n 6.- Ejecutar algoritmo 4");
        printf("\n 7.- Ejecutar algoritmo 5");
        printf("\n 8.- Ejecutar algoritmo 6");
        printf("\n 9.- Ejecutar algoritmo 7");
        printf("\n 10.- Ejecutar algoritmo 8");
        printf("\n 11.- Ejecutar algoritmo 9");
        printf("\n 12.- Ejecutar algoritmo 10");
        printf("\n 13.- Ejecutar algoritmo 11");
        printf("\n\n 0.- Salir");

        printf("\n\nOpcion? ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                printf("\nNumero minimo de repeticiones? ");
                scanf("%d", &numRepeticiones);
                break;

            case 2:
                printf("\nValor de n? ");
                scanf("%d", &n);
                break;

            case 3: /* Algoritmo 1 */
                if(numRepeticiones == 0 || n == 0) {
                    printf("\n\nIntroduzca el numero minimo de repeticiones y/o el valor de n.\n");
                    break;
                } else {
                    repeticiones = 0;
                    tiempoInicial = tiempoFinal = (double)clock();

                    while ((tiempoFinal-tiempoInicial < tiempoMinimo) || (repeticiones < numRepeticiones)) { 
                        c = 1;
                        for (i = 1; i < n; i++) {
                            for (j = 1; j < n; j++) {
                                c += 1;
                            }
                        }
                        repeticiones++;
                        tiempoFinal = (double)clock();
                    }

                    tiempo =  (tiempoFinal - tiempoInicial) / (double)CLOCKS_PER_SEC/repeticiones;

                    fprintf(f,"\n\nAlgoritmo 1");
                    fprintf(f,"\nn           ;tiempoMedio;  repeticiones\n");
                    fprintf(f, " %d ;%g ; %d \n", n, tiempo, repeticiones);
                    num = 1;
                }
                break;

            case 4: /* Algoritmo 2 */
                if(numRepeticiones == 0 || n == 0) {
                    printf("\n\nIntroduzca el numero minimo de repeticiones y/o el valor de n.\n");
                    break;
                } else {
                    repeticiones = 0;
                    tiempoInicial = tiempoFinal = (double)clock();

                    while ((tiempoFinal-tiempoInicial < tiempoMinimo) || (repeticiones < numRepeticiones)) { 
                        c = 1;
                        for (i = 1; i < n; i++) {
                            for(j = 1; j < n; j++) {
                                for(k = 1; k < 2; k++) {
                                    c += 1;
                                }
                            }
                        }
                        repeticiones++;
                        tiempoFinal = (double)clock();
                    }

                    tiempo =  (tiempoFinal - tiempoInicial) / (double)CLOCKS_PER_SEC/repeticiones;

                    fprintf(f,"\n\nAlgoritmo 2");
                    fprintf(f,"\nn           ;tiempoMedio;  repeticiones\n");
                    fprintf(f, " %d ;%g ; %d \n", n, tiempo, repeticiones);
                    num = 2;
                }
                break;

            case 5: /* Algoritmo 3 */
                if(numRepeticiones == 0 || n == 0) {
                    printf("\n\nIntroduzca el numero minimo de repeticiones y/o el valor de n.\n");
                    break;
                } else {
                    repeticiones = 0;
                    tiempoInicial = tiempoFinal = (double)clock();

                    while ((tiempoFinal-tiempoInicial < tiempoMinimo) || (repeticiones < numRepeticiones)) { 
                        c = 1;
                        for (i = 1; i < n; i++) {
                            for (j = 1; j < pow(n, 2); j++) {
                                for (k = 1; k < pow(n, 3); k++) {
                                    c += 1;
                                }
                            }
                        }
                        repeticiones++;
                        tiempoFinal = (double)clock();
                    }

                    tiempo =  (tiempoFinal - tiempoInicial) / (double)CLOCKS_PER_SEC/repeticiones;

                    fprintf(f,"\n\nAlgoritmo 3");
                    fprintf(f,"\nn           ;tiempoMedio;  repeticiones\n");
                    fprintf(f, " %d ;%g ; %d \n", n, tiempo, repeticiones);
                    num = 3;
                }
                break;

            case 6: /* Algoritmo 4 */
                if(numRepeticiones == 0 || n == 0) {
                    printf("\n\nIntroduzca el numero minimo de repeticiones y/o el valor de n.\n");
                    break;
                } else {
                    repeticiones = 0;
                    tiempoInicial = tiempoFinal = (double)clock();

                    while ((tiempoFinal-tiempoInicial < tiempoMinimo) || (repeticiones < numRepeticiones)) { 
                        c = 1;
                        for (i = 1; i < n; i++) {
                            for (j = 1; j < i; j++) {
                                c += 1;
                            }
                        }
                        repeticiones++;
                        tiempoFinal = (double)clock();
                    }

                    tiempo =  (tiempoFinal - tiempoInicial) / (double)CLOCKS_PER_SEC/repeticiones;

                    fprintf(f,"\n\nAlgoritmo 4");
                    fprintf(f,"\nn           ;tiempoMedio;  repeticiones\n");
                    fprintf(f, " %d ;%g ; %d \n", n, tiempo, repeticiones);
                    num = 4;
                }
                break;

            case 7: /* Algoritmo 5 */
                if(numRepeticiones == 0 || n == 0) {
                    printf("\n\nIntroduzca el numero minimo de repeticiones y/o el valor de n.\n");
                    break;
                } else {
                    repeticiones = 0;
                    tiempoInicial = tiempoFinal = (double)clock();

                    while ((tiempoFinal-tiempoInicial < tiempoMinimo) || (repeticiones < numRepeticiones)) { 
                        c = 1;
                        for (i = 1; i < n; i++) {
                            for (j = 1; j < n; j++) {
                                for (k = 1; k < j; k++) {
                                    c += 1;
                                }
                            }
                        }
                        repeticiones++;
                        tiempoFinal = (double)clock();
                    }

                    tiempo =  (tiempoFinal - tiempoInicial) / (double)CLOCKS_PER_SEC/repeticiones;

                    fprintf(f,"\n\nAlgoritmo 5");
                    fprintf(f,"\nn           ;tiempoMedio;  repeticiones\n");
                    fprintf(f, " %d ;%g ; %d \n", n, tiempo, repeticiones);
                    num = 5;
                }
                break;

            case 8: /* Algoritmo 6 */
                if(numRepeticiones == 0 || n == 0) {
                    printf("\n\nIntroduzca el numero minimo de repeticiones y/o el valor de n.\n");
                    break;
                } else {
                    repeticiones = 0;
                    tiempoInicial = tiempoFinal = (double)clock();

                    while ((tiempoFinal-tiempoInicial < tiempoMinimo) || (repeticiones < numRepeticiones)) { 
                        c = 1;
                        for (i = 1; i < n; i++) {
                            for (j = 1; j < i; j++) {
                                for (k = 1; k < j; k++) {
                                    c += 1;
                                }
                            }
                        }
                        repeticiones++;
                        tiempoFinal = (double)clock();
                    }

                    tiempo =  (tiempoFinal - tiempoInicial) / (double)CLOCKS_PER_SEC/repeticiones;

                    fprintf(f,"\n\nAlgoritmo 6");
                    fprintf(f,"\nn           ;tiempoMedio;  repeticiones\n");
                    fprintf(f, " %d ;%g ; %d \n", n, tiempo, repeticiones);
                    num = 6;
                }
                break;

            case 9: /* Algoritmo 7 */
                if(numRepeticiones == 0 || n == 0) {
                    printf("\n\nIntroduzca el numero minimo de repeticiones y/o el valor de n.\n");
                    break;
                } else {
                    repeticiones = 0;
                    tiempoInicial = tiempoFinal = (double)clock();

                    while ((tiempoFinal-tiempoInicial < tiempoMinimo) || (repeticiones < numRepeticiones)) { 
                        x = 0;
                        j = n;
                        while (j >= 1) {
                            x += 1;
                            j /= 2;
                        }
                        repeticiones++;
                        tiempoFinal = (double)clock();
                    }

                    tiempo =  (tiempoFinal - tiempoInicial) / (double)CLOCKS_PER_SEC/repeticiones;

                    fprintf(f,"\n\nAlgoritmo 7");
                    fprintf(f,"\nn           ;tiempoMedio;  repeticiones\n");
                    fprintf(f, " %d ;%g ; %d \n", n, tiempo, repeticiones);
                    num = 7;
                }
                break;

            case 10: /* Algoritmo 8 */
                if(numRepeticiones == 0 || n == 0) {
                    printf("\n\nIntroduzca el numero minimo de repeticiones y/o el valor de n.\n");
                    break;
                } else {
                    repeticiones = 0;
                    tiempoInicial = tiempoFinal = (double)clock();

                    while ((tiempoFinal-tiempoInicial < tiempoMinimo) || (repeticiones < numRepeticiones)) { 
                        x = 0;
                        j = n;
                        while (j >= 1) {
                            x += 1;
                            j /= 3;
                        }
                        repeticiones++;
                        tiempoFinal = (double)clock();
                    }

                    tiempo =  (tiempoFinal - tiempoInicial) / (double)CLOCKS_PER_SEC/repeticiones;

                    fprintf(f,"\n\nAlgoritmo 7");
                    fprintf(f,"\nn           ;tiempoMedio;  repeticiones\n");
                    fprintf(f, " %d ;%g ; %d \n", n, tiempo, repeticiones);
                    num = 8;
                }
                break;

            case 11: /* Algoritmo 9 */
                if(numRepeticiones == 0 || n == 0) {
                    printf("\n\nIntroduzca el numero minimo de repeticiones y/o el valor de n.\n");
                    break;
                } else {
                    repeticiones = 0;
                    tiempoInicial = tiempoFinal = (double)clock();

                    while ((tiempoFinal-tiempoInicial < tiempoMinimo) || (repeticiones < numRepeticiones)) { 
                        x = 0;
                        i = 1;
                        do {
                            j = 1;
                            while (j <= i) {
                                x += 1;
                                j *= 2;
                            }
                            i += 1;
                        } while (i < n);
                        repeticiones++;
                        tiempoFinal = (double)clock();
                    }

                    tiempo =  (tiempoFinal - tiempoInicial) / (double)CLOCKS_PER_SEC/repeticiones;

                    fprintf(f,"\n\nAlgoritmo 9");
                    fprintf(f,"\nn           ;tiempoMedio;  repeticiones\n");
                    fprintf(f, " %d ;%g ; %d \n", n, tiempo, repeticiones);
                    num = 9;
                }
                break;

            case 12: /* Algoritmo 10 */
                if(numRepeticiones == 0 || n == 0) {
                    printf("\n\nIntroduzca el numero minimo de repeticiones y/o el valor de n.\n");
                    break;
                } else {
                    repeticiones = 0;
                    tiempoInicial = tiempoFinal = (double)clock();

                    while ((tiempoFinal-tiempoInicial < tiempoMinimo) || (repeticiones < numRepeticiones)) { 
                        x = 0;
                        i = 1;
                        do {
                            j = 1;
                            while (j <= i) {
                                x += 1;
                                j += 2;
                            }
                            i += 1;
                        } while (i < n);
                        repeticiones++;
                        tiempoFinal = (double)clock();
                    }

                    tiempo =  (tiempoFinal - tiempoInicial) / (double)CLOCKS_PER_SEC/repeticiones;

                    fprintf(f,"\n\nAlgoritmo 10");
                    fprintf(f,"\nn           ;tiempoMedio;  repeticiones\n");
                    fprintf(f, " %d ;%g ; %d \n", n, tiempo, repeticiones);
                    num = 10;
                }
                break;

            case 13: /* Algoritmo 11 */
                if(numRepeticiones == 0 || n == 0) {
                    printf("\n\nIntroduzca el numero minimo de repeticiones y/o el valor de n.\n");
                    break;
                } else {
                    repeticiones = 0;
                    tiempoInicial = tiempoFinal = (double)clock();

                    while ((tiempoFinal-tiempoInicial < tiempoMinimo) || (repeticiones < numRepeticiones)) { 
                        x = 0;
                        i = 1;
                        while (i < n) {
                            for (j = 1; j < i; j++) {
                                x += 1;
                            } 
                            i *= 10;
                        }
                        repeticiones++;
                        tiempoFinal = (double)clock();
                    }

                    tiempo =  (tiempoFinal - tiempoInicial) / (double)CLOCKS_PER_SEC/repeticiones;

                    fprintf(f,"\n\nAlgoritmo 11");
                    fprintf(f,"\nn           ;tiempoMedio;  repeticiones\n");
                    fprintf(f, " %d ;%g ; %d \n", n, tiempo, repeticiones);
                    num = 11;
                }
                break;
                
            default:
                break;   
        }
    } while (opt != 0);

	fclose(f);
	return 0;
}
