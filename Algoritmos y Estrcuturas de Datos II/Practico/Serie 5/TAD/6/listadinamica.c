#include "listaDinamica.h"

void menu();
void solicitarDatosProductos();

tLista * lista;
tDatosNodo data;

int main(){
	inicializarLista();
	menu();
	return 0;
}
void solicitarDatosProductos(){

	printf("Ingrese identificador del producto: ");
	scanf("%d", &data.identificador);
	printf("Ingrese descripcion del elemento: ");
	fflush(stdin);	
	gets(data.descripcion);
	
}

void menu(){
	int opcion, posicion;
	do{
	printf("\t\t-------------------------------------------------\n");
	printf("\t\t|\t\tMenu de opciones\t\t|\n");
	printf("\t\t-------------------------------------------------\n");
	printf("\t\t|\t1. Listar elemento\t\t\t|\n");
	printf("\t\t|\t2. Mostrar listado \t\t\t|\n");
	printf("\t\t|\t3. Eliminar elemento \t\t\t|\n");
	printf("\t\t|\t4. Listar elemento en K posicion \t|\n");
	printf("\t\t|\t5. Eliminar elemento en K posicion \t|\n");		
	printf("\t\t|\t0. Salir\t\t\t\t|\n");			
	printf("\t\t-------------------------------------------------\n");
	printf("\n\t\tSeleccionar una opcion del menu: ");
	scanf("%d", &opcion);
	system("cls");	
		switch(opcion){

			case 1: {
			
				solicitarDatosProductos(data);
				insertarProducto(data);
				break;
			}
			case 2:{
				mostrarLista(lista);
				break;
			}
			case 3:{
				eliminarProducto();
				break;
			}
			case 4:{

				printf("Ingrese numero de posicion a insertar: ");
				scanf("%d", &posicion);
				solicitarDatosProductos(data);	
				insertarProductoPos(data, posicion);
				break;
			}
			case 5:{
				printf("Ingrese numero de posicion a eliminar: ");
				scanf("%d", &posicion);
				eliminarProductoPos(posicion);
				break;
			}
			case 0:{
				printf("Programa finalizado\n");
				break;
			}
			default: {
				printf("La opcion ingresada no es valida!\n");
				break;
			}
		}
	system("pause");
	system("cls");	
	}while(opcion != 0);
}
