#include <stdio.h>
/*Pubico*/
typedef struct{
	int caraInferior, caraSuperior;
}tDado;

void inicializarCaras(tDado);
void lanzarDado(tDado);

/*Privado*/
void inicializarCaras(tDado pDado){
	pDado.caraInferior = 0;
	pDado.caraSuperior = 0;
}

void lanzarDado(tDado pDado){
	pDado.caraInferior = 1;
	pDado.caraSuperior = 6;
	
	srand (time(NULL));
	
	printf("El numero es: %d\n", pDado.caraInferior + rand() % (pDado.caraSuperior + 1 - pDado.caraInferior));
	
}


