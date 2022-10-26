/* Escribir un programa que permita mostrar por pantalla una cuenta regresiva, a partir de un valor ingresado 
por teclado. Programar una función recursiva que, al llegar la cuenta a cero, informe que el tiempo se ha 
agotado*/
#include <stdio.h>
#include <windows.h>

void solicitarDatos();
void cuentaReg(int);

int valor;

int main(){
	solicitarDatos();
	cuentaReg(valor);
	printf("\n");
	printf("Fin del programa\n");
	return 0;
}

void solicitarDatos(){

	printf("Ingrese la cantidad de numeros a mostrar: ");
	scanf("%d", &valor);
}

void cuentaReg(int pValor){
	if(pValor != 0){
		printf("%d\t", pValor);
		Sleep(2000);
		cuentaReg(pValor-1);
	}
}
