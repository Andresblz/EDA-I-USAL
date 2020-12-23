CC   = gcc

OBJ  = pruebaLista.o listas/lista.o pilas/pila.o colas/cola.o
LIBS =  
BIN  = pruebaLista
CFLAGS = -g 
RM = rm -f

all: pruebaLista 

clean: 
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CC) $(OBJ) -o pruebaLista $(LIBS)

pruebaLista.o: pruebaLista.c listas/lista.h pilas/pila.h
	$(CC) -c pruebaLista.c -o pruebaLista.o $(CFLAGS)

listas/lista.o: listas/lista.c listas/lista.h 
	$(CC) -c listas/lista.c -o listas/lista.o $(CFLAGS)
	
pilas/pila.o: pilas/pila.c pilas/pila.h 
	$(CC) -c pilas/pila.c -o pilas/pila.o $(CFLAGS)
	
colas/cola.o: colas/cola.c colas/cola.h 
	$(CC) -c colas/cola.c -o colas/cola.o $(CFLAGS)