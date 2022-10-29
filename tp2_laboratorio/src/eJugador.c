/*
 * eJugador.c
 *
 *  Created on: 26 oct. 2022
 *      Author: pablo
 */

#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
#include "eJugador.h"
#include <string.h>
#include "outputs.h"
#include "eConfederacion.h"

#define VACIO 0
#define LLENO 1

int inicializarArrayJugador(eJugador aJugador[], int longitud_aJugador){
	int retorno;

	retorno=-1;

	if(aJugador!=NULL && longitud_aJugador>0){
		for(int i=0;i<longitud_aJugador;i++){
			aJugador[i].isEmpty=VACIO;
		}
		retorno=0;
	}

	return retorno;
}

int buscarIndiceVacioJugador(eJugador aJugador[], int longitud_aJugador){
	int indice;

	for(int i=0;i<longitud_aJugador;i++){
		if(aJugador[i].isEmpty==VACIO){
			indice=i;
			break;
		}
	}

	return indice;
}

int asignarIdJugador(eJugador aJugador[], int longitud_aJugador){
	static int id = -1;

	if(aJugador!=NULL && longitud_aJugador>0){
		id++;
	}

	return id;
}

int pedirNombreJugador(eJugador* pArrayJugador, int longitud_aJugador){
	int retorno;
	char bufferNombre[50];
	int errorInput;

	retorno=-1;

	if(pArrayJugador!=NULL && longitud_aJugador>0){
		errorInput=utn_pedirTexto(bufferNombre, "Ingrese el nombre del jugador (max 50 caracteres): ", "ERROR. Nombre invalido. Intente nuevamente.",50,3);
		if(errorInput==0){
			strcpy(pArrayJugador->nombre,bufferNombre);
			retorno=0;
		}else{
			printf("\nSIN REINTENTOS\nVOLVIENDO AL MENU PRINCIPAL...");
		}
	}

	return retorno;
}

int pedirPosicionJugador(eJugador* pArrayJugador, int longitud_aJugador){
	int retorno;
	int errorInput;
	int posicionElegida;

	retorno=-1;

	if(pArrayJugador!=NULL && longitud_aJugador>0){
		errorInput=utn_pedirNumero(&posicionElegida, "1 - ARQUERO\n"
				"2 - DEFENSOR\n"
				"3 - MEDIOCAMPISTA\n"
				"4 - DELANTERO\n"
				"¿EN QUE POSICION JUEGA?: ", "ERROR. Posicion invalida. Intente nuevamente.",1,4,3);

		if(errorInput==0 && asignarPosicionJugador(pArrayJugador,posicionElegida) == 0){
			retorno=0;
		}else{
			printf("\nSIN REINTENTOS\nVOLVIENDO AL MENU PRINCIPAL...");
		}
	}

	return retorno;
}

int asignarPosicionJugador(eJugador* pArrayJugador, int opcionElegida){
	int retorno;

	retorno=-1;

	if(opcionElegida>=1 && opcionElegida<=4){
		switch(opcionElegida){
		case 1:
			strcpy(pArrayJugador->posicion, "Arquero");
			break;

		case 2:
			strcpy(pArrayJugador->posicion, "Defensor");
			break;

		case 3:
			strcpy(pArrayJugador->posicion, "Mediocampista");
			break;

		case 4:
			strcpy(pArrayJugador->posicion, "Delantero");
			break;
		}
		retorno=0;
	}

	return retorno;
}

int pedirNumeroCamisetaJugador(eJugador* pArrayJugador, int longitud_aJugador){
	int retorno;
	int errorInput;
	int bufferNumeroCamiseta;

	retorno=-1;

	if(pArrayJugador!=NULL && longitud_aJugador>0){
		errorInput=utn_pedirNumero(&bufferNumeroCamiseta, "Ingrese el numero de camiseta (de 1 a 99): ", "ERROR. Numero de camiseta invalido",1,99,3);

		if(errorInput==0){
			pArrayJugador->numeroCamiseta=bufferNumeroCamiseta;
			retorno=0;
		}else{
			printf("\nSIN REINTENTOS\nVOLVIENDO AL MENU PRINCIPAL...");
		}
	}

	return retorno;
}

int pedirIdConfederacionJugador(eJugador* pArrayJugador, int longitud_aJugador, eConfederacion aConfederacion[], int longitud_aConfederacion){
	int retorno;
	int errorInput;
	int bufferIdConfederacion;

	retorno=-1;

	if(pArrayJugador!=NULL && longitud_aJugador>0){
		mostrarDatosIngresadosConfederacion(aConfederacion, longitud_aConfederacion);
		errorInput=utn_pedirNumero(&bufferIdConfederacion, "Ingrese el ID de la confederacion: ", "ERROR. ID de la confederacion invalido",100,106,3);
		if(errorInput==0){
			pArrayJugador->idConfederacion=bufferIdConfederacion;
			retorno=0;
		}else{
			printf("\nSIN REINTENTOS\nVOLVIENDO AL MENU PRINCIPAL...");
		}
	}

		return retorno;
}

