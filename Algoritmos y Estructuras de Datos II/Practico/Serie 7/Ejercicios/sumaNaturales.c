#include <stdio.h>
#define TITULO "### Programa que determina la suma de 'N' numeros naturales ###\n"
int suma(int);
void mostrarNumeros();
int n, resultado;
	
int main(){
	printf("%s", TITULO);
	printf("Ingrese un numero natural: ");
	scanf("%d", &n);
	mostrarNumeros();
	resultado = suma(n);
	printf("\nEl resultado de la suma es: %d", resultado);
	return 0;
}

int suma(int n){
	if(n==0){
		return 0;
	}else if(n>0){
		return n + suma(n-1);
	}
	
}
void mostrarNumeros(){
	int i;
	printf("Serie de numeros desde 1 hasta %d\n", n);
	for (i=1; i<=n; i++){
		printf("%d\t", i);
	}
}
