/*
 * menu_listado.c
 *
 *  Created on: 9 nov. 2022
 *      Author: pablo
 */

#include <stdio.h>

#include "Controller.h"
#include "Jugador.h"
#include "inputs.h"
#include "Seleccion.h"

/// @fn int mostrarMenuListados(LinkedList*, LinkedList*)
/// @brief Muestra el menu de listados
/// @param pArrayListJugador Puntero a la LinkedList que contiene los datos de los jugadores
/// @param pArrayListSeleccion Puntero a la LinkedList que contiene los datos de las selecciones
/// @return Retorna 0 si pudo mostrar el menu y -1 si no pudo
int mostrarMenuListados(LinkedList *pArrayListJugador,
		LinkedList *pArrayListSeleccion) {
	int retorno;
	int opcion;

	retorno = -1;
	opcion = -1;

	if (pArrayListJugador != NULL && pArrayListSeleccion != NULL) {
		printf("\n");
		printf("\n===============================================");
		printf("\n---------------MENU DE LISTADOS----------------");
		printf("\n-----------------------------------------------");
		if (utn_pedirNumero(&opcion, "\n1 - Jugadores"
				"\n2 - Selecciones"
				"\n3 - Jugadores convocados"
				"\n4 - Volver"
				"\n¿Que listado quiere ver?: ", "ERROR. Opcion incorrecta.", 1,
				4, 3) == 0) {
			switch (opcion) {
			case 1:
				if (controller_ordenarJugadorPorId(pArrayListJugador) != 0
						|| controller_listarJugadores(pArrayListJugador) != 0) {
					printf(
							"\nHUBO UN PROBLEMA AL QUERER LISTAR A LOS JUGADORES\n");
				}
				break;

			case 2:
				if (controller_ordenarSeleccionPorPais(pArrayListSeleccion) != 0
						|| controller_listarSelecciones(pArrayListSeleccion)
								!= 0) {
					printf(
							"\nHUBO UN PROBLEMA AL QUERER LISTAR A LAS SELECCIONES\n");
				}
				break;

			case 3:
				if (hayConvocados(pArrayListJugador) == 0) {
					if (controller_listarJugadoresConvocados(pArrayListJugador)
							!= 0) {
						printf(
								"\nHUBO UN PROBLEMA AL LISTAR LOS JUGADORES CONVOCADOS\n");
					}
				} else {
					printf("\nAUN NO HAY JUGADORES CONVOCADOS\n");
				}
				break;

			case 4:
				printf("\nVOLVIENDO AL MENU PRINCIPAL...\n");
			}
			retorno = 0;
		}
	}

	return retorno;
}
