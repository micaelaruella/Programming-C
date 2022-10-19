#include <stdio.h>
#include <stdlib.h>

typedef int cosa; /*cosa es un tipo de dato entero*/
typedef cosa *apuntadorACosa; /*apuntadorACosa es un tipo de dato de puntero entero*/
cosa c, cc; /*variables de tipo entero*/
apuntadorACosa apuntC, apuntCC; /*variables de tipo puntero que apuntan a un entero*/


int main() {
	apuntC = NULL; 
	apuntCC = malloc(sizeof(int));
	
	/*¿Qué contienen las siguientes variables?
a) apuntC -> Contiene NULL
b) apuntCC -> Dirección de memoria
c) c -> nada
d) cc -> nada
e) *apuntC -> nada
f) *apuntCC -> nada    */ 
	return 0;
}
