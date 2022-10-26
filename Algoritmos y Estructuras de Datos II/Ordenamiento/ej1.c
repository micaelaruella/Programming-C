#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10


/*Declaración de tipos de datos personalizados*/
typedef float tVectorFloat [MAX];

/*Declaración de prototipo*/
void cargarVectorTeclado(tVectorFloat);
void intercambioDirecto(tVectorFloat);
void seleccionDirecta(tVectorFloat);
void insercionDirecta(tVectorFloat);
void mostrarElementosVector(tVectorFloat);

/*Declaración de variables globales*/
tVectorFloat vector1, vector2, vector3;

/*Función principal*/
int main(){
	printf("### Metodo de seleccion directa ###\n");
	cargarVectorTeclado (vector1);
	seleccionDirecta (vector1);
	mostrarElementosVector(vector1);
	system("pause");
	system("cls");
	
	printf("### Metodo de intercambio directo (Burbuja) ###\n");
	cargarVectorTeclado(vector2);
	intercambioDirecto(vector2);
	mostrarElementosVector(vector2);
	system("pause");
	system("cls");
	
	printf("### Metodo de insercion directa (Baraja) ###\n");
	cargarVectorTeclado(vector3);
	insercionDirecta(vector3);
	mostrarElementosVector(vector3);
	
	
	return 0;
}

/*Implementación de funciones*/
void cargarVectorTeclado(tVectorFloat pVector){
	int i;
	for (i=0; i<MAX; i++){
		printf("Ingrese un valor flotante: ");
		scanf("%f", &pVector[i]);
	}
}

void seleccionDirecta(tVectorFloat pVector){
	int i, j, posMenor;
	float valMenor, aux;
	for(i=0; i<MAX-1; i++){
		valMenor = pVector[i];
		posMenor = i;
		
		for(j=i+1; j<MAX; j++){
			if(pVector[j] < valMenor){
				valMenor = pVector[j];
				posMenor = j;
			}
		}
		
		if(posMenor != i){
			aux = pVector[i];
			pVector[i] = pVector[posMenor];
			pVector[posMenor] = aux;
		}
	
	}
	
}

void intercambioDirecto(tVectorFloat pVector){
	int i, j;
	float aux;
	
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

void insercionDirecta(tVectorFloat pVector){
	int i,j;
	float aux;
	
	for(i=1; i<MAX; i++){
		aux = pVector[i];
		j = i-1;
		while(j>=0 && pVector[j]>aux){
			pVector[j+1] = pVector[j];
			j = j-1;
		}
		pVector[j+1] = aux;
	}
	
}

void mostrarElementosVector(tVectorFloat pVector){
	int i;
	printf("********************************\n");
	printf("Elementos del vector: ");
	for(i=0; i<MAX; i++){
		printf(" %.2f |", pVector[i]);
	}

	printf("\n");
}
