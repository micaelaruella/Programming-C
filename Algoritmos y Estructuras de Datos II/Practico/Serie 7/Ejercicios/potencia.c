#include <stdio.h>
#include <math.h>
#define TITULO "### Programa para la operacion exponenciacion entera ###\n"


int calcularPotencia(int, int);
int a, b, resultado;

int main(){
	printf("%s", TITULO);
	printf("\nIngrese dos numeros enteros\n");
	printf("Base entera: ");
	scanf("%d", &a);
	printf("Exponente entero: ");
	scanf("%d", &b);
	
	resultado = calcularPotencia(a,b);
	printf("\nEl resultado es: %d", resultado);
	return 0;
}

int calcularPotencia(int a, int b){
	if(b==0){
		return 0;
	}else if(b==1){
		return a;
	}else if(b>0){
		a = a * calcularPotencia(a, b-1);
		return a;
	}
}

