#include <stdio.h>	
#include <stdlib.h>

int main() {
	
	int limite_inferior = 1;
	int limite_superior = 10;
	
	srand(time(NULL));
	
	/* número aleatorio entre 1 y 10 */
	printf("%d\n", limite_inferior + rand() % (limite_superior + 1 - limite_inferior));
	
	/*número aleatoria sin intervalo*/ 
	printf("%d", rand());

}


		
