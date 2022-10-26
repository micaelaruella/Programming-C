/*Escribir una función que permita encontrar un valor en un arreglo de números reales, según el método de
búsqueda binaria. La función debe devolver true en el caso que el elemento a buscar exista dentro del
arreglo y false en caso contrario. Probar la función en el bloque principal de un programa C.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5

typedef float tVectorFloat [MAX];

void cargarVectorOrdenado(tVectorFloat);
void mostrarVector(tVectorFloat);

bool encontrarValorBB(tVectorFloat, float);

tVectorFloat vector;

int main(){
	cargarVectorOrdenado(vector);
	mostrarVector(vector);
	
	bool existeValor, existeValor2;
	existeValor = encontrarValorBB(vector, 50.1);
	printf("Existe el valor 50.1 en el vector?: %s \n", existeValor == true ? "True" : "False");
	
	existeValor2 = encontrarValorBB(vector, 33.5);
	printf("Existe el valor 33.5 en el vector?: %s \n", existeValor2 == true ? "True" : "False");
	
	return 0;
}

void cargarVectorOrdenado(tVectorFloat pVector){
	pVector[0]= 22.5;
	pVector[1]= 33.5;
	pVector[2]= 55.4;
	pVector[3]= 88.3;
	pVector[4]= 98.7;			
}

void mostrarVector(tVectorFloat pVector){
	int i;
	for(i=0; i<MAX; i++){
		printf("%.2f \t", pVector[i]);
	}
	printf("\n");
}

bool encontrarValorBB(tVectorFloat pVector, float pElem){
	int extInf = 0;
	int extSup = MAX;
	int posMedio;
	bool existe = false;
	
	while((!existe) && (extSup >= extInf)){
		posMedio = (extSup + extInf) / 2;
		if(pVector[posMedio] == pElem){
			existe = true;
		}else if(pElem > pVector[posMedio]){
			extInf = posMedio + 1;
		}else{
			extSup = posMedio - 1;
		}		
	}
	return existe;	
}
