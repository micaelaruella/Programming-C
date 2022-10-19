#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 30

/*Parte publica*/
typedef char tString [20];

typedef tString tArrayPila [MAX];

typedef struct{
	tArrayPila lista;
	int tope;	
}tPila;

void inicializarPila();
bool pilaVacia(tPila);
bool pilaLlena(tPila);
void insertarElem(tString);
void mostrarElem(tPila);


tPila pila;

/*Parte Privada*/

void inicializarPila(){
	pila.tope = -1;
}


bool pilaVacia(tPila pPila){
	return (pPila.tope == -1);
}

bool pilaLlena(tPila pPila){
	return (pPila.tope == (MAX-1));
}

void insertarElem(tString pCadena) {
	if (pilaLlena(pila)){
		printf("Pila llena!\n");
	}else{
		printf("Ingrese una cadena de caracteres: ");
		fflush(stdin);
		gets(pCadena);
		pila.tope = pila.tope + 1;
		strcpy(pila.lista[pila.tope], pCadena);
	
	}
}

void mostrarElem(tPila pPila){
	if(pilaVacia(pPila)){
		printf("Pila vacia!\n");
	}else{
		int i;
		printf("Pila de elementos: \n");
		for(i=0; i<= pPila.tope; i++){
			printf("Elemento ingresado: %s\n", pPila.lista[i]);
		}
	}
}