int pedirSalarioJugador(eJugador* pArrayJugador, int longitud_aJugador){
	int retorno;
	int errorInput;
	float bufferSalario;

	retorno=-1;

	if(pArrayJugador!=NULL && longitud_aJugador>0){
		errorInput=utn_pedirNumeroFlotante(&bufferSalario, "Ingrese el sueldo del jugador (entre 0 y 1000000): ", "ERROR. Sueldo invalido",0,1000000,3);

		if(errorInput==0){
			pArrayJugador->salario=bufferSalario;
			retorno=0;
		}else{
			printf("\nSIN REINTENTOS\nVOLVIENDO AL MENU PRINCIPAL...");
		}
	}

	return retorno;
}

int pedirAniosDeContratoJugador(eJugador* pArrayJugador, int longitud_aJugador){
	int retorno;
	int errorInput;
	int bufferAniosDeContrato;

	retorno=-1;

	if(pArrayJugador!=NULL && longitud_aJugador>0){
		errorInput=utn_pedirNumero(&bufferAniosDeContrato, "Ingrese los años de contrato (de 0 a 5): ", "ERROR. Años de contrato invalidos",0,5,3);

		if(errorInput==0){
			pArrayJugador->aniosContrato=bufferAniosDeContrato;
			retorno=0;
		}else{
			printf("\nSIN REINTENTOS\nVOLVIENDO AL MENU PRINCIPAL...");
		}
	}

	return retorno;
}

int altaJugador(eJugador aJugador[], int longitud_aJugador, eConfederacion aConfederacion[], int longitud_aConfederaicon){
	int retorno;
	eJugador bufferJugador;
	int indice;
	int errorInput;
	eJugador* pBufferJugador;

	pBufferJugador=&bufferJugador;

	retorno=-1;

	if(aJugador!=NULL && longitud_aJugador>0){
		indice=buscarIndiceVacioJugador(aJugador, longitud_aJugador);
		if(indice>=0){
			bufferJugador.id=asignarIdJugador(aJugador, longitud_aJugador);
			errorInput=pedirNombreJugador(pBufferJugador,longitud_aJugador);
			if(errorInput==0){
				errorInput=pedirPosicionJugador(pBufferJugador,longitud_aJugador);
				if(errorInput==0){
					errorInput=pedirNumeroCamisetaJugador(pBufferJugador,longitud_aJugador);
					if(errorInput==0){
						errorInput=pedirIdConfederacionJugador(pBufferJugador,longitud_aJugador,aConfederacion,longitud_aConfederaicon);
							errorInput=pedirSalarioJugador(pBufferJugador,longitud_aJugador);
							if(errorInput==0){
								errorInput=pedirAniosDeContratoJugador(pBufferJugador,longitud_aJugador);
							}
					}
				}
			}
		}
		if(errorInput==0){
			aJugador[indice].id=bufferJugador.id;
			strcpy(aJugador[indice].nombre,bufferJugador.nombre);
			strcpy(aJugador[indice].posicion,bufferJugador.posicion);
			aJugador[indice].numeroCamiseta=bufferJugador.numeroCamiseta;
			aJugador[indice].idConfederacion=bufferJugador.idConfederacion;
			aJugador[indice].salario=bufferJugador.salario;
			aJugador[indice].aniosContrato=bufferJugador.aniosContrato;
			aJugador[indice].isEmpty=LLENO;
			retorno=0;
		}
	}

	return retorno;
}

int darBajaJugador(eJugador aJugador[], int longitud_aJugador, int idElegido){
	int retorno;

	retorno=-1;

	if(aJugador!=NULL && longitud_aJugador>0 && idElegido >= 0){
		for(int i=0;i<longitud_aJugador;i++){
			if(aJugador[i].id==idElegido && aJugador[i].isEmpty==LLENO){
				aJugador[i].isEmpty=VACIO;
				retorno=0;
			}
		}
	}

	return retorno;
}

