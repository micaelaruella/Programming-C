#include <stdio.h>

/*Parte publica*/

typedef struct{
	float base, altura;
}tDatosRectangulo;

float calcularPerimetro(tDatosRectangulo); /*suma de sus lados*/
float calcularArea(tDatosRectangulo); /*base x altura*/

/*Parte privada: Implementacion*/

float calcularPerimetro(tDatosRectangulo pDatosRectangulo){
	float perimetro;
	perimetro = (pDatosRectangulo.base * 2) + (pDatosRectangulo.altura * 2);
	return perimetro;
}

float calcularArea(tDatosRectangulo pDatosRectangulo){
	float area;
	area = pDatosRectangulo.base * pDatosRectangulo.altura;
	return area;
	
}
