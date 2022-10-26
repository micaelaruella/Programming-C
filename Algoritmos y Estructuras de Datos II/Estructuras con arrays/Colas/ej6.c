/*En el estacionamiento de un shopping, existe solo un carril en el que entran hasta 20 automóviles. Los
vehículos llegan por el extremo sur del estacionamiento y salen por el extremo norte del mismo. El
empleado de la cochera registra algunos datos de los automóviles que están en el carril. Se solicita escribir
un programa que permita al usuario ingresar matrícula, marca y modelo de los automóviles en una cola
hasta que la misma se llene o el usuario haya decidido no ingresar más datos. Además, se pide generar un
listado de todos los vehículos que están en el carril y se desea saber cuánta disponibilidad hay en ese carril.
Utilizar implementación con frente fijo*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 20
/*Declaración de tipos de datos personalizados*/
typedef char tString [10];
typedef struct{
	int matricula; 
	tString marca;
	tString modelo;
}tDatosAuto;

typedef  tDatosAuto tArrayAuto [MAX];
typedef struct{
	tArrayAuto lista;
	int frente, final;
}tCola;
/*Declaración de prototipo*/
void crearColaVacia();
bool colaVacia(tCola);
bool colaLlena(tCola);
void consultarContinuidad();
void agregarAuto(int, tString, tString);
void listadoAutos(tCola);
void disponibilidadCarril();
void eliminarAutoFF(); /*Frente fijo*/
void menu();
/*Declaración de variables globales*/
tCola vColaAuto;
char respuesta;
/*función principal*/
int main(){
	crearColaVacia();
	menu();
	return 0;
}
/*Implementación de funciones*/
void crearColaVacia(){
	/*Inicialización de frente y final*/
	vColaAuto.frente = -1;
	vColaAuto.final = -1;
}

bool colaVacia(tCola pCola){
	return (pCola.frente == -1 && pCola.final == -1);
}

bool colaLlena(tCola pCola){
	return (pCola.final == (MAX-1));
}

void consultarContinuidad(){
	printf("Desea estacionar un auto? s/n: ");
	fflush(stdin);
	scanf("%c", &respuesta);
}

void menu(){
	tDatosAuto dato;
	int menu;
	do{
		printf("\t\t\t-----------------------------------------\n");
		printf("\t\t\t|\t\tM E N U\t\t\t|\n");
		printf("\t\t\t-----------------------------------------\n");	
		printf("\t\t\t|\t1. Agregar auto\t\t\t|\n");
		printf("\t\t\t|\t2. Mostrar listado de autos\t|\n");
		printf("\t\t\t|\t3. Disponibilidad carril\t|\n");
		printf("\t\t\t|\t4. Eliminar auto\t\t|\n");	
		printf("\t\t\t|\t0. Salir\t\t\t|\n");
		printf("\t\t\t-----------------------------------------\n");
		printf("\n\t\t\tSeleccione una opcion del menu:");
		scanf("%d", &menu);
		system("cls");
		switch(menu){
			case 1:{

				if(!colaLlena(vColaAuto)){
					
					do{
						consultarContinuidad();
						printf("Ingrese los datos del auto\n");
						printf("Matricula: ");
						scanf("%d", &dato.matricula);
						printf("Marca: ");
						fflush(stdin);
						gets(dato.marca);
						printf("Modelo: ");
						fflush(stdin);
						gets(dato.modelo);
						agregarAuto(dato.matricula, dato.marca, dato.modelo);	
						consultarContinuidad();	
					}while (respuesta == 's' || respuesta == 'S');
					
				break;
			}
			case 2:{
				listadoAutos(vColaAuto);
				break;
			}
			case 3:{
				disponibilidadCarril();
				break;
			}
			case 4:{
				eliminarAutoFF();
				break;
			}
			default: printf("Opcion no valida\n");		
		}
		system("pause");
		system("cls");		
	} while(menu != 0);
}

void agregarAuto(int pMatricula, tString pMarca, tString pModelo){
	tDatosAuto dato;
	if(colaLlena(vColaAuto)){
		printf("Carril lleno!\n");
	}else{
		/*Actualizar el indice final*/
		vColaAuto.final = vColaAuto.final + 1;
		 /* Almacenar el elemento en la lista*/
		vColaAuto.lista[vColaAuto.final].matricula = pMatricula;
		strcpy(vColaAuto.lista[vColaAuto.final].marca, pMarca);
		strcpy(vColaAuto.lista[vColaAuto.final].modelo, pModelo);
		/* Verificar si se está insertando el primer elemento */
		if (vColaAuto.final == 0){
			/* Es el primer elemento*/	
			vColaAuto.frente = 0;
		}
		printf("Auto ingresado: %d - %s - %s\n", vColaAuto.lista[vColaAuto.final].matricula, vColaAuto.lista[vColaAuto.final].marca, vColaAuto.lista[vColaAuto.final].modelo);
	}
}

void eliminarAutoFF(){
	tString marcaEliminar = " ";
	tString modeloEliminar = " ";
	int matriEliminar = 0;
	
	if(colaVacia(vColaAuto)){
		printf("No hay autos estacionados");
	}else{
		int i;
		/*Resguardar el elemento a eliminar*/
		matriEliminar = vColaAuto.lista[vColaAuto.frente].matricula;
		strcpy(marcaEliminar, vColaAuto.lista[vColaAuto.frente].marca);
		strcpy(modeloEliminar, vColaAuto.lista[vColaAuto.frente].modelo);
		/*Borrar el elemento que se encuentra en el frente*/
		vColaAuto.lista[vColaAuto.frente].matricula = 0;
		strcpy(vColaAuto.lista[vColaAuto.frente].marca, " ");
		strcpy(vColaAuto.lista[vColaAuto.frente].modelo, " ");		
		/*Reacomodar la lista*/
		for (i=vColaAuto.frente; i<vColaAuto.final; i++){
			vColaAuto.lista[i] = vColaAuto.lista[i+1];
			strcpy(vColaAuto.lista[i].marca, vColaAuto.lista[i+1].marca);
			strcpy(vColaAuto.lista[i].modelo, vColaAuto.lista[i+1].modelo);	
		}
		/*Borrar el valor duplicado al final*/
		vColaAuto.lista[vColaAuto.final].matricula = 0;
		strcpy(vColaAuto.lista[vColaAuto.final].marca, " ");
		strcpy(vColaAuto.lista[vColaAuto.final].modelo, " ");
		/*Verificar si la cola tiene un solo elemento y actualizar índice*/
		if(vColaAuto.frente == vColaAuto.final){
			crearColaVacia();
		}else{
			vColaAuto.final = vColaAuto.final - 1;
		}
		/*Mensaje de eliminado*/
		printf("Auto eliminado: %d - %s - %s \n", matriEliminar, marcaEliminar, modeloEliminar);
	}
}

void listadoAutos(tCola pCola){
	int i;
	if(colaVacia(vColaAuto)){
		printf("No hay autos estacionados\n");
	}else{
		printf("Listado de autos estacionados\n");
		for (i=vColaAuto.frente; i<=vColaAuto.final; i++){
			printf("%d%c auto estacionado: %d - %s - %s\n", i+1, 167, vColaAuto.lista[i].matricula, vColaAuto.lista[i].marca, vColaAuto.lista[i].modelo);
		}
	}	
}

void disponibilidadCarril(){
	if(colaLlena(vColaAuto)){
		printf("No hay estacionamiento disponible");
	}else{
		printf("La disponibilidad de vehiculos en este carril es: %d\n\n", (MAX-1) - vColaAuto.final);
	}	
}
