#include "pilaEstatica.h"

void menu();

tPila pila;

int main(){
	inicializarPila();
	menu();
	return 0;
}


void menu(){
	int opcion;
	do{
	printf("\t\t---------------------------------\n");
	printf("\t\t|\tMenu de opciones\t|\n");
	printf("\t\t---------------------------------\n");
	printf("\t\t|\t1. Apilar elemento\t|\n");
	printf("\t\t|\t2. Mostrar listado \t|\n");	
	printf("\t\t|\t0. Salir\t\t|\n");			
	printf("\t\t---------------------------------\n");
	printf("\n\t\tSeleccionar una opcion del menu: ");
	scanf("%d", &opcion);
	system("cls");	
		switch(opcion){
			case 1: {
				tString cadena;
				insertarElem(cadena);
				break;
			}
			case 2:{

				mostrarElem(pila);
				break;
			}
			case 0:{
				printf("Programa finalizado\n");
				break;
			}
			default: {
				printf("La opcion ingresada no es valida!\n");
				break;
			}
		}
	system("pause");
	system("cls");	
	}while(opcion != 0);
	
}
