/* 4. En una libreria, al no tener mas lugar en los estantes,
	se van acomodando los libros en pilas de hasta 30 libros
	como maximo. Escribir un programa que permita:
	. ingresar los ISBN, titulo y editorial de los libros
	. listar los ultimos 5 libros apilados
	. eliminar de la pila los libros a medida que se solicitan
	. detectar cual es el libro que esta en el TOPE */
	
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX 30

/* Declaracion de tipos de datos personalizados */
typedef char tString[50];

typedef struct{
	tString isbn;
	tString titulo;
	tString editorial;
}tDatos;

typedef tDatos tVectorDatos[MAX];

typedef struct {
	tVectorDatos listaLibros;
	int tope;
}tPila;

/* Declaracion de prototipos */
void inicializarPila();
void menu();
bool pilaVacia( tPila );
bool pilaLlena( tPila );
void ingresarLibro();
void eliminarLibro();
void listarLibros( tPila ); 

/* Declaracion de variables globales */
tPila pila;

/* Funcion principal */
int main(){
	inicializarPila();
	menu();
	return 0;
}

/* Implementacion de funciones */
void inicializarPila(){
	pila.tope = -1;	
}

void menu(){
	int opcion;
	printf("------------MENU------------\n");
	printf("\n1- Ingresar libro");
	printf("\n2- Listar ultimos 5 libros");
	printf("\n3- Quitar libro");
	printf("\n4- Mostrar ultimo ingreso");
	printf("\n0- Salir");
	printf("\n\n Seleccione una opcion: ");
	scanf("%d", &opcion);
	system("cls");
	
	if( opcion < 0 || opcion > 4){
		printf("Opcion incorrecta...\n");
		system("pause");
		system("cls");
		menu();
	} else {	
		switch(opcion){
			case 1:{
				ingresarLibro();
				system("pause");
				system("cls");
				menu();
				break;
			}
			case 2: {
				listarLibros(pila);
				system("pause");
				system("cls");
				menu();
				break;
			}
			case 3: {
				eliminarLibro();
				system("pause");
				system("cls");
				menu();
				break;
			}
			case 4: {
				printf("El ultimo libro ingresado es:\nISBN: %s \nTitulo: %s \nEditorial: %s\n", pila.listaLibros[pila.tope].isbn, pila.listaLibros[pila.tope].titulo, pila.listaLibros[pila.tope].editorial);
				system("pause");
				system("cls");
				menu();
				break;
			}
			default: printf("ByeBye!\n");
		}
	}
}

bool pilaVacia( tPila pPila ){
	return( pPila.tope == -1 );
}

bool pilaLlena( tPila pPila ){
	return( pPila.tope == (MAX-1) );
}

void ingresarLibro(){
	if( pilaLlena(pila) ){
		printf("Estante lleno!\n\n");	
	} else {
		tString isbn_, titulo_, editorial_;
		printf("--Ingresar datos del libro--\n");
		printf("ISBN: ");
		fflush(stdin);
		gets(isbn_);
		printf("Titulo: ");
		fflush(stdin);
		gets(titulo_);
		printf("Editorial: ");
		fflush(stdin);
		gets(editorial_);
		pila.tope++;
		strcpy( pila.listaLibros[pila.tope].isbn, isbn_ );
		strcpy( pila.listaLibros[pila.tope].titulo, titulo_ );
		strcpy( pila.listaLibros[pila.tope].editorial, editorial_ );
		printf("\nLibro ingresado...\n");	
	}
}

void listarLibros( tPila pPila){
	int i;
	if( pilaVacia(pila) ){
		printf("Estante Vacio!\n\n");
	} else if( pPila.tope >= 4 ){
		printf("Ultimos 5 libros ingresados: \n\n");
		for( i=(pPila.tope - 4); i<= pPila.tope; i++){
			printf("%s, %s, %s \n", pPila.listaLibros[i].isbn, pPila.listaLibros[i].titulo, pPila.listaLibros[i].editorial);	
		}
	} else if( pPila.tope < 4 ){
		printf("Hay solo %d libros en el estante\n", (pPila.tope + 1) );
		for( i=0; i<=pPila.tope; i++){
			printf("%s, %s, %s \n", pPila.listaLibros[i].isbn, pPila.listaLibros[i].titulo, pPila.listaLibros[i].editorial);
		}
	}
}

void eliminarLibro(){
	if( pilaVacia(pila) ){
		printf("Estante Vacio!...\n");
	} else {
		strcpy( pila.listaLibros[pila.tope].isbn, " ");
		strcpy( pila.listaLibros[pila.tope].titulo, " ");
		strcpy( pila.listaLibros[pila.tope].editorial, " ");
		pila.tope--;
		printf("Libro eliminado...\n");
	}
}
