/*Escribir una funci�n que calcule la divisi�n entera entre 2 n�meros de manera recursiva. Recordar que la 
divisi�n matem�tica se define como una operaci�n aritm�tica, que consiste en saber cu�ntas veces un 
n�mero (divisor) est� contenido en otra cifra (dividendo).*/
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
