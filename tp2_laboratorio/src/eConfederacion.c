/*
 * eConfederacion.c
 *
 *  Created on: 26 oct. 2022
 *      Author: pablo
 */


#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
#include "eConfederacion.h"
#include <string.h>
#include "eJugador.h"
#include "outputs.h"

#define VACIO 0
#define LLENO 1

int inicializarArrayConfederacion(eConfederacion aConfederacion[], int longitud_aConfederacion){
	int retorno;

	retorno=-1;

	if(aConfederacion!=NULL && longitud_aConfederacion>0){
		for(int i=0;i<longitud_aConfederacion;i++){
			aConfederacion[i].isEmpty=VACIO;
		}
		retorno=0;
	}

	return retorno;
}

int buscarIndiceVacioConfederacion(eConfederacion aConfederacion[], int longitud_aConfederacion){
	int indice;

	for(int i=0;i<longitud_aConfederacion;i++){
		if(aConfederacion[i].isEmpty==VACIO){
			indice=i;
			break;
		}
	}

	return indice;
}

int asignarIdConfederacion(eConfederacion aConfederacion[], int longitud_aConfederacion){
	static int id = 99;

	if(aConfederacion!=NULL && longitud_aConfederacion>0){
		id++;
	}

	return id;
}

int pedirNombreConfederacion(eConfederacion* pArrayConfederacion, int longitud_aConfederacion){
	int retorno;
	char bufferNombre[50];
	int errorInput;

	retorno=-1;

	if(pArrayConfederacion!=NULL && longitud_aConfederacion>0){
		errorInput=utn_pedirTexto(bufferNombre, "Ingrese el nombre de la confederacion (max 50 caracteres): ", "ERROR. Nombre invalido. Intente nuevamente.",50,3);
		if(errorInput==0){
			strcpy(pArrayConfederacion->nombre,bufferNombre);
			retorno=0;
		}else{
			printf("\nSIN REINTENTOS\nVOLVIENDO AL MENU PRINCIPAL...");
		}
	}

	return retorno;
}

int pedirRegionConfederacion(eConfederacion* pArrayConfederacion, int longitud_aConfederacion){
	int retorno;
	char bufferRegion[50];
	int errorInput;

	retorno=-1;
	if(pArrayConfederacion!=NULL && longitud_aConfederacion>0){
		errorInput=utn_pedirTexto(bufferRegion, "Ingrese la region (max 50 caracteres): ", "ERROR. Region invalida. Intente nuevamente.",50,3);
		if(errorInput==0){
			strcpy(pArrayConfederacion->region,bufferRegion);
			retorno=0;
		}else{
			printf("\nSIN REINTENTOS\nVOLVIENDO AL MENU PRINCIPAL...");
		}
	}

	return retorno;
}

int pedirAnioCreacionConfederacion(eConfederacion* pArrayConfederacion, int longitud_aConfederacion){
	int retorno;
	int errorInput;
	int bufferAnioCreacion;

	retorno=-1;

	if(pArrayConfederacion!=NULL && longitud_aConfederacion>0){
		errorInput=utn_pedirNumero(&bufferAnioCreacion, "Ingrese el año de creación: ", "ERROR. Año de creacion invalido",1900,2022,3);

		if(errorInput==0){
			pArrayConfederacion->anioCreacion=bufferAnioCreacion;
			retorno=0;
		}else{
			printf("\nSIN REINTENTOS\nVOLVIENDO AL MENU PRINCIPAL...");
		}
	}

	return retorno;
}

