/*
 * outputs.h
 *
 *  Created on: 29 oct. 2022
 *      Author: pablo
 */

#ifndef OUTPUTS_H_
#define OUTPUTS_H_

int mostrarDatosIngresadosJugador(eJugador aJugador[], int longitud_aJugador,
		eConfederacion aConfederacion[], int longitud_aConfederacion);
int mostrarDatosIngresadosConfederacion(eConfederacion aConfederacion[],
		int longitud_aConfederacion);
int listadoConfederacionesConSusJugadores(eJugador aJugador[],
		int longitud_aJugador, eConfederacion aConfederacion[],
		int longitud_aConfederacion);
int mostrarTotalYPromedioSalarios(eJugador aJugador[], int longitud_aJugador);
int mostrarPorcentajeJugadoresPorConfederacion(eJugador aJugador[],
		int longitud_aJugador);
int mostrarRegionConMasJugadores(eJugador aJugador[], int longitud_aJugador,
		eConfederacion aConfederacion[], int longitud_aConfederacion);
int mostrarJugadoresPorRegion(eJugador aJugador[], int longitud_aJugador,
		int idConfederacion);
int mostrarConfederacionConMasAniosContrato(eJugador aJugador[],
		int longitud_aJugador, eConfederacion aConfederacion[],
		int longitud_aConfederacion);

#endif /* OUTPUTS_H_ */
