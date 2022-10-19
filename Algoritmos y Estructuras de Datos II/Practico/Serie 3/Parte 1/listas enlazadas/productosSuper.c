#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*Declaracion de tipos de datos personalizados*/
/*Lista para almacenar nodos*/
typedef char tString [25];
typedef struct{
	int codigo;
	tString descripcionProducto;
}tDato;
/*Tipo de dato para la lista*/
typedef struct nodo{
	tDato dato;
	struct nodo * siguiente; 
}tLista;

/*Declaración de prototipo*/
void inicializarLista();
bool listaVacia(tLista * );
void solicitarDatosProductos();
void insertarProductoPrimero(tDato);
void insertarProductoAdelante(tDato);
void insertarProducto(tDato);
void eliminarPrimerProducto();
void visualizarProductos(tLista *);/*Recibimos una copia del puntero a la lista*/ 
void insertarProductoPosicion(tDato, int);
void eliminarProductoPosicion(int);
void menu ();

/*Declaración de variables globales*/
tLista * listaProductos;

/*Función principal*/
int main(){
	tDato data;
	inicializarLista();

	menu();
	/*printf("Esta vacia? %s\n", listaVacia(listaProductos) == true ? "si" : "no");
	
	data.codigo = 222;
	strcpy(data.descripcionProducto, "Pancho");
	insertarProducto(data);
	
	data.codigo = 333;
	strcpy (data.descripcionProducto, "Hamburguesa");
	insertarProducto(data);
	
	printf("Esta vacia? %s\n", listaVacia(listaProductos) == true ? "si" : "no");
	
	visualizarProductos(listaProductos);
	
	data.codigo = 444;
	strcpy(data.descripcionProducto, "Agua saborizada");
	insertarProductoPosicion(data, 2);
	
	visualizarProductos(listaProductos);
	
	data.codigo = 555;
	strcpy(data.descripcionProducto, "Helado");
	insertarProductoPosicion(data, 3);

	eliminarPrimerProducto();
	visualizarProductos(listaProductos);
	
	eliminarProductoPosicion(3);	
	visualizarProductos(listaProductos);*/	
	return 0;
}
/*Implementación de funciones*/
void inicializarLista(){
	/*Inicializar lista diciendo que el puntero vale nulo*/
	listaProductos = NULL;
	printf("Lista inicializada... \n");
	system("pause");
	system("cls");
}

bool listaVacia(tLista * pListaProducto){
	return pListaProducto == NULL;
}

void solicitarDatosProductos(){
	tDato data;
	printf("Ingrese descripcion del producto: ");
	fflush(stdin);	
	gets(data.descripcionProducto);
	printf("Ingrese codigo del producto: ");
	scanf("%d", &data.codigo);	
}

void menu(){
	tDato data;	
	int opcion;
	do{
		printf("\t\t\t-------------------------------------------------\n");
		printf("\t\t\t|\t\tM E N U\t\t\t\t|\n");
		printf("\t\t\t-------------------------------------------------\n");	
		printf("\t\t\t|\t1. Agregar producto\t\t\t|\n");
		printf("\t\t\t|\t1. Agregar producto en K posicion\t|\n");	
		printf("\t\t\t|\t2. Mostrar productos\t\t\t|\n");
		printf("\t\t\t|\t3. Eliminar primer producto\t\t|\n");
		printf("\t\t\t|\t3. Eliminar producto en K posicion\t|\n");
		printf("\t\t\t|\t0. Salir\t\t\t\t|\n");
		printf("\t\t\t-------------------------------------------------\n");
		printf("\n\t\t\tSeleccione una opcion del menu:");
		scanf("%d", &opcion);
		system("cls");
		switch (opcion){
			case 0: {
				printf("Programa finalizado! \n");
				break;
			}	
			case 1:{

				solicitarDatosProductos();
				insertarProducto(data);
				system("pause");
				system("cls");
				break;
			}
			case 2:{
				solicitarDatosProductos();
			
			
				break;
			}
			case 3: 
				break;
			case 4: 
				break;
		}
	
	}while(opcion != 0);
}

void insertarProductoPrimero(tDato datoProducto){
	/*Crear memoria*/
	tLista * nuevoNodo;
	/*Reservar espacio de memoria para nuevo nodo y se 
	le asigna esa memoria al puntero*/
	nuevoNodo = (tLista *)malloc(sizeof(tLista));
	/*Asignar valor al componente correspondiente al dato*/
	/*-> Accede a cada uno de los campos dentro del puntero*/
	nuevoNodo->dato = datoProducto;
	/*Asignar una dirección al componente correspondiente
	al siguiente nodo*/
	nuevoNodo->siguiente = NULL; /*quien le sigue*/
	/*Se le asigna a la lista la dirección de nuevoNodo*/
	listaProductos = nuevoNodo;
	
	printf("Primer producto insertado %s | %d\n", datoProducto.descripcionProducto, datoProducto.codigo);
}

