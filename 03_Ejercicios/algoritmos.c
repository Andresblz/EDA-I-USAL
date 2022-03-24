#include <math.h>
#include "algoritmos.h"

extern int contadorExterno, contadorMedio, contadorInterno;

void algA(int n) {
	int i, j, c;

	c = 1;
	for (i = 1; i <= n; i++){
		contadorExterno++;
		for (j = 1; j <= n; j++) {
			contadorInterno++;
			c += 1;
		}
  	}
}

void algB(int n) {
	int i, j, c, k;

	c = 1;
	for (i = 1; i < n; i++) {
		contadorExterno++;
        for(j = 1; j < n; j++) {
			contadorMedio++;
            for(k = 1; k < 2; k++) {
				contadorInterno++;
                c += 1;
            }
        }
    }

    return;
}

void algC(int n) {
	int i, j, c, k;

	c = 1;
    for (i = 1; i < n; i++) {
		contadorExterno++;
        for (j = 1; j < pow(n, 2); j++) {
			contadorMedio++;
            for (k = 1; k < pow(n, 3); k++) {
				contadorInterno++;
                c += 1;
            }
        }
    }

    return;
}

void algD(int n) {
	int i, j, c;

	c = 1;
    for (i = 1; i < n; i++) {
		contadorExterno++;
        for (j = 1; j < i; j++) {
			contadorInterno++;
            c += 1;
        }
	}

    return;
}

void algE(int n) {
	int i, j, c, k;

	c = 1;
    for (i = 1; i < n; i++) {
		contadorExterno++;
        for (j = 1; j < n; j++) {
			contadorMedio++;
            for (k = 1; k < j; k++) {
				contadorInterno++;
                c += 1;
            }
        }
    }

    return;
}

void algF(int n) {
	int i, j, c, k;

	c = 1;
    for (i = 1; i < n; i++) {
		contadorExterno++;
        for (j = 1; j < i; j++) {
			contadorMedio++;
            for (k = 1; k < j; k++) {
				contadorInterno++;
                c += 1;
            }
        }
    }

    return;
}

void algG(int n) {
	int x, j;

	x = 0;
    j = n;
    while (j >= 1) {
		contadorInterno++;
        x += 1;
        j /= 2;
    }

    return;
}

void algH(int n) {
	int x, j;

	x = 0;
    j = n;
    while (j >= 1) {
        contadorInterno++;
        x += 1;
    	j /= 3;
    }

    return;
}

void algI(int n) {
	int x, i, j;

	x = 0;
    i = 1;
    do {
		contadorExterno++;
        j = 1;
        while (j <= i) {
			contadorInterno++;
            x += 1;
            j *= 2;
        }
        i += 1;
    } while (i < n);

    return;
}

void algJ(int n) {
	int x, i, j;

	x = 0;
    i = 1;
    do {
		contadorExterno++;
        j = 1;
        while (j <= i) {
			contadorInterno++;
            x += 1;
            j += 2;
        }
        i += 1;
    } while (i < n);

    return;
}

void algK(int n) {
	int x, i, j;

	x = 0;
    i = 1;
    while (i < n) {
		contadorExterno++;
        for (j = 1; j < i; j++) {
			contadorInterno++;
            x += 1;
        } 
        i *= 10;
    }

    return;
}