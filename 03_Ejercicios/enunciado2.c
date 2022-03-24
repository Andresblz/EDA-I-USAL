#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "algoritmos.h"

int contadorExterno, contadorMedio, contadorInterno;

int main(int argc, char *argv[]) { 
	double tiempoInicial, tiempoFinal, tiempoMinimo = 10*CLOCKS_PER_SEC, tiempo;
	int *vector, *vectorOrdenado, rango = 100000, repeticiones, numEjecuciones,
        opt, n = 0, num = 0;
	FILE *f;

	f = fopen("enunciado2.txt", "w+");
	fprintf(f, "RESULTADOS EJECUCION\n");

    do {
        system("clear");
        printf("=======================================\n");
        printf("            CALCULO TIEMPOS            \n");
        printf("=======================================\n");
        printf("Ultimo algoritmo ejecutado: %d\n", num);
        printf("Valor de n: %d\n", n);
        printf("=======================================\n");

        printf("\n 1.- Ejecutar algoritmo 1");
        printf("\n 2.- Ejecutar algoritmo 2");
        printf("\n 3.- Ejecutar algoritmo 3");
        printf("\n 4.- Ejecutar algoritmo 4");
        printf("\n 5.- Ejecutar algoritmo 5");
        printf("\n 6.- Ejecutar algoritmo 6");
        printf("\n 7.- Ejecutar algoritmo 7");
        printf("\n 8.- Ejecutar algoritmo 8");
        printf("\n 9.- Ejecutar algoritmo 9");
        printf("\n 10.- Ejecutar algoritmo 10");
        printf("\n 11.- Ejecutar algoritmo 11");
        printf("\n\n 12.- Valor de n");
        printf("\n 0.- Salir");
        

        printf("\n\nOpcion? ");
        scanf("%d", &opt);

        switch (opt) {
            case 12:
                printf("\nValor de n? ");
                scanf("%d", &n);
                break;

            case 1: /* Algoritmo 1 */
                if(n == 0) {
                    printf("\n\nIntroduzca el valor de n.\n");
                    break;
                } else {
                    contadorExterno = contadorMedio = contadorInterno = 0;
                    repeticiones = 0;
                    tiempoInicial = tiempoFinal = (double)clock();

                    while (tiempoFinal-tiempoInicial < tiempoMinimo) { 
                        algA(n);
                        repeticiones++;
                        tiempoFinal = (double)clock();
                    }

                    tiempo =  (tiempoFinal - tiempoInicial) / (double)CLOCKS_PER_SEC/repeticiones;
                    
                    fprintf(f, "\n\nAlgoritmo A");
                    fprintf(f, "\nTiempo medio ejecucion: %.2f/%d/%d = %f", tiempoFinal - tiempoInicial, CLOCKS_PER_SEC, repeticiones, tiempo);
                    fprintf(f, "\nPromedio contadorExterno = %f", contadorExterno/(double)repeticiones);
                    fprintf(f, "\nPromedio contadorInterno = %f", contadorInterno/(double)repeticiones);
                    num = 1;
                }
                break;

            case 2: /* Algoritmo 2 */
                if(n == 0) {
                    printf("\n\nIntroduzca el valor de n.\n");
                    break;
                } else {
                    contadorExterno = contadorMedio = contadorInterno = 0;
                    repeticiones = 0;
                    tiempoInicial = tiempoFinal = (double)clock();

                    while (tiempoFinal-tiempoInicial < tiempoMinimo) { 
                        algB(n);
                        repeticiones++;
                        tiempoFinal = (double)clock();
                    }

                    tiempo =  (tiempoFinal - tiempoInicial) / (double)CLOCKS_PER_SEC/repeticiones;
                    
                    fprintf(f, "\n\nAlgoritmo B");
                    fprintf(f, "\nTiempo medio ejecucion: %.2f/%d/%d = %f", tiempoFinal - tiempoInicial, CLOCKS_PER_SEC, repeticiones, tiempo);
                    fprintf(f, "\nPromedio contadorExterno = %f", contadorExterno/(double)repeticiones);
                    fprintf(f, "\nPromedio contadorMedio = %f", contadorMedio/(double)repeticiones);
                    fprintf(f, "\nPromedio contadorInterno = %f", contadorInterno/(double)repeticiones);
                    num = 2;
                }
                break;

            case 3: /* Algoritmo 3 */
                if(n == 0) {
                    printf("\n\nIntroduzca el valor de n.\n");
                    break;
                } else {
                    contadorExterno = contadorMedio = contadorInterno = 0;
                    repeticiones = 0;
                    tiempoInicial = tiempoFinal = (double)clock();

                    while (tiempoFinal-tiempoInicial < tiempoMinimo) { 
                        algC(n);
                        repeticiones++;
                        tiempoFinal = (double)clock();
                    }

                    tiempo =  (tiempoFinal - tiempoInicial) / (double)CLOCKS_PER_SEC/repeticiones;
                    
                    fprintf(f, "\n\nAlgoritmo C");
                    fprintf(f, "\nTiempo medio ejecucion: %.2f/%d/%d = %f", tiempoFinal - tiempoInicial, CLOCKS_PER_SEC, repeticiones, tiempo);
                    fprintf(f, "\nPromedio contadorExterno = %f", contadorExterno/(double)repeticiones);
                    fprintf(f, "\nPromedio contadorMedio = %f", contadorMedio/(double)repeticiones);
                    fprintf(f, "\nPromedio contadorInterno = %f", contadorInterno/(double)repeticiones);
                    num = 3;
                }
                break;

            case 4: /* Algoritmo 4 */
                if(n == 0) {
                    printf("\n\nIntroduzca el valor de n.\n");
                    break;
                } else {
                    contadorExterno = contadorMedio = contadorInterno = 0;
                    repeticiones = 0;
                    tiempoInicial = tiempoFinal = (double)clock();

                    while (tiempoFinal-tiempoInicial < tiempoMinimo) { 
                        algD(n);
                        repeticiones++;
                        tiempoFinal = (double)clock();
                    }

                    tiempo =  (tiempoFinal - tiempoInicial) / (double)CLOCKS_PER_SEC/repeticiones;
                    
                    fprintf(f, "\n\nAlgoritmo D");
                    fprintf(f, "\nTiempo medio ejecucion: %.2f/%d/%d = %f", tiempoFinal - tiempoInicial, CLOCKS_PER_SEC, repeticiones, tiempo);
                    fprintf(f, "\nPromedio contadorExterno = %f", contadorExterno/(double)repeticiones);
                    fprintf(f, "\nPromedio contadorInterno = %f", contadorInterno/(double)repeticiones);
                    num = 4;
                }
                break;

            case 5: /* Algoritmo 5 */
                if(n == 0) {
                    printf("\n\nIntroduzca el valor de n.\n");
                    break;
                } else {
                    contadorExterno = contadorMedio = contadorInterno = 0;
                    repeticiones = 0;
                    tiempoInicial = tiempoFinal = (double)clock();

                    while (tiempoFinal-tiempoInicial < tiempoMinimo) { 
                        algE(n);
                        repeticiones++;
                        tiempoFinal = (double)clock();
                    }

                    tiempo =  (tiempoFinal - tiempoInicial) / (double)CLOCKS_PER_SEC/repeticiones;

                    fprintf(f, "\n\nAlgoritmo E");
                    fprintf(f, "\nTiempo medio ejecucion: %.2f/%d/%d = %f", tiempoFinal - tiempoInicial, CLOCKS_PER_SEC, repeticiones, tiempo);
                    fprintf(f, "\nPromedio contadorExterno = %f", contadorExterno/(double)repeticiones);
                    fprintf(f, "\nPromedio contadorMedio = %f", contadorMedio/(double)repeticiones);
                    fprintf(f, "\nPromedio contadorInterno = %f", contadorInterno/(double)repeticiones);
                    num = 5;
                }
                break;

            case 6: /* Algoritmo 6 */
                if( n == 0) {
                    printf("\n\nIntroduzca el valor de n.\n");
                    break;
                } else {
                    contadorExterno = contadorMedio = contadorInterno = 0;
                    repeticiones = 0;
                    tiempoInicial = tiempoFinal = (double)clock();

                    while (tiempoFinal-tiempoInicial < tiempoMinimo) { 
                        algF(n);
                        repeticiones++;
                        tiempoFinal = (double)clock();
                    }

                    tiempo =  (tiempoFinal - tiempoInicial) / (double)CLOCKS_PER_SEC/repeticiones;

                    fprintf(f, "\n\nAlgoritmo F");
                    fprintf(f, "\nTiempo medio ejecucion: %.2f/%d/%d = %f", tiempoFinal - tiempoInicial, CLOCKS_PER_SEC, repeticiones, tiempo);
                    fprintf(f, "\nPromedio contadorExterno = %f", contadorExterno/(double)repeticiones);
                    fprintf(f, "\nPromedio contadorMedio = %f", contadorMedio/(double)repeticiones);
                    fprintf(f, "\nPromedio contadorInterno = %f", contadorInterno/(double)repeticiones);
                    num = 6;
                }
                break;

            case 7: /* Algoritmo 7 */
                if(n == 0) {
                    printf("\n\nIntroduzca el valor de n.\n");
                    break;
                } else {
                    contadorExterno = contadorMedio = contadorInterno = 0;
                    repeticiones = 0;
                    tiempoInicial = tiempoFinal = (double)clock();

                    while (tiempoFinal-tiempoInicial < tiempoMinimo) { 
                        algG(n);
                        repeticiones++;
                        tiempoFinal = (double)clock();
                    }

                    tiempo =  (tiempoFinal - tiempoInicial) / (double)CLOCKS_PER_SEC/repeticiones;

                    fprintf(f, "\n\nAlgoritmo G");
                    fprintf(f, "\nTiempo medio ejecucion: %.2f/%d/%d = %f", tiempoFinal - tiempoInicial, CLOCKS_PER_SEC, repeticiones, tiempo);
                    fprintf(f, "\nPromedio contadorInterno = %f", contadorInterno/(double)repeticiones);
                    num = 7;
                }
                break;

            case 8: /* Algoritmo 8 */
                if(n == 0) {
                    printf("\n\nIntroduzca el valor de n.\n");
                    break;
                } else {
                    contadorExterno = contadorMedio = contadorInterno = 0;
                    repeticiones = 0;
                    tiempoInicial = tiempoFinal = (double)clock();

                    while (tiempoFinal-tiempoInicial < tiempoMinimo) { 
                        algH(n);
                        repeticiones++;
                        tiempoFinal = (double)clock();
                    }

                    tiempo =  (tiempoFinal - tiempoInicial) / (double)CLOCKS_PER_SEC/repeticiones;

                    fprintf(f, "\n\nAlgoritmo H");
                    fprintf(f, "\nTiempo medio ejecucion: %.2f/%d/%d = %f", tiempoFinal - tiempoInicial, CLOCKS_PER_SEC, repeticiones, tiempo);
                    fprintf(f, "\nPromedio contadorInterno = %f", contadorInterno/(double)repeticiones);
                    num = 8;
                }
                break;

            case 9: /* Algoritmo 9 */
                if(n == 0) {
                    printf("\n\nIntroduzca el valor de n.\n");
                    break;
                } else {
                    contadorExterno = contadorMedio = contadorInterno = 0;
                    repeticiones = 0;
                    tiempoInicial = tiempoFinal = (double)clock();

                    while (tiempoFinal-tiempoInicial < tiempoMinimo) { 
                        algI(n);
                        repeticiones++;
                        tiempoFinal = (double)clock();
                    }

                    tiempo =  (tiempoFinal - tiempoInicial) / (double)CLOCKS_PER_SEC/repeticiones;

                    fprintf(f, "\n\nAlgoritmo I");
                    fprintf(f, "\nTiempo medio ejecucion: %.2f/%d/%d = %f", tiempoFinal - tiempoInicial, CLOCKS_PER_SEC, repeticiones, tiempo);
                    fprintf(f, "\nPromedio contadorExterno = %f", contadorExterno/(double)repeticiones);
                    fprintf(f, "\nPromedio contadorInterno = %f", contadorInterno/(double)repeticiones);
                    num = 9;
                }
                break;

            case 10: /* Algoritmo 10 */
                if(n == 0) {
                    printf("\n\nIntroduzca el valor de n.\n");
                    break;
                } else {
                    contadorExterno = contadorMedio = contadorInterno = 0;
                    repeticiones = 0;
                    tiempoInicial = tiempoFinal = (double)clock();

                    while (tiempoFinal-tiempoInicial < tiempoMinimo) { 
                        algJ(n);
                        repeticiones++;
                        tiempoFinal = (double)clock();
                    }

                    tiempo =  (tiempoFinal - tiempoInicial) / (double)CLOCKS_PER_SEC/repeticiones;

                    fprintf(f, "\n\nAlgoritmo J");
                    fprintf(f, "\nTiempo medio ejecucion: %.2f/%d/%d = %f", tiempoFinal - tiempoInicial, CLOCKS_PER_SEC, repeticiones, tiempo);
                    fprintf(f, "\nPromedio contadorExterno = %f", contadorExterno/(double)repeticiones);
                    fprintf(f, "\nPromedio contadorInterno = %f", contadorInterno/(double)repeticiones);
                    num = 10;
                }
                break;

            case 11: /* Algoritmo 11 */
                if(n == 0) {
                    printf("\n\nIntroduzca el valor de n.\n");
                    break;
                } else {
                    contadorExterno = contadorMedio = contadorInterno = 0;
                    repeticiones = 0;
                    tiempoInicial = tiempoFinal = (double)clock();

                    while (tiempoFinal-tiempoInicial < tiempoMinimo) { 
                        algK(n);
                        repeticiones++;
                        tiempoFinal = (double)clock();
                    }

                    tiempo =  (tiempoFinal - tiempoInicial) / (double)CLOCKS_PER_SEC/repeticiones;

                    fprintf(f, "\n\nAlgoritmo K");
                    fprintf(f, "\nTiempo medio ejecucion: %.2f/%d/%d = %f", tiempoFinal - tiempoInicial, CLOCKS_PER_SEC, repeticiones, tiempo);
                    fprintf(f, "\nPromedio contadorExterno = %f", contadorExterno/(double)repeticiones);
                    fprintf(f, "\nPromedio contadorInterno = %f", contadorInterno/(double)repeticiones);
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