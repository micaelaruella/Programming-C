#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define MAX 40

typedef char tString20[20];
typedef struct{
	int numero;
	tString20 localidad;
}tDatoLlamada;
typedef struct{
	tDatoLlamada vLlamada[MAX];
	int frente,final;
}tCola;
tCola cLlamadas;

void incializarCola();
bool colaLlena(tCola);
bool colaVacia(tCola);
void menu();
void aumentarCola(int,tString20);
int cantidadEnEspera(tCola);
void contestarLlamada();
void listaLlamadasAtendidas();


int main(){
	incializarCola();
	menu();
	
	return 0;
}

void incializarCola(){
	cLlamadas.frente=-1;
	cLlamadas.final=-1;
}
bool colaLlena(tCola pCola){
	return(pCola.final==MAX);
}
bool colaVacia(tCola pCola){
	return(pCola.final==-1);
}
void menu(){
	int opcion;
	system("cls");
	printf("\n*********************MENU*********************");
	printf("\n1) Ingrese datos de la llamada entrante.");
	printf("\n2) Cantidad de llamadas en espera.");
	printf("\n3) Atender llamada en espera.");
	printf("\n4) Listado de llamadas atendidas .");
	printf("\n5) Salir.\n");
	scanf("%d",&opcion);
	system("cls");
	if(opcion<1||opcion>5){
		printf("\nLa opcion ingresada es incorrecta!\n");
		system("pause");
		menu();		
	}
	switch(opcion){
		case 1:{
			int num;
			tString20 local;
			char salida='n';
			do{
				printf("\nDatos de la llamada:\nNumero: ");
				scanf("%d",&num);
				printf("\nLocalidad: ");
				fflush(stdin);
				gets(local);
				local[0]=toupper(local[0]);
				aumentarCola(num,local);
				if(cLlamadas.frente!=-1){
					printf("\nIngresar otra llamada? (s/n)");
					salida=tolower(salida);
					fflush(stdin);
					scanf("%c",&salida);
				}
			}while(salida!='n');
			printf("\n");
			system("pause");
			menu();
			break;
		}
		case 2:{
			if(colaVacia(cLlamadas)){
				printf("\nNo hay llamadas en espera!");
			}else{
				printf("\nHay %d llamadas en espera.",cantidadEnEspera(cLlamadas));
			}
			printf("\n");
			system("pause");
			menu();
			break;
		}
		case 3:{
			contestarLlamada();
			printf("\n");
			system("pause");
			menu();
			break;
		}
		case 4:{
			listaLlamadasAtendidas();
			printf("\n");
			system("pause");
			menu();
			break;
		}
		case 5:{
			printf("\nHasta pronto!");
			break;
		}
	}
}
void aumentarCola(int pNumero,tString20 pLocalidad){
	if(colaLlena(cLlamadas)){
		printf("\nNo hay lugar para mas llamadas en espera!");
	}else{
		if(cLlamadas.frente=-1){
			cLlamadas.frente++;
		}
		cLlamadas.final++;
		cLlamadas.vLlamada[cLlamadas.final].numero=pNumero;
		strcpy(cLlamadas.vLlamada[cLlamadas.final].localidad,pLocalidad);
		printf("\nLlamada puesta en espera!");
	}
}
int cantidadEnEspera(tCola pCola){
	return(pCola.final-pCola.frente+1);
}
void contestarLlamada(){
	if(colaVacia(cLlamadas)){
		printf("\nNo hay llamadas en espera!");
	}else{
		printf("\nAtendiendo el numero %d de la localidad %s",cLlamadas.vLlamada[cLlamadas.frente].numero,cLlamadas.vLlamada[cLlamadas.frente].localidad);
		cLlamadas.frente++;
	}
	
}
void listaLlamadasAtendidas(){
	if(colaVacia(cLlamadas)){
		printf("\nNo hay llamadas en espera!");
	}else{
		if(cLlamadas.frente==0){
			printf("\nNo se atendieron llamadas todavia!");
		}else{
			int i;
			printf("\nLista de llamadas atendidas hasta el momento:");
			for(i=0;i<cLlamadas.frente;i++){
			printf("\nLlamada nro %d\n\tNumero: %d\n\tLocalidad: %s",i+1,cLlamadas.vLlamada[i].numero,cLlamadas.vLlamada[i].localidad);
			}
		}
	}
}


