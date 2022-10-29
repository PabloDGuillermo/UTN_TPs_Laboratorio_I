/*
 * informes.c
 *
 *  Created on: 29 oct. 2022
 *      Author: pablo
 */


#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
#include "eJugador.h"
#include <string.h>
#include "outputs.h"
#include "eConfederacion.h"
#include "informes.h"

#define VACIO 0
#define LLENO 1

int ordenarPorNombreConfederacionYJugador(eJugador aJugador[], int longitud_aJugador, eConfederacion aConfederacion[], int longitud_aConfederacion){
	int retorno;
	eJugador auxJugador;

	retorno=-1;

	if(aJugador!=NULL && longitud_aJugador>0 && aConfederacion!=NULL && longitud_aConfederacion>0){
		for(int i=0;i<longitud_aJugador;i++){
			if(strcmp(aConfederacion[i].nombre,aConfederacion[i+1].nombre)<=0){
				if(strcmp(aJugador[i].nombre,aJugador[i+1].nombre)<=0){
					auxJugador=aJugador[i];
					aJugador[i]=aJugador[i+1];
					aJugador[i+1]=auxJugador;
				}
			}
		}
		mostrarDatosIngresadosJugador(aJugador,longitud_aJugador,aConfederacion,longitud_aConfederacion);
		retorno=0;
	}

	return retorno;
}

int listadoConfederacionesConSusJugadores(eJugador aJugador[], int longitud_aJugador, eConfederacion aConfederacion[], int longitud_aConfederacion){
	int retorno;

	retorno=-1;

	for(int i=0;i<longitud_aConfederacion;i++){
		printf("\n=========================================\n");
		printf("|-----JUGADORES DE LA %s-----|\n",aConfederacion[i].nombre);
		printf("-----------------------------------------\n");
		for(int j=0;j<longitud_aJugador;j++){
			if(aJugador[j].idConfederacion==aConfederacion[i].id && aJugador[j].isEmpty==LLENO){
				printf("| %s |",aJugador[j].nombre);
			}
		}
	}

	return retorno;
}

int mostrarTotalYPromedioSalarios(eJugador aJugador[], int longitud_aJugador){
	int retorno;
	float total;
	float promedio;
	int contadorJugadoresArribaPromedio;
	int contadorDeJugadoresIngresados;
	int errorInputs;

	total=0;
	contadorDeJugadoresIngresados=0;
	contadorJugadoresArribaPromedio=0;

	retorno=-1;

	errorInputs=calcularTotalSalarios(aJugador,longitud_aJugador,&total,&contadorDeJugadoresIngresados);
	if(errorInputs==0){
		errorInputs=calcularPromedioSalarios(aJugador,longitud_aJugador,total,contadorDeJugadoresIngresados,&promedio);
		if(errorInputs==0){
			errorInputs=contarJugadoresArribaPromedio(aJugador,longitud_aJugador,promedio,&contadorJugadoresArribaPromedio);
		}
	}

	if(errorInputs==0){
		printf("\nTotal de todos los salarios: %.2f",total);
		printf("\nPromedio de los salarios: %.2f", promedio);
		if(contadorJugadoresArribaPromedio>0){
			printf("\nCantidad de jugadores arriba del promedio salarial: %d", contadorJugadoresArribaPromedio);
		}else{
			printf("\nNo hay jugadores arriba del promedio salarial");
		}
		retorno=0;
	}


	return retorno;
}

int calcularTotalSalarios(eJugador aJugador[], int longitud_aJugador, float* pTotal, int* contadorJugadores){
	int retorno;

	retorno=-1;

	if(aJugador!=NULL && longitud_aJugador>0 && pTotal!=NULL && contadorJugadores!=NULL){
		for(int i=0;i<=longitud_aJugador;i++){
			if(aJugador[i].isEmpty==LLENO){
				*pTotal+=aJugador[i].salario;
				contadorJugadores++;
			}
		}
		retorno=0;
	}

	return retorno;
}

int calcularPromedioSalarios(eJugador aJugador[], int longitud_aJugador, float total, int contadorJugadores, float* pPromedioSalarios){
	int retorno;

	retorno=-1;

	if(aJugador!=NULL && longitud_aJugador>0 && total>0 && contadorJugadores>0 && pPromedioSalarios!=NULL){
		*pPromedioSalarios=total/contadorJugadores;
		retorno=0;
	}

	return retorno;
}

int contarJugadoresArribaPromedio(eJugador aJugador[], int longitud_aJugador, float promedio, int* pContadorJugadoresArribaPromedio){
	int retorno;

	retorno=-1;

	if(aJugador!=NULL && longitud_aJugador>0 && promedio>0 && pContadorJugadoresArribaPromedio!=NULL){
		for(int i=0;i<=longitud_aJugador;i++){
			if(aJugador[i].isEmpty==LLENO && aJugador[i].salario>promedio){
				pContadorJugadoresArribaPromedio++;
			}
		}
		retorno=0;
	}

	return retorno;
}

int mostrarConfederacionConMasAniosContrato(eJugador aJugador[], int longitud_aJugador, eConfederacion aConfederacion[], int longitud_aConfederacion){
	int retorno;


	retorno=-1;

	if(aJugador!=NULL && longitud_aJugador>0 && aConfederacion!=NULL && longitud_aConfederacion>0){

		retorno=0;
	}

	return retorno;
}

int confederacionMasAniosContrato(eJugador aJugador[], int longitud_aJugador, eConfederacion aConfederacion[], int longitud_aConfederacion, int* idConfederacion){
	int retorno;

	retorno=-1;

	if(aJugador!=NULL && longitud_aJugador>0 && aConfederacion!=NULL && longitud_aConfederacion>0){

		retorno=0;
	}

	return retorno;
}
