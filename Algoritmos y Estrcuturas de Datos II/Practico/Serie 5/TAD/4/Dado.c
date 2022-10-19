#include "Dado.h"
#include <stdio.h>

void menu();

tDado dado;

int main(){
	inicializarCaras(dado);
	menu();
	return 0;
}

void menu(){
	int opcion;
	do{
	printf("\t\t---------------------------------\n");
	printf("\t\t|\tJuego del dado\t\t|\n");
	printf("\t\t---------------------------------\n");
	printf("\t\t| 1. Lanzar dado\t\t|\n");	
	printf("\t\t| 0. Salir del programa \t|\n");
	printf("\t\t---------------------------------\n");
	printf("\t\t Seleccione una opcion: ");
	scanf("%d", &opcion);	
	system("cls");	

		switch(opcion){
			case 1:{

				lanzarDado(dado);
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
