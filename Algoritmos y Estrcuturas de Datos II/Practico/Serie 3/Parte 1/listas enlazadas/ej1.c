/*Crear un tipo de dato tListaProductos para un nodo que permita almacenar los siguientes datos de un
producto: codProducto, descripción, precio unitario. Luego, declarar un puntero a una variable de ese tipo,
y crear el primer nodo de la lista a partir del ingreso de datos por teclado. Por último, mostrar los datos
del primer nodo almacenado*/

/*Librerias*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*Declaración de tipos de datos personalizados*/
typedef char tString [20];
typedef struct{
	int codProducto;	
	tString descripcion;
	float precioUnitario;
}tDatoProducto;

typedef struct nodo{
	tDatoProducto dato;
	struct nodo * siguiente;
}tListaProductos;

/*Declaración de prototipo*/
void inicializarLista();
bool listaVacia(tListaProductos *);
void ingresarDatosProducto(tDatoProducto);
void insertarPrimerProducto(tDatoProducto);
void visualizarProductos(tListaProductos *);
void eliminarPrimerProducto();

/*Declaración de variables globales*/
tListaProductos * listaProductos;

/*Función principal*/
int main(){
	
	return 0;
}

/*Implementación de funciones*/
/*printf("\n");*/
void inicializarLista(){
	/*Inicializar lista diciendo que el puntero vale NULL*/
	listaProductos = NULL;
	printf("Lista inicializada...\n");
	system("pause");
	system("cls");
}
bool listaVacia(tListaProductos * pListaProductos){
	return (pListaProductos == NULL);
}
void ingresarDatosProducto(tDatoProducto pElem){
	tDatoProducto info;
	
	printf("Ingrese codigo del producto: ");
	scanf("%d", &info.codProducto);	
	printf("Ingrese descripcion del producto: ");
	fflush(stdin);	
	gets(info.descripcion);
	printf("Ingrese precio unitario del producto: ");
	scanf("%f", &info.precioUnitario);

}
void insertarPrimerProducto(tDatoProducto pElem){
}
void visualizarProductos(tListaProductos * pListaProductos){
}
void eliminarPrimerProducto(){
}
