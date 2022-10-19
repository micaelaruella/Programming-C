/* Ejemplo de Pila con Vectores - Almacena datos compuestos */
#include <stdio.h>
#include <stdbool.h>
#define MAX 5

typedef struct {
	int datoInt;
	char datoChar;
}tDatos;

typedef tDatos tArrayDatosCompuestos [MAX];

typedef struct {
	tArrayDatosCompuestos lista;
	int tope;
}tPila;

tPila pila;
int i;

void crearPilaVacia();
bool pilaVacia(tPila);
bool pilaLlena(tPila);
void apilar(int, char);
void desapilar();
tDatos cima(tPila);
void visualizarElementos(tPila);

int main() {
	crearPilaVacia();
	/*	este ejercicio no contempla el pedido de datos por teclado porque se realiz?
		solo a manera de ejemplificar para mostrar c?mo utilizar los procedimientos y/o funciones */
	printf("Pila vacia? %s\n", pilaVacia(pila) ? "si" : "no");
	apilar(1, 'A');
	printf("Pila vacia? %s\n", pilaVacia(pila) ? "si" : "no");
	apilar(2, 'B');
	apilar(3, 'C');
	apilar(4, 'D');
	visualizarElementos(pila);
	desapilar();
	printf("Elementos en pila luego de desapilar: \n");
	visualizarElementos(pila);
	printf("Elemento en la cima de la pila: %d-%c \n\n", cima(pila).datoInt, cima(pila).datoChar);
	apilar(5, 'E');
	printf("Elementos en pila luego de agregar el 5: \n");
	visualizarElementos(pila);
	apilar(6, 'F');
	apilar(7, 'E');
	printf("Elementos en pila luego de agregar 6 y 7: \n");
	visualizarElementos(pila);

	return 0;
}

void crearPilaVacia() {
	pila.tope = -1;
}

bool pilaVacia(tPila pPila) {
	return (pPila.tope == -1);		
}

bool pilaLlena(tPila pPila) {
	return (pPila.tope == (MAX-1));	
}

void apilar(int pDatoInt, char pDatoChar) {
	if (pilaLlena(pila) != true) {
		pila.tope = pila.tope + 1;
		pila.lista[pila.tope].datoInt = pDatoInt;
		pila.lista[pila.tope].datoChar = pDatoChar;
		printf("Elemento Insertado! %d-%c\n", pila.lista[pila.tope].datoInt, pila.lista[pila.tope].datoChar);
	}
	else {
		printf("Pila Llena!\n");
	}	
}

void desapilar() {
	if (pilaVacia(pila) == true)
		printf("Pila Vacia!!!\n");
	else {
		pila.lista[pila.tope].datoInt = 0;
		pila.tope = pila.tope - 1;
		printf("Elemento eliminado!!!\n");
	}
}

tDatos cima(tPila pPila) {
	return pPila.lista[pPila.tope];
}

void visualizarElementos(tPila pPila) {
	int i;
	printf("Elementos en pila: \n");
	for (i = 0; i <= pPila.tope; i++) {
		printf("%d ", pPila.lista[i]);
	}
	printf("\n\n");
}

