/*Modificar el programa codificado en el ejercicio 1 de esta serie, para que la cuenta regresiva se realice de 
a un segundo por vez.*/
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
		Sleep(1000);
		cuentaReg(pValor-1);
	}
}
