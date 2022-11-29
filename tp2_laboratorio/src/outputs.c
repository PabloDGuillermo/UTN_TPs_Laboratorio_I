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
#include "informes.h"
#include "outputs.h"

#define VACIO 0
#define LLENO 1

int mostrarDatosIngresadosJugador(eJugador aJugador[], int longitud_aJugador,
		eConfederacion aConfederacion[], int longitud_aConfederacion) {
	int retorno;
	char bufferNombre[50];

	retorno = -1;

	if (aJugador != NULL && longitud_aJugador > 0) {
		printf(
				"==========================================================================================================\n");
		printf("| %-2s | %-20s | %-15s | %s | %-12s | %s | %s |\n", "ID",
				"NOMBRE", "POSICION", "N° CAMISETA", "SUELDO", "CONFEDERACION",
				"AÑOS de CONTRATO");
		printf(
				"----------------------------------------------------------------------------------------------------------\n");
		for (int i = 0; i < longitud_aJugador; i++) {
			if (aJugador[i].isEmpty == LLENO) {
				buscarNombreConfederacionPorId(aConfederacion,
						longitud_aConfederacion, aJugador[i].idConfederacion,
						bufferNombre);
				printf(
						"| %-2d | %-20s | %-15s | %-11d | %-12.2f | %-13s | %-16d |\n",
						aJugador[i].id, aJugador[i].nombre,
						aJugador[i].posicion, aJugador[i].numeroCamiseta,
						aJugador[i].salario, bufferNombre,
						aJugador[i].aniosContrato);
			}
		}
		printf(
				"==========================================================================================================\n");
		retorno = 0;
	}

	return retorno;
}

int mostrarDatosIngresadosConfederacion(eConfederacion aConfederacion[],
		int longitud_aConfederacion) {
	int retorno;

	retorno = -1;

	if (aConfederacion != NULL && longitud_aConfederacion > 0) {
		printf(
				"=================================================================\n");
		printf("| %-5s | %-10s | %-25s | %s |\n", "ID", "NOMBRE", "REGION",
				"AÑO de CREACION");
		printf(
				"-----------------------------------------------------------------\n");
		for (int i = 0; i < longitud_aConfederacion; i++) {
			if (aConfederacion[i].isEmpty == LLENO) {
				printf("| %-5d | %-10s | %-25s | %-11d |\n",
						aConfederacion[i].id, aConfederacion[i].nombre,
						aConfederacion[i].region,
						aConfederacion[i].anioCreacion);
			}
		}
		printf(
				"=================================================================\n");
	}

	return retorno;
}

int listadoConfederacionesConSusJugadores(eJugador aJugador[],
		int longitud_aJugador, eConfederacion aConfederacion[],
		int longitud_aConfederacion) {
	int retorno;

	retorno = -1;

	if (aJugador != NULL && longitud_aJugador > 0 && aConfederacion != NULL
			&& longitud_aConfederacion > 0) {
		for (int i = 0; i < longitud_aConfederacion; i++) {
			printf("\n=========================================\n");
			printf("|-----JUGADORES DE LA %s-----|\n",
					aConfederacion[i].nombre);
			printf("-----------------------------------------\n");
			for (int j = 0; j < longitud_aJugador; j++) {
				if (aJugador[j].idConfederacion
						== aConfederacion[i].id&& aJugador[j].isEmpty==LLENO) {
					printf("| %s |", aJugador[j].nombre);
				}
			}
		}
		retorno = 0;
	}

	return retorno;
}

int mostrarTotalYPromedioSalarios(eJugador aJugador[], int longitud_aJugador) {
	int retorno;
	float total;
	float promedio;
	int contadorJugadoresArribaPromedio;

	total = 0;
	contadorJugadoresArribaPromedio = 0;

	retorno = -1;

	if (aJugador != NULL && longitud_aJugador > 0) {
		if (calcularTotalSalarios(aJugador, longitud_aJugador, &total) == 0
				&& calcularPromedioSalarios(aJugador, longitud_aJugador, total,
						&promedio) == 0
				&& contarJugadoresArribaPromedio(aJugador, longitud_aJugador,
						promedio, &contadorJugadoresArribaPromedio) == 0) {

			printf("\nTotal de todos los salarios: %.2f", total);
			printf("\nPromedio de los salarios: %.2f", promedio);
			if (contadorJugadoresArribaPromedio > 0) {
				printf(
						"\nCantidad de jugadores arriba del promedio salarial: %d",
						contadorJugadoresArribaPromedio);
			} else {
				printf("\nNo hay jugadores arriba del promedio salarial");
			}
			retorno = 0;
		}
	}

	return retorno;
}

int mostrarPorcentajeJugadoresPorConfederacion(eJugador aJugador[],
		int longitud_aJugador) {
	int retorno;
	float porcentajeCONMEBOL;
	float porcentajeUEFA;
	float porcentajeAFC;
	float porcentajeCAF;
	float porcentajeCONCACAF;
	float porcentajeOFC;

	retorno = -1;

	if (aJugador != NULL && longitud_aJugador > 0) {
		if (porcentajeJugadoresPorConfederacion(aJugador, longitud_aJugador,
				&porcentajeCONMEBOL, &porcentajeUEFA, &porcentajeAFC,
				&porcentajeCAF, &porcentajeCONCACAF, &porcentajeOFC) == 0) {
			printf("\n===================================================");
			printf("\n-----PORCENTAJE DE JUGADORES POR CONFEDERACION-----");
			printf("\n===================================================");
			printf("\n\t- CONMEBOL: %.2f", porcentajeCONMEBOL);
			printf("\n\t- UEFA: %.2f", porcentajeUEFA);
			printf("\n\t- AFC: %.2f", porcentajeAFC);
			printf("\n\t- CAF: %.2f", porcentajeCAF);
			printf("\n\t- CONCACAF: %.2f", porcentajeCONCACAF);
			printf("\n\t- OFC: %.2f", porcentajeOFC);
			printf("\n----------------------------------------------------\n");
			retorno = 0;
		}
	}

	return retorno;
}

