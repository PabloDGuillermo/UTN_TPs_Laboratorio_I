/*
 * eConfederacion.h
 *
 *  Created on: 26 oct. 2022
 *      Author: pablo
 */

#ifndef ECONFEDERACION_H_
#define ECONFEDERACION_H_

typedef struct{
	int id;
	char nombre[50];
	char region[50];
	int anioCreacion;
	int isEmpty;
}eConfederacion;

int inicializarArrayConfederacion(eConfederacion aConfederacion[], int longitud_aConfederacion);
int buscarIndiceVacioConfederacion(eConfederacion aConfederacion[], int longitud_aConfederacion);
int asignarIdConfederacion(eConfederacion aConfederacion[], int longitud_aConfederacion);
int pedirNombreConfederacion(eConfederacion* pArrayConfederacion, int longitud_aConfederacion);
int pedirRegionConfederacion(eConfederacion* pArrayConfederacion, int longitud_aConfederacion);
int pedirAnioCreacion(eConfederacion* pArrayConfederacion, int longitud_aConfederacion);
int altaConfederacion(eConfederacion aConfederacion[], int longitud_aConfederacion);
int darBajaConfederacion(eConfederacion aConfederacion[], int longitud_aConfederacion, int idElegido);
int menuDarBajaConfederacion(eConfederacion aConfederacion[], int longitud_aConfederacion);
int menuModificarConfederacion(eConfederacion aConfederacion[], int longitud_aConfederacion);
int modificarConfederacion(eConfederacion aConfederacion[], int longitud_aConfederacion, int id);
void hardcodeoConfederaciones(eConfederacion aConfederacion[], int longitud_aConfederacion);
void asignarNombreHardcodeado(eConfederacion* pArrayConfederacion, int id);
void asignarRegionHardcodeada(eConfederacion* pArrayConfederacion, int id);
void asignarAnioCreacionHardcodeado(eConfederacion* pArrayConfederacion, int id);
int buscarNombreConfederacionPorId(eConfederacion aConfederacion[], int longitud_aConfederacion, int id, char nombre[]);

#endif /* ECONFEDERACION_H_ */
