#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

/*Declaración de tipos de datos personalizados*/
typedef char tString [50];

typedef struct {
	int nroCuenta;
	tString nombreCliente;
	int codOperacion;
	float importe;
}tRegistro;

/*Declaración de prototipo*/
void inicializacion();
void grabar();
void finalizacion();

void registrarDatos();

/*Declaración de variables globales*/
tRegistro cuenta;
FILE * archivoBanco;

/*Función principal*/
int main(){
	 inicializacion();
	 grabar();
	 finalizacion();
	return 0;
}

/*Implementacion de funciones*/

void inicializacion(){
	
	archivoBanco = fopen ("Cliente.dat", "wb");

}
void grabar(){
	char respuesta, respuesta2;

	printf("Desea registrar una operacion? S/N: ");
	fflush(stdin);
	scanf("%c", &respuesta);
	while (respuesta != 'n' ){
		registrarDatos();		
		fwrite(&cuenta, sizeof(tRegistro), 1, archivoBanco);
		printf("\nOperacion registrada!\n");
		Sleep(2000);
		
		printf("Desea ingresar otra operacion con la misma cuenta? S/N: ");
		fflush(stdin);
		scanf("%c", &respuesta2);
	
		while (respuesta2 != 'n' ){

			printf("Codigo de operacion (1-Deposito/2-Extraccion): ");
			scanf("%d", &cuenta.codOperacion);
			printf("Importe: ");
			scanf("%f", &cuenta.importe);
			
			printf("\nOperacion registrada!\n");
			Sleep(2000);			
	
			printf("\nDesea ingresar otra operacion con la misma cuenta? S/N: ");
			fflush(stdin);
			scanf("%c", &respuesta2);	
		
			fwrite(&cuenta, sizeof(tRegistro), 1, archivoBanco);
		}
		
		printf("\nLa operacion fue exitosa!\n");
		Sleep(2000);
		system("pause");
		system("cls");
		printf("\nDesea registrar una operacion? S/N: ");
		fflush(stdin);
		scanf("%c", &respuesta);

	}

}


void registrarDatos(){

		printf("*********************************\n");
		printf("Ingrese los siguientes datos por movimiento: \n");
		printf("Numero de cuenta: ");
		scanf("%d", &cuenta.nroCuenta);
		printf("Nombre y apellido del cliente: ");
		fflush(stdin);
		gets(cuenta.nombreCliente);
		printf("Codigo de operacion (1-Deposito/2-Extraccion): ");
		scanf("%d", &cuenta.codOperacion);
		printf("Importe: ");
		scanf("%f", &cuenta.importe);	
	
}

void finalizacion(){
	fclose(archivoBanco);
}

