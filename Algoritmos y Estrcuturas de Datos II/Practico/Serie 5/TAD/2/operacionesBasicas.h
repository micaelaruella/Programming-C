
/*Parte privada*/
typedef struct{
	float a, b;
}tDatosValores;

float sumar(tDatosValores );
float restar(tDatosValores);
float multiplicar(tDatosValores );
float dividir(tDatosValores);


/*Parte publica*/
float sumar(tDatosValores pValor){
	float suma = 0.0;
	suma = (pValor.a + pValor.b);
	return suma;
}

float restar(tDatosValores pValor){
	float resta = 0.0;
	resta = (pValor.a - pValor.b);
	return resta;
}
float multiplicar(tDatosValores pValor){
	float producto = 0.0;
	producto = (pValor.a * pValor.b);
	return producto;
}
float dividir(tDatosValores pValor){
	float division = 0.0;
	division = (pValor.a / pValor.b);
	return division;
}


