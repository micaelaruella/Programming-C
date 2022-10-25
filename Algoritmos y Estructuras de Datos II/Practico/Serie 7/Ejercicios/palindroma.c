#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define TITULO "### Programa para determinar si una palabra es palindroma ###\n"
#define MAX 30

typedef char tString[MAX];


bool palindromo(tString, int, int);

bool resultado;
int i = 0;
int longitud = 0;
tString cadena;

int main(){
	printf("%s", TITULO);
	printf("Ingrese una palabra: ");
	gets(cadena);
	
	longitud = strlen(cadena);
	resultado = (palindromo(cadena, i, longitud-1));
	if(resultado){
		printf("La palabra es un palindromo!\n");
	}else{
		printf("La palabra no es un palindromo!\n");
	}
	getch(); /*No se cierra la ventana hasta pulsar una tecla*/
	return 0;
}


bool palindromo(tString cadena, int inicio, int fin){
	if(inicio>=fin){
		return true;
	}else if(cadena[inicio]==cadena[fin]){
		palindromo(cadena, inicio+1, fin-1);
	}else{
		return false;
	}
}