int altaConfederacion(eConfederacion aConfederacion[], int longitud_aConfederacion){
	int retorno;
	eConfederacion bufferConfederacion;
	int indice;
	int errorInput;
	eConfederacion* pBufferConfederacion;

	pBufferConfederacion=&bufferConfederacion;

	retorno=-1;

	if(aConfederacion!=NULL && longitud_aConfederacion>0){
		indice=buscarIndiceVacioConfederacion(aConfederacion, longitud_aConfederacion);
		if(indice>=0){
			bufferConfederacion.id=asignarIdConfederacion(aConfederacion, longitud_aConfederacion);
			errorInput=pedirNombreConfederacion(pBufferConfederacion,longitud_aConfederacion);
			if(errorInput==0){
				errorInput=pedirRegionConfederacion(pBufferConfederacion,longitud_aConfederacion);
				if(errorInput==0){
					errorInput=pedirAnioCreacionConfederacion(pBufferConfederacion,longitud_aConfederacion);
				}
			}
		}
		if(errorInput==0){
			aConfederacion[indice].id=bufferConfederacion.id;
			strcpy(aConfederacion[indice].nombre,bufferConfederacion.nombre);
			strcpy(aConfederacion[indice].region,bufferConfederacion.region);
			aConfederacion[indice].anioCreacion=bufferConfederacion.anioCreacion;
			aConfederacion[indice].isEmpty=LLENO;
			retorno=0;
		}
	}

	return retorno;
}

int darBajaConfederacion(eConfederacion aConfederacion[], int longitud_aConfederacion, int idElegido){
	int retorno;

	retorno=-1;

	if(aConfederacion!=NULL && longitud_aConfederacion>0 && idElegido >= 0){
		for(int i=0;i<longitud_aConfederacion;i++){
			if(aConfederacion[i].id==idElegido && aConfederacion[i].isEmpty==LLENO){
				aConfederacion[i].isEmpty=VACIO;
				retorno=0;
			}
		}
	}

	return retorno;
}

int menuDarBajaConfederacion(eConfederacion aConfederacion[], int longitud_aConfederacion){
	int retorno;
	int idElegido;
	int errorInput;

	retorno=-1;

	if(aConfederacion!=NULL && longitud_aConfederacion>0){
		mostrarDatosIngresadosConfederacion(aConfederacion, longitud_aConfederacion);
		errorInput=utn_pedirNumero(&idElegido, "Elija el ID de la confederacion a dar de baja: ", "ERROR. ID invalido.",0,3000,3);
		if(errorInput==0){
			errorInput=darBajaConfederacion(aConfederacion,longitud_aConfederacion,idElegido);
			if(errorInput==0){
				printf("La confederacion fue dada de baja exitosamente");
				retorno=0;
			}else{
				printf("\nLa confederacion con ese ID no existe\nVOLVIENDO AL MENU PRINCIPAL...");
			}
		}else{
			printf("\nSIN REINTENTOS\nVOLVIENDO AL MENU PRINCIPAL...");
		}
	}

	return retorno;
}

int menuModificarConfederacion(eConfederacion aConfederacion[], int longitud_aConfederacion){
	int retorno;
	int idElegido;
	int errorInput;
	eConfederacion* pArrayConfederacion;

	retorno=-1;
	pArrayConfederacion=aConfederacion;

	mostrarDatosIngresadosConfederacion(aConfederacion,longitud_aConfederacion);
	errorInput=utn_pedirNumero(&idElegido, "Elija el ID de la confederacion que quiere modificar: ", "ERROR. ID invalido",100,longitud_aConfederacion,3);
	if(errorInput==0){
		modificarConfederacion(pArrayConfederacion,longitud_aConfederacion,idElegido);
		retorno=0;
	}else{
		printf("\nSIN REINTENTOS\nVOLVIENDO AL MENU PRINCIPAL...");
	}

	return retorno;
}

int modificarConfederacion(eConfederacion aConfederacion[], int longitud_aConfederacion, int id){
	int retorno;
	int errorInput;
	int opcionElegida;
	eConfederacion bufferConfederacion;
	eConfederacion* pBufferConfederacion;

	pBufferConfederacion=&bufferConfederacion;

	retorno=-1;

	errorInput=utn_pedirNumero(&opcionElegida, "1 - Modificar nombre\n"
			"2 - Modificar region\n"
			"3 - Modificar año de creacion\n"
			"4 - Volver\n"
			"¿Que desea modificar?: ", "ERROR. Opcion invalida.",1,4,3);
	if(errorInput==0){
		switch(opcionElegida){
		case 1:
			errorInput=pedirNombreConfederacion(pBufferConfederacion, longitud_aConfederacion);
			if(errorInput==0){
				strcpy(aConfederacion[id].nombre,bufferConfederacion.nombre);
				retorno=0;
			}
			break;

		case 2:
			errorInput=pedirRegionConfederacion(pBufferConfederacion, longitud_aConfederacion);
			if(errorInput==0){
				strcpy(aConfederacion[id].region,bufferConfederacion.region);
				retorno=0;
			}
			break;

		case 3:
			errorInput=pedirAnioCreacionConfederacion(pBufferConfederacion, longitud_aConfederacion);
			if(errorInput==0){
				aConfederacion[id].anioCreacion=bufferConfederacion.anioCreacion;
				retorno=0;
			}
			break;

		default:
			printf("\nVOLVIENDO AL MENU PRINCIPAL...");
			retorno=0;
		}
	}else{
		printf("\nSIN REINTENTOS\nVOLVIENDO AL MENU PRINCIPAL...");
	}

	return retorno;
}

