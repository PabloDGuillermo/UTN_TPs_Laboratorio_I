/*
 ============================================================================
 Name        : tp2_laboratorio.c
 Author      : Pablo Guillermo
 Version     :
 Copyright   : 1ra Div E
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "eConfederacion.h"
#include "eJugador.h"
#include "inputs.h"
#include "outputs.h"
#include "menuInformes.h"

#define LONG_CONFEDERACION 6
#define LONG_JUGADORES 3000

int main(void) {
	setbuf(stdout, NULL);

	eConfederacion aConfederaciones[LONG_CONFEDERACION] = { { 100, "CONMEBOL",
			"SUDAMERICA", 1916, 1 }, { 101, "UEFA", "EUROPA", 1954, 1 },
			{ 102, "AFC", "ASIA", 1954, 1 }, { 103, "CAF", "AFRICA", 1957,
					1 }, { 104, "CONCACAF", "NORTE Y CENTRO AMERICA", 1961,
					1 }, { 105, "OFC", "OCEANIA", 1966, 1 } };
	eJugador aJugadores[LONG_JUGADORES]={
		       {1,"Emiliano Martinez","ARQUERO",1,100,100000,4,1},
		       {2,"Juan Musso","ARQUERO",12,100,80000,2,1},
		       {3,"Leo Messi","DELANTERO",10,100,80000,4,1},
		       {4,"Almirez Ali","DELANTERO",9,100,55000,1,1},
		       {5,"Harry Maguire","DEFENSOR",2,101,70000,4,1},
		       {6,"Eric Dier","DEFENSOR",3,101,60000,2,1},
		       {7,"Harry Kane","DELANTERO",10,101,3000,2,1},
		       {8,"Alfred Gomis","ARQUERO",1,101,9000,1,1},
		       {9,"Abdelkarim Hassan","MEDIOCAMPISTA",8,101,48000,1,1},
		       {10,"Guillermo Ochoa","ARQUERO",1,104,90000,4,1},
		       {11,"Tecatito","DELANTERO",11,104,100000,3,1},
		       {12,"Luis Romo","MEDIOCAMPISTA",7,104,100000,2,1},
		       {13,"Bamba Dieng ","DELANTERO",9,103,100000,2,1},
		       {14,"Demba Seck","DELANTERO",11,103,6000,2,1},
		       {15,"Tarek Salman","DEFENSOR",6,102,78000,5,1}
		   };

	char confirmacion;
	int opcion;

	do {

		//if (inicializarArrayJugador(aJugadores, LONG_JUGADORES) == 0) {

			printf("\n\n--------------------------\n");
			printf("|-----MENU PRINCIPAL-----|\n");
			printf("--------------------------\n\n");
			utn_pedirNumero(&opcion, "1 - ALTA DE JUGADOR\n"
					"2 - BAJA DE JUGADOR\n"
					"3 - MODIFICACION DE JUGADOR\n"
					"4 - MENU INFORMES\n"
					"5 - SALIR\n"
					"ELIJA UNA OPCION: ",
					"ERROR. No inrgeso una opcion valida.", 1, 5, 3);
			switch (opcion) {

			case 1:
				;
				if (altaJugador(aJugadores, LONG_JUGADORES, aConfederaciones,
				LONG_CONFEDERACION) == 0) {
					printf("\nJUGADOR DADO DE ALTA EXITOSAMENTE\n");
				} else {
					printf("\nNO SE PUDO DAR DE ALTA AL JUGADOR\n");
				}
				break;

			case 2:
				if (hayJugadores(aJugadores, LONG_JUGADORES) == 0) {
					if (menuDarBajaJugador(aJugadores, LONG_JUGADORES,
							aConfederaciones, LONG_CONFEDERACION) == 0) {
						printf("\nJUGADOR DADO DE BAJA EXITOSAMENTE\n");
					} else {
						printf("\nNO SE PUDO DAR DE BAJA AL JUGADOR\n");
					}
				} else {
					printf("\nAUN NO SE CARGO AUNQUE SEA UN JUGADOR\n");
				}
				break;

			case 3:
				if (hayJugadores(aJugadores, LONG_JUGADORES) == 0) {
					if (menuModificarJugador(aJugadores, LONG_JUGADORES,
							aConfederaciones, LONG_CONFEDERACION) == 0) {
						printf("\nJUGADOR MODIFICADO EXITOSAMENTE\n");
					} else {
						printf("\nNO SE PUDO MODIFICAR AL JUGADOR\n");
					}
				} else {
					printf("\nAUN NO SE CARGO AUNQUE SEA UN JUGADOR\n");
				}
				break;

			case 4:
				if (hayJugadores(aJugadores, LONG_JUGADORES) == 0) {
					menuInformes(aConfederaciones,
					LONG_CONFEDERACION, aJugadores, LONG_JUGADORES);
				} else {
					printf("\nAUN NO SE CARGO AUNQUE SEA UN JUGADOR\n");
				}
				break;

			case 5:
				utn_pedirChar(&confirmacion,
						"¿Desea finalizar el programa? (s/n): ",
						"ERROR. Opcion invalida.", 3);
				break;
			}
		/*} else {
			printf("\nHUBO UN PROBLEMA AL INICIALIZAR LOS ARRAYS\n");
		}*/
	} while (opcion != 5 && confirmacion != 's');

	printf("\nPROGRAMA FINALIZADO");

	return EXIT_SUCCESS;
}
