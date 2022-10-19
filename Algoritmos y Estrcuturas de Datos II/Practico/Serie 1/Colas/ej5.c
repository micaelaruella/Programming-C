/*En una clínica la secretaria hace un listado con los nombres y apellidos de los pacientes que van llegando
para luego ser atendidos en ese orden, también agenda el tipo de cobertura (1-obra social 2-pre-paga 3-
particular). El médico atiende un máximo de 20 pacientes por día. Se solicita: generar un listado de todos
los pacientes que van a ser atendidos en el día, conocer si hay turnos disponibles, y realizar una función
para borrar de la lista los pacientes a medida que son atendidos (utilizar la implementación con frente
móvil)*/


#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#define MAX 20

/*Declaración de tipos de datos personalizados*/
typedef char tString [15];
typedef struct {
	tString nombre;
	tString apellido;
	char nombreCompleto[30];
	int cobertura;
}tDatosPaciente;

typedef tDatosPaciente tArrayPaciente[20];
typedef struct{
	tArrayPaciente lista;
	int frente, final;
}tCola;

/*Declaración de variables globales*/
tCola vCola;

/*Declaración de funciones*/
void crearColaVacia();
bool colaVacia(tCola);
bool colaLlena(tCola);
void insertarElemento(tDatosPaciente);
void generarListadoPacientes(tCola);
void eliminarElementoFM(); /*Eliminar por frente móvil*/ 
void turnosDisponibles();
void menu();

/*Funcion main*/
int main(){
	crearColaVacia();
	menu();
	return 0;
}

/*Definicion de funciones*/

void crearColaVacia(){
	/*Inicialización de final y frente*/
	vCola.frente = -1;
	vCola.final = -1;	
	printf("Se inicializo la cola de la lista\n\n");
	system("pause");
	system("cls");
}

bool colaVacia(tCola pCola){
	return (pCola.frente == -1 && pCola.final == -1);	
}

bool colaLlena(tCola pCola){
	return (pCola.final == (MAX-1));
}

void menu(){
	int menu;
	
	
	do{
	printf("\t\t\t-----------------------------------------\n");
	printf("\t\t\t|\t\tM E N U\t\t\t|\n");
	printf("\t\t\t-----------------------------------------\n");	
	printf("\t\t\t|\t1. Agregar paciente\t\t|\n");
	printf("\t\t\t|\t2. Mostrar pacientes\t\t|\n");
	printf("\t\t\t|\t3. Hay turnos disponibles?\t|\n");
	printf("\t\t\t|\t4. Eliminar paciente\t\t|\n");	
	printf("\t\t\t|\t0. Salir\t\t\t|\n");
	printf("\t\t\t-----------------------------------------\n");
	printf("\n\t\t\tSeleccione una opcion del menu:");
	scanf("%d", &menu);
	system("cls");
		switch (menu){
			tDatosPaciente datos;
			case 1: 
				if (!colaLlena(vCola)){
					printf("Ingrese los siguientes datos del paciente:\n");
					printf("Nombre: ");
					fflush(stdin); 
					gets(datos.nombre);
					printf("Apellido: ");
					fflush(stdin);
					gets(datos.apellido);
					printf("Cobertura (1-Obra social 2-Pre-paga 3-Particular): ");
					scanf("%d", &datos.cobertura);
					/*insertarElemento(datos);*/
		
				}else{
					printf("No hay turnos disponibles\n");
				}
				break;
			case 2: {
				generarListadoPacientes(vCola);
				break;
			}
			case 3: {
				turnosDisponibles();
				break;
			}
			case 4: {
				eliminarElementoFM();				
				break;
			}
			default: printf("Opcion no valida\n");

		}	
		system("pause");
		system("cls");
	}while(menu != 0);
}

/*void insertarElemento(tDatosPaciente pDatosPaciente){
	tDatosPaciente datos;
	if (colaLlena(vCola)){
		printf("No hay turnos disponibles\n");
	}else{	
		/*Actualizar el indice final
		vCola.final = vCola.final + 1;
		 /* Almacenar el elemento en la lista
		strcpy(vCola.lista[vCola.final].nombreCompleto, pDatosPaciente);
		strcat (vCola.lista[vCola.final].nombreCompleto, ", ");
		strcat(vCola.lista[vCola.final].nombreCompleto, pDatosPaciente);
		vCola.lista[vCola.final].cobertura = pCobertura;
		/* Verificar si se está insertando el primer elemento 
		if(vCola.final == 0){
			/* Es el primer elemento
			vCola.frente = 0;
		}
		printf("El paciente insertado es: %s \n", vCola.lista[vCola.final].nombreCompleto);
	}
}*/

void eliminarElementoFM(){
	tDatosPaciente datos;
	tString pcteEliminar = " ";
	int cobertEliminar = 0;
	
	if(colaVacia(vCola)){
		printf("No hay turnos asignados\n");
	}else{
		/*Resguardar el elemento a eliminar*/
		
		strcpy(pcteEliminar, vCola.lista[vCola.frente].nombreCompleto);
		cobertEliminar = vCola.lista[vCola.frente].cobertura;
		/*Borrar el elemento que se encuentra en el frente*/
		strcpy(vCola.lista[vCola.frente].nombreCompleto, " ");
		vCola.lista[vCola.frente].cobertura = 0;
		/*Verificar si la cola tiene un solo elemento y actualizar índice*/
		if(vCola.frente == vCola.final){
			vCola.frente = -1;
			vCola.final = -1;
		}else{
			vCola.frente = vCola.frente + 1;
		}

		/*Mensaje de eliminado*/
		printf("Paciente eliminado: %s - %d\n", pcteEliminar, cobertEliminar);		
	}
}

void generarListadoPacientes(tCola pCola){
	int i;
	if(colaVacia(vCola)){
		printf("No hay pacientes para mostrar\n");
	}else{
		printf("Listado de pacientes:\n");
		for (i=vCola.frente; i<= vCola.final; i++){
			printf("# Paciente nro %d : \n\tApellido y nombre: %s \n\tCobertura: %d\n", i+1, vCola.lista[i].nombreCompleto, vCola.lista[i].cobertura);
		}
	}
}

void turnosDisponibles(){
	if (colaLlena(vCola)){
		printf("No hay turnos disponibles\n");
	}else{
		printf("Si, hay turnos disponibles\n");
	}
}


	                                                    
