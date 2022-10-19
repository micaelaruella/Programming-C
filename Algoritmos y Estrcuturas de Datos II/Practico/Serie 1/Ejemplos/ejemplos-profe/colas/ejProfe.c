#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX 5
typedef char cadena[10];

typedef struct{
	cadena nombre;
	int codigo;
}tDatos;

typedef struct{
	tDatos lista[MAX];
	int frente;
	int final;
}tCola;

tCola vCola;

void crearColaVacia();
bool colaVacia(tCola);
bool colaLlena(tCola);
void agregarElemento(tDatos);
void eliminarFM();
void eliminarFF();
void mostrarDatos(tCola);
void menu();

void main(){
	crearColaVacia();
	menu();
		
	return 0;
}

void crearColaVacia(){
	vCola.frente = -1;
	vCola.final = -1;
}

bool colaVacia(tCola pCola){
	return (pCola.frente == -1);
}
bool colaLlena(tCola pCola){
	return (pCola.final == MAX-1);
}


void menu(){
	int menu;
	printf("\t\t\t-----------------------------------------\n");
	printf("\t\t\t|\t\tM E N U\t\t\t|\n");
	printf("\t\t\t-----------------------------------------\n");	
	printf("\t\t\t|\t1. Agregar \t\t|\n");
	printf("\t\t\t|\t2. Mostrar \t\t|\n");
	printf("\t\t\t|\t3. Eliminar FF\t\t|\n");
	printf("\t\t\t|\t4. Eliminar FM\t\t|\n");	
	printf("\t\t\t|\t0. Salir\t\t\t|\n");
	printf("\t\t\t-----------------------------------------\n");
	
	printf("\n\t\t\tSeleccione una opcion del menu:");
	
	scanf("%d", &menu);
	system("cls");
	
	while (menu != 0){
		switch (menu){
			tDatos datos;
			case 1: 
				agregarElementos(datos.nombre, datos.codigo);
				break;
			case 2: {
				mostrarDatos();	
				break;
			}
			case 3: {
				eliminarFF();
				break;
			}
			case 4: {
				eliminarFM();
				break;
			}
			
			default:
				printf("Opcion no valida \n");
				break;
		}
	}
}


void agregarElemento(tDatos pDatos){
	if (colaLlena(vCola)){
		printf("No hay espacio!");
	} else {
		vCola.final = vCola.final + 1;
		strcpy(vCola.lista[vCola.final].nombre, pDatos.nombre);
		vCola.lista[vCola.final].codigo = pDatos.codigo;
		if (vCola.final == 0){
			vCola.frente = 0;
		}
		printf("Se inserto el elemento!\n");
	}
}

void eliminarFM(){
	int codEliminar;
	if (colaVacia(vCola)){
		printf("No hay elementos!");
	} else {
		codEliminar = vCola.lista[vCola.frente].
		;
		vCola.lista[vCola.frente].codigo = 0;
		strcpy(vCola.lista[vCola.frente].nombre, "");
		if (vCola.frente == vCola.final){
			crearColaVacia();
		} else {
			vCola.frente = vCola.frente + 1;
		}
		printf("Elemento eliminado: %d\n", codEliminar);
	}
}
void eliminarFF(){
	int codEliminar;
	int i;
	if (colaVacia(vCola)){
		printf("No hay elementos!");
	} else {
		codEliminar = vCola.lista[vCola.frente].codigo;
		for(i = vCola.frente; i < vCola.final; i++){
			vCola.lista[i].codigo = vCola.lista[i+1].codigo;
			strcpy(vCola.lista[i].nombre, vCola.lista[i+1].nombre);
		}
		vCola.lista[vCola.final].codigo = 0;
		strcpy(vCola.lista[vCola.final].nombre, "");
		if (vCola.frente == vCola.final){
			crearColaVacia();
		} else {
			vCola.final = vCola.final - 1; 
		}
		printf("Elemento eliminado: %d\n", codEliminar);
	}
}

void mostrarDatos(tCola pCola){
	int i;
	if (colaVacia(vCola)){
		printf("No hay elementos!");
	} else {
		printf("Elementos en cola: \n");
		for (i = vCola.frente; i <= vCola.final; i++){
			printf("%s - %d\n", vCola.lista[i].nombre, vCola.lista[i].codigo);
		}
	}
	
}

