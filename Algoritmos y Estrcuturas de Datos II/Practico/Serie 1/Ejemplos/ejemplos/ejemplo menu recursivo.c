/*ejemplo menu recursivo*/

#include<stdio.h>
#include<string.h>

void menu();
void accion1();
void accion2();

int a,b;

int main(){
	menu();
	return 0;
}

void menu(){
	int opcion;
	
	printf("\nIngrese una opcion:");
	printf("\n1): sumar 2 numeros");
	printf("\n2): restar 2 numeros\n");
	scanf("%d",&opcion);
	switch(opcion){
		case 1:{
			accion1();
			menu();
			break;
		}
		case 2:{
			accion2();
			menu();
			break;
		}
	}
}
void accion1(){
	printf("\nIngrese dos numeros enteros para sumarlos:");
	printf("\na: ");
	scanf("%d",&a);
	printf("\nb: ");
	scanf("%d",&b);
	printf("\nLa suma de %d y %d es %d",a,b,a+b);
}
void accion2(){
	printf("\nIngrese dos numeros enteros para multiplicarlos:");
	printf("\na: ");
	scanf("%d",&a);
	printf("\nb: ");
	scanf("%d",&b);
	printf("\nEl producto de %d y %d es %d",a,b,a*b);
}

