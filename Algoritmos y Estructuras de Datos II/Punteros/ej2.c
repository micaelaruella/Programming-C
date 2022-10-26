#include <stdio.h>
#include <stdlib.h>

/*Declaración de tipo de datos*/
typedef int indice; /*Indice es un tipo de dato entero*/

typedef indice *apuntIndice; /*apuntIndice es un tipo de dato puntero entero*/

indice i; /*i es una variable de tipo entero*/

apuntIndice apuntI; /*apuntI es un puntero a un entero pero no contiene nada porque el puntero no está inicializado*/

int main(){
	apuntI = malloc(sizeof(int));

	*apuntI = 2;
	i = 4;
	
	printf("Que contendra apuntI? Contiene la direccion: %p\n", apuntI);
	printf("Que contendra *apuntI? Contiene: %d", *apuntI);

	return 0;
}
