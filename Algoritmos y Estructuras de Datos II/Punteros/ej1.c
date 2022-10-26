#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 25

typedef char tString [MAX];

void itemA();
void itemB();
void itemC();
void itemD();
void itemE();

int main(){
	itemA();
	itemB();
	itemC();
	itemD();
	itemE();
	return 0;
}



void itemA(){
	/*Asignación dinámica*/
	tString * apString;
	/*Reservar memoria para una variable tipo String
	y asignarsela al puntero*/
	apString = (tString *) malloc (sizeof(tString));
	/*Asignacion de dato a la variable*/		
	strcpy( (*apString), "Maria Acosta");
	printf("Punto a:\n");
	printf("\t-Contenido de la variable apuntada: %s\n", *apString);
	printf("\t-Direccion de la variable apuntada: %p\n", apString);
	printf("\t-Direccion de la variable puntero: %p\n", &apString);
	
	free(apString);

}

void itemB(){	
	float * apFloat;
	/*Reservar memoria para una variable tipo float
	y asignarsela al puntero*/
	apFloat = (float *) malloc (sizeof(float));
	/*Asignacion de dato a la variable*/	
	*apFloat = 20.5;
	
		
	printf("\n\n");	
	printf("Punto b:\n");
	printf("\t-Contenido de la variable apuntada: %.2f\n", *apFloat);
	printf("\t-Direccion de la variable apuntada: %p\n", apFloat);
	printf("\t-Direccion de la variable puntero: %p\n", &apFloat);	
	
	free(apFloat);
}

void itemC(){
	bool dato = true;
	bool * apBool;
		/*Reservar memoria para una variable tipo booleano
	y asignarsela al puntero*/
	apBool = (bool *) malloc (sizeof(bool));
	/*Asignacion de dato a la variable*/	
	*apBool = &dato;
			
	printf("\n\n");	
	printf("Punto c:\n");
	/*Uso del doble condicional en una sola linea*/
	printf("\t-Contenido de la variable apuntada: %s\n", dato? "True" : "False");
	printf("\t-Direccion de la variable apuntada: %p\n", apBool);
	printf("\t-Direccion de la variable puntero: %p\n", &apBool);	
	
	free(apBool);
}

void itemD(){	
	int * apInt;
	/*Reservar memoria para una variable tipo entero
	y asignarsela al puntero*/
	apInt = (int *) malloc (sizeof(int));
	/*Asignacion de dato a la variable*/	
	*apInt = 7350;
	
	printf("\n\n");	
	printf("Punto d:\n");
	printf("\t-Contenido de la variable apuntada: %d\n", *apInt);
	printf("\t-Direccion de la variable apuntada: %p\n", apInt);
	printf("\t-Direccion de la variable puntero: %p\n", &apInt);	
	
	free(apInt);
	
}

void itemE(){
	char * apChar;
	/*Reservar memoria para una variable tipo caracter
	y asignarsela al puntero*/	
	apChar = (char *) malloc (sizeof(char));
	/*Asignacion de dato a la variable*/
	*apChar = 'z';
	
	printf("\n\n");	
	printf("Punto e:\n");
	printf("\t-Contenido de la variable apuntada: %c\n", *apChar);
	printf("\t-Direccion de la variable apuntada: %p\n", apChar);
	printf("\t-Direccion de la variable puntero: %p\n", &apChar);	
	
	free(apChar);
	
}
