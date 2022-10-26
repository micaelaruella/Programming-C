/* Escribir un programa que, a partir del ingreso de dos números enteros positivos, calcule el producto de los 
mismos utilizando una función recursiva. Tener presente que la definición recursiva de la multiplicación 
de dos números a y b, se deriva de la definición de la multiplicación como una suma abreviada y la 
aplicación de la propiedad asociativa de la suma.*/
#include <stdio.h>

int calcularProducto(int, int);

int main(){
	int a, b;
	printf("Ingrese dos numeros enteros positivos para multiplicar\n");
	printf("Valor a: ");
	scanf("%d", &a);
	printf("Valor b: ");
	scanf("%d", &b);
	printf("El resultado de %d * %d es: %d", a, b, calcularProducto(a, b));
	
	return 0;
}

int calcularProducto(int a , int b){
	if(b == 1){
		return a;
	}else if ( b == 0){
		return 0;
	}else if (b > 0){
		return a + (calcularProducto(a, b - 1)) ;
	}else{
		return - a + (calcularProducto(a, b + 1));
	}
}
