/*
 * menu_convocatorias.c
 *
 *  Created on: 9 nov. 2022
 *      Author: pablo
 */

#include <stdio.h>

#include "inputs.h"
#include "LinkedList.h"


int mostrarMenuConvocatorias(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion){
	int retorno;
	int opcion;

	retorno=-1;
	opcion=-1;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL){
		opcion=utn_pedirNumero(&opcion, "\n1 - Convocar jugador"
				"\n2 - Quitar jugador de la convocatoria"
				"\n3 - Volver"
				"\n¿Que desea hacer?: ", "ERROR. Opcion invalida.",1,3,3);
		switch(opcion){
		case 1:

			break;

		case 2:

			break;

		case 3:
			printf("\nVOLVIENDO AL MENU PRINCIPAL...\n");
			break;
		}
		retorno=0;
	}

	return retorno;
}
