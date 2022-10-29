/*
 * menuPrincipal.c
 *
 *  Created on: 26 oct. 2022
 *      Author: pablo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"
#include "eConfederacion.h"
#include "eJugador.h"
#include "menuInformes.h"

int menuPrincipal(eConfederacion aConfederacion[], int longitud_aConfederacion, eJugador aJugador[], int longitud_aJugador) {
	int retorno;
	int opcion;
	int retornoInputs;
	int contadorJugadores;

	contadorJugadores=0;


	retorno = -1;

	do {
		printf("\n\n--------------------------\n");
		printf("|-----MENU PRINCIPAL-----|\n");
		printf("--------------------------\n\n");
		retornoInputs = utn_pedirNumero(&opcion, "1 - ALTA DE JUGADOR\n"
				"2 - BAJA DE JUGADOR\n"
				"3 - MODIFICACION DE JUGADOR\n"
				"4 - MENU INFORMES\n"
				"5 - SALIR\n"
				"ELIJA UNA OPCION: ", "ERROR. No inrgeso una opcion valida.", 1,
				5, 3);
		if (retornoInputs == 0) {
			switch (opcion) {

			case 1:
				retornoInputs=altaJugador(aJugador,longitud_aJugador,aConfederacion,longitud_aConfederacion);
				if(retornoInputs==0){
					printf("\nJUGADOR DADO DE ALTA EXITOSAMENTE\n");
					contadorJugadores++;
				}
				break;

			case 2:
				if (contadorJugadores > 0) {
					menuDarBajaJugador(aJugador,longitud_aJugador,aConfederacion,longitud_aConfederacion);
					contadorJugadores--;
				} else {
					printf("\nAun no cargo aunque sea un jugador");
				}
				break;

			case 3:
				if (contadorJugadores > 0) {
					menuModificarJugador(aJugador,longitud_aJugador,aConfederacion,longitud_aConfederacion);
				} else {
					printf("\nAun no cargo aunque sea un jugador");
				}
				break;

			case 4:
				if (contadorJugadores > 0) {
					menuInformes(aConfederacion, longitud_aConfederacion, aJugador, longitud_aJugador);
				} else {
					printf("\nAun no cargo aunque sea un jugador");
				}
				break;
			}
		}
	} while (opcion != 5);

	if(opcion==5){
		retorno=0;
	}

	return retorno;
}
