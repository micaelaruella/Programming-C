#include <stdio.h>	
#include <stdlib.h>

int main() {
	
	int limite_inferior = 1;
	int limite_superior = 10;
	
	srand(time(NULL));
	
	/* n�mero aleatorio entre 1 y 10 */
	printf("%d\n", limite_inferior + rand() % (limite_superior + 1 - limite_inferior));
	
	/*n�mero aleatoria sin intervalo*/ 
	printf("%d", rand());

}


		
