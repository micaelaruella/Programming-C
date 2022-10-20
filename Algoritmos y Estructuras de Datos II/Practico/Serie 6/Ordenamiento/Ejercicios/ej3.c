#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 10

/*Declaración de tipos de datos personalizados*/
typedef int tVectorInt [MAX];

/*Declaración de prototipo*/
void cargarVector(tVectorInt);
void mostrarVector(tVectorInt);
void ordenarShell(tVectorInt);
void intercambio(int * a, int * b);
void ordenarQuickSort(int *, int *);



/*Declaración de variables globales*/
tVectorInt vector1, vector2;
/*Función principal*/
int main(){
	cargarVector(vector1);
	mostrarVector(vector1);
	ordenarShell(vector1);
	printf("Vector ordenado por el metodo de Shell: \n");
	mostrarVector(vector1);
	
	printf("\n\n");
	
	cargarVector(vector2);
	mostrarVector(vector2);
	ordenarQuickSort(&vector2[0], &vector2[MAX-1]);
	printf("Vector ordenado por el metodo de QuickSort: \n");
	mostrarVector(vector2);
	
	return 0;
}

/*Implementación de funciones*/
 void cargarVector(tVectorInt pVector){
 	int i;
 	srand (time(NULL));
 	for(i=0; i<MAX; i++){
 		pVector[i] = 0 + rand () % (100+1-0);
 	}
}

void mostrarVector(tVectorInt pVector){
	int i;
	printf("Elementos del vector: \n");
	for(i=0; i<MAX; i++){
		printf(" %d |", pVector[i]);
	}
	printf("\n");
}

void ordenarShell(tVectorInt pVector){
	int inter = (MAX/2);
	int i=0, j=0, k=0, aux;
	while (inter > 0){
		for(i=inter; i<MAX; i++){
			j = i - inter;
			while(j>= 0){
				k = j + inter;
				if(pVector[j]<= pVector[k]){
					j--;
				}else{
					aux = pVector[j];
					pVector[j] = pVector[k];
					pVector[k] = aux;
					j = j-inter;
				}
			}
		}
		inter = inter / 2;
	}
}

void intercambio(int* a, int* b){
	int aux = *a;
	*a = *b;
	*b = aux;
}

void ordenarQuickSort(int* izq, int* der){
	if(der < izq){
		return;
	}
	int pivote = *izq;
	int* ult = der;
	int* pri = izq;
	while(izq < der){
		while((*izq <= pivote) && (izq < der + 1)){
			izq ++;
		}
		while((*der > pivote) && (der > izq - 1)){
			der --;
		}
		if (izq < der){
			intercambio(izq, der);
		}
	}
	intercambio(pri, der);
	ordenarQuickSort(pri, der-1);
	ordenarQuickSort(der+1, ult);
}


