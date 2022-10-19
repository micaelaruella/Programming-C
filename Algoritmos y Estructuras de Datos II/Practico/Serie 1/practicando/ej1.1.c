/*Implemente una pila con capacidad de 10 elementos, donde cada elemento será un número real. El
programa debe permitirle al usuario ingresar elementos (números reales) a la pila hasta que la misma se
llene o el usuario no desee cargar más valores en la pila. Como salida debe devolver la suma de todos los
elementos apilados, a través de una función. Además, mostrar los elementos que se encuentran apilados.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef float tPila [MAX];
tPila pila; 

int tope; 

void crearPilaVacia();
bool pilaLlena();
bool pilaVacia();
void apilar(float);
void listarElementos();
float sumar();
void desapilar();
void menu();

int main(){
	crearPilaVacia();
	menu();
	return 0;
}

void menu(){
	int menu;
	
	printf("Menu de opciones\n");
	printf("0.Salir\n");
	printf("1.Insertar elemento\n");
	printf("2.Eliminar elemento\n");
	printf("3.Mostrar listado de elementos\n");
	printf("4.Sumar todos los elementos\n");
	printf("Seleccione una opcion:");
	scanf("%d", &menu);
	system("cls");
	
	while (menu != 0){
		switch (menu){
			case 1: {
				float num;
				if (pilaLlena() != true){
					printf("Ingrese un numero real (0.0 = fin): ");
					scanf("%f", &num);	
					while (num != 0.0){
						apilar(num);
						printf("Ingrese un numero real (0.0 = fin): ");
						scanf("%f", &num);		
					}											
				}else{
					printf("Pila llena. \n");
				}	
				break;
			}
			case 2:{
				desapilar();
				break;
			}
			case 3:{
				listarElementos();
				break;
			}
			case 4: {
				
				break;
			}
		}
		
	system("pause");
	system("cls");
	printf("Menu de opciones\n");
	printf("0.Salir\n");
	printf("1.Insertar elemento\n");
	printf("2.Eliminar elemento\n");
	printf("3.Mostrar listado de elementos\n");
	printf("4.Sumar todos los elementos\n");
	printf("Seleccione una opcion:");
	scanf("%d", &menu);
	system("cls");	
	}
}

void crearPilaVacia(){
	tope = -1;
}

bool pilaLlena(){
	if (tope == (MAX - 1)){ 
		return true;		
	}else {
		return false;
	}
}

bool pilaVacia(){
	if (tope == -1){
		return true;
	}else {
		return false;
	}
}

void apilar(float pElemento){
	if (pilaLlena()){
		printf("Pila llena. Desbordamiento.\n");
	}else{
		tope++;
		pila[tope] = pElemento;
		printf("Elemento apilado! \n");
	}
}

void desapilar(){
	if (pilaVacia()){
		printf("Pila vacia. Subdesbordamiento. \n");	
	}else{
		pila[tope] = 0;
		tope = tope - 1;
		printf("Elemento desapilado! \n");
	}
}

void listarElementos(){
	int i;
	if (pilaVacia()){
		printf("No hay elementos para mostrar\n");
	}else{
		printf("Los elementos en pila son: ");
		for (i=0; i<=tope; i++){
			printf("%.2f \n", pila[i]);
		}		
	}

}
float sumar(){
	float suma = 0.0;
	int i;
	for(i=0; i<=tope; i++){
		suma = suma + pila[i];	
	}
	return suma;
}
