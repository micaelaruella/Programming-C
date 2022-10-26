/*. Escribir un TDA para cargar y mostrar los elementos de una lista dinámica, en donde el nodo tenga un
campo identificador de tipo entero y un campo descripción de tipo cadena de caracteres. Luego desarrolle
un programa para probar dicho TDA.*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*Publico*/
typedef char tString [30];
typedef struct{
	int identificador;
	tString descripcion;
}tDatosNodo;

typedef struct nodo{
	tDatosNodo datos;
	struct nodo * siguiente;
}tLista;

void inicializarLista();
bool listaVacia(tLista *);
void insertarProducto(tDatosNodo);
void insertarProductoPrimero(tDatosNodo);
void insertarProductoAdelante(tDatosNodo);
void mostrarLista(tLista *);
void eliminarProducto();

void insertarProductoPos(tDatosNodo, int);
void eliminarProductoPos(int);

tLista * lista;
/*Privado*/


void inicializarLista(){
	lista = NULL;	
}

bool listaVacia(tLista * pLista){
	return pLista == NULL;		
}

void insertarProducto(tDatosNodo pDatosNodo){
	if(listaVacia(lista)){
		insertarProductoPrimero(pDatosNodo);
	}else{
		insertarProductoAdelante(pDatosNodo);
	}
}

void insertarProductoPrimero(tDatosNodo pDatosNodo){
	tLista * nuevoNodo;
	nuevoNodo = (tLista *)malloc(sizeof(tLista));
	nuevoNodo->datos = pDatosNodo;
	nuevoNodo->siguiente = NULL; 
	lista = nuevoNodo;
	printf("Primer elemento insertado  %d - %s \n", pDatosNodo.identificador, pDatosNodo.descripcion);	
}

void insertarProductoAdelante(tDatosNodo pDatosNodo){
	tLista * nuevoNodo;
	nuevoNodo = (tLista *)malloc(sizeof(tLista));
	nuevoNodo->datos = pDatosNodo;
	nuevoNodo->siguiente = lista; 
	lista = nuevoNodo;	
	printf("Elemento insertado %d - %s \n", pDatosNodo.identificador, pDatosNodo.descripcion);
}

void mostrarLista(tLista * pLista){
	tLista * aux;
	aux = pLista;
	
	if(!listaVacia(aux)){
		printf("Lista de elementos\n");
		printf("Identificador |  Descripcion  |\n");	
		while (aux != NULL){
			printf(" %d \t\t| %s \n", aux->datos.identificador, aux->datos.descripcion);
			aux = aux->siguiente;			
		}
		printf ("\n\n");
	}else{
		printf("No hay elementos para mostrar\n");
	}
}

void eliminarProducto(){
	tLista * nodoEliminar = lista;
	lista = lista->siguiente;
	printf("Elemento eliminado %d - %s\n", nodoEliminar->datos.identificador, nodoEliminar->datos.descripcion);
	free (nodoEliminar);
	nodoEliminar = NULL;
}

void insertarProductoPos(tDatosNodo pNuevoDato, int pPos){
	int i; 	
	tLista * aux, * nuevoNodo;
	aux = lista;	

	for (i=1; i<pPos-1; i++){
		aux = aux->siguiente;
	}
	
	nuevoNodo = (tLista *) malloc(sizeof(tLista));	
	nuevoNodo->datos = pNuevoDato;
	nuevoNodo->siguiente = aux->siguiente;
	aux->siguiente = nuevoNodo;	
	printf("Elemento insertado %d - %s\n", pNuevoDato.identificador, pNuevoDato.descripcion);
}

void eliminarProductoPos(int pPos){
	int i;
	tLista * aux, * nodoEliminar;
	aux = lista;

	for (i=1; i<pPos-1; i++){
		aux = aux->siguiente;
	}
	nodoEliminar = aux->siguiente;
	aux->siguiente = nodoEliminar->siguiente;
	printf("Elemento eliminado %d - %s\n", nodoEliminar->datos.identificador, nodoEliminar->datos.descripcion);
	free(nodoEliminar);
	nodoEliminar = NULL;
}
