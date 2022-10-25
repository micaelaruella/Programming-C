#include <stdio.h>
#define TITULO "Sucesion de Fibonacci\n"


int sucesionFibonacci(int);



int main(){
	int num, sucesion;
	printf("%s", TITULO);
	printf("\n");
	printf("Ingrese un numero entero: ");
	scanf("%d", &num);
	
	sucesion = sucesionFibonacci(num);
	printf("La sucesion de Fibonacci da como resultado: %d\n", sucesion);
	
	return 0;
}

int sucesionFibonacci(int pNum){
	if(pNum > 1){
		return (sucesionFibonacci(pNum-1) + sucesionFibonacci(pNum-2));
	}else if(pNum == 0){
		return 0;
	}else if(pNum == 1){
		return 1;
	}
}
