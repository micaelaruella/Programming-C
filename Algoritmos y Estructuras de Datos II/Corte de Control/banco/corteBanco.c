#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define TITULO "*** Detalle de Movimientos por cuenta ***\n"

/*Declaración de tipos de datos personalizados*/
typedef char tString [50];

typedef struct {
	int nroCuenta;
	tString nombreCliente;
	int codOperacion;
	float importe;
}tRegistroCuenta;

/*Declaración de prototipo*/
void inicializacion();
void procesoCorte();
void finalizacion();

void principioCorte();
void unaCuenta();
void finCorte();

/*Declaración de variables globales*/
tRegistroCuenta cuenta, cuentaAnt;
FILE * archCuenta;

float totalCta, totalDeposito, totalExtraccion, subtotalDeposito, subtotalExtraccion;
int movDepositos, movExtracciones;

/*Función principal*/
int main(){
	 inicializacion();
	 procesoCorte();
	 finalizacion();
	return 0;
}

/*Implementación de funciones*/
void inicializacion(){
	/*Abre archivo*/
	archCuenta = fopen ("Cliente.dat", "rb");
	
	if (archCuenta != NULL){
		/*Lee el primer registro*/
		fread(&cuenta, sizeof (tRegistroCuenta), 1, archCuenta);
	}else{
		printf("No existe el archivo...\n");
		exit (EXIT_FAILURE);
	}
	
	/*Guarda el registro anterior*/
	cuentaAnt = cuenta;
	
	/*Inicializa contadores/acumuladores totales*/
	totalCta = 0.0;
	totalDeposito = 0.0;
	totalExtraccion = 0.0;

	/*Mostrar titulo*/
	printf("%s", TITULO);
	printf("\n--------------------------------------------------------------\n");
	printf("Nro. Cuenta \t\t Deposito \t\t Extraccion \n");
	printf("--------------------------------------------------------------\n");
	
	
}
void procesoCorte(){
	/*Reccore el archivo hasta feof*/
	while (!feof(archCuenta)){
		principioCorte();
		/*Recorre cada cuenta*/
		while (!feof(archCuenta) && cuenta.nroCuenta == cuentaAnt.nroCuenta){
			unaCuenta();
			/*Lee otro archivo*/
			fread(&cuenta, sizeof (tRegistroCuenta), 1, archCuenta);			
		}
		finCorte();
	}
	
}
void principioCorte(){
	subtotalDeposito = 0.0;
	subtotalExtraccion = 0.0;
	movDepositos = 0; 
	movExtracciones = 0;
}
void unaCuenta(){
	printf("\t%d \t\t %.2f \t\t %.2f\n", cuenta.nroCuenta, 
	cuenta.codOperacion == 1 ? cuenta.importe : 0, 
	cuenta.codOperacion == 2 ? cuenta.importe : 0);
	
	if(cuenta.codOperacion == 1){
		movDepositos = movDepositos + 1;
		subtotalDeposito = subtotalDeposito + cuenta.importe;
	}else if (cuenta.codOperacion == 2){
		movExtracciones = movExtracciones + 1;
		subtotalExtraccion = subtotalExtraccion + cuenta.importe;
		
	}
	

}
void finCorte(){ 
	printf("--------------------------------------------------------------\n");
	printf("Total Cta %d: \t\t $%.2f  \t\t$%.2f \n", cuentaAnt.nroCuenta, subtotalDeposito, subtotalExtraccion );
	printf("Cantidad de mov Cta %d:   %d \t\t\t %d\n", cuentaAnt.nroCuenta, movDepositos, movExtracciones);
	printf("--------------------------------------------------------------\n");
	
	totalDeposito = totalDeposito + subtotalDeposito;
	totalExtraccion = totalExtraccion + subtotalExtraccion;	
	cuentaAnt = cuenta;
}

void finalizacion(){
	fclose (archCuenta);
}
