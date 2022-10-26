#include <stdio.h>

void mostrarMenores(int, int);

int main(){
	int inicial, limite;
	printf("Ingrese el valor de inicial: ");
	scanf("%d", &inicial);
	printf("Ingrese el valor limite: ");
	scanf("%d", &limite);
	
	mostrarMenores(inicial, limite);
}

void mostrarMenores(int pX, int pN){
	if (pX < pN){
		printf("    -> %d\n", pX);
		mostrarMenores(pX+1, pN);
		printf("    <- %d\n", pX);
	}
	
}

