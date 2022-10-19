/*ejemplo menu recursivo*/

#include<stdio.h>
#include<string.h>

void menu();
void sumar();
void restar();
void multiplicar();
void dividir();


int a,b,c;

int main(){
	menu();
	return 0;
}

void menu(){
	int opcion;
	
	printf("### Menu de opciones ### \n");
	printf("0. Salir.\n");
	printf("1. Sumar.\n");
	printf("2. Restar.\n");
	printf("3. Multiplicar.\n");
	printf("4. Dividir.\n");

	printf("Seleccione una opcion del menu:");
	scanf("%d",&opcion);
	system("cls");
	
	while (opcion !=0){
		switch(opcion){
			case 1:{
				sumar();
				system("pause");
				system("cls");
				menu();
				break;
			}
			case 2:{
				restar();
				system("pause");
				system("cls");
				menu();
				break;
			}
			case 3:{
				multiplicar();
				system("pause");
				system("cls");
				menu();				
				break;
			}
			case 4:{
				dividir();
				system("pause");
				system("cls");
				menu();				
				break;
			}
		}	
	}
}



void sumar(){
	printf("Ingrese dos numeros enteros para sumar:\n");
	printf("\na: ");
	scanf("%d",&a);
	printf("\nb: ");
	scanf("%d",&b);
	printf("\nLa suma de %d y %d es %d \n",a,b,a+b);
}
void multiplicar(){
	printf("\nIngrese dos numeros enteros para multiplicar:\n");
	printf("\na: ");
	scanf("%d",&a);
	printf("\nb: ");
	scanf("%d",&b);
	printf("\nEl producto de %d y %d es %d\n",a,b,a*b);
	
}
void restar(){
	printf("\nIngrese dos numeros enteros para restar:\n");
	printf("\na: ");
	scanf("%d",&a);
	printf("\nb: ");
	scanf("%d",&b);
	printf("\nLa resta de %d y %d es %d\n",a,b,a-b);	
	
}

void dividir(){
	printf("\nIngrese dos numeros enteros para dividir:\n");
	printf("\na: ");
	scanf("%d",&a);
	printf("\nb: ");
	scanf("%d",&b);
	printf("\nLa division de %d y %d es %d\n",a,b,a/b);		
}



