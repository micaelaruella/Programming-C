#include <stdio.h>

int factorialNro(int);

int main(){
	int valor;
	printf("Ingrese el valor para el calculo factorial: ");
	scanf("%d", &valor);
	printf("El valor factorial es: %d\n", factorialNro(valor));
	return 0;
}

int factorialNro(int n){
	if (n==0){
		return 1;
	}else if(n>0){
		return (n*factorialNro(n-1));
	}
}
