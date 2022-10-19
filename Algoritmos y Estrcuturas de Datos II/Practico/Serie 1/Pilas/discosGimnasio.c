#include <stdio.h>
#include <stdbool.h>
#define MAX 12

typedef float tArrayPesoDisco [MAX];
typedef struct {
	tArrayPesoDisco lista;
	int tope;
}tPila;
tPila pila;

void menu();
void crearPilaVacia();
bool pilaLlena(tPila);
bool pilaVacia(tPila);
void listarPesosDiscos(tPila);
void apilar(float);
void desapilar();
void discoTope();
void cantidadDiscos();
void calcularPromedio(tPila);

int main(){
	crearPilaVacia();
	menu();
	return 0;
}

void menu(){
	int menu;
	printf("### Menu de opciones ###\n");
	printf("0. Salir\n");
	printf("1. Ingresar peso de disco \n");
	printf("2. Mostrar listado los pesos de los discos apilados\n");
	printf("3. Eliminar disco \n");
	printf("4. Mostrar el disco en tope \n");		
	printf("5. Mostrar cantidad de discos apilados \n");
	printf("6. Calcular promedio de pesos de los discos apilados\n");
	printf("\nSeleccione una opcion del menu:");
	scanf("%d", &menu);	
	system("cls");		
	
	while (menu != 0){
		switch (menu){
			case 1:{
				float peso;
				if (!pilaLlena(pila)){
					printf("Ingrese el peso del disco (0 = inicio):");
					scanf("%f", &peso);
					while (peso != 0){
					apilar(peso);
					printf("Ingrese el peso del disco (0 = inicio):");
					scanf("%f", &peso);	
					}
				}			
				break;
			}
			case 2:{
				listarPesosDiscos(pila);
				break;
			}
			case 3:{
				desapilar();
				break;
			}
			case 4:{
				discoTope();
				break;
			}	
			case 5:{
				cantidadDiscos();
				break;
			}
			case 6:{
				calcularPromedio(pila);
				break;
			}														
		}
	
	system("pause");
	system("cls");	
	printf("### Menu de opciones ###\n");
	printf("0. Salir\n");
	printf("1. Ingresar peso de disco \n");
	printf("2. Mostrar listado los pesos de los discos apilados\n");
	printf("3. Eliminar disco \n");
	printf("4. Mostrar el disco en tope \n");		
	printf("5. Mostrar cantidad de discos apilados \n");
	printf("6. Calcular promedio de pesos de los discos apilados\n");
	printf("\nSeleccione una opcion del menu:");
	scanf("%d", &menu);	
	system("cls");		
	}
}


void crearPilaVacia(){
	pila.tope = -1; /*Inicializar tope en -1 porque el indice del array comienza en 0*/
}

bool pilaLlena(tPila pPila){
	return (pPila.tope == (MAX-1));
}

bool pilaVacia(tPila pPila){
	return (pPila.tope == -1);	
}

void apilar(float peso){
	if (!pilaLlena(pila)){
		pila.tope++; /*pila.tope = pila.tope + 1;*/
		pila.lista[pila.tope] = peso;
		printf("Peso de disco insertado!\n", pila.lista[pila.tope]);
	}else{
		printf("Pila llena!\n");
	}
}

void desapilar(){
	if (pilaVacia(pila)){
		printf("Pila vacia! \n");
	}else{
		pila.lista[pila.tope] = 0;
		pila.tope = pila.tope - 1;
		printf("Peso de disco eliminado! \n");
	}
}

void discoTope(){
	printf("El peso del disco que se encuentra en el tope es: %.2f\n", pila.lista[pila.tope]);
}

void listarPesosDiscos(tPila pPila){
	int i;
	printf("Listado de discos apilados: \n");
	for (i=0; i<= pPila.tope; i++){
		
		printf("%.2f\n", pPila.lista[i]);		
	}
}
void cantidadDiscos(){
	printf("La cantidad de discos apilados es: %d\n", pila.tope + 1);
	
}


void calcularPromedio(tPila pPila){
	float suma = 0.0;
	float promedio = 0.0;
	int i;
	for(i=0; i<= pPila.tope; i++){
		suma = suma + pila.lista[i];
	}
	
	promedio = suma / (pila.tope + 1) ;
	printf("El promedio  de pesos de los discos apilados es: %.2f \n", promedio);
}































