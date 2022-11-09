# Algoritmos EDyA

<div id="indice" />

## Índice
**[1. Algoritmos de búsqueda](#algoritmos-busqueda)**
* [1.1. Búsqueda secuencial](#busqueda-secuencial)
* [1.2. Búsqueda binaria o dicotómica](#busqueda-binaria)

**[2. Algoritmos de ordenación](#algoritmos-ordenacion)**
* [2.1. Ordenación por burbuja](#ordenacion-burbuja)
* [2.2. Ordenación por selección](#ordenacion-seleccion)
* [2.3. Ordenación por inserción](#ordenacion-insercion)
* [2.4. Ordenación por inserción binaria](#ordenacion-insercion-binaria)

**[3. Otros algoritmos de ordenación](#otros-algoritmos)**
* [3.1. ShellSort](#otros-algoritmos)
* [3.2. QuickSort](#otros-algoritmos)
* [3.3. RadixSort](#otros-algoritmos)
* [3.4. MergeSort](#otros-algoritmos)

**[4. Técnicas recursivas](#otros-algoritmos)**
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
<pre style="font-family: Menlo, Monaco, Consolas, Courier New, monospace">
<b>Funcion</b> secuencial (T[1..n], valor)
    posicion <- 0

    <b>Para</b> i <- 1 <b>Hasta</b> n <b>Hacer</b>
        <b>Si</b> T[i] = valor <b>Entonces</b>
            posicion <- i
        <b>Fin Si</b>
    <b>Fin Para</b>

    <b>Devolver</b> posicion
<b>Fin Funcion</b>
</pre>

#### Implementación en C
```c
int secuencial (int *lista, int elementos, int valor) {
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
<pre style="font-family: Menlo, Monaco, Consolas, Courier New, monospace">
<b>Funcion</b> secuencial (T[1..n], valor)
    <b>Para</b> i <- 1 <b>Hasta</b> n <b>Hacer</b>
        <b>Si</b> T[i] = valor <b>Entonces</b>
            <b>Devolver</b> i
        <b>Fin Si
    Fin Para</b>

    <b>Devolver</b> -1
<b>Fin Funcion</b>
</pre>

#### Implementación en C
```c
int secuencial (int *lista, int elementos, int valor) {
    int i;

    for (i = 0; i < elementos; i++) {
        if (lista[i] == valor)
            return i;
    }

    return -1;
}
```

[Volver al índice](#indice)

---

<div id="busqueda-binaria" />

### 1.1. Búsqueda binaria o dicotómica

Algoritmo basado en la técnica "Divide y Vencerás", la solución de todo caso suficientemente grande se reduce a un caso más pequeño, en este caso de tamaño la mitad.

En la primera iteración se toma el elemento central de la lista. Encontramos 3 posibilidades:
- Que sea el valor buscado.
- Que sea un valor mayor que el buscado, entonces se repite el proceso con la sublista izquierda.
- Que se aun valor menor que el buscado, entonces se repite el proceso con la sublista derecha.

**Condición:** La lista o vector debe estar ordenado de manera creciente.

#### Tiempo
- En el caso mejor: **O(1)**
- En el caso medio y caso peor: **O(log n)**

### Opción iterativa

#### Implementación en Pseudocódigo
<pre style="font-family: Menlo, Monaco, Consolas, Courier New, monospace">
<b>Funcion</b> busquedaBinariaIterativa (T[1..n], valor)
    i <- 1
    j <- n

    <b>Mientras</b> i < j <b>Hacer</b>
        k <- (i + j) / 2
        <b>Si</b> valor < T[k] <b>Entonces</b>
            j <- k - 1
        <b>Si no si</b> valor = T[k] <b>Entonces</b>
            i, j <- k
        <b>Si no si</b> valor > T[k] <b>Entonces</b>
            i <- k + 1
        <b>Fin Si
    Fin Mientras</b>

    <b>Si</b> valor = T[i] <b>Entonces</b>
        <b>Devolver</b> i
    <b>Si no</b>
        <b>Devolver</b> -1
    <b>Fin Si</b>
<b>Fin Funcion</b>
</pre>

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
<pre style="font-family: Menlo, Monaco, Consolas, Courier New, monospace">
<b>Funcion</b> busquedaBinariaRecursiva (T[1..n], valor)
    <b>Si</b> i > j <b>Entonces</b>
        <b>Devolver</b> -1
    <b>Si no</b>
        k <- (i + j) / 2
        <b>Si valor</b> < T[k] <b>Entonces</b>
            j <- k - 1
        <b>Si no si</b> valor = T[k] <b>Entonces</b>
            <b>Devolver</b> k
        <b>Si no si</b> valor > T[k] <b>Entonces</b>
            i <- k + 1
        <b>Fin Si</b>

        <b>Devolver</b> busquedaBinariaRecursiva(T[i..j], valor)
    <b>Fin Si</b>
<b>Fin Funcion</b>
</pre>

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

[Volver al índice](#indice)

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
<pre style="font-family: Menlo, Monaco, Consolas, Courier New, monospace">
<b>Procedimiento</b> ordenacionBurbuja (T[1..n])
    <b>Para</b> i <- 1 <b>Hasta</b> n - 1 <b>Hacer</b>
        <b>Para</b> j <- n - 1 <b>Hasta</b> i <b>Hacer</b>
            <b>Si</b> T[j] > T[j+1] <b>Entonces</b>
                temp <- T[j]
                T[j] <- T[j+1]
                T[j+1] <- temp
            <b>Fin Si
        Fin Para
    Fin Para
Fin Procedimiento</b>
</pre>

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

[Volver al índice](#indice)

---

<div id="ordenacion-seleccion" />

### 2.2. Ordenación por selección

Busca el elemento más pequeño (orden ascendente) en la lista desordenada y lo coloca al final de la lista ordenada. Al principio la lista ordenada está vacía, mientras que la lista desordenada contiene los elementos que se irán examinando para formar la ordenada.

Necesitamos dos bucles, uno externo que indica la posición a insertar de la lista ordenada, y otro interno que con cada iteración del externo recorre la lista desordenada y se encarga de buscar el elemento más pequeño a insertar.

#### Tiempo
- En todos los casos el tiempo es: **O(n<sup>2</sup>)**

#### Implementación en Pseudocódigo
<pre style="font-family: Menlo, Monaco, Consolas, Courier New, monospace">
<b>Procedimiento</b> ordenacionSeleccion (T[1..n])
    <b>Para</b> i <- 1 <b>Hasta</b> n - 1 <b>Hacer</b>
        minJ <- i
        minX <- T[i]

        <b>Para</b> j <- i + 1 <b>Hasta</b> n <b>Hacer</b>
            <b>Si</b> T[j] < minX <b>Entonces</b>
                minJ <- j
                minX <- T[j]
            <b>Fin Si
        Fin Para</b>

        T[minJ] <- T[i]
        T[i] <- minX
    <b>Fin Para
Fin Procedimiento</b>
</pre>

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

[Volver al índice](#indice)

---

<div id="ordenacion-insercion" />

### 2.3. Ordenación por inserción

Inserta cada elemento de una lista desordenada en la posición que le corresponde en una lista ordenada. Al principio la lista ordenada está formada por un único elemento, el primer elemento de la lista a ordenar.

Necesitamos dos bucles, uno externo que recorre la lista indicando el elemento de la lista desordenada a insertar, y uno interno que recorrerá la lista ordenada buscando la posición que le corresponde al elemento a insertar.

#### Tiempo
- Para el caso mejor el tiempo es: **O(n)**
- Para los casos medio y peor el tiempo es: **O(n<sup>2</sup>)**

#### Implementación en Pseudocódigo
<pre style="font-family: Menlo, Monaco, Consolas, Courier New, monospace">
<b>Procedimiento</b> ordenacionInsercion (T[1..n])
    <b>Para</b> i <- 2 <b>Hasta</b> n <b>Hacer</b>
        j <- i - 1
        x <- T[i]

        <b>Mientras</b> j > 0 <b>Y</b> T[j] > x <b>Hacer</b>
            T[j+1] <- T[j]
            j <- j - 1
        <b>Fin Mientras</b>

        T[j+1] <- x
    <b>Fin Para
Fin Procedimiento</b>
</pre>

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

[Volver al índice](#indice)

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
<pre style="font-family: Menlo, Monaco, Consolas, Courier New, monospace">
<b>Procedimiento</b> ordenacionInsercionBinaria (T[1..n])
    <b>Para</b> z <- 2 <b>Hasta</b> n <b>Hacer</b>
        valor <- T[z]
        i <- 1
        j <- z - 1

        <b>Si</b> lista[z] > lista[z-1] <b>Entonces</b>
            j = -1
            k = z
        <b>Fin Si</b>

        <b>Mientras</b> i <= j <b>Hacer</b>
            k <- (i + j) / 2
            <b>Si</b> valor > T[k] <b>Entonces</b>
                i <- k + 1
            <b>Si no si</b> valor < T[k] <b>Entonces</b>
                j <- k - 1
            <b>Fin Si
        Fin Mientras</b>

        <b>Para</b> i <- z - 1 <b>Hasta</b> k <b>Hacer</b>
            T[i+1] <- T[i]
        <b>Fin Para</b>

        T[k] <- valor
    <b>Fin Para
Fin Procedimiento</b>
</pre>

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

[Volver al índice](#indice)

---

<div id="otros-algoritmos" />

_Trabajando en el resto del documento._
