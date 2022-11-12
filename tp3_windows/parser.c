#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"

/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int parser_JugadorFromText(FILE *pFile, LinkedList *pArrayListJugador) {
	int retorno;
	char auxId[100];
	char auxNombreCompleto[100];
	char auxEdad[100];
	char auxPosicion[30];
	char auxNacionalidad[30];
	char auxIdSeleccion[100];
	int retornoFscanf;
	Jugador *pElemento = NULL;

	retorno = -1;

	fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxId,
			auxNombreCompleto, auxEdad, auxPosicion, auxNacionalidad,
			auxIdSeleccion);

	do {
		retornoFscanf = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
				auxId, auxNombreCompleto, auxEdad, auxPosicion, auxNacionalidad,
				auxIdSeleccion);
		if (retornoFscanf == 6) {
			pElemento = jug_newParametros(auxId, auxNombreCompleto, auxEdad,
					auxPosicion, auxNacionalidad, auxIdSeleccion);
			if (pElemento != NULL) {
				ll_add(pArrayListJugador, pElemento);
				retorno = 0;
			} else {
				printf("\nHUBO UN ERROR AL LEER EL ARCHIVO.");
				retorno = -1;
				break;
			}
		}
	} while (!feof(pFile));
	return retorno;
}

/** \brief Parsea los datos de los jugadores desde el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int parser_JugadorFromBinary(FILE *pFile, LinkedList *pArrayListJugador) {
	return 1;
}

/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int parser_SeleccionFromText(FILE *pFile, LinkedList *pArrayListSeleccion) {
	int retorno;
	char auxId[100];
	char auxPais[100];
	char auxConfederacion[100];
	char auxConvocados[30];
	int retornoFscanf;
	Seleccion *pElemento = NULL;

	retorno = -1;

	fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxPais, auxConfederacion,
			auxConvocados);


	do {
		retornoFscanf = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxId,
				auxPais, auxConfederacion, auxConvocados);
		if (retornoFscanf == 4) {
			pElemento = selec_newParametros(auxId, auxPais, auxConfederacion,
					auxConvocados);
			if (pElemento != NULL) {
				ll_add(pArrayListSeleccion, pElemento);
				retorno = 0;
			} else {
				printf("\nHUBO UN ERROR AL LEER EL ARCHIVO.");
				retorno = -1;
				break;
			}
		}
	} while (!feof(pFile));
	return retorno;
}

int parser_IdUnicoFromText(FILE *pFile, int *id) {
	int retorno;
	int cantidadLeida;
	int auxId;

	retorno = -1;

	if (pFile != NULL && id != NULL) {
		cantidadLeida = fscanf(pFile, "%d", &auxId);
		if (cantidadLeida == 1) {
			*id = auxId;
			retorno = 0;
		}
	}

	return retorno;
}
