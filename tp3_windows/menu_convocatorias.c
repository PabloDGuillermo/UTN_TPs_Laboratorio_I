/*
 * menu_convocatorias.c
 *
 *  Created on: 9 nov. 2022
 *      Author: pablo
 */

#include <stdio.h>

#include "inputs.h"
#include "LinkedList.h"
#include "Jugador.h"

/// @fn int mostrarMenuConvocatorias(LinkedList*, LinkedList*)
/// @brief Muestra el menu de las convocatorias
/// @param pArrayListJugador Puntero a la LinkedList que contiene los datos de los jugadores
/// @param pArrayListSeleccion Puntero a la LinkedList que contiene los datos de las selecciones
/// @return Retrona 0 si pudo mostrar el menu y -1 si no pudo
int mostrarMenuConvocatorias(LinkedList *pArrayListJugador,
		LinkedList *pArrayListSeleccion) {
	int retorno;
	int opcion;

	retorno = -1;
	opcion = -1;

	if (pArrayListJugador != NULL && pArrayListSeleccion != NULL) {
		if (utn_pedirNumero(&opcion, "\n1 - Convocar jugador"
				"\n2 - Quitar jugador de la convocatoria"
				"\n3 - Volver"
				"\n¿Que desea hacer?: ", "ERROR. Opcion invalida.", 1, 3, 3)
				== 0) {
			switch (opcion) {
			case 1:
				if (jug_convocarJugador(pArrayListJugador, pArrayListSeleccion)
						== 0) {
					printf("\nEL JUGADOR FUE CONVOCADO EXITOSAMENTE\n");
				} else {
					printf("\nNO SE PUDO CONVOCAR AL JUGADOR\n");
				}
				break;

			case 2:
				if (jug_quitarDeConvocatoria(pArrayListJugador,
						pArrayListSeleccion) == 0) {
					printf(
							"\nEL JUGADOR FUE QUITADO CON EXITO DE LA CONVOCATORIA\n");
				} else {
					printf(
							"\nHUBO UN PROBLEMA AL QUERER QUITAR EL JUGADOR DE LA CONVOCATORIA\n");
				}
				break;

			case 3:
				printf("\nVOLVIENDO AL MENU PRINCIPAL...\n");
				break;
			}
			retorno = 0;
		}
	}

	return retorno;
}
