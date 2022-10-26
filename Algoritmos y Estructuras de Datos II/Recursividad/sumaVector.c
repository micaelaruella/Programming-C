#include <stdio.h>
#define TITULO "Programa para sumar elementos de un vector de manera recursiva\n"
#define NMAX 5

typedef int tVector[NMAX];

void cargarVector();
void mostrarVector();
int sumaVec(tVector, int);

tVector v;

int main(){
	int suma = 0;
	
	printf("%s", TITULO);	
	cargarVector();
	mostrarVector();
	suma = sumaVec(v, NMAX);
	printf("La suma total de los elementos del vector es: %d \n", suma);
	return 0;
}

void cargarVector( ){
	v[0]= 10;
	v[1]= 20;
	v[2]= 30;
	v[3]= 40;
	v[4]= 50;
}

void mostrarVector(){
	int i;
	printf("Lista de elementos del vector: \n");
	for(i=0; i<NMAX; i++){
		printf("%d \t", v[i]);
	}
	printf("\n");
}

int sumaVec(tVector v, int n){
	if(n == 0){
		return 0;
	}else{
		return (sumaVec(v, n-1)+v[n-1]);
	}
}



