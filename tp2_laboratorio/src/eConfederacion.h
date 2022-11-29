/*
 * eConfederacion.h
 *
 *  Created on: 26 oct. 2022
 *      Author: pablo
 */

#ifndef ECONFEDERACION_H_
#define ECONFEDERACION_H_

typedef struct {
	int id;
	char nombre[50];
	char region[50];
	int anioCreacion;
	int isEmpty;
} eConfederacion;

int inicializarArrayConfederacion(eConfederacion aConfederacion[],
		int longitud_aConfederacion);
int buscarIndiceVacioConfederacion(eConfederacion aConfederacion[],
		int longitud_aConfederacion);
int asignarIdConfederacion(eConfederacion aConfederacion[],
		int longitud_aConfederacion);
int buscarConfederacionPorId(eConfederacion aConfederacion[],
		int longitud_aConfederacion, int id, int *index);
int pedirNombreConfederacion(eConfederacion *unaConfederacion);
int pedirRegionConfederacion(eConfederacion *unaConfederacion);
int pedirAnioCreacion(eConfederacion *unaConfederacion);
int altaConfederacion(eConfederacion aConfederacion[],
		int longitud_aConfederacion);
int darBajaConfederacion(eConfederacion aConfederacion[],
		int longitud_aConfederacion, int index);
int menuDarBajaConfederacion(eConfederacion aConfederacion[],
		int longitud_aConfederacion);
int menuModificarConfederacion(eConfederacion aConfederacion[],
		int longitud_aConfederacion);
int modificarConfederacion(eConfederacion aConfederacion[],
		int longitud_aConfederacion, int index);
int buscarNombreConfederacionPorId(eConfederacion aConfederacion[],
		int longitud_aConfederacion, int id, char bufferNombre[]);

#endif /* ECONFEDERACION_H_ */
