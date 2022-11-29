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

int ordenarPorNombreConfederacionYJugador(eJugador aJugador[],
		int longitud_aJugador, eConfederacion aConfederacion[],
		int longitud_aConfederacion) {
	int retorno;
	eJugador auxJugador;
	char nombreUno[50];
	char nombreDos[50];
	int ordenado;

	retorno = -1;
	ordenado = -1;

	if (aJugador != NULL && longitud_aJugador > 0 && aConfederacion != NULL
			&& longitud_aConfederacion > 0) {
		while (ordenado != 0) {
			ordenado = 0;
			for (int i = 0; i < longitud_aJugador; i++) {
				if (buscarNombreConfederacionPorId(aConfederacion,
						longitud_aConfederacion, aJugador[i].idConfederacion,
						nombreUno) == 0
						&& buscarNombreConfederacionPorId(aConfederacion,
								longitud_aConfederacion,
								aJugador[i + 1].idConfederacion, nombreDos)
								== 0) {
					if (strcmp(nombreUno, nombreDos) > 0) {
						auxJugador = aJugador[i];
						aJugador[i] = aJugador[i + 1];
						aJugador[i + 1] = auxJugador;
						ordenado = -1;
					} else if (strcmp(nombreUno, nombreDos) == 0) {
						if (strcmp(aJugador[i].nombre, aJugador[i + 1].nombre)
								> 0) {
							auxJugador = aJugador[i];
							aJugador[i] = aJugador[i + 1];
							aJugador[i + 1] = auxJugador;
							ordenado = -1;

						}
					}
				}
			}
		}
		mostrarDatosIngresadosJugador(aJugador, longitud_aJugador,
				aConfederacion, longitud_aConfederacion);
		retorno = 0;
	}

	return retorno;
}

int calcularTotalSalarios(eJugador aJugador[], int longitud_aJugador,
		float *pTotal) {
	int retorno;

	retorno = -1;

	if (aJugador != NULL && longitud_aJugador > 0 && pTotal != NULL) {
		for (int i = 0; i <= longitud_aJugador; i++) {
			if (aJugador[i].isEmpty == LLENO) {
				*pTotal += aJugador[i].salario;
				retorno = 0;
			}
		}
	}

	return retorno;
}

int calcularPromedioSalarios(eJugador aJugador[], int longitud_aJugador,
		float total, float *pPromedioSalarios) {
	int retorno;

	retorno = -1;

	if (aJugador != NULL
			&& longitud_aJugador > 0&& total>0 && pPromedioSalarios!=NULL) {
		*pPromedioSalarios = total
				/ contadorJugadoresIngresados(aJugador, longitud_aJugador);
		retorno = 0;
	}

	return retorno;
}

int contarJugadoresArribaPromedio(eJugador aJugador[], int longitud_aJugador,
		float promedio, int *pContadorJugadoresArribaPromedio) {
	int retorno;

	retorno = -1;

	if (aJugador != NULL
			&& longitud_aJugador
					> 0&& promedio > 0 && pContadorJugadoresArribaPromedio!=NULL) {
		for (int i = 0; i <= longitud_aJugador; i++) {
			if (aJugador[i].isEmpty == LLENO
					&& aJugador[i].salario > promedio) {
				*pContadorJugadoresArribaPromedio += 1;
			}
		}
		retorno = 0;
	}

	return retorno;
}

int confederacionMasAniosContrato(eJugador aJugador[], int longitud_aJugador,
		eConfederacion aConfederacion[], int longitud_aConfederacion,
		int *idConfederacion) {

	int retorno;
	int contadorConfederacion[6] = { 0, 0, 0, 0, 0, 0 };
	int max;

	retorno = -1;
	max = 0;
	if (aJugador != NULL && longitud_aJugador > 0&& aConfederacion != NULL
	&& longitud_aConfederacion > 0 && idConfederacion!=NULL) {
		for (int i = 0; i < longitud_aConfederacion; i++) {
			for (int j = 0; j < longitud_aJugador; i++) {
				if (aJugador[i].isEmpty==LLENO && aJugador[i].idConfederacion == aConfederacion[j].id) {
					contadorConfederacion[j] += aJugador[i].aniosContrato;
				}
			}
		}
		for (int i = 0; i < longitud_aConfederacion; i++) {
			if (contadorConfederacion[i] > max) {
				max = contadorConfederacion[i];
				*idConfederacion = aConfederacion[i].id;
			}
		}
		retorno = 0;
	}

	return retorno;
}

int porcentajeJugadoresPorConfederacion(eJugador aJugador[],
		int longitud_aJugador, float *porcentajeCONMEBOL, float *porcentajeUEFA,
		float *porcentajeAFC, float *porcentajeCAF, float *porcentajeCONCACAF,
		float *porcentajeOFC) {
	int retorno;
	int contadorCONMEBOL = 0;
	int contadorUEFA = 0;
	int contadorAFC = 0;
	int contadorCAF = 0;
	int contadorCONCACAF = 0;
	int contadorOFC = 0;
	int cantidadJugadores = contadorJugadoresIngresados(aJugador,
			longitud_aJugador);

	retorno = -1;

	if (aJugador != NULL && longitud_aJugador > 0) {
		for (int i = 0; i < longitud_aJugador; i++) {
			switch (aJugador[i].idConfederacion) {
			case 100:
				contadorCONMEBOL++;
				break;

			case 101:
				contadorUEFA++;
				break;

			case 102:
				contadorAFC++;
				break;

			case 103:
				contadorCAF++;
				break;

			case 104:
				contadorCONCACAF++;
				break;

			case 105:
				contadorOFC++;
				break;
			}
		}
		*porcentajeCONMEBOL = contadorCONMEBOL * 100 / cantidadJugadores;
		*porcentajeUEFA = contadorUEFA * 100 / cantidadJugadores;
		*porcentajeAFC = contadorAFC * 100 / cantidadJugadores;
		*porcentajeCAF = contadorCAF * 100 / cantidadJugadores;
		*porcentajeCONCACAF = contadorCONCACAF * 100 / cantidadJugadores;
		*porcentajeOFC = contadorOFC * 100 / cantidadJugadores;
		retorno = 0;
	}

	return retorno;
}

int cantidadJugadoresPorConfederacion(eJugador aJugador[],
		int longitud_aJugador, int *contadorCONMEBOL, int *contadorUEFA,
		int *contadorAFC, int *contadorCAF, int *contadorCONCACAF,
		int *contadorOFC) {

	int retorno;

	retorno = -1;

	if (aJugador != NULL && longitud_aJugador > 0) {
		for (int i = 0; i < longitud_aJugador; i++) {
			switch (aJugador[i].idConfederacion) {
			case 100:
				*contadorCONMEBOL += 1;
				break;

			case 101:
				*contadorUEFA += 1;
				break;

			case 102:
				*contadorAFC += 1;
				break;

			case 103:
				*contadorCAF += 1;
				break;

			case 104:
				*contadorCONCACAF += 1;
				break;

			case 105:
				*contadorOFC += 1;
				break;
			}
		}
		retorno = 0;
	}

	return retorno;
}