int mostrarRegionConMasJugadores(eJugador aJugador[], int longitud_aJugador,
		eConfederacion aConfederacion[], int longitud_aConfederacion) {
	int retorno;
	int contadorCONMEBOL = 0;
	int contadorUEFA = 0;
	int contadorAFC = 0;
	int contadorCAF = 0;
	int contadorCONCACAF = 0;
	int contadorOFC = 0;

	retorno = -1;

	if (aJugador != NULL && longitud_aJugador > 0 && aConfederacion != NULL
			&& longitud_aConfederacion > 0) {
		if (cantidadJugadoresPorConfederacion(aJugador, longitud_aJugador,
				&contadorCONMEBOL, &contadorUEFA, &contadorAFC, &contadorCAF,
				&contadorCONCACAF, &contadorOFC) == 0) {
			if (contadorCONMEBOL > contadorUEFA
					&& contadorCONMEBOL > contadorAFC
					&& contadorCONMEBOL > contadorCAF
					&& contadorCONMEBOL > contadorCONCACAF
					&& contadorCONMEBOL > contadorOFC) {
				printf("\nLa region con mas jugadores es %s:\n",
						aConfederacion[0].region);
				mostrarJugadoresPorRegion(aJugador, longitud_aJugador, 100);
			} else if (contadorUEFA > contadorCONMEBOL
					&& contadorUEFA > contadorAFC && contadorUEFA > contadorCAF
					&& contadorUEFA > contadorCONCACAF
					&& contadorUEFA > contadorOFC) {
				printf("\nLa region con mas jugadores es %s:\n",
						aConfederacion[1].region);
				mostrarJugadoresPorRegion(aJugador, longitud_aJugador, 101);
			} else if (contadorAFC > contadorCONMEBOL
					&& contadorAFC > contadorUEFA && contadorAFC > contadorCAF
					&& contadorAFC > contadorCONCACAF
					&& contadorAFC > contadorOFC) {
				printf("\nLa region con mas jugadores es %s:\n",
						aConfederacion[2].region);
				mostrarJugadoresPorRegion(aJugador, longitud_aJugador, 102);
			} else if (contadorCAF > contadorCONMEBOL
					&& contadorCAF > contadorUEFA && contadorCAF > contadorAFC
					&& contadorCAF > contadorCONCACAF
					&& contadorCAF > contadorOFC) {
				printf("\nLa region con mas jugadores es %s:\n",
						aConfederacion[3].region);
				mostrarJugadoresPorRegion(aJugador, longitud_aJugador, 103);
			} else if (contadorCONCACAF > contadorCONMEBOL
					&& contadorCONCACAF > contadorUEFA
					&& contadorCONCACAF > contadorAFC
					&& contadorCONCACAF > contadorCAF
					&& contadorCONCACAF > contadorOFC) {
				printf("\nLa region con mas jugadores es %s:\n",
						aConfederacion[4].region);
				mostrarJugadoresPorRegion(aJugador, longitud_aJugador, 104);
			} else if (contadorOFC > contadorCONMEBOL
					&& contadorOFC > contadorUEFA && contadorOFC > contadorAFC
					&& contadorOFC > contadorCAF
					&& contadorOFC > contadorCONCACAF) {
				printf("\nLa region con mas jugadores es %s:\n",
						aConfederacion[5].region);
				mostrarJugadoresPorRegion(aJugador, longitud_aJugador, 105);
			}
			retorno = 0;
		}
	}

	return retorno;
}

int mostrarJugadoresPorRegion(eJugador aJugador[], int longitud_aJugador,
		int idConfederacion) {
	int retorno;

	retorno = -1;

	if (aJugador != NULL && longitud_aJugador > 0) {

		for (int i = 0; i < longitud_aJugador; i++) {
			if (aJugador[i].idConfederacion
					== idConfederacion&& aJugador[i].isEmpty==LLENO) {
				printf("\n- %s", aJugador[i].nombre);
			}
		}

		retorno = 0;
	}

	return retorno;
}

int mostrarConfederacionConMasAniosContrato(eJugador aJugador[],
		int longitud_aJugador, eConfederacion aConfederacion[],
		int longitud_aConfederacion) {
	int retorno;
	int idConfederacion;

	retorno = -1;

	if (aJugador != NULL && longitud_aJugador > 0 && aConfederacion != NULL
			&& longitud_aConfederacion > 0) {
		if (confederacionMasAniosContrato(aJugador, longitud_aJugador,
				aConfederacion, longitud_aConfederacion, &idConfederacion)
				== 0) {

			for (int i = 0; i < longitud_aConfederacion; i++) {
				if (idConfederacion == aConfederacion[i].id) {
					printf(
							"\nLa confederacion con mas años de contrato es: %s\n",
							aConfederacion[i].nombre);
				}
			}
			retorno = 0;
		}
	}

	return retorno;
}
