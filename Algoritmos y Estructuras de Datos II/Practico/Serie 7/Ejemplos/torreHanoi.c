#include <stdio.h>

void torreHanoi(int, int, int, int);

int main(){
	int n;
	printf("Ingrese el numero de discos: ");
	scanf("%d", &n);
	torreHanoi(n, 1, 2, 3);
	
	return 0;
}

void torreHanoi(int n, int origen, int aux, int destino){
	if(n==1){
		printf("Mover disco de %d a %d \n", origen, destino);
	}else{
		torreHanoi(n-1, origen, destino, aux);
		printf("Mover disco de %d a %d \n", origen, destino);
		torreHanoi(n-1, aux, origen, destino);
	}
	
}
