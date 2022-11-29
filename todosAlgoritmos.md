# Algoritmos EDyA

<a href="https://www.buymeacoffee.com/andr3kt" target="_blank"><img src="https://cdn.buymeacoffee.com/buttons/default-blue.png" alt="Buy Me A Coffee" height="41" width="174"></a>

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
* [3.1. ShellSort](#shell-sort)
* [3.2. QuickSort](#quick-sort)
* [3.3. RadixSort](#radix-sort)
* [3.4. MergeSort](#merge-sort)

**[4. Técnicas recursivas](#tecnicas-recursivas)**
* [4.1. Torres de Hanoi](#tecnicas-recursivas)
* [4.2. El problema de las 8 reinas](#tecnicas-recursivas)
* [4.3. El recorrido del caballo](#tecnicas-recursivas)
* [4.4. El problema de la mochila](#tecnicas-recursivas)
* [4.5. El problema de los números](#tecnicas-recursivas)

**[5. TADs](#tecnicas-recursivas)**
* [5.1. Listas enlazadas](#tecnicas-recursivas)
* [5.2. Matrices](#tecnicas-recursivas)

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
    int i, posicion = -1;

    for (i = 0; i < elementos; i++) {
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

## 3. Otros algoritmos de ordenación

---

<div id="shell-sort" />

### 3.1. ShellSort

Se propone como mejora al algoritmo de inserción.
 
Basado en suponer que los elementos desordenados son pocos y están en posiciones muy alejadas de la que les corresponde en la lista ordenada. En vez de realizar comparaciones con los elementos de _posiciones consecutivas_, se realizan con elementos en _posiciones separadas_ con una distancia mayor que uno.

Se realizan varias pasadas del algoritmo de inserción rebajando la distancia de comparación en cada una, de manera que los elementos se acercan a la posición que les corresponde en la lista ordenada. En la última pasada del algoritmo de inserción la distancia de comparaciones es  exactamente uno con lo que se garantiza que la lista queda ordenada.

**Importante:** Inc[1..n_inc] es una lista con los incrementos crecientes. Obsérvese que para _i = 1_, estamos en el algoritmo de inserción

La eficiencia de este algoritmo se basa en el hecho de que la ordenación con un determinado incremento no deshace el trabajo realizado anteriormente.

#### Tiempo
- Caso peor: **O(n<sup>2</sup>)**
- Caso medio: **O(n log n)**
- Caso mejor: **O(n log n)**

#### Implementación en Pseudocódigo
<pre style="font-family: Menlo, Monaco, Consolas, Courier New, monospace">
<b>Procedimiento</b> ShellSort (T[1..n], Inc[1..n_inc])
    <b>Para</b> i <- n_inc <b>Hasta</b> 1 <b>Hacer</b>
        incremento <- Inc[i]
        <b>Para</b> j <- incremento + 1 <b>Hasta</b> n <b>Hacer</b>
            x <- T[j]
            k <- j - incremento
            <b>Mientras</b> k > 0 <b>Y</b> T[k] > x <b>Hacer</b>
                T[k + incremento] <- T[k]
                k <- k - incremento
            <b>Fin Mientras</b>
            T[k + incremento] <- x
        <b>Fin Para
    Fin Para
Fin Procecimiento</b>
</pre>

#### Implementación en C
```c
void shellSort(int *lista, int tope, int *listaIncremento, int topeIncremento) {
    int i, j, inc, x, k;

    for (i = topeIncremento; i > 0; i--) {
        inc = listaIncremento[i];

        for(j = inc + 1; j < tope; j++) {
            x = lista[j];
            k = j - inc;

            while (k > 0 && lista[k] > x) {
                lista[k + inc] = lista[k];
                k = k - inc;
            }

            lista[k + inc] = x;
        }
    }
}
```

[Volver al índice](#indice)

---

<div id="quick-sort" />

### 3.2. QuickSort

Se basa en la técnica de "Divide y Vencerás", trata de dividir el problema inicial en dos problemas más sencillos de resolver:
- Una lista a ordenar -> Dos listas a ordenar de tamaño más pequeño

La técnica es la siguiente:
1. Escoger un elemento de la lista, denominado pivote.
2. Recolocar todos los elementos de la lista inicial, incluyendo el pivote, de manera que ésta quede dividida en dos sublistas, cumpliéndose que:
    - **Izquierda**: menores que el pivote
    - **Derecha**: mayores que el pivote

De esta forma el pivote queda ordenado en la posicion correspondiente de la lista, de la misma forma se ordenarán las dos sublistas generadas aplicando _recursividad_ hasta obtener sublistas de tamaño unidad.

#### Tiempo
- Caso peor (Elegir como pivote el elemento más pequeño de la lista): **O(n<sup>2</sup>)**
- Caso medio: **O(n log n)**

#### Implementación en Pseudocódigo
<pre style="font-family: Menlo, Monaco, Consolas, Courier New, monospace">
<b>Procedimiento</b> OrdenaciónRápida (T[base..tope]) 
    <b>Si</b> base < tope <b>Entonces</b>
        pivote <- colocar(T[base..tope])
        ordenación_rápida(T[base, pivote-1])
        ordenación_rápida(T[pivote+1, tope])
    <b>Fin Si
Fin Procedimiento
  
Función</b> colocar (T[base..tope])
    pivote <- base
    valor_pivote <- T[pivote]

    <b>Para</b> índice <- base + 1 <b>Hasta</b> tope <b>Hacer</b>
        <b>Si</b> T[índice] < valor_pivote <b>Entonces</b>
            pivote <- pivote + 1
            intercambiar(T[pivote], T[índice])
        <b>Fin Si
    Fin Para</b>

    intercambiar(T[base], T[pivote])
    <b>Devolver</b> pivote
<b>Fin Función</b>
</pre>

#### Implementación en C
```c
void quickSort(int *lista, int base, int tope) {
    int pivote; 
 
    if (base < tope) { 
        pivote = colocar(lista, base, tope);
        quickSort(lista, base, pivote);
        quickSort(lista, pivote+1, tope);
    } 
}
 
int colocar(int *lista, int base, int tope) {
    int pivote = base, valor_pivote = lista[pivote];

    for (int i = base+1; i < tope; i++) {
        if (lista[i] < valor_pivote) {
            pivote++;
            intercambiar(lista, pivote, i);​
        }
    }

    intercambiar(lista, base, pivote);
    return pivote;
}
```

#### Mejoras en el algoritmo

Podemos realizar unas mejoras al algoritmo para que el caso peor no se llegue a dar. Ya que el problema principal es la elección del pivote:
1. Valor aleatorio de la lista.
2. Elegir la mediana entre los valores base y tope: ((base + tope) / 2), no tendríamos los problemas anteriores.

#### Implementación en Pseudocódigo
<pre style="font-family: Menlo, Monaco, Consolas, Courier New, monospace">
<b>Procedimiento</b> OrdenaciónRápida (T[base..tope])
    i <- base
    j <- tope
    pivote <- (base + tope)/2
    x <- T[pivote]
    
    <b>Repetir
        Mientras</b> T[i] < x <b>Hacer</b>
            i <- i + 1 
        <b>Fin Mientras</b>

        <b>Mientras</b> T[j] > x <b>Hacer</b>
            j <- j - 1
        <b>Fin Mientras</b>
        
        <b>Si</b> i <= j <b>Entonces</b>
            intercambiar(T[i], T[j])
            i <- i + 1, j <- j - 1
        <b>Fin Si
    Hasta</b> i > j
    
    <b>Si</b> base < j <b>Entonces</b>
        OrdenaciónRápida(T[base, j])
    <b>Fin Si</b>

    Si</b> tope > i <b>Entonces </b> 
        OrdenaciónRápida(T[i, tope])
    <b>Fin Si
Fin Procedimiento</b>
</pre>

#### Implementación en C
```c
void quickSort (int *lista, int base, int tope) {
    int i = base, j = tope,
        pivote = (base + tope) / 2,
        valor_pivote = lista[pivote];
    
    do { 
        while(lista[i] < valor_pivote) i++;
        while(lista[j] > valor_pivote) j--;
        if(i <= j) { 
            intercambiar(lista, i, j);
            i++;
            j--;
        }
    } while (i < j);
     
    if(base < j) quickSort(lista, base, j);
    if(tope > i) quickSort(lista, i, tope);
}
```

Pseudocódigo de una versión en la que se utiliza un TAD pila para simular el comportamiento recursivo del algoritmo:

<pre style="font-family: Menlo, Monaco, Consolas, Courier New, monospace">
<b>Procedimiento</b> OrdenaciónRápida (T[1..n])
    push(pila, 1)
    push(pila, n)

    <b>Mientras</b> pila no vacía <b>Hacer</b>
        pop(pila, tope)
        pop(pila, base)

        <b>Mientras</b> base < tope <b>Hacer</b>
            pivote <- colocar(T[base, tope])
            push(pila, pivote+1)
            push(pila, tope)
            tope <- pivote - 1
        <b>Fin Mientras
    Fin Mientras
Fin Procedimiento</b>
</pre>

[Volver al índice](#indice)

---

<div id="radix-sort" />

### 3.3. RadixSort

Algoritmo RadixSort u Ordenación por Base.

La primera versión del algoritmo sería seguir paso por paso las tres fases:
1. Distribución de los elementos en grupos, pilas o lotes, atendiendo a una determinada característica de dichos elementos.
2. Ordenación de los grupos individuales por algún algoritmo conocido.
3. Combinación de las listas ordenadas (concatenación).

Una versión recursiva sería:
1. Tomar la cifra más significativa.
2. Distribuir los elemenots de la lista entre diez grupos o pilas.
3. Aplicar el mismo mecanismo a cada uno de los grupos.

Esta versión recursiva, implica que no se puede realizar la última fase hasta que no se terminen de ordenar todos los grupos.

Variación de la versión anterior:
1. Tomar la cifra menos significativa.
2. Distribuir los elementos de la lista entre diez grupos o pilas.
3. Concatenar los grupos en una única lista.
4. Aplicar los mismos pasos con la siguiente cifra hacia la izquierda.

Esta última versión ofrece:
- Mantener el orden al pasar de cifras menos a más significativas
- No hace falta ningún algoritmo adicional de ordenación
- No hay problemas de índices ni punteros, ya que se parte de una única lista.

Recibe el nombre de ordenación por base o por intercambio de base, porque trata los elementos como números en una determinada base, utiliza las cifras decimales (base 10).

#### Tiempo
- En todos los casos el tiempo es: **O(n)**

#### Implementación en Pseudocódigo
<pre style="font-family: Menlo, Monaco, Consolas, Courier New, monospace">
Procedimiento RadixSort (ref ↑ Lista:Nodo; n_grupos, n_cifras)
    /* Lista es el puntero raíz de una lista enlazada */

    Nodo ↑ pt_grupos[1..n_grupos],
         ↑ pt_últimos[1..n_grupos],
         ↑ pt_aux
    
    Para i <- 1 Hasta n_cifras Hacer
        Para j <- 1 Hasta n_grupos Hacer
            pt_grupos[j] <- pt_NULO
            pt_últimos[j] <- pt_NULO
        Fin Para
    
        pt_aux <- Lista
        Mientras pt_aux ≠ pt_NULO Hacer
            extraer la i-ésima cifra de pt_aux↑.llave
            j <- valor cifra obtenida
            añadir pt_aux al final de la lista pt_grupos[j],
            utilizando pt_últimos[j]
            pt_aux <- pt_aux↑.siguiente
        Fin Mientras

        Para j <- 1 Hasta n_grupos Hacer     
            Si pt_grupos[j] ≠ pt_NULO Entonces
                añadir pt_grupos[j] al final de la lista en construcción
            Fin Si
        Fin Para
    Fin Par
Fin Procedimiento
</pre>

#### Implementación en C
```c
void radixSort (nodo **lista, int n_grupos, int n_cifras){ 
    nodo *pt_grupos[n_grupos],
         *pt_ultimos[n_grupos],
         *aux;
    int i, pos, j, pot = 10, div = 1;
    
    for (i = 0; i < n_cifras; i++) {
        for (j = 0; j < n_grupos; j++) {
            pt_grupos[j] = NULL;
            pt_ultimos[j] = NULL;
        }
    
        aux = (*lista);
        while (aux) {
            j = ((aux->num) / div) % pot;
            
            if (!pt_grupos[j]) {
                pt_grupos[j] = aux;
                pt_ultimos[j] = aux;
            } else {
                (pt_ultimos[j])->siguiente = aux;
                pt_ultimos[j] = aux;
            }
            
            aux = aux->siguiente;
        }
                
        div *= 10;
        (*lista) = NULL;
        pos = -1;
        
        for (j = 0; j < n_grupos; j++) {
            if (pt_grupos[j]) {
                if (!(*lista)) (*lista) = pt_grupos[j];
                if (pos != -1) {
                    pt_ultimos[pos]->siguiente = pt_grupos[j];
                    pt_ultimos[j]->siguiente = NULL;
                }

                pos = j;
            }
        }
    }
}
```

[Volver al índice](#indice)

---

<div id="merge-sort" />

### 3.4. MergeSort

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
<pre style="font-family: Menlo, Monaco, Consolas, Courier New, monospace">
<b>Función</b> OrdenaciónFusión (T[base..tope])
    <b>Si</b> base < tope <b>Entonces</b>
        OrdenaciónFusión(T[base, (base+tope)/2])
        OrdenaciónFusión(T[(base+tope)/2+1, tope])
        Fusionar(base, (base+tope)/2, (base+tope)/2+1, tope)
    <b>Fin Si
Fin Función

Función</b> Fusionar (base_A, tope_A, base_B, tope_B)
    matriz A[1..n], B[1..m]
    ind_A <- 1
    ind_B <- 1
    ind_T <- base_A
    n <- tope_A - base_A + 1
    m <- tope_B - base_B + 1
    
    A[1..n] <- T[base_A..tope_A]
    B[1..m] <- T[base_B..tope_B]
    
    <b>Mientras</b> ind_A < n <b>Y</b> ind_B < m <b>Hacer
        Si</b> A[ind_A] < B[ind_B] <b>Entonces</b>
            T[ind_T] <- A[ind_A]
            ind_A <- ind_A + 1
        <b>Si No</b>
            T[ind_T] <- B[ind_B]
            ind_B <- ind_B + 1
        <b>Fin Si</b>

        ind_T <- ind_T + 1
    <b>Fin Mientras
    
    Si</b> ind_A > n <b>Entonces</b>
        T[ind_T..tope_B] <- B[ind_B..m]
    <b>Si No</b>
        T[ind_T..tope_B] <- A[ind_A..n]
    <b>Fin Si
Fin Si</b>
</pre>

#### Implementación en C
```c
void mergeSort (int *lista, int base, int tope) {
    if (base < tope) {
        mergeSort(lista, base, (base+tope)/2);
        mergeSort(lista, (base+tope)/2+1, tope);
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

[Volver al índice](#indice)

---


<div id="tecnicas-recursivas" />

_Trabajando en el resto del documento._
