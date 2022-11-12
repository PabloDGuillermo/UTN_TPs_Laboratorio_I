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

int mostrarMenuListados(LinkedList* pArrayListJugador,
		LinkedList* pArrayListSeleccion) {
	int retorno;
	int opcion;
	int flagError;

	retorno = -1;
	opcion=-1;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL){
		printf("\n");
		printf("\n===============================================");
		printf("\n---------------MENU DE LISTADOS----------------");
		printf("\n-----------------------------------------------");
		flagError = utn_pedirNumero(&opcion, "\n1 - Jugadores"
				"\n2 - Selecciones"
				"\n3 - Jugadores convocados"
				"\n4 - Volver"
				"\n¿Que listado quiere ver?: ", "ERROR. Opcion incorrecta.", 1, 4,
				3);
		if(flagError==0){
			switch(opcion){
			case 1:
				controller_listarJugadores(pArrayListJugador);
				break;

			case 2:
				controller_listarSelecciones(pArrayListSeleccion);
				break;

			case 3:
				if(hayConvocados(pArrayListJugador)==0){
					controller_listarJugadoresConvocados(pArrayListJugador);
				}else{
					printf("\nNo hay jugadores convocados\n");
				}
				break;

			case 4:
				printf("\nVOLVIENDO AL MENU PRINCIPAL...\n");
			}
			retorno=0;
		}
	}



	return retorno;
}
