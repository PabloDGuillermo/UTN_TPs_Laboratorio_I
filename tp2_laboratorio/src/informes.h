/*
 * informes.h
 *
 *  Created on: 29 oct. 2022
 *      Author: pablo
 */

#ifndef INFORMES_H_
#define INFORMES_H_

int ordenarPorNombreConfederacionYJugador(eJugador aJugador[], int longitud_aJugador, eConfederacion aConfederacion[], int longitud_aConfederacion);
int listadoConfederacionesConSusJugadores(eJugador aJugador[], int longitud_aJugador, eConfederacion aConfederacion[], int longitud_aConfederacion);
int mostrarTotalYPromedioSalarios(eJugador aJugador[], int longitud_aJugador);
int calcularTotalSalarios(eJugador aJugador[], int longitud_aJugador, float* pTotal, int* contadorJugadores);
int calcularPromedioSalarios(eJugador aJugador[], int longitud_aJugador, float total, int contadorJugadores, float* pPromedioSalarios);
int contarJugadoresArribaPromedio(eJugador aJugador[], int longitud_aJugador, float promedio, int* pContadorJugadoresArribaPromedio);

#endif /* INFORMES_H_ */
