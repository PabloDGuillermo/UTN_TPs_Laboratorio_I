/*
 * eJugador.h
 *
 *  Created on: 26 oct. 2022
 *      Author: pablo
 */
#include "eConfederacion.h"

#ifndef EJUGADOR_H_
#define EJUGADOR_H_

typedef struct {
	int id;
	char nombre[50];
	char posicion[50];
	short numeroCamiseta;
	int idConfederacion;
	float salario;
	short aniosContrato;
	short isEmpty;
} eJugador;

int inicializarArrayJugador(eJugador aJugador[], int longitud_aJugador);
int hayJugadores(eJugador aJugador[], int longitud_aJugador);
int buscarIndiceVacioJugador(eJugador aJugador[], int longitud_aJugador);
int asignarIdJugador(eJugador aJugador[], int longitud_aJugador);
int buscarJugadorPorId(eJugador aJugador[], int longitud_aJugador, int id,
		int *index);
int pedirNombreJugador(eJugador *unJugador);
int pedirPosicionJugador(eJugador *unJugador);
int asignarPosicionJugador(eJugador *unJugador, int opcionElegida);
int pedirNumeroCamisetaJugador(eJugador *unJugador);
int pedirIdConfederacionJugador(eJugador *unJugador,
		eConfederacion aConfederacion[], int longitud_aConfederacion);
int pedirSalarioJugador(eJugador *unJugador);
int pedirAniosDeContratoJugador(eJugador *unJugador);
int altaJugador(eJugador aJugador[], int longitud_aJugador,
		eConfederacion aConfederacion[], int longitud_aConfederacion);
int darBajaJugador(eJugador aJugador[], int longitud_aJugador, int idElegido);
int menuDarBajaJugador(eJugador aJugador[], int longitud_aJugador,
		eConfederacion aConfederacion[], int longitud_aConfederacion);
int ordenarPorIdJugador(eJugador aJugador[], int longitud_aJugador);
int menuModificarJugador(eJugador aJugador[], int longitud_aJugador,
		eConfederacion aConfederacion[], int longitud_aConfederacion);
int modificarJugador(eJugador aJugador[], int longitud_aJugador,
		eConfederacion aConfederacion[], int longitud_aConfederacion, int index);
int contadorJugadoresIngresados(eJugador aJugador[], int longitud_aJugador);

#endif /* EJUGADOR_H_ */
