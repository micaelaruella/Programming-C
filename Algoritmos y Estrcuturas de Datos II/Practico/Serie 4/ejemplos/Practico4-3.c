#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define TITULO "***Documentos impresos***"

typedef char tString30[30];

typedef struct{
	tString30 ip;
	tString30 nombre;
	int tipo;
	int size;
}tRegImp;
tRegImp rImpresion,rImpresionAnt;
FILE * aImpresiones;
int contImpresiones,contImagenes=0,contDocumentos=0;
float totalEnKB,totalImagenes=0,totalDocumentos=0;
tString30 aux="";

void inicializacion();
void procesoCorte();
void finalizacion();

void principioCorte();
void unaImpresion();
void finCorte();

char* documentoConExtension(tRegImp);

int main(){
	inicializacion();
	procesoCorte();
	finalizacion();
	
	return 0;
}

void inicializacion(){
	fopen("impresiones.dat","rb");
	if(aImpresiones==NULL){
		printf("\nEl archivo no existe!");
		exit(EXIT_FAILURE);
	}else{
		fread(&rImpresion,sizeof(rImpresion),1,aImpresiones);
	}
	rImpresionAnt=rImpresion;
	printf("\n%s",TITULO);
	printf("\nIP\tDocumento\tTamano(MB)");
}
void procesoCorte(){
	while(!feof( aImpresiones )){
		principioCorte();
		while(!feof( aImpresiones) && strcmp( rImpresion.ip , rImpresionAnt.ip ) == 0){
			unaImpresion();
			fread(&rImpresion,sizeof(rImpresion),1,aImpresiones);
		}
		finCorte();
	}
}
void finalizacion(){
	printf("\nTotal de archivos de imagen impresos: %d\t%.3f KB",contImagenes,totalImagenes);
	printf("\nTotal de documentos impresos: %d\t%.3f KB",contDocumentos,totalDocumentos);
	fclose(aImpresiones);
}

void principioCorte(){
	printf("\n%s",rImpresion.ip);
	
	contDocumentos=0;
	totalEnKB=0;
}
void unaImpresion(){
	contImpresiones++;
	if(rImpresion.tipo==3||rImpresion.tipo==4){
		contImagenes++;
		totalImagenes+=rImpresion.size*1024;
	}else if(rImpresion.tipo==1||rImpresion.tipo==2){
		contDocumentos++;
		totalDocumentos+=rImpresion.size*1024;
	}
	totalEnKB+=rImpresion.size*1024;
	printf("\t%s\t%d\n",documentoConExtension(rImpresion),rImpresion.size);
}
void finCorte(){
	printf("Cantidad de documentos impresos por %s\t%d documentos\t%.3f KB",rImpresionAnt.ip,contImpresiones,totalEnKB);
	rImpresionAnt=rImpresion;
}

char* documentoConExtension(tRegImp pImpresion){
	strcpy(aux,pImpresion.nombre);
	switch(pImpresion.tipo){
		case 1:{
			strcpy(aux,".docx");
			break;
		}
		case 2:{
			strcpy(aux,".pdf");
			break;
		}
		case 3:{
			strcpy(aux,".jpg");
			break;
		}
		case 4:{
			strcpy(aux,".png");
			break;
		}
		case 5:{
			strcpy(aux,".xlsx");
			break;
		}
	}
	return (aux);
}

