#include <stdio.h>
#include <stdlib.h>


void ejPunteroEstatico();
void ejPunteroDinamica();

int main(){
	ejPunteroEstatico();
	ejPunteroDinamica();
	return 0;
}
void ejPunteroEstatico(){
	/*Asignación estática (cuando la dirección ya existe)*/
	int edad; 
	int * apEdad;
	
	apEdad = &edad; /*apEdad contiene la dirección de edad*/ 
	
	printf("La direccion de la variable edad es: %p\n", &edad );
	printf("La direccion de la variable edad es: %p\n", apEdad);
	/*Asignacion de dato a la variable*/
	
	edad = 24;
	
	*apEdad = 44;	
	
	printf("El contenido de la variable edad es: %d\n", edad);	
	printf("El contenido de la variable edad es: %d\n", *apEdad);
	
}

void ejPunteroDinamica(){
	/*Asignación dinamica*/
	float * apFloat;
	/*Reserva memoria para una variable de tipo float
	y asigna al puntero*/
	apFloat = (float *) malloc (sizeof(float));
	
	*apFloat = 15.5;
	
	printf("El contenido de apFloat es: %p\n",  apFloat);
	
	printf("El contenido de la variable referenciada por apFloat: %.2f\n", *apFloat);
	
	/*Liberar memoria cuando ya no se necesita la 
	variable referenciada*/
	free(apFloat);
	apFloat = NULL;
	
	apFloat = (float *) malloc (sizeof(float));
	*apFloat = 99.9;	
	
	printf("El contenido de apFloat es: %p\n",  apFloat);
	
	printf("El contenido de la variable referenciada por apFloat: %.2f\n", *apFloat);	
	
}
