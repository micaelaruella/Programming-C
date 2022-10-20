/*Escribir un programa que permita ingresar por teclado la cantidad de elementos de un vector, y cada uno
de los valores de los elementos del vector. Además, escribir funciones para obtener:
a) el máximo valor almacenado en el vector
b) el mínimo valor almacenado en el vector
c) la media de todos los valores
d) la semisuma (promedio entre el máximo y mínimo).*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int max;
typedef float tVectorFloat [1];


void cargarVector(tVectorFloat);
void mostrarVector(tVectorFloat);
float mayorValor(tVectorFloat);
float menorValor(tVectorFloat);
float mediaValores(tVectorFloat);
float semiSuma(tVectorFloat); /*promedio entre el máximo y mínimo*/
void menu();
tVectorFloat vector;

int main(){
	menu();
	return 0;
}

void cargarVector(tVectorFloat pVector){
	int i;
	printf("Ingrese la cantidad(tama%co) de elementos del vector: ", 164);
	scanf("%d", &max);
	for(i=0; i<max; i++){
		printf("Ingrese valores para el vector: ");
		scanf("%f", &pVector[i]);
	}
	printf("Vector lleno!\n");
}

void mostrarVector(tVectorFloat pVector){
	int i;
	printf("Valores que tiene el vector: \n");
	for(i=0; i<max; i++){
		printf("%.2f \t", pVector[i]);
	}
	printf("\n");
}


float mayorValor(tVectorFloat pVector){
	int i;
	float valorMayor = pVector[0];
	
	for(i=0; i<max; i++){
		if(pVector[i] > valorMayor){
			valorMayor = pVector[i];
		}
	}
	return valorMayor;
}


float menorValor(tVectorFloat pVector){
	int i;
	float valorMenor = pVector[0];
	
	for(i=0; i<max; i++){
		if(pVector[i]< valorMenor){
			valorMenor = pVector[i];
		}
	}
	return valorMenor;
}


float mediaValores(tVectorFloat pVector){
	int i;
	float sumaTotalValores = 0.0;
	float media;
	for (i=0; i<max; i++){
		sumaTotalValores = sumaTotalValores + pVector[i];
	}
	media = (sumaTotalValores / max );
	return media;
}


float semiSuma(tVectorFloat pVector){
	 /*promedio entre el máximo y mínimo*/
	 int i;
	 float valorMin = pVector[0];
	 float valorMax = pVector[0];
	 float promedio = 0.0;
	 for(i=0; i<max; i++){
	 	if(pVector[i] < valorMin){
	 		valorMin = pVector[i];
	 	}else if(pVector[i] > valorMax){
	 		valorMax = pVector[i];
	 	}
	 }
	promedio = (valorMin + valorMax) / 2;
	return promedio;

}

void menu(){
	int opcion;
	do{
		printf("*** Menu de opciones ***\n");
		printf("1. Ingresar cantidad y valores de los elementos\n");
		printf("2. Mostrar elementos en el vector\n");
		printf("3. Mostrar datos sobre los valores almacenados en el vector\n");
		printf("0. Salir del programa\n");
		printf("Seleccione una opcion del menu: ");
		scanf("%d", &opcion);
		system("cls");
		switch(opcion){
			case 1:{

				cargarVector(vector);
				break;
			}
			case 2:{
				mostrarVector(vector);
				break;
			}
			case 3:{
				printf("El minimo valor almacenado en el vector es: %.2f \n", menorValor(vector));
				printf("El maximo valor almacenado en el vector es: %.2f \n", mayorValor(vector));
				printf("La semisuma es: %.2f\n", semiSuma(vector));
				printf("La media de todos los valores es: %.2f\n", mediaValores(vector));
				break;
			}
			case 0: {
				printf("Programa finalizado!\n");
				break;
			}
			default:{
				printf("Opcion ingresada invalida\n");
				break;
			}
		}
	system("pause");
	system("cls");
		
	}while(opcion!= 0);
}