void insertarProductoAdelante(tDato datoProducto){
	/*Crear memoria*/
	tLista * nuevoNodo;
	/*Reservar espacio de memoria para nuevo nodo y se 
	le asigna esa memoria al puntero*/
	nuevoNodo = (tLista*)malloc(sizeof(tLista));
	/*Asignar valor al componente correspondiente al dato*/
	/*-> Accede a cada uno de los campos dentro del puntero*/
	nuevoNodo->dato = datoProducto;
	/*Asignar la direccion al componente correspondiente
	al siguiente nodo*/
	nuevoNodo->siguiente = listaProductos;
	/*Asignar la direccion del nuevo nodo a la lista*/
	listaProductos = nuevoNodo;
	printf("Producto insertado: %d-%s\n", datoProducto.codigo, datoProducto.descripcionProducto);
}

void insertarProducto(tDato datoProducto){
	if ( listaVacia (listaProductos)){
		insertarProductoPrimero (datoProducto);	
	}else{
		insertarProductoAdelante (datoProducto);
	}
}

void eliminarPrimerProducto(){
	/*Se guarda en una aux en el primer */
	tLista * nodoEliminar = listaProductos;
	/*Se avanza el puntero una vez*/
	listaProductos = listaProductos->siguiente;
	printf("Elemento eliminado %d-%s\n", nodoEliminar->dato.codigo, nodoEliminar->dato.descripcionProducto);
	/*Se libera la memoria del nodo a suprimir*/
	free (nodoEliminar);
	/*Se le asigna NULL a aux*/
	nodoEliminar = NULL;
}

void visualizarProductos(tLista * pListaProducto){/*Recibimos una copia del puntero a la lista*/ 
	tLista * aux;
	aux = pListaProducto;
	
	if(!listaVacia(aux)){
		printf("Lista de productos\n");
		printf("------------------------\n");
		printf("Codigo  | Descripcion\n");	
		printf("------------------------\n");
		while (aux != NULL){
			printf("%d \t| %s \n", aux->dato.codigo, aux->dato.descripcionProducto);
			aux = aux->siguiente;			
		}
		printf ("\n\n");
	}else{
		printf("No hay productos para mostrar\n");
	}
}

void insertarProductoPosicion(tDato nuevoDatoProducto, int pPosicion){
	int i; 	
	tLista * aux, * nuevoNodo;
	/* 1.Se debe utilizar una lista auxiliar aux */
	aux = listaProductos;	
	/* 2. Utilizar un bucle para avanzar aux hasta el nodo que se encuentra en pos-1 */
	for (i=1; i<pPosicion-1; i++){
		aux = aux->siguiente;
	}
	/* 3. Reservar memoria para el nodo a insertar */
	nuevoNodo = (tLista *) malloc(sizeof(tLista));	
	/* 4. Se asigna el dato recibido al componente correspondiente al elemento */
	nuevoNodo->dato = nuevoDatoProducto;
	/* 5. Se actualizan los punteros */
	nuevoNodo->siguiente = aux->siguiente;
	aux->siguiente = nuevoNodo;
	
	printf("Producto insertado %d-%s\n", nuevoDatoProducto.codigo, nuevoDatoProducto.descripcionProducto);
}

void eliminarProductoPosicion(int pPosicion){
	int i;
	tLista * aux, * nodoEliminar;
	/* 1. Se debe utilizar una lista auxiliar aux */
	aux = listaProductos;
	/* 2. Utilizar un bucle para avanzar aux hasta el nodo que se encuentra en pos-1 */
	for (i=1; i<pPosicion-1; i++){
		aux = aux->siguiente;
	}
	/* 3. Se resguarda el nodo que se va a suprimir en una variable auxiliar */
	nodoEliminar = aux->siguiente;
	/* 4. Se indica a qué nodo tiene que apuntar aux: al siguiente del que se va a eliminar */
	aux->siguiente = nodoEliminar->siguiente;
	printf("Producto eliminado %d-%s\n", nodoEliminar->dato.codigo, nodoEliminar->dato.descripcionProducto);
	/* 5. Se libera la memoria del nodo a suprimir que contenía el elemento de la posición pos de la lista */
	free(nodoEliminar);
	/* 6. Se asigna NULL a la variable auxiliar que guarda el nodo a suprimir */
	nodoEliminar = NULL;
}

