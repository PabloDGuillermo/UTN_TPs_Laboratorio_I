/*
 * outputs.c
 *
 *  Created on: 29 oct. 2022
 *      Author: pablo
 */

#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
#include "eJugador.h"
#include <string.h>
#include "eConfederacion.h"

#define VACIO 0
#define LLENO 1

int mostrarDatosIngresadosJugador(eJugador aJugador[], int longitud_aJugador, eConfederacion aConfederacion[], int longitud_aConfederacion){
	int retorno;
	char bufferNombre[50];

	retorno=-1;

	if(aJugador!=NULL && longitud_aJugador>0 && (ordenarPorIdJugador(aJugador,longitud_aJugador))==0){
		printf("==========================================================================================================\n");
		printf("| %-2s | %-20s | %-10s | %s | %-12s | %s | %s |\n", "ID", "NOMBRE", "POSICION", "N° CAMISETA", "SUELDO", "CONFEDERACION", "AÑOS de CONTRATO");
		printf("----------------------------------------------------------------------------------------------------------\n");
		for(int i =0;i<longitud_aJugador;i++){
			if(aJugador[i].isEmpty==LLENO){
				buscarNombreConfederacionPorId(aConfederacion, longitud_aConfederacion,aJugador[i].idConfederacion,bufferNombre);
				printf("| %-2d | %-20s | %-10s | %-11d | %-12.2f | %-13s | %-16d |\n", aJugador[i].id,aJugador[i].nombre,aJugador[i].posicion, aJugador[i].numeroCamiseta,aJugador[i].salario, bufferNombre, aJugador[i].aniosContrato);
			}
		}
		printf("==========================================================================================================\n");
	}

	return retorno;
}

int mostrarDatosIngresadosConfederacion(eConfederacion aConfederacion[], int longitud_aConfederacion){
	int retorno;

	retorno=-1;

	if(aConfederacion!=NULL && longitud_aConfederacion>0){
		printf("=================================================================\n");
		printf("| %-5s | %-10s | %-25s | %s |\n", "ID", "NOMBRE", "REGION", "AÑO de CREACION");
		printf("-----------------------------------------------------------------\n");
		for(int i =0;i<longitud_aConfederacion;i++){
			if(aConfederacion[i].isEmpty==LLENO){
				printf("| %-5d | %-10s | %-25s | %-11d |\n", aConfederacion[i].id,aConfederacion[i].nombre,aConfederacion[i].region, aConfederacion[i].anioCreacion);
			}
		}
		printf("=================================================================\n");
	}

	return retorno;
}
