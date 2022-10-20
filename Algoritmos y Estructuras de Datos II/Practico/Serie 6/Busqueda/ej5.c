#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define FILA 2
#define COLUMNA 4
typedef char tString [20];
typedef float tMatriz[FILA][COLUMNA];

tString estilos[5] = {" ", "Chamame", "Tango", "Rock", "Folklore"};

void cargarPuntuaciones(tMatriz);
void mostrarPuntuaciones(tMatriz);
int mostrarGanador(tMatriz);

tMatriz matriz;


int main(){
	cargarPuntuaciones(matriz);
	mostrarPuntuaciones(matriz);
	printf("El ganador es el participante de la posicion %d\n", mostrarGanador(matriz));
	return 0;
}

void cargarPuntuaciones(tMatriz pMatriz){
	int i, j;
	printf("Ingrese las puntuaciones de los participantes: \n");

	for(i=0; i<FILA; i++){
		printf("Participante %d \n", i+1);	
		for(j=0; j<COLUMNA; j++){
			printf("Estilo de baile %d: ", j+1);
			scanf("%f", &pMatriz[i][j]);
		}
		printf("------------------------------------\n");
	}
	
	printf("Se cargaron todas las puntuaciones\n");
	printf("\n\n");
}
void mostrarPuntuaciones(tMatriz pMatriz){
	int i, j;
	for(i=0; i<FILA; i++){
		for(j=0; j<COLUMNA-1; j++){
			printf("%.1f \t", pMatriz[i][j]);
		}
		printf("%.1f \n", pMatriz[i][j]);
		
	}
}

int mostrarGanador(tMatriz pMatriz){
	int i,j;
	float puntMayor, puntMenor, puntExcluy, puntFinal, puntuacion, puntGanador;
	int posGanador; 
	
	puntGanador = 0.0;
	posGanador = 0;
	
	
	for(i=0; i<FILA; i++){
		 puntuacion = 0.0;	
		 puntExcluy = 0.0;	 
		 puntMayor = -1;
		 puntMenor = 9999;
		 puntFinal = 0.0;

		for(j=0; j<COLUMNA; j++){
			
			if(pMatriz[i][j] > puntMayor){
				puntMayor = pMatriz[i][j];
			}else if(pMatriz[i][j] < puntMenor){
				puntMenor = pMatriz[i][j];				
			}

			puntuacion = (puntuacion + pMatriz[i][j]);
			puntExcluy = (puntMayor + puntMenor);
			puntFinal = (puntuacion - puntExcluy);
			
			puntGanador = puntFinal; /*Puntuacion ganadora se le asigna la puntuacion final*/
			posGanador = pMatriz[i][j] ; /*Posicion ganador se le asigna la posicion actual */
			
		}	
		if(puntFinal > puntGanador){
			posGanador = pMatriz[i][j];
		}

	}
	return posGanador;
}
	
