/*Dada una matriz A de 5 filas y 4 columnas, determinar el valor máximo y mínimo de la matriz, indicando
además las posiciones en las que se encuentran estos valores.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define FILAS 5
#define COLUMNAS 4

typedef int tMatriz[FILAS][COLUMNAS];

void crearMatriz(tMatriz);
void mostrarMatriz(tMatriz);
bool maximoMatriz(tMatriz);
bool minimoMatriz(tMatriz);
void menu();
tMatriz matriz;

int main(){
	menu();
	return 0;
}

void crearMatriz(tMatriz pMatriz){
	int i, j;
	for(i=0; i<FILAS; i++){	
		for(j=0; j<COLUMNAS; j++){
			printf("Ingrese valor de %d,%d: ", i+1, j+1);
			scanf("%d", &pMatriz[i][j]);
		}
	}
}
void mostrarMatriz(tMatriz pMatriz){
	int i, j;
	for(i=0; i<FILAS; i++){		
		for(j=0; j<COLUMNAS-1; j++){
			printf("%d\t", pMatriz[i][j]);
		}
		printf("%d\n", pMatriz[i][j]);
	}
}
bool maximoMatriz(tMatriz pMatriz){
	int i, j;
	int valorMax = pMatriz[0][0];
	int filaMax, columnaMax;
	for(i=0; i<FILAS; i++){
		for(j=0; j<COLUMNAS; j++){
			if(pMatriz[i][j] > valorMax){
				valorMax = pMatriz[i][j];
				filaMax = i + 1;
				columnaMax = j + 1;
			}
		
		}
	}
	printf("El valor maximo de la matriz es: %d \t en la posicion %d,%d\n", valorMax, filaMax, columnaMax);
	return valorMax;
}
bool minimoMatriz(tMatriz pMatriz){
	int i, j;
	int valorMin = 99999;
	int filaMin, columnaMin;
	for(i=0; i<FILAS; i++){
		for(j=0; j<COLUMNAS; j++){
			if(pMatriz[i][j] < valorMin){
				valorMin = pMatriz[i][j];
				filaMin = i + 1;
				columnaMin = j + 1;
			}
		}
	}
	printf("El valor minimo de la matriz es: %d \t en la posicion %d,%d\n", valorMin, filaMin, columnaMin);
	return valorMin;
}


void menu(){
	int opcion;
	do{
		printf("*** Menu de opciones ***\n");
		printf("1. Generar matriz\n");
		printf("2. Mostrar matriz\n");
		printf("0. Salir del programa\n");
		printf("Seleccione una opcion del menu: ");
		scanf("%d", &opcion);
		system("cls");	
		switch(opcion){
			case 1:{
				crearMatriz(matriz);
				break;
			}
			case 2:{
				printf("\tMatriz 5x4 \n");
				mostrarMatriz(matriz);
				maximoMatriz(matriz);
				minimoMatriz(matriz);
				break;
			}
			case 0:{
				printf("Programa finalizado!\n");
				break;
			}
			default: {
				printf("Opcion ingresada invalida...\n");
				break;
			}
		}
		system("pause");
		system("cls");
	}while(opcion!=0);
	
}
