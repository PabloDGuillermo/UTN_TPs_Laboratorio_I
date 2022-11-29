#include <stdio.h>

#include "inputs.h"
#include "LinkedList.h"
#include "Controller.h"

/// @fn int mostrarMenuOrdenarYListar(LinkedList*, LinkedList*)
/// @brief Muestra el menu para ordenar y listar
/// @param pArrayListJugador Puntero a la LinkedList que contiene los datos de los jugadores
/// @param pArrayListSeleccion Puntero a la LinkedList que contiene los datos de las selecciones
/// @return Retorna 0 si pudo mostrar el menu y -1 si no pudo
int mostrarMenuOrdenarYListar(LinkedList *pArrayListJugador,
		LinkedList *pArrayListSeleccion) {
	int retorno;

	retorno = -1;
	char opcion;
	char mensaje[1024] = { "A) JUGADORES POR NACIONALIDAD\n"
			"B) SELECCIONES POR CONFEDERACIÓN\n"
			"C) JUGADORES POR EDAD\n"
			"D) JUGADORES POR NOMBRE\n"
			"E) SALIR\n"
			"Elija una opcion (en minusculas): " };

	if (pArrayListJugador != NULL && pArrayListSeleccion != NULL) {
		do {
			printf("|=======================================|\n");
			printf("|---------MENU ORDENAR Y LISTAR---------|\n");
			printf("|---------------------------------------|\n");
			if (utn_pedirChar(&opcion, mensaje, "ERROR. Opcion invalida", 3)
					== 0) {
				switch (opcion) {
				case 'a':
					if (controller_ordenarJugadorPorNacionalidad(
							pArrayListJugador) != 0
							|| controller_listarJugadores(pArrayListJugador)
									!= 0) {
						printf(
								"\nHUBO UN PROBLEMA AL QUERER ORDENAR Y MOSTRAR A LOS JUGADORES\n");
					}
					break;

				case 'b':
					if (controller_ordenarSeleccionPorConfederacion(
							pArrayListSeleccion) != 0
							|| controller_listarSelecciones(pArrayListSeleccion)
									!= 0) {
						printf(
								"\nHUBO UN PROBLEMA AL QUERER ORDENAR Y MOSTRAR A LAS SELECCIONES\n");
					}
					break;

				case 'c':
					if (controller_ordenarJugadorPorEdad(pArrayListJugador) != 0
							|| controller_listarJugadores(pArrayListJugador)
									!= 0) {
						printf(
								"\nHUBO UN PROBLEMA AL QUERER ORDENAR Y MOSTRAR A LOS JUGADORES\n");
					}
					break;

				case 'd':
					if (controller_ordenarJugadorPorNombre(pArrayListJugador)
							!= 0
							|| controller_listarJugadores(pArrayListJugador)
									!= 0) {
						printf(
								"\nHUBO UN PROBLEMA AL QUERER ORDENAR Y MOSTRAR A LOS JUGADORES\n");
					}
					break;

				case 'e':
					printf("\nVOLVIENDO AL MENU PRINCIPAL\n");
					break;

				default:
					printf("\nNO INGRESO UNA OPCION VALIDA\n");
					break;
				}
			}
		} while ((opcion == 'a' || opcion == 'b' || opcion == 'c'
				|| opcion == 'd') || opcion != 'e');
	}

	return retorno;
}
