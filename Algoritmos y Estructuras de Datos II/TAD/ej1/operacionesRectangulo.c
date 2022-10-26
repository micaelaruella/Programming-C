#include "operacionesRectangulo.h"
#include <stdio.h>
#include <stdlib.h>

void menu();
void ingresarDatosRectangulo();

tDatosRectangulo dato;

int main(){
	menu();
	return 0;
}

void ingresarDatosRectangulo(){

	printf("Ingrese la base del rectangulo: ");
	scanf("%f", &dato.base);
	
	printf("Ingrese la altura del rectangulo: ");
	scanf("%f", &dato.altura);
	
}

void menu(){

	int opcion;
	do{	
	printf("\t\t-----------------------------------------\n");
	printf("\t\t|\t\tMENU\t\t\t|\n");
	printf("\t\t-----------------------------------------\n");
	printf("\t\t| 1. Ingresar datos del rectangulo \t|\n");
	printf("\t\t| 2. Calcular perimetro del rectangulo \t|\n");
	printf("\t\t| 3. Calcular area del rectangulo \t|\n");
	printf("\t\t| 0. Salir del programa \t\t|\n");
	printf("\t\t-----------------------------------------\n");
	printf("\t\t Seleccione una opcion del menu: ");
	scanf("%d", &opcion);	
	system("cls");		

		switch(opcion){
			case 1:{
				ingresarDatosRectangulo(dato);
				break;
			}
			case 2: {
				printf("El perimetro del rectangulo es: %.2f \n", calcularPerimetro(dato));
				break;
			}
			case 3: {
				printf("El area del rectangulo es: %.2f\n", calcularArea(dato));
				break;
			}
			case 0: {
				printf("Programa finalizado \n");
				break;
			}	
		
		}
	system("pause");	
	system("cls");	

	}while(opcion != 0);
}