int menuDarBajaJugador(eJugador aJugador[], int longitud_aJugador, eConfederacion aConfederacion[], int longitud_aConfederacion){
	int retorno;
	int idElegido;
	int errorInput;

	retorno=-1;

	if(aJugador!=NULL && longitud_aJugador>0){
		mostrarDatosIngresadosJugador(aJugador, longitud_aJugador,aConfederacion,longitud_aConfederacion);
		errorInput=utn_pedirNumero(&idElegido, "Elija el ID del jugador a dar de baja: ", "ERROR. ID invalido.",0,3000,3);
		if(errorInput==0){
			errorInput=darBajaJugador(aJugador,longitud_aJugador,idElegido);
			if(errorInput==0){
				printf("El jugador fue dado de baja exitosamente");
				retorno=0;
			}else{
				printf("\nEl jugador con ese ID no existe\nVOLVIENDO AL MENU PRINCIPAL...");
			}
		}else{
			printf("\nSIN REINTENTOS\nVOLVIENDO AL MENU PRINCIPAL...");
		}
	}

	return retorno;
}

int ordenarPorIdJugador(eJugador aJugador[], int longitud_aJugador){
	int retorno;
	int ordenado;
	eJugador bufferJugador;

	retorno=-1;
	ordenado=-1;
	if(aJugador!=NULL && longitud_aJugador>0){
		while(ordenado!=0){
			ordenado=0;
			for(int i=0; i<longitud_aJugador;i++){
				if(aJugador[i].id>aJugador[i+1].id){
					bufferJugador=aJugador[i];
					aJugador[i]=aJugador[i+1];
					aJugador[i+1]=bufferJugador;
					ordenado=-1;
				}
			}
		}
		retorno=0;
	}

	return retorno;
}

int menuModificarJugador(eJugador aJugador[], int longitud_aJugador, eConfederacion aConfederacion[], int longitud_aConfederacion){
	int retorno;
	int idElegido;
	int errorInput;
	eJugador* pArrayJugador;

	retorno=-1;
	pArrayJugador=aJugador;

	mostrarDatosIngresadosJugador(aJugador,longitud_aJugador,aConfederacion,longitud_aConfederacion);
	errorInput=utn_pedirNumero(&idElegido, "Elija el ID del jugador que quiere modificar: ", "ERROR. ID invalido",0,3000,3);
	if(errorInput==0){
		modificarJugador(pArrayJugador,longitud_aJugador,aConfederacion, longitud_aConfederacion, idElegido);
		retorno=0;
	}else{
		printf("\nSIN REINTENTOS\nVOLVIENDO AL MENU PRINCIPAL...");
	}

	return retorno;
}

int modificarJugador(eJugador aJugador[], int longitud_aJugador, eConfederacion aConfederacion[], int longitud_aConfederacion, int id){
	int retorno;
	int errorInput;
	int opcionElegida;
	eJugador bufferJugador;
	eJugador* pBufferJugador;

	pBufferJugador=&bufferJugador;

	retorno=-1;

	errorInput=utn_pedirNumero(&opcionElegida, "1 - Modificar nombre\n"
			"2 - Modificar posicion\n"
			"3 - Modificar numero de camiseta\n"
			"4 - Modificar confederacion"
			"5 - Modificar salario\n"
			"6 - Modificar años de contrato\n"
			"7 - Volver\n"
			"¿Que desea modificar?: ", "ERROR. Opcion invalida.",1,7,3);
	if(errorInput==0){
		switch(opcionElegida){
		case 1:
			errorInput=pedirNombreJugador(pBufferJugador, longitud_aJugador);
			if(errorInput==0){
				strcpy(aJugador[id].nombre,bufferJugador.nombre);
				retorno=0;
			}
			break;

		case 2:
			errorInput=pedirPosicionJugador(pBufferJugador, longitud_aJugador);
			if(errorInput==0){
				strcpy(aJugador[id].posicion,bufferJugador.posicion);
				retorno=0;
			}
			break;

		case 3:
			errorInput=pedirNumeroCamisetaJugador(pBufferJugador, longitud_aJugador);
			if(errorInput==0){
				aJugador[id].numeroCamiseta=bufferJugador.numeroCamiseta;
				retorno=0;
			}
			break;

		case 4:
			errorInput=pedirIdConfederacionJugador(pBufferJugador, longitud_aJugador, aConfederacion, longitud_aConfederacion);
			if(errorInput==0){
				aJugador[id].idConfederacion=bufferJugador.idConfederacion;
				retorno=0;
			}
			break;

		case 5:
			errorInput=pedirSalarioJugador(pBufferJugador, longitud_aJugador);
			if(errorInput==0){
				aJugador[id].salario=bufferJugador.salario;
				retorno=0;
			}
			break;

		case 6:
			errorInput=pedirAniosDeContratoJugador(pBufferJugador, longitud_aJugador);
			if(errorInput==0){
				aJugador[id].aniosContrato=bufferJugador.aniosContrato;
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

