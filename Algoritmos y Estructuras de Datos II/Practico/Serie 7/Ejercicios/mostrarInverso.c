/*Escribir un programa que permita ingresar un número entero positivo y luego, mediante una función 
recursiva, muestre el número de forma invertida. Ej.: 123 - 321.*/
#include <stdio.h>

void ingreseNumero();
int mostrarInverso(int);

int num, inverso = 0;

int main(){
	ingreseNumero();
	inverso = mostrarInverso(num);	
	printf("El numero invertido es: %d ", inverso);
	return 0;
}

void ingreseNumero(){
	printf("Ingrese un numero entero positivo: ");
	scanf("%d", &num);
}

int mostrarInverso(int pNum){
	if(pNum == 0){
		return 0;
	}else{
		inverso = inverso * 10;
		inverso = inverso + pNum % 10;
		mostrarInverso (pNum/10);
		return inverso;
	}
}
