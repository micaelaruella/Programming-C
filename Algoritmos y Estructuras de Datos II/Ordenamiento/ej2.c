#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

/*Declaración de tipos de datos personalizados*/
typedef int tVectorInt[MAX];

/*Declaración de prototipo*/
void menu();
void cargarVector();
void ordenarVector(tVectorInt); /*Burbuja*/
void mostrarVector(tVectorInt);
int busquedaBinaria(tVectorInt, int);

/*Declaración de variables globales*/
tVectorInt vector;

/*Función principal*/
int main(){
	cargarVector();
	mostrarVector(vector);
	ordenarVector(vector);
	mostrarVector(vector);
	printf("El elemento buscado se encuentra en la posicion %d\n", busquedaBinaria(vector, 19));
	return 0;
}

/*Implementacion de funciones*/
void cargarVector(){
	int i;
	srand(time(NULL));
	for(i=0; i<MAX; i++){
		vector[i] = 0 + rand() % (100+1-0);
	}
}

void mostrarVector(tVectorInt pVector){
	int i;
	printf("Listado de elementos del vector: \n");
	for(i=0; i<MAX; i++){
		printf(" %d |", pVector[i]);
	}
	printf("\n");
}

void ordenarVector(tVectorInt pVector){
	int i, j, aux;
	for(i=0; i<MAX-1; i++){
		for(j=0; j<MAX-1; j++){
			if(pVector[j] > pVector[j+1]){
				aux = pVector[j];
				pVector[j] = pVector[j+1];
				pVector[j+1] = aux;
			}
		}
	}
}

int busquedaBinaria(tVectorInt pVector, int nroBuscado){
	int extInf = 0;
	int extSup = MAX;
	int posMed;
	bool existe = false;
	int result = -1;
	
	while((!existe) && (extSup >= extInf)){
		posMed = (extSup + extInf) / 2;
		if(pVector[posMed] == nroBuscado){
			existe = true;
		} else if(nroBuscado > pVector[posMed]){
			extInf = posMed + 1;
		}else{
			extSup = posMed - 1;
		}
	}
	
	if(existe){
		result = posMed;
		printf("Se encontro el numero buscado en el vector!\n");
	}else{
		printf("No se encontro el numero buscado en el vector!\n");
	}
	return result;
	
}






