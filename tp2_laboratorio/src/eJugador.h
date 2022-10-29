/*
 * eJugador.h
 *
 *  Created on: 26 oct. 2022
 *      Author: pablo
 */
#include "eConfederacion.h"

#ifndef EJUGADOR_H_
#define EJUGADOR_H_


typedef struct{
	int id;
	char nombre[50];
	char posicion[50];
	short numeroCamiseta;
	int idConfederacion;
	float salario;
	short aniosContrato;
	short isEmpty;
}eJugador;

int inicializarArrayJugador(eJugador aJugador[], int longitud_aJugador);
int buscarIndiceVacioJugador(eJugador aJugador[], int longitud_aJugador);
int asignarIdJugador(eJugador aJugador[], int longitud_aJugador);
int pedirNombreJugador(eJugador* pArrayJugador, int longitud_aJugador);
int pedirPosicionJugador(eJugador* pArrayJugador, int longitud_aJugador);
int asignarPosicionJugador(eJugador* pArrayJugador, int opcionElegida);
int pedirNumeroCamisetaJugador(eJugador* pArrayJugador, int longitud_aJugador);
int pedirIdConfederacionJugador(eJugador* pArrayJugador, int longitud_aJugador, eConfederacion aConfederacion[], int longitud_aConfederacion);
int pedirSalarioJugador(eJugador* pArrayJugador, int longitud_aJugador);
int pedirAniosDeContratoJugador(eJugador* pArrayJugador, int longitud_aJugador);
int altaJugador(eJugador aJugador[], int longitud_aJugador, eConfederacion aConfederacion[], int longitud_aConfederacion);
int darBajaJugador(eJugador aJugador[], int longitud_aJugador, int idElegido);
int menuDarBajaJugador(eJugador aJugador[], int longitud_aJugador, eConfederacion aConfederacion[], int longitud_aConfederacion);
int ordenarPorIdJugador(eJugador aJugador[], int longitud_aJugador);
int menuModificarJugador(eJugador aJugador[], int longitud_aJugador, eConfederacion aConfederacion[], int longitud_aConfederacion);
int modificarJugador(eJugador aJugador[], int longitud_aJugador, eConfederacion aConfederacion[], int longitud_aConfederacion, int id);
int modificarNombreJugador(eJugador aJugador);


#endif /* EJUGADOR_H_ */
