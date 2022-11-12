#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "inputs.h"
#include "menu_listado.h"

int main() {
	setbuf(stdout, NULL);
	int option = 0;
	LinkedList *listaJugadores = ll_newLinkedList();
	LinkedList *listaSelecciones = ll_newLinkedList();
	char confirmacion;
	int flag;

	option=-1;
	flag = 0;

	do {
		do {
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
					"\nIngrese una opcion: ", "ERROR. Opcion invalida", 1, 11,
					3);
			switch (option) {
			case 1:
				if (flag == 0
						&& controller_cargarJugadoresDesdeTexto("jugadores.csv",
								listaJugadores) == 0
						&& controller_cargarSeleccionesDesdeTexto(
								"selecciones.csv", listaSelecciones) == 0) {
					printf("\nLOS ARCHIVOS SE CARGARON CORRECTAMENTE");
					flag = 1;
				} else {
					printf("\nLOS ARCHIVOS NO PUDIERON ABRIRSE");
				}
				break;

			case 2:
				if (controller_agregarJugador(listaJugadores) == 0) {
					printf("\nJUGADOR AGREGADO CORRECTAMENTE");
				} else {
					printf("\nNO SE PUDO AGREGAR AL JUGADOR");
				}
				break;

			case 3:
				if (controller_editarJugador(listaJugadores) == 0) {
					printf("\nEL JUGADOR FUE MODIFICADO CON EXITO");
				} else {
					printf("\nNO SE PUDO MODIFICAR AL JUGADOR");
				}
				break;

			case 4:
				if (controller_removerJugador(listaJugadores) == 0) {
					printf("\nEL JUGADOR FUE DADO DE BAJA EXITOSAMENTE");
				} else {
					printf("\nEL JUGADOR NO PUDO SER DADO DE BAJA");
				}
				break;

			case 5:
				mostrarMenuListados(listaJugadores,listaSelecciones);
				break;

			case 6:

				break;

			case 7:

				break;

			case 8:

				break;

			case 9:

				break;

			case 10:
				if (controller_guardarJugadoresModoTexto("jugadores.csv",
						listaJugadores) == 0) {
					printf("\nEL ARCHIVO SE GUARDO CORRECTAMENTE");
				} else {
					printf("\nEL ARCHIVO NO PUDO SER GUARDADO CORRECTAMENTE");
				}
				break;
			}

		} while (option != 11);

		utn_pedirChar(&confirmacion,
				"CUALQUIER CAMBIO QUE NO HAYA GUARDADO SE PERDERÁ\nSEGURO QUE DESEA SALIR? (s/n): ",
				"ERROR.", 3);
	} while (confirmacion != 's');
	return 0;
}