void hardcodeoConfederaciones(eConfederacion aConfederacion[], int longitud_aConfederacion){
	int id;
	eConfederacion bufferConfederacion;
	eConfederacion* pArrayConfederacion;

	pArrayConfederacion=&bufferConfederacion;

	for(int i=0;i<longitud_aConfederacion;i++){
		id=asignarIdConfederacion(aConfederacion,longitud_aConfederacion);
		asignarNombreHardcodeado(pArrayConfederacion,id);
		asignarRegionHardcodeada(pArrayConfederacion,id);
		asignarAnioCreacionHardcodeado(pArrayConfederacion,id);

		aConfederacion[i].id=id;
		strcpy(aConfederacion[i].nombre,bufferConfederacion.nombre);
		strcpy(aConfederacion[i].region,bufferConfederacion.region);
		aConfederacion[i].anioCreacion=bufferConfederacion.anioCreacion;
		aConfederacion[i].isEmpty=LLENO;
	}
}

void asignarNombreHardcodeado(eConfederacion* pArrayConfederacion, int id){
	if(id==100){
		strcpy(pArrayConfederacion->nombre,"CONMEBOL");
	}else if(id==101){
		strcpy(pArrayConfederacion->nombre,"UEFA");
	}else if(id==102){
		strcpy(pArrayConfederacion->nombre,"AFC");
	}else if(id==103){
		strcpy(pArrayConfederacion->nombre,"CAF");
	}else if(id==104){
		strcpy(pArrayConfederacion->nombre,"CONCACAF");
	}else{
		strcpy(pArrayConfederacion->nombre,"OFC");
	}
}

void asignarRegionHardcodeada(eConfederacion* pArrayConfederacion, int id){
	if(id==100){
		strcpy(pArrayConfederacion->region,"SUDAMERICA");
	}else if(id==101){
		strcpy(pArrayConfederacion->region,"EUROPA");
	}else if(id==102){
		strcpy(pArrayConfederacion->region,"ASIA");
	}else if(id==103){
		strcpy(pArrayConfederacion->region,"AFRICA");
	}else if(id==104){
		strcpy(pArrayConfederacion->region,"NORTE Y CENTRO AMERICA");
	}else{
		strcpy(pArrayConfederacion->region,"OCEANIA");
	}
}

void asignarAnioCreacionHardcodeado(eConfederacion* pArrayConfederacion, int id){
	if(id==100){
		pArrayConfederacion->anioCreacion=1916;
	}else if(id==101){
		pArrayConfederacion->anioCreacion=1954;
	}else if(id==102){
		pArrayConfederacion->anioCreacion=1954;
	}else if(id==103){
		pArrayConfederacion->anioCreacion=1957;
	}else if(id==104){
		pArrayConfederacion->anioCreacion=1961;
	}else{
		pArrayConfederacion->anioCreacion=1966;
	}
}

int buscarNombreConfederacionPorId(eConfederacion aConfederacion[], int longitud_aConfederacion, int id, char nombre[]){
	int retorno;

	retorno=-1;

	for(int i=0;i<longitud_aConfederacion;i++){
		if(aConfederacion[i].id==id){
			strcpy(nombre,aConfederacion[i].nombre);
			retorno=0;
		}
	}

	return retorno;
}
