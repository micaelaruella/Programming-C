#include <stdio.h>
#define MAX 5

typedef float tVector [MAX];
tVector vector;

void generarVector();
void mostrarVector(tVector);


int main (){
	generarVector();
	mostrarVector(vector);
	return 0;
}


void generarVector(){
	int i;
	for (i=0; i<MAX; i++){
		printf("Ingrese el elemento %d: ", i+1);
		scanf("%f", &vector[i]);
	}
}

void mostrarVector(tVector pVector){
	int i;
	for (i=0; i<MAX; i++){
		printf("%.2f \t", pVector[i]); 
	}
}
