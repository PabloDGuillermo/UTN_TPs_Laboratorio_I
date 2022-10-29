/*
 * menuInformes.c
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
#include "informes.h"

int menuInformes(eConfederacion aConfederacion[], int longitud_aConfederacion, eJugador aJugador[], int longitud_aJugador) {
	int retorno;
	int opcion;
	int retornoInputs;

	retorno = -1;

	do {
		printf("\n\n--------------------------\n");
		printf("|-----MENU DE INFORMES-----|\n");
		printf("--------------------------\n\n");
		retornoInputs = utn_pedirNumero(&opcion, "1 - MOSTRAR JUGADORES ORDENADOS ALFABETICAMENTE POR NOMBRE DE CONFEDERACION Y NOMBRE DE JUGADOR\n"
				"2 - MOSTRAR CONFEDERACIONES CON SUS JUGADORES\n"
				"3 - MOSTRAR EL TOTAL Y EL PROMEDIO DE TODOS LOS SALARIOS Y CUANTOS JUGADORES COBRAN MAS DEL SALARIO PROMEDIO\n"
				"4 - MOSTRAR LA CONFEDERACION CON MAYOR CANTIDAD DE AÑOS DE CONTRATO TOTAL\n"
				"5 - MOSTRAR EL PORCENTAJE DE JUGADORES POR CADA CONFEDERACION\n"
				"6 - MOSTRAR LA REGION CON MAS JUGADORES\n"
				"7 - VOLVER AL MENU PRINCIPAL\n"
				"ELIJA UNA OPCION: ", "ERROR. No ingreso una opcion valida.", 1,
				7, 3);
		if (retornoInputs == 0) {
			switch (opcion) {

			case 1:
				ordenarPorNombreConfederacionYJugador(aJugador,longitud_aJugador,aConfederacion,longitud_aConfederacion);
				break;

			case 2:
				listadoConfederacionesConSusJugadores(aJugador,longitud_aJugador,aConfederacion,longitud_aConfederacion);
				break;

			case 3:
				printf("\nEntre a opcion 3");
				break;

			case 4:
				printf("\nEntre a opcion 4");
				break;

			case 5:
				printf("\nEntre a la opcion 5");
				break;

			case 6:
				printf("\nEntre a la opcion 6");
			}
		}
	} while (opcion != 7);

	if(opcion==7){
		retorno=0;
		printf("\nVOLVIENDO AL MENU PRINCIPAL...");
	}

	return retorno;
}

