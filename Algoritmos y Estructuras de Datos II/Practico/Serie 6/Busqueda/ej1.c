/*1. Escribir un programa que permita determinar si un número entero ingresado por teclado, existe en un
vector. Para ello será necesario, disponer de lo siguiente:
a) Una función que permita cargar elementos en un vector de números enteros.
b) Una función que permita visualizar los elementos almacenados en el vector.
c) Una función que devuelva verdadero en el caso que el elemento a buscar exista en el vector, y falso
en caso contrario*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 6

typedef int tVector [MAX];

void menu();
void cargarVector(tVector);
void mostrarElementosVector();
bool buscarElemento(tVector, int);

tVector v;


int main(){
	menu();
	return 0;
}

void menu(){
	int opcion;
	do{
		printf("*** Menu de opciones ***\n");
		printf("1. Cargar vector con elementos enteros\n");
		printf("2. Mostrar vector\n");
		printf("3. Encontrar vector\n");
		printf("0. Salir del programa\n");
		printf("Seleccione una opcion del menu: ");
		scanf("%d", &opcion);
		system("cls");
		switch(opcion){
			case 1:{
				cargarVector(v);
				break;
			}
			case 2:{
				mostrarElementosVector();
				break;
			}
			case 3:{
				bool existeElem;
				int nroBuscado;
		
				printf("Ingrese el numero para buscar en el vector: ");
				scanf("%d", &nroBuscado);
				existeElem = buscarElemento(v, nroBuscado);
				printf("Existe el elemento buscado?: %s \n", existeElem == true ? "Verdadero" : "Falso");
				
				break;
			}
			case 0:{
				printf("Programa finalizado!\n");
				break;
			}
			default: {
				printf("La opcion ingresada es invalida. Ingrese otra opcion\n");
				break;
			}
		}
		system("pause");
		system("cls");
	}while (opcion!=0);
	
}

void cargarVector(tVector pV){
	int i;
	for (i=0; i<MAX; i++){
		printf("Ingrese un numero entero: ");
		scanf("%d", &pV[i]);
	}
}

void mostrarElementosVector(){
	int i;
	printf("Los elementos enteros en el vector son: \n");
	for(i=0; i<MAX; i++){
		printf("%d \t", v[i]);
	}
	printf("\n");
}

bool buscarElemento(tVector pV, int pElem){
	bool existe = false;
	int i = 0;
	while((pV[i] != pElem) && (i != MAX)){
		i = i + 1;
	}
	if(pV[i] == pElem){
		existe = true;
	}
	return existe;
}
