#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "inputs.h"
#include "menu_listado.h"
#include "menu_convocatorias.h"
#include "menu_ordenarYListar.h"

int main() {
	setbuf(stdout, NULL);
	int option;
	LinkedList *listaJugadores = ll_newLinkedList();
	LinkedList *listaSelecciones = ll_newLinkedList();
	LinkedList *listaJugadoresBinario = ll_newLinkedList();
	char confirmacion;
	int flag;

	flag = 0;

	do {
		option = -1;
		confirmacion = 'z';

		printf("\n");
		printf(
				"============================================================\n");
		printf(
				"|----------------------MENU PRINCIPAL----------------------|\n");
		printf(
				"------------------------------------------------------------\n");
		utn_pedirNumero(&option, "\n1 - CARGA DE ARCHIVOS"
				"\n2 - ALTA DE JUGADOR"
				"\n3 - MODIFICACION DEL JUGADOR"
				"\n4 - BAJA DE JUGADOR"
				"\n5 - LISTADOS"
				"\n6 - CONVOCAR JUGADORES"
				"\n7 - ORDENAR Y LISTAR"
				"\n8 - GENERAR ARCHIVO BINARIO"
				"\n9 - CARGAR ARCHIVO BINARIO"
				"\n10 - GUARDAR ARCHIVOS .CSV"
				"\n11 - SALIR"
				"\nIngrese una opcion: ", "ERROR. Opcion invalida", 1, 11, 3);
		switch (option) {
		case 1:
			if (flag == 0
					&& controller_cargarJugadoresDesdeTexto("jugadores.csv",
							listaJugadores) == 0
					&& controller_cargarSeleccionesDesdeTexto("selecciones.csv",
							listaSelecciones) == 0) {
				printf("\nLOS ARCHIVOS SE CARGARON CORRECTAMENTE");
				flag = 1;
			} else {
				printf(
						"\nLOS ARCHIVOS NO PUDIERON ABRIRSE O YA FUERON CARGADOS ANTERIORMENTE\n");
			}
			break;

		case 2:
			if (flag == 1) {
				if (controller_agregarJugador(listaJugadores) == 0) {
					printf("\nJUGADOR AGREGADO CORRECTAMENTE");
				} else {
					printf("\nNO SE PUDO AGREGAR AL JUGADOR");
				}
			} else {
				printf("\nAUN NO SE CARGARON LOS ARCHIVOS\n");
			}
			break;

		case 3:
			if (flag == 1) {
				if (controller_editarJugador(listaJugadores) == 0) {
					printf("\nEL JUGADOR FUE MODIFICADO CON EXITO");
				} else {
					printf("\nNO SE PUDO MODIFICAR AL JUGADOR");
				}
			} else {
				printf("\nAUN NO SE CARGARON LOS ARCHIVOS\n");
			}
			break;

		case 4:
			if (flag == 1) {
				if (controller_removerJugador(listaJugadores) == 0) {
					printf("\nEL JUGADOR FUE DADO DE BAJA EXITOSAMENTE");
				} else {
					printf("\nEL JUGADOR NO PUDO SER DADO DE BAJA");
				}
			} else {
				printf("\nAUN NO SE CARGARON LOS ARCHIVOS\n");
			}
			break;

		case 5:
			if (flag == 1) {
				if (mostrarMenuListados(listaJugadores, listaSelecciones)
						!= 0) {
					printf(
							"\nHUBO UN PROBLEMA AL INTENTAR INGRESAR AL MENU DE LISTADOS\n");
				}
			} else {
				printf("\nAUN NO SE CARGARON LOS ARCHIVOS\n");
			}
			break;

		case 6:
			if (flag == 1) {
				if (mostrarMenuConvocatorias(listaJugadores, listaSelecciones)
						!= 0) {
					printf(
							"\nHUBO UN PROBLEMA AL INTENTAR INGRESAR AL MENU DE CONVOCATORIAS\n");
				}
			} else {
				printf("\nAUN NO SE CARGARON LOS ARCHIVOS\n");
			}
			break;

		case 7:
			if (flag == 1) {
				if (mostrarMenuOrdenarYListar(listaJugadores, listaSelecciones)
						!= 0) {
					printf(
							"\nHUBO UN PROBLEMA AL INTENTAR INGRESAR AL MENU DE ORDENAR Y LISTAR\n");
				}
			} else {
				printf("\nAUN NO SE CARGARON LOS ARCHIVOS\n");
			}
			break;

		case 8:
			if (flag == 1) {
				if(controller_guardarJugadoresModoBinario("jugadores.bin",listaJugadores)==0){
					printf("\nEL ARCHIVO BINARIO SE GUARDO CORRECTAMENTE\n");
				}
			} else {
				printf("\nAUN NO SE CARGARON LOS ARCHIVOS\n");
			}
			break;

		case 9:
			if (controller_cargarJugadoresDesdeBinario("jugadores.bin",
					listaJugadoresBinario) == 0) {
				printf(
						"\nEL ARCHIVO BINARIO DE JUGADORES SE CARGO CORRECTAMENTE\n");
				controller_listarJugadores(listaJugadoresBinario);
			} else {
				printf(
						"\nHUBO UN ERROR AL CARGAR EL ARCHIVO BINARIO DE JUGADORES\n");
			}
			break;

		case 10:
			if (flag == 1) {
				if (controller_guardarJugadoresModoTexto("jugadores.csv",
						listaJugadores) == 0) {
					printf("\nEL ARCHIVO SE GUARDO CORRECTAMENTE");
				} else {
					printf("\nEL ARCHIVO NO PUDO SER GUARDADO CORRECTAMENTE");
				}
			} else {
				printf("\nAUN NO SE CARGARON LOS ARCHIVOS\n");
			}
			break;

		case 11:
			if (utn_pedirChar(&confirmacion,
					"CUALQUIER CAMBIO QUE NO HAYA GUARDADO SE PERDERÁ\nSEGURO QUE DESEA SALIR? (s/n): ",
					"ERROR.", 3) == 0) {
				printf("-----PROGRAMA FINALIZADO-----");
			}
		}

	} while (option != 11 && confirmacion != 's');
	return 0;
}

