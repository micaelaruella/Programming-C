#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX 5

/* Declaración de tipos de datos personalizados */
typedef char tString[50];

typedef tString tLista[MAX];

typedef struct {
	tLista lista;
	int frente;
	int final;
}tCola;

/* Declaración de prototipos */
void inicializarCola();
bool colaVacia(tCola);
bool colaLlena(tCola);
void agregarElemento( tString );

/* ATENCIÓN: Sólo puede utilizarse uno de los modos de eliminación en el programa !!! */
void eliminarElementoFM(); // Eliminar frente móvil
void eliminarElementoFF(); // Eliminar frente fijo

void mostrarPrimerElemento(tCola);
void visualizarElementos(tCola);

/* Declaración de variables */
tCola colaNombres;

/* Bloque principal */
int main() {
	inicializarCola();

	agregarElemento("CECI");
	agregarElemento("JOSE");
	agregarElemento("AGUS");
	
	visualizarElementos( colaNombres );
	
	mostrarPrimerElemento( colaNombres );
	eliminarElementoFF();	
	
	visualizarElementos( colaNombres );
	
	return 0;
}

/* Implementación de funciones */
void inicializarCola() {
	colaNombres.frente = -1;
	colaNombres.final = -1;
	printf("Se inicializo la cola de nombres ... \n");
}

bool colaVacia(tCola pCola) {
	return ( pCola.frente == -1 && pCola.final == -1 );
}

bool colaLlena(tCola pCola)  {
	return ( pCola.final == (MAX-1) );
}

void agregarElemento( tString pNombre )  {
	if( colaLlena( colaNombres ) ) {
		printf("No hay lugares disponibles!\n");
	} else {
		/* Hay lugar para insertar */
		
		/* Actualizar el indice final */
		colaNombres.final = colaNombres.final + 1;
		
		/* Almacenar el elemento en la lista  */
		strcpy( colaNombres.lista[colaNombres.final], pNombre );
		
		/* Verificar si se está insertando el primer elemento */
		if( colaNombres.final == 0 ) {
			/* Es el primer elemento */
			colaNombres.frente = 0;
		}
		printf("Se inserto el nombre: %s!\n", pNombre);
	}
}

void eliminarElementoFM()  {
	tString elemSuprimir = " ";
	
	if( colaVacia( colaNombres ) ) {
		printf("No hay elementos para eliminar\n");
	} else {
		/* Hay elementos por eliminar */
		
		/* Resguardar el elemento por eliminar */
		strcpy( elemSuprimir, colaNombres.lista[colaNombres.frente] );
		
		/* Borrar el elemento que se encuentra en el frente */
		strcpy(colaNombres.lista[colaNombres.frente], " ");
		
		/* Verificar si la cola tiene un solo elemento, y actualizar índices */
		if( colaNombres.frente == colaNombres.final ) {
			/* 	Significa que se elimina el único elemento en la cola,
				por lo que hay que inicializar la cola nuevamente */
			inicializarCola();
		} else {
			colaNombres.frente = colaNombres.frente + 1;
		}
		
		/* Emitir mensaje de confirmación */
		printf("Elemento eliminado: %s\n", elemSuprimir);
	}
}

void eliminarElementoFF() {
	tString elemSuprimir = " ";
	int i;
	
	if( colaVacia( colaNombres ) ) {
		printf("No hay elementos para eliminar\n");
	} else {
		/* Hay elementos por eliminar */
		
		/* Resguardar el elemento por eliminar */
		strcpy( elemSuprimir, colaNombres.lista[colaNombres.frente] );
		
		/* Borrar el elemento que se encuentra en el frente */
		strcpy(colaNombres.lista[colaNombres.frente], " ");
		
		/* Reacomodar la lista */
		for( i= colaNombres.frente; i< colaNombres.final; i++ ) {
			strcpy( colaNombres.lista[i], colaNombres.lista[i+1] );			
		}
		
		/* Borrar el valor duplicado del final */
		strcpy(colaNombres.lista[colaNombres.final], " ");
		
		/* Verificar si la cola tiene un solo elemento, y actualizar índices */
		if( colaNombres.frente == colaNombres.final ) {
			/* 	Significa que se elimina el único elemento en la cola,
				por lo que hay que inicializar la cola nuevamente */
			inicializarCola();
		} else {
			colaNombres.final = colaNombres.final - 1;
		}
		
		/* Emitir mensaje de confirmación */
		printf("Elemento eliminado: %s\n", elemSuprimir);
	}

}

void mostrarPrimerElemento(tCola pCola)  {
	printf("Elemento en el frente: %s\n", pCola.lista[pCola.frente]);
}

void visualizarElementos(tCola pCola)  {
	int i;
	if( colaVacia(pCola) ) {
		printf("No hay elementos para visualizar\n");
	} else {
		printf("Elementos: \n");
		for( i= pCola.frente; i<= pCola.final; i++ ) {
			printf("%s | ", pCola.lista[i]);
		}
		printf("\n");
	}
}

