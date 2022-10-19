#include "ListaTAD.h"

void menu();
void mostrarOpcionesMenu();
tElem ingresarColor();

tLista * listaBebidas;

int main() {
	inicializarLista(&listaBebidas);
	menu();	
	return 0;
}

tElem ingresarBebida() {
	tElem bebida;
	
	printf("Ingrese codigo de bebida: ");
	scanf("%d", &bebida.codigo);
	
	printf("Ingrese descripcion de la bebida: ");
	fflush(stdin);
	gets(bebida.descripcion);
	
	return bebida;
}

void mostrarOpcionesMenu() {
	printf("1-Insertar 2-Quitar Primero 3-Listar x-salir: ");
}

void menu() {
	char opcion;
	
	mostrarOpcionesMenu();
	fflush(stdin);
	scanf("%c", &opcion);
	
	
	/* Falta completar con el resto de las funciones de la lista */
	switch(opcion) {
		case '1':
					insertarAdelante( ingresarBebida(), &listaBebidas) ;
					menu();
					break;
		
		case '2': 	eliminarPrimero(&listaBebidas);
					menu();
					break;
					
		case '3': 	visualizarElementos(listaBebidas);
					menu();
					break;
					
		case 'x': 	printf("\tHasta la proxima!\n");
					break;
		
		default:	printf("\tError! No existe la opcion seleccionada\n");
					menu();
					break;
	}
}
