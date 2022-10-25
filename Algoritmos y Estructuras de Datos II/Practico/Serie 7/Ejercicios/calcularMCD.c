#include <stdio.h>
#define TITULO "Programa para calcular el MCD de dos numeros enteros\n"

int calcularMCD(int, int);

int main(){
	int a, b;
	printf("%s", TITULO);
	
	printf("Ingrese dos numeros enteros\n");
	printf("Valor a: ");
	scanf("%d", &a);
	printf("Valor b: ");
	scanf("%d", &b);
	printf("El MCD de %d y %d es: %d", a, b, calcularMCD(a,b));
	return 0;
}

int calcularMCD(int a , int b){
	if (b==0){
		return a;
	}
	return calcularMCD(b, a%b);
	
}
