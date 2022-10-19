#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 20

typedef char tString20[20];
typedef struct{
	float pulgadas;
	tString20 marca;
}tDatosTv;

typedef tDatosTv tArrayCajas[MAX];
typedef struct{
	tArrayCajas pila;
	int tope;
}tPila;
tPila vPila;

void crearPilaVacia();
bool pilaLlena(tPila);
bool pilaVacia(tPila);
void apilar(float, char);
void desapilar();
void listado(tPila);
void menu();

int main(){
	float pulgadas;
	char marca;
	crearPilaVacia();
	printf("ingresar pulgadas: ");
	scanf("%f", &vPila.pila[vPila.tope].pulgadas);
	printf("\ningresar marca: ");
	fflush(stdin);
	gets(vPila.pila[vPila.tope].marca);
	apilar(vPila.pila[vPila.tope].pulgadas, vPila.pila[vPila.tope].marca[20]);
	printf("televisor apilado: pulgadas (%.2f) y marca (%s)", vPila.pila[vPila.tope].pulgadas, vPila.pila[vPila.tope].marca);
	return 0;
}

void crearPilaVacia(){
	vPila.tope = -1;
}

bool pilaLlena(tPila pPila){
	return (pPila.tope == (MAX - 1));
}

bool pilaVacia(tPila pPila){
	return (pPila.tope == -1);
}

void apilar(float pPulgadas, char pMarca){
	if (!pilaLlena(vPila)){
		vPila.tope = vPila.tope + 1;
		vPila.pila[vPila.tope].pulgadas = pPulgadas;
		vPila.pila[vPila.tope].marca[20] = pMarca;
		printf("\nTelevisor apilado!\n");
	}else{
		printf("Pila llena!\n");
	}
}


