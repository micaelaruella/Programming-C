/*Se dispone de un archivo en el cual se tienen registrados los datos de todos los documentos que se envían
a imprimir en una impresora. Los datos que se almacenan son: IP de la PC que envía el documento,
Nombre del documento, Tipo de documento (01. docx - 02.pdf - 03.jpg - 04.png - 05.xlsx), tamaño en
bytes. El archivo se encuentra ordenado ascendentemente por la IP de la PC que envía el documento. 
El formato del registro es el siguiente:
	IP de la PC que envia el documento-string
	Nombre del documento-string
	Tipo de documento-int-01-docx 02-pdf 03-jpg 04-png 05-xlsx
	Tamaño en bytes*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DOCUMENTS 6

/*TIPOS DE DATOS PERSONALIZADOS*/
typedef char t_string[50];

typedef t_string t_vectorTipoDocumentos[MAX_DOCUMENTS];

typedef struct{
	t_string ipPc;
	t_string nombreDocumento;
	int codTipoDocumento;
	float megabytes;
}tr_datosDocumento;

/*DECLARACION DE PROTOTIPOS*/
void inicializar();
void procesoCorte();
void finalizar();

void principioCorte();
void unDocumento();
void finCorte();


/*DELCARACION DE VARIABLES GLOBALES*/
FILE * vf_documentos;
tr_datosDocumento vr_datosDocumento;
tr_datosDocumento vr_campoControlAnt;

t_vectorTipoDocumentos v_vectorTipoDocumentos = {"","docx","pdf","jpg","png","xlsx"};

unsigned int contDocumentos, contDocumentosTotal, contImagenesTotal;
float sumaPesoDocumentos, sumaPesoDocumentosTotal, sumaPesoImagenesTotal;

/*BLOQUE PRINCIPAL*/
int main() {
	
	inicializar();
	procesoCorte();
	finalizar();
	
	return 0;
}

/*DESARROLLO DE PROCEDIMIENTOS/FUNCIONES*/
void inicializar() {
	vf_documentos = fopen("Documentos.dat", "rb");
	if( vf_documentos != NULL ){
		printf("\nArchivo abierto...\n\n");
	}else {
		printf("ERROR\n");
		exit(EXIT_FAILURE);
	}
	fread(&vr_datosDocumento, sizeof( tr_datosDocumento ),1, vf_documentos);
	
	vr_campoControlAnt = vr_datosDocumento;
	
	contDocumentosTotal = 0; contImagenesTotal = 0;
	sumaPesoDocumentosTotal = 0.0; sumaPesoImagenesTotal = 0.0;
	
	printf("\n------------------------------------------------------------\n");
	printf("\nIP\tDocumento\t\tTamanio(MB)\n");
	printf("\n------------------------------------------------------------\n");
}

void procesoCorte() {
	while( !feof( vf_documentos ) ) {
		principioCorte();
		
		while( !feof( vf_documentos ) && strcmp( vr_campoControlAnt.ipPc, vr_datosDocumento.ipPc ) == 0 ) {
			unDocumento();
			
			fread(&vr_datosDocumento, sizeof( tr_datosDocumento ), 1, vf_documentos);
		}
		finCorte();
	}
}


void principioCorte() {
	contDocumentos = 0; 
	sumaPesoDocumentos = 0.0;
	
	printf("%s\n\n", vr_campoControlAnt.ipPc);
}

void unDocumento() {
	printf("\t%s.%s\t\t%.2f MB\n", vr_datosDocumento.nombreDocumento, 
	v_vectorTipoDocumentos[vr_datosDocumento.codTipoDocumento], vr_datosDocumento.megabytes);
	
	contDocumentos++;
	contDocumentosTotal++;
	
	sumaPesoDocumentos += vr_datosDocumento.megabytes;
	sumaPesoDocumentosTotal += vr_datosDocumento.megabytes;
	
	if( vr_datosDocumento.codTipoDocumento == 3 || vr_datosDocumento.codTipoDocumento == 4 ){
		contImagenesTotal++;
		
		sumaPesoImagenesTotal += vr_datosDocumento.megabytes;
	} 
}

void finCorte() {
	printf("\n\n------------------------------------------------------------");
	printf("\nCantidad de documentos: %d\t%.2f KB", contDocumentos, sumaPesoDocumentos*1024);
	printf("\nimpresos %s", vr_campoControlAnt.ipPc);
	printf("\n------------------------------------------------------------\n");

	
	vr_campoControlAnt = vr_datosDocumento;
}

void finalizar() {
	printf("\n\n------------------------------------------------------------\n");
	printf("\nTotal de archivos de imagenes impresos: %d\t%.2f KB", contImagenesTotal, sumaPesoImagenesTotal*1024);
	printf("\nTotal de documentos impresos: %d\t   %.2fKB", contDocumentosTotal, sumaPesoDocumentosTotal*1024);	
	printf("\n\n------------------------------------------------------------\n");
	
	fclose(vf_documentos);
	printf("\n\nArchivo cerrado...");
}

