# Algoritmos EDyA

## Indice
**[1. Algoritmos de búsqueda](#algoritmos-busqueda)**
* [1.1. Búsqueda secuencial](#busqueda-secuencial)
* [1.2. Búsqueda binaria o dicotómica](#busqueda-binaria)

**[2. Algoritmos de ordenación](#algoritmos-ordenacion)**
* [2.1. Ordenación por burbuja](#ordenacion-burbuja)
* [2.2. Ordenación por selección](#ordenacion-seleccion)
* [2.3. Ordenación por inserción](#ordenacion-insercion)
* [2.4. Ordenación por inserción binaria](#ordenacion-insercion-binaria)
* [2.5. Ordenación por fusión](#ordenacion-fusion)

**[3. Otros algoritmos de ordenación](#otros-algoritmos)**
* [3.1. ShellSort](#otros-algoritmos)
* [3.2. QuickSort](#otros-algoritmos)
* [3.3. RadixSort](#otros-algoritmos)

**[4. Técnicas recursivas](#tecnicas-recursivas)**
* [4.1. Torres de Hanoi](#otros-algoritmos)
* [4.2. El problema de las 8 reinas](#otros-algoritmos)
* [4.3. El recorrido del caballo](#otros-algoritmos)
* [4.4. El problema de la mochila](#otros-algoritmos)
* [4.5. El problema de los números](#otros-algoritmos)

**[5. TADs](#otros-algoritmos)**
* [5.1. Listas enlazadas](#otros-algoritmos)
* [5.2. Matrices](#otros-algoritmos)

---

<div id="algoritmos-busqueda" />

## 1. Algoritmos de búsqueda

---

<div id="busqueda-secuencial" />

### 1.1. Búsqueda secuencial
Consiste en recorrer la lista, desde el primer elemento hasta el último, comparando con el valor buscado.

### Opción 1
#### Tiempo
- En cualquier caso: **O(n)**

#### Implementación en Pseudocódigo
```
funcion secuencial (T[1..n], valor)
    posicion <- -1

    para i <- 1 hasta n hacer
        si T[i] = valor entonces
            posicion <- i
        fin si
    fin para

    return posicion
fin
```

#### Implementación en C
```c
int Secuencial (int *lista, int elementos, int valor) {
    int posicion = -1;

    for (int i = 0; i < elementos; i++) {
        if (lista[i] == valor) 
            posicion = i;
    }
    return posicion;
}
```

### Opción 2
#### Tiempo
- Caso mejor (primera posición): **O(1)**
- Caso medio y caso peor: **O(n)**

#### Implementación en Pseudocódigo
```
funcion secuencial (T[1..n], valor)
    para i <- 1 hasta n hacer
        si T[i] = valor entonces
            devolver i
        fin si
    fin para

    devolver -1
fin
```

#### Implementación en C
```c
int Secuencial2 (int *lista, int elementos, int valor) {
    int i;

    for (i = 0; i < elementos; i++) {
        if (lista[i] == valor)
            return i;
    }

    return -1;
}
```

---

<div id="busqueda-binaria" />

### 1.1. Búsqueda binaria o dicotómica
Algoritmo basado en la técnica "Divide y Vencerás", la solución de todo caso suficientemente grande se reduce a un caso más pequeño, en este caso de tamaño la mitad.

En la primera iteración se toma el elemento central de la lista. Encontramos 3 posibilidades:
- Que sea el valor buscado.
- Que sea un valor mayor que el buscado, entonces se repite el proceso con la sublista izquierda.
- Que sea un valor menor que el buscado, entonces se repite el proceso con la sublista derecha.

**Condición:** La lista o vector debe estar ordenado de manera creciente.

#### Tiempo
- En el caso mejor: **O(1)**
- En el caso medio y caso peor: **O(log n)**

### Opción iterativa

#### Implementación en Pseudocódigo
```
funcion busquedaBinariaIterativa (T[1..n], valor)
    i <- 1
    j <- n

    mientras i < j hacer
        k <- (i + j) / 2
        si valor < T[k] entonces
            j <- k - 1
        fin si 
        si valor = T[k] entonces
            i, j <- k
        fin si
        si valor > T[k] entonces
            i <- k + 1
        fin si
    fin mientras

    si valor = T[i] entonces
        devolver i
    si no
        devolver -1
    fin si
fin
```

#### Implementación en C
```c
int busquedaBinariaIterativa (int *lista, int elementos, int valor) {
    int i = 0, j = elementos, k;

    while (i < j) {
        k = (i + j) / 2;
        if (valor < lista[k]) j = k - 1;
        else if (valor == lista [k]) i = j = k;
        else if (valor > lista[k]) i = k + 1;
    }

    if (valor == lista[i]) return i;
    else return -1;
}
```

### Opción recursiva

#### Implementación en Pseudocódigo
```
funcion busquedaBinariaRecursiva (T[1..n], valor)
    si i > j entonces
        devolver -1
    si no
        k <- (i + j) / 2
        si valor < T[k] entonces
            j <- k - 1
        fin si 
        si valor = T[k] entonces
            devolver k
        fin si
        si valor > T[k] entonces
            i <- k + 1
        fin si

        devolver busquedaBinariaRecursiva(T[i..j], valor)
    fin si
fin
```

#### Implementación en C
```c
int busquedaBinariaRecursiva (int *lista, int i, int j, int valor) {
    int k;
    if (i > j) {
        return -1;
    } else {
        k = (i + j) / 2;
        if (valor < lista[k]) j = k - 1;
        else if (valor == lista [k]) return k;
        else if (valor > lista[k]) i = k + 1;
        return busquedaBinariaRecursiva(lista, i, j, valor);
    }
}
```

---

<div id="algoritmos-ordenacion" />

## 2. Algoritmos de ordenación

---

<div id="ordenacion-burbuja" />

### 2.1. Ordenación por burbuja

Compara elementos adyacentes y los intercambia si están desordenados, de esta manera los valores más pequeños, van _burbujeando_ hacia la parte superior de la lista y los más grandes se _hunden_ a la parte inferior.

Necesitamos dos bucles, uno recorre la lista indicando la posición a la que debe _burbujear_ el elemento más pequeño de la lista deosrdenada, y otro interno que por cada iteración del externo, recorre la lista desordenada y se encarga del _burbujeo_.

#### Tiempo
- En todos los casos el tiempo es: **O(n<sup>2</sup>)**

#### Implementación en Pseudocódigo
```
funcion ordenacionBurbuja(T[1..n])
    para i <- 1 hasta n - 1 hacer
        para j <- n - 1 hasta i hacer
            si T[j] > T[j+1] entonces
                temp <- T[j]
                T[j] <- T[j+1]
                T[j+1] <- temp
            fin si
        fin para
    fin para
fin
```

#### Implementación en C
```c
void ordenacionBurbuja (int *lista, int elementos) {
    int i, j, aux;

    for (i = 0; i < elementos-1; i++) {
        for(j = elementos-2; j >= i; j--) {
            if (lista[j] > lista[j+1]) {
                aux = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = aux;
            }
        }
    }
}
```

---

<div id="ordenacion-seleccion" />

### 2.2. Ordenación por selección
Busca el elemento más pequeño (orden ascendente) en la lista desordenada y lo coloca al final de la lista ordenada. Al principio la lista ordenada está vacía, mientras que la lista desordenada contiene los elementos que se irán examinando para formar la ordenada.

Necesitamos dos bucles, uno externo que indica la posición a insertar de la lista ordenada, y otro interno que con cada iteración del externo recorre la lista desordenada y se encarga de buscar el elemento más pequeño a insertar.

#### Tiempo
- En todos los casos el tiempo es: **O(n<sup>2</sup>)**

#### Implementación en Pseudocódigo
```
funcion ordenacionSeleccion (T[1..n])
    para i <- 1 hasta n - 1 hacer
        minJ <- i
        minX <- T[i]

        para j <- i + 1 hasta n hacer
            si T[j] < minX entonces
                minJ <- j
                minX <- T[j]
            fin si
        fin para

        T[minJ] <- T[i]
        T[i] <- minX
    fin para
fin
```

#### Implementación en C
```c
void ordenacionSeleccion (int *lista, int elementos) {
    int i, j, menor, posicion;

    for (i = 0; i < elementos-1; i++) {
        posicion = i;
        menor = lista[i];

        for (j = i+1; j < elementos; j++) {
            if (lista[j] < menor) {
                posicion = j;
                menor = lista[j];
            }
        }

        lista[posicion] = lista[i];
        lista[i] = menor;
    }
}
```

---

<div id="ordenacion-insercion" />

### 2.3. Ordenación por inserción
Inserta cada elemento de una lista desordenada en la posición que le corresponde en una lista ordenada. Al principio la lista ordenada está formada por un único elemento, el primer elemento de la lista a ordenar.

Necesitamos dos bucles, uno externo que recorre la lista indicando el elemento de la lista desordenada a insertar, y uno interno que recorrerá la lista ordenada buscando la posición que le corresponde al elemento a insertar.

#### Tiempo
- Para el caso mejor el tiempo es: **O(n)**
- Para los casos medio y peor el tiempo es: **O(n<sup>2</sup>)**

#### Implementación en Pseudocódigo
```
funcion ordenacionInsercion (T[1..n])
    para i <- 2 hasta n hacer
        j <- i - 1
        x <- T[i]

        mientras j > 0 y T[j] > x hacer
            T[j+1] <- T[j]
            j <- j - 1
        fin mientras

        T[j+1] <- x
    fin para
fin
```

#### Implementación en C
```c
void ordenacionInsercion (int *lista, int elementos) {
    int i, j, valor;

    for (i = 1; i < elementos; i++) {
        j = i - 1;
        valor = lista[i];

        while (j > -1 && lista[j] > valor) {
            lista[j+1] = lista[j];
            j--;
        }

        lista[j+1] = valor;
    }
}
```

---

<div id="ordenacion-insercion-binaria" />

### 2.4. Ordenación por inserción binaria
Inserta cada elemento de una lista desordenada en la posición que le corresponde de una lista ordenada. Al principio la lista ordenada está formada por un único elemento: el primer elemento de la lista a ordenar.

Necesitamos tres bucles:
1. El primer bucle, nos indicará el elemento de la lista a ordenar
2. El segundo bucle, nos dará la posición en la lista ordenada del elemento a ordenar
3. El tercer buble, desplazará los elementos necesarios de la lista para poder insertar el nuevo elemento en la posición correspondiente

#### Tiempo
- En todos los casos el tiempo es: **O(n<sup>2</sup> log n)**

#### Implementación en Pseudocódigo
```
funcion ordenacionInsercionBinaria (T[1..n])
    para z <- 2 hasta n hacer
        valor <- T[z]
        i <- 1
        j <- z - 1

        si lista[z] > lista[z-1] entonces
            j = -1
            k = z
        fin si

        mientras i <= j hacer
            k <- (i + j) / 2
            si valor > T[k] entonces
                i <- k + 1
            sino si valor < T[k] entonces
                j <- k - 1
            fin si
        fin mientras

        para i <- z - 1 hasta k (decrementando) hacer
            T[i+1] <- T[i]
        fin para

        T[k] <- valor
    fin para
fin
```

#### Implementación en C
```c
void ordenacionInsercionBinaria (int *lista, int elementos) {
    int i, j, k, z, valor;

    for (z = 1; z < elementos; z++) {
        valor = lista[z];
        i = 0;
        j = z - 1;

        if (lista[z] > lista[z-1]) {
            j = -1;
            k = z;
        }
        
        while (i <= j) {
            k = (i + j) / 2;
            if (valor > lista[k]) i = k + 1;
            else if (valor < lista[k]) j = k - 1;
        }

        for (i = z-1; i >= k; i--) {
            lista[i+1] = lista[i];
        }

        lista[k] = valor;
    }
}
```

---

<div id="ordenacion-fusion" />

### 2.5. Ordenación por fusión
Se basa en la técnica de "Divide y Vencerás"

Se divide la lista a ordenar en dos sublistas aproximadamente de la misma longitud, para pasar a fusionar de forma ordenada ambas sublistas, una vez han sidor ordenadas separadamente.

El algoritmo tiene una naturaleza recursiva: para ordenar las dos sublistas que se producen se puede aplicar la misma técnica. El final de la recursividad se tiene cuando tenemos sublistas de longitud unidad.

La técnica que se sigue es:
1. Dividir la lista a ordenar en dos sublistas aproximadamente del mismo tamaño.
2. Se ordenan las dos sublistas producidas (se puede utilizar cualquier algoritmo, incluyendo este mismo mediante _recursividad_).
3. Se fusionan las sublistas ordenadas de tal forma que se mantiene el orden.

#### Tiempo
- En todos los casos el tiempo es: **O(n log n)**

#### Implementación en Pseudocódigo
```
funcion ordenacionFusion (T[base..tope])
    si base < tope entonces
        ordenacionFusion(T[base, (base+tope)/2])
        ordenacionFusion(T[(base+tope)/2+1, tope])
        fusionar(base, (base+tope)/2, (base+tope)/2+1, tope)
    fin si
fin

funcion fusionar (base_A, tope_A, base_B, tope_B)
    matriz A[1..n], B[1..m]
    ind_A <- 1
    ind_B <- 1
    ind_T <- base_A
    n <- tope_A - base_A + 1
    m <- tope_B - base_B + 1
    
    A[1..n] <- T[base_A..tope_A]
    B[1..m] <- T[base_B..tope_B]
    
    mientras ind_A < n y ind_B < m hacer
        si A[ind_A] < B[ind_B] entonces
            T[ind_T] <- A[ind_A]
            ind_A <- ind_A + 1
        si no
            T[ind_T] <- B[ind_B]
            ind_B <- ind_B + 1
        fin si

        ind_T <- ind_T + 1
    fin
    
    si ind_A > n entonces
        T[ind_T..tope_B] <- B[ind_B..m]
    si no
        T[ind_T..tope_B] <- A[ind_A..n]
    fin si
fin
```

#### Implementación en C
```c
void ordenacionFusion (int *lista, int base, int tope) {
    if (base < tope) {
        ordenacionFusion(lista, base, (base+tope)/2);
        ordenacionFusion(lista, (base+tope)/2+1, tope);
        fusionar(lista, base, (base+tope)/2, (base+tope)/2+1, tope);
    }
}

void fusionar (int *lista, int baseA, int topeA, int baseB, int topeB) {
    int *listaA, *listaB; 
    int i, A = 0, B = 0,
        T = baseA,
        n = topeA - baseA + 1,
        m = topeB - baseB + 1; 
    
    listaA = (int *)malloc(sizeof(int)*n); 
    listaB = (int *)malloc(sizeof(int)*m); 
    
    if (!listaA || !listaB) {
        printf("No hay memoria suficiente");
        exit(1);
    }

    generarLista(lista, baseA, topeA, listaA); 
    generarLista(lista, baseB, topeB, listaB); 
    
    while (A < n && B < m) {
        if (listaA[A] < listaB[B]) lista[T] = listaA[A++];
        else lista[T]=listaB[B++];
        T++;
    }

    if (A > n) {
        for (i = B; i < m; i++)
            lista[T++] = listaB[i];
    } else {
        for (i = A; i < n; i++)
            lista[T++] = listaA[i];
    }

    free(listaA);
    free(listaB);
}

void generarLista (int *origen, int base, int tope, int *destino) {
    int i, j = 0;
    
    for (i = base; i <= tope; i++, j++)
        destino[j] = origen[i];
}
``` 

---

<div id="otros-algoritmos" />

_Trabajando en el resto del documento._
