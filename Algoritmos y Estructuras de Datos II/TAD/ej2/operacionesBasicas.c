#include "operacionesBasicas.h"
#include <stdlib.h>
#include <stdio.h>

void menu();
void ingresarValores();

tDatosValores valores;

int main(){
	menu();
	return 0;
}

void menu(){
	
	int opcion;
	do{	
	printf("\t\t-----------------------------------------\n");
	printf("\t\t|\t\tMENU\t\t\t|\n");
	printf("\t\t-----------------------------------------\n");
	printf("\t\t| 1. Ingresar valores \t\t\t|\n");
	printf("\t\t| 2. Sumar valores \t\t\t|\n");
	printf("\t\t| 3. Restar valores \t\t\t|\n");
	printf("\t\t| 4. Multiplicar valores \t\t|\n");
	printf("\t\t| 5. Dividir valores \t\t\t|\n");		
	printf("\t\t| 0. Salir del programa \t\t|\n");
	printf("\t\t-----------------------------------------\n");
	printf("\t\t Seleccione una opcion del menu: ");
	scanf("%d", &opcion);	
	system("cls");		

		switch(opcion){
			case 1:{
				ingresarValores(valores);
				break;
			}
			case 2: {
				printf("La suma de los valores ingresados es: %.2f\n",sumar(valores));
				break;
			}
			case 3: {
				printf("La resta de los valores ingresados es: %.2f\n", restar(valores));
				break;
			}
			case 4: {
				printf("El producto de los valores ingresados es: %.2f\n", multiplicar(valores));
				break;
			}
			case 5:{
				printf("La division de los valores ingresados es: %.2f\n", dividir(valores));
				break;
			}
			case 0: {
				printf("Programa finalizado \n");
				break;
			}
			default: {
				printf("La opcion ingresada es incorrecta \n");
				break;
			}	
		
		}
	system("pause");	
	system("cls");	

	}while(opcion != 0);
}

void ingresarValores(){
	printf("Ingrese los dos valoresque desea calcular: \n");
	printf("Valor a: ");
	scanf("%f", &valores.a);
	printf("Valor b: ");
	scanf("%f", &valores.b);	
}
