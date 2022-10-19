/*En el puerto de la ciudad se apilan contenedores a medida que van llegando, hasta un máximo de 8. Cada
contenedor tiene un número de identificación que se registra. Elaborar un programa que permita
gestionar el ingreso y egreso de contenedores, teniendo en cuenta las funciones básicas necesarias para
la implementación mediante vectores.*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#define MAX 8

typedef int tArrayContenedor[MAX];
typedef struct{
	tArrayContenedor lista;
	int nroIdentificacion;
	int tope;
}tPila;

tPila pila;

void crearPilaVacia();
bool pilaVacia(tPila);
bool pilaLlena(tPila);
void apilar(int);
void desapilar();
void visualizarContenedores(tPila);
void menu();


int main (){
	crearPilaVacia();
	menu();
	return 0;
}

void crearPilaVacia(){
	pila.tope = -1;
}

bool pilaVacia(tPila pPila){
	return (pPila.tope == -1);
}

bool pilaLlena(tPila pPila){
	return (pPila.tope == (MAX-1));
}

void menu(){
	int menu;
	
	printf("### Menu de opciones ###\n");
	printf("0. Salir\n");
	printf("1. Ingresar numero de identificacion del contenedor\n");
	printf("2. Listar numeros de identificacion de los contenedores\n");
	printf("3. Eliminar contenedor\n");
	printf("Seleccione una opcion del menu: ");
	scanf("%d", &menu);
	system("cls");
	
	while (menu != 0){
		switch (menu){
			case 1:{
				int nroIdentificador;
				if (pilaLlena(pila) != true){
					printf("Ingresar numero de identificacion del contenedor: ");
					scanf("%d", &nroIdentificador);	
					apilar (nroIdentificador);				
				}else{
					printf("Pila llena!\n");
				}
				break;
			}
			case 2:{
				visualizarContenedores(pila);
				break;
			}
			case 3:{
				desapilar();
				break;
			}
		}
	system("pause");
	system("cls");
	printf("### Menu de opciones ###\n");
	printf("0. Salir\n");
	printf("1. Ingresar numero de identificacion del contenedor\n");
	printf("2. Listar numeros de identificacion de los contenedores\n");
	printf("3. Eliminar contenedor\n");
	printf("Seleccione una opcion del menu: ");
	scanf("%d", &menu);
	system("cls");	
	}
	
}

void apilar(int pNroIdenticacion){
	if (pilaLlena(pila) != true){ /*Verificar que haya espacio libre*/
		pila.tope++; /*Actualizar tope*/
		pila.lista[pila.tope] = pNroIdenticacion;
		printf("Contenedor apilado! \n");
	}else{
		printf("Pila llena!\n");
	}
}

void desapilar(){
	if (pilaVacia(pila) == true){/*Verificar que haya espacio ocupado*/
		printf("Pila vacia!\n");	
	}else{
		pila.lista[pila.tope] = 0;
		pila.tope--;
		printf("Contenedor eliminado! \n");
	}
}

void visualizarContenedores(tPila pPila){
	int i;
	/*Verificar que haya elementos para mostrar*/
	if (pilaVacia(pila) == true){
		printf("No hay contenedores para mostrar!\n");
	}else{
		printf("Listado de contenedores:\n");
		for (i=0; i<=pPila.tope; i++){
			printf("Numero de identificacion del contenedor nro %d: %d\n", i+1, pila.lista[i]);
		}
	}
}

