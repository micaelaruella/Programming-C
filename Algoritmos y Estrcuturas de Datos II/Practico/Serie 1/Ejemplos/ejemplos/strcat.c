#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#define MAX 15

typedef char tString[MAX];
typedef struct{
	tString nombre, apellido;
}tDatoPersona;

tDatoPersona dato;

void ingresarDatos();
void mostrarNombreCompleto();

int main(){
	ingresarDatos();
	mostrarNombreCompleto();
	return 0;
}

void ingresarDatos(){

	printf("Ingresar nombre:");
	fflush(stdin);
	scanf("%[^\n]s", dato.nombre);
	
	printf("Ingresar apellido:");
	fflush(stdin);
	scanf("%[^\n]s", dato.apellido);
}
void mostrarNombreCompleto(){

	char nombreCompleto[30];
	
	strcpy(nombreCompleto, dato.apellido);
	strcat(nombreCompleto, ", ");
	strcat(nombreCompleto, dato.nombre);
	
	printf("El nombre completo es: %s \n", nombreCompleto);
	
	
}
