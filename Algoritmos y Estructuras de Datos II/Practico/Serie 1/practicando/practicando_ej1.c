/*Implemente una pila con capacidad de 10 elementos, donde cada elemento será un número real. El
programa debe permitirle al usuario ingresar elementos (números reales) a la pila hasta que la misma se
llene o el usuario no desee cargar más valores en la pila. Como salida debe devolver la suma de todos los
elementos apilados, a través de una función. Además, mostrar los elementos que se encuentran apilados.*/

/*Incluye las librerias necesarias.*/
#include <stdio.h>
#include <stdbool.h> /*para datos de tipo booleanos.*/
#define MAX 10 /*Definir la capaidad máxima de la pila*/

/*Declaración de tipos de datos personalizados.*/
typedef float tPila [MAX];
tPila pila;

/*Declaración de variables globales.*/

int tope;

/*Declaración de funciones.*/

void crearPilaVacia();
bool pilaLlena();
bool pilaVacia();
void apilarElementos(float); 
void mostrarElementos();
float sumarElementos();
void desapilarElementos();
void menu();

/*Función principal*/
int main(){
	crearPilaVacia();
	menu();
	return 0;
}

/*Desarrollo de funciones*/

void crearPilaVacia(){
	tope = -1; 
}

bool pilaLlena(){
	if (tope == (MAX-1)){
		return true;
	}else{
		return false;
	}
}

bool pilaVacia(){
	if(tope == -1){
		return true;
	}else{
		return false;
	}
}

void apilarElementos(float pElemento){ /*PUSH*/
	if (pilaLlena()){
		printf("La pila est%c llena.\n", 160);
	}else{
		tope = tope +1;/*Actualiza tope*/
		pila [tope] = pElemento;  /*inserta el nuevo elemento en el tope de pila.*/
		printf("Elemento insertado. \n");
	}	
}

void desapilarElementos(){ /*POP*/
	if (pilaVacia()){
		printf("La pila est%c vacia. \n", 160);
	}else{
		pila [tope] = 0; 
		tope = tope -1; /*Actualiza tope*/
		printf("Elemento eliminado. \n");
	}
}

void mostrarElementos(){
	int i;
	printf("Los elementos en pila son: \n");
	for (i=0; i<=tope; i++){
		printf("%.2f\n", pila[i]);
	}
}

float sumarElementos(){
	
	float suma = 0.0;	
	int i;
	for(i=0; i<=tope; i++){
		suma = suma + pila[i];
	}
	return suma;
}

void menu(){
	int menu;
	
	printf("### Menu de opciones ###\n");
	printf("0. Salir.\n");
	printf("1. Apilar elemento. \n");
	printf("2. Mostrar lista de elementos. \n");
	printf("3. Eliminar elemento apilado. \n");
	printf("4. Sumar elementos apilados.\n");
	printf("Seleccione una opcion:");
	scanf("%d", &menu);
	system("cls");  /*Limpia*/
	
	while (menu != 0){
		switch(menu){
			case 1:{
				float numReal;
				if (!pilaLlena()){
					printf("Ingrese un numero real (0.0 = volver al inicio): ");
					scanf("%f", &numReal);
						while (numReal != 0.0){
							apilarElementos(numReal);
							printf("Ingrese un numero real (0.0 = volver al inicio): ");
							scanf("%f", &numReal);
						}	
				}else{
					printf("Pila llena. \n");
				}
				break;
			}
			case 2:{
				mostrarElementos();
				break;
			}
			case 3: {
				desapilarElementos();
				break;
			}
			case 4: {
				float sumaTotal = sumarElementos();
				printf("El valor de sumar todos los elementos apilados es: %.2f \n", sumaTotal);
				
				break;
			}
		}
		
		system("pause");
		system("cls");
		printf("### Menu de opciones ###\n");
		printf("0. Salir.\n");
		printf("1. Apilar elemento. \n");
		printf("2. Mostrar lista de elementos. \n");
		printf("3. Eliminar elemento apilado. \n");
		printf("4. Sumar elementos apilados.\n");
		printf("Seleccione una opcion:");
		scanf("%d", &menu);
		system("cls");
	}
}


























