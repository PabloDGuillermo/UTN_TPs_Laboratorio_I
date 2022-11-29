/*
 * informes.h
 *
 *  Created on: 29 oct. 2022
 *      Author: pablo
 */

#ifndef INFORMES_H_
#define INFORMES_H_

int ordenarPorNombreConfederacionYJugador(eJugador aJugador[],
		int longitud_aJugador, eConfederacion aConfederacion[],
		int longitud_aConfederacion);
int calcularTotalSalarios(eJugador aJugador[], int longitud_aJugador,
		float *pTotal);
int calcularPromedioSalarios(eJugador aJugador[], int longitud_aJugador,
		float total, float *pPromedioSalarios);
int contarJugadoresArribaPromedio(eJugador aJugador[], int longitud_aJugador,
		float promedio, int *pContadorJugadoresArribaPromedio);
int confederacionMasAniosContrato(eJugador aJugador[], int longitud_aJugador,
		eConfederacion aConfederacion[], int longitud_aConfederacion,
		int *idConfederacion);
int porcentajeJugadoresPorConfederacion(eJugador aJugador[],
		int longitud_aJugador, float *porcentajeCONMEBOL, float *porcentajeUEFA,
		float *porcentajeAFC, float *porcentajeCAF, float *porcentajeCONCACAF,
		float *porcentajeOFC);
int cantidadJugadoresPorConfederacion(eJugador aJugador[],
		int longitud_aJugador, int *contadorCONMEBOL, int *contadorUEFA,
		int *contadorAFC, int *contadorCAF, int *contadorCONCACAF,
		int *contadorOFC);

#endif /* INFORMES_H_ */
