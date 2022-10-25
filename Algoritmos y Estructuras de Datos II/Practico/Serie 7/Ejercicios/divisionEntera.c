/*Escribir una función que calcule la división entera entre 2 números de manera recursiva. Recordar que la 
división matemática se define como una operación aritmética, que consiste en saber cuántas veces un 
número (divisor) está contenido en otra cifra (dividendo).*/
#include <stdio.h>

int divisionRecursiva(int, int);

int main(){
	int a, b;
	printf("Ingrese dos numeros enteros para calcular una division \n");
	printf("Divisor: ");
	scanf("%d", &a);
	printf("Dividendo: ");
	scanf("%d", &b);
	printf("La division de %d y %d es: %d ", a, b, divisionRecursiva(a,b));
	return 0;
}


int divisionRecursiva(int a, int b){
	if(a == b){
		return 1;
	}else if (a < b){
		return 0;
	}else{
		return (divisionRecursiva(a-b, b)+1);
	}
}
