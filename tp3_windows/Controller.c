#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "parser.h"
#include "inputs.h"
#include "Controller.h"

/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeTexto(char *path,
		LinkedList *pArrayListJugador) {
	int retorno;
	FILE *pArchivo;

	retorno = -1;

	if (path != NULL && pArrayListJugador != NULL) {
		pArchivo = fopen(path, "r");
		if (pArchivo != NULL) {
			parser_JugadorFromText(pArchivo, pArrayListJugador);
			retorno = 0;
		} else {
			pArchivo = fopen(path, "w");
			if (pArchivo != NULL) {
				printf("\nEL ARCHIVO NO EXISTÍA Y FUE CREADO CORRECTAMENTE.");
			}
		}
		fclose(pArchivo);
	}

	return retorno;
}

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeBinario(char *path,
		LinkedList *pArrayListJugador) {
	return 0;
}

/** \brief Alta de jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_agregarJugador(LinkedList *pArrayListJugador) {
	int retorno;
	int auxId;
	char auxNombreCompleto[100];
	int auxEdad;
	char auxPosicion[50];
	char auxNacionalidad[50];
	int auxNacionalidadInt;
	int auxIdSeleccion;
	int contadorErrores;
	int opcionPosicion;
	char idParametro[50];
	char edadParametro[50];
	char idSeleccionParametro[50];
	Jugador *pNuevoJugador;

	retorno = -1;

	pNuevoJugador = jug_new();

	if (pNuevoJugador != NULL) {

		printf("\n-------AGREGANDO JUGADOR-------\n");

		controller_cargarIdUnicoDesdeTexto("ID_Unico.csv", &auxId);
		auxId++;
		sprintf(idParametro, "%d", auxId);

		contadorErrores = utn_pedirTexto(auxNombreCompleto,
				"Ingrese el nombre completo (max 100 caracteres): ",
				"ERROR. Nombre invalido.", 100, 3);
		if (contadorErrores == 0) {
			contadorErrores = utn_pedirNumero(&auxEdad, "Ingrese la edad: ",
					"ERROR. Edad Invalida", 14, 65, 3);
			sprintf(edadParametro, "%d", auxEdad);
		}
		if (contadorErrores == 0) {
			contadorErrores = utn_pedirNumero(&opcionPosicion, "\n1 - Portero"
					"\n2 - Defensa central"
					"\n3 - Lateral izquierdo"
					"\n4 - Lateral derecho"
					"\n5 - Pivote"
					"\n6 - Mediocentro"
					"\n7 - Extremo izquierdo"
					"\n8 - Extermo derecho"
					"\n9 - Mediapunta"
					"\n10 - Delantero centro"
					"\nElija una posicion: ", "ERROR. Posicion invalida.", 1,
					10, 3);
			jug_elegirPosicion(opcionPosicion, auxPosicion);
		}
		if (utn_pedirNumero(&auxNacionalidadInt, "\n1 - Aleman"
				"\n2 - Arabe"
				"\n3 - Argentino"
				"\n4 - Australiano"
				"\n5 - Brasilero"
				"\n7 - Camerunes"
				"\n8 - Canadiense"
				"\n9 - Coreano del Sur"
				"\n10 - Costarricense"
				"\n11 - Croata"
				"\n12 - Danes"
				"\n13 - Ecuatoriano"
				"\n14 - Español"
				"\n15 - Estado Unidense"
				"\n16 - Frances"
				"\n17 - Gales"
				"\n18 - Ghanes"
				"\19 - Holandes"
				"\n20 - Ingles"
				"\n21 - Irani"
				"\n22 - Japones"
				"\n23 - Marroqui"
				"\n24 - Mexicano"
				"\n25 - Polaco"
				"\n26 - Portugues"
				"\n27 - Qatari"
				"\n28 - Senegales"
				"\n29 - Serbio"
				"\n30 - Suizo"
				"\n31 - Tunecino"
				"\n32 - Uruguayo"
				"\nIngrese la nacionalidad: ", "ERROR. Nacionalidad invalida",
				1, 32, 3) == 0) {
			jug_elegirNacionalidad(auxNacionalidadInt, auxNacionalidad);

		}
		if (contadorErrores == 0) {
			auxIdSeleccion = 0;
			sprintf(idSeleccionParametro, "%d", auxIdSeleccion);
		}

		if (contadorErrores == 0) {
			pNuevoJugador = jug_newParametros(idParametro, auxNombreCompleto,
					edadParametro, auxPosicion, auxNacionalidad,
					idSeleccionParametro);
			contadorErrores = ll_add(pArrayListJugador, pNuevoJugador);
			if (contadorErrores == 0) {
				controller_guardarIdUnicoModoTexto("ID_Unico.csv", auxId);
				retorno = 0;
			}
		}
	} else {
		printf("\nNO HAY MAS LUGAR PARA NUEVOS JUGADORES\n");
	}

	return retorno;
}

/** \brief Modificar datos del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_editarJugador(LinkedList *pArrayListJugador) {
	int retorno;
	int idElegido;
	Jugador jugador;
	Jugador *jugadorAModificar;

	jugadorAModificar = &jugador;

	retorno = -1;

	if (pArrayListJugador != NULL) {
		printf("\n------DAR DE BAJA A UN JUGADOR------\n");
		if (controller_listarJugadores(pArrayListJugador) == 0) {
			utn_pedirNumero(&idElegido,
					"Elija el ID del jugador que quiere modificar: ",
					"ERROR. ID invalido.", 1, 1000, 3);

			jugadorAModificar = jug_encontrarPorId(pArrayListJugador,
					idElegido);

			if (jugadorAModificar != NULL) {
				if (menuModificarJugador(jugadorAModificar) == 0) {
					retorno = 0;
				} else {
					printf("\nEL JUGADOR CON ESE ID NO EXISTE");
				}
			}
		}
	}

	return retorno;
}

/** \brief Baja del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_removerJugador(LinkedList *pArrayListJugador) {
	int retorno;
	int idElegido;
	Jugador *pJugador = NULL;

	retorno = -1;

	if (pArrayListJugador != NULL) {
		printf("\n------DAR DE BAJA A UN JUGADOR------\n");
		if (controller_listarJugadores(pArrayListJugador) == 0) {
			utn_pedirNumero(&idElegido,
					"Elija el ID del jugador que quiere dar de baja: ",
					"ERROR. ID invalido.", 1, 1000, 3);

			pJugador = jug_encontrarPorId(pArrayListJugador, idElegido);

			if (pJugador != NULL) {
				jug_eliminarJugador(pArrayListJugador, pJugador);
				retorno = 0;
			} else {
				printf("\nEL JUGADOR CON ESE ID NO EXISTE");
			}
		} else {
			printf("\nVOLVIENDO AL MENU PRINCIPAL...");
		}
	}

	return retorno;
}

/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_listarJugadores(LinkedList *pArrayListJugador) {
	int retorno;
	Jugador *pJugador;
	int lenLL;
	int auxId;
	char auxNombre[100];
	int auxEdad;
	char auxPosicion[30];
	char auxNacionalidad[30];
	int auxIdSeleccion;
	char auxConvocatoria[50];

	lenLL = ll_len(pArrayListJugador);

	retorno = -1;
	if (pArrayListJugador != NULL && lenLL > 0) {
		printf(
				"==================================================================================================\n");
		printf(
				"|----------------------------------LISTA COMPLETA DE JUGADORES-----------------------------------|\n");
		printf(
				"|------------------------------------------------------------------------------------------------|\n");
		printf("| %-3s | %-25s | %s | %-20s | %-15s | %s |\n", "ID",
				"Nombre completo", "Edad", "Posicion", "Nacionalidad",
				"ID Seleccion");
		printf(
				"|------------------------------------------------------------------------------------------------|\n");
		for (int i = 0; i < lenLL; i++) {
			pJugador = (Jugador*) ll_get(pArrayListJugador, i);
			jug_getId(pJugador, &auxId);
			jug_getNombreCompleto(pJugador, auxNombre);
			jug_getEdad(pJugador, &auxEdad);
			jug_getPosicion(pJugador, auxPosicion);
			jug_getNacionalidad(pJugador, auxNacionalidad);
			jug_getIdSeleccion(pJugador, &auxIdSeleccion);
			jug_elegirConvocatoria(auxIdSeleccion, auxConvocatoria);
			if (i >= 0) {
				printf("| %-3d | %-25s |  %-3d | %-20s | %-15s | %-12s |\n",
						auxId, auxNombre, auxEdad, auxPosicion, auxNacionalidad,
						auxConvocatoria);
			}
		}
		retorno = 0;
	}

	return retorno;
}

int controller_listarJugadoresConvocados(LinkedList *pArrayListJugador) {
	int retorno;
	Jugador *pJugador;
	int lenLL;
	int auxId;
	char auxNombre[100];
	int auxEdad;
	char auxPosicion[30];
	char auxNacionalidad[30];
	int auxIdSeleccion;
	char auxConvocatoria[50];

	lenLL = ll_len(pArrayListJugador);

	retorno = -1;
	if (pArrayListJugador != NULL && lenLL > 0) {
		printf(
				"==================================================================================================\n");
		printf(
				"|---------------------------------LISTA DE JUGADORES CONVOCADOS----------------------------------|\n");
		printf(
				"|------------------------------------------------------------------------------------------------|\n");
		printf("| %-3s | %-25s | %s | %-20s | %-15s | %s |\n", "ID",
				"Nombre completo", "Edad", "Posicion", "Nacionalidad",
				"Convocatoria");
		printf(
				"|------------------------------------------------------------------------------------------------|\n");
		for (int i = 0; i < lenLL; i++) {
			pJugador = (Jugador*) ll_get(pArrayListJugador, i);
			jug_getIdSeleccion(pJugador, &auxIdSeleccion);
			if (auxIdSeleccion != 0) {
				jug_getId(pJugador, &auxId);
				jug_getNombreCompleto(pJugador, auxNombre);
				jug_getEdad(pJugador, &auxEdad);
				jug_getPosicion(pJugador, auxPosicion);
				jug_getNacionalidad(pJugador, auxNacionalidad);
				jug_getIdSeleccion(pJugador, &auxIdSeleccion);
				jug_elegirConvocatoria(auxIdSeleccion, auxConvocatoria);
				if (i >= 0) {
					printf("| %-3d | %-25s |  %-3d | %-20s | %-15s | %-12s |\n",
							auxId, auxNombre, auxEdad, auxPosicion,
							auxNacionalidad, auxConvocatoria);
				}
			}
		}
		retorno = 0;
	}

	return retorno;
}

/** \brief Ordenar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_ordenarJugadores(LinkedList *pArrayListJugador) {
	int retorno;

	retorno = -1;

	if (pArrayListJugador != NULL) {

		retorno = 0;
	}

	return retorno;
}

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoTexto(char *path,
		LinkedList *pArrayListJugador) {
	int retorno;
	FILE *pArchivo;
	Jugador *auxJugador;
	int auxId;
	char auxNombre[100];
	int auxEdad;
	char auxPosicion[30];
	char auxNacionalidad[30];
	int auxIdSeleccion;

	retorno = -1;

	if (path != NULL && pArrayListJugador != NULL) {
		pArchivo = fopen(path, "w");
		if (pArchivo != NULL) {
			for (int i = 0; i < ll_len(pArrayListJugador); i++) {
				auxJugador = (Jugador*) ll_get(pArrayListJugador, i);

				if (jug_getId(auxJugador, &auxId) == 0
						&& jug_getNombreCompleto(auxJugador, auxNombre) == 0
						&& jug_getEdad(auxJugador, &auxEdad) == 0
						&& jug_getPosicion(auxJugador, auxPosicion) == 0
						&& jug_getNacionalidad(auxJugador, auxNacionalidad) == 0
						&& jug_getIdSeleccion(auxJugador, &auxIdSeleccion)
								== 0) {

					fprintf(pArchivo, "%d,%s,%d,%s,%s,%d\n", auxId, auxNombre,
							auxEdad, auxPosicion, auxNacionalidad,
							auxIdSeleccion);

					/*if (retornoEscrito == longitudEnBytes) {
					 retorno = 0;
					 } else {
					 printf(
					 "\nHUBO UN ERROR AL INTENTAR GUARDAR UN JUGADOR.");
					 }*/
				}
			}
		}
		fclose(pArchivo);
	}

	return retorno;
}

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoBinario(char *path,
		LinkedList *pArrayListJugador) {
	return 1;
}

/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_cargarSeleccionesDesdeTexto(char *path,
		LinkedList *pArrayListSeleccion) {
	int retorno;
	FILE *pArchivo;

	retorno = -1;

	if (path != NULL && pArrayListSeleccion != NULL) {
		pArchivo = fopen(path, "r");
		if (pArchivo != NULL) {
			parser_SeleccionFromText(pArchivo, pArrayListSeleccion);
			retorno = 0;
		} else {
			pArchivo = fopen(path, "w");
			if (pArchivo != NULL) {
				printf("\nEL ARCHIVO NO EXISTÍA Y FUE CREADO CORRECTAMENTE.");
			}
		}
		fclose(pArchivo);
	}

	return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_editarSeleccion(LinkedList *pArrayListSeleccion) {
	return 1;
}

/** \brief Listar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_listarSelecciones(LinkedList *pArrayListSeleccion) {
	int retorno;
	Seleccion *pSeleccion;
	int lenLL;
	int auxId;
	char auxPais[30];
	char auxConfederacion[30];
	int auxConvocados;

	lenLL = ll_len(pArrayListSeleccion);

	retorno = -1;
	if (pArrayListSeleccion != NULL && lenLL > 0) {
		printf("=====================================================\n");
		printf("|----------------LISTA COMPLETA DE SELECCIONES------|\n");
		printf("|---------------------------------------------------|\n");
		printf("| %-3s | %-14s | %-13s | %-10s |\n", "ID", "Pais",
				"Confederacion", "Convocados");
		printf("|---------------------------------------------------|\n");
		for (int i = 0; i < lenLL; i++) {
			pSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, i);
			selec_getId(pSeleccion, &auxId);
			selec_getPais(pSeleccion, auxPais);
			selec_getConfederacion(pSeleccion, auxConfederacion);
			selec_getConvocados(pSeleccion, &auxConvocados);

			printf("| %-3d | %-14s | %-13s | %-10d |\n", auxId, auxPais,
					auxConfederacion, auxConvocados);
		}
		retorno = 0;
	}

	return retorno;
}

/** \brief Ordenar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_ordenarSelecciones(LinkedList *pArrayListSeleccion) {
	return 1;
}

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarSeleccionesModoTexto(char *path,
		LinkedList *pArrayListSeleccion) {
	return 1;
}

int controller_cargarIdUnicoDesdeTexto(char *path, int *id) {
	int retorno;
	FILE *pArchivo;
	int retornoParser;
	int auxId;

	retorno = -1;

	if (path != NULL && id != NULL) {
		pArchivo = fopen(path, "r");
		if (pArchivo != NULL) {
			retornoParser = parser_IdUnicoFromText(pArchivo, &auxId);
			if (retornoParser == 0) {
				*id = auxId;
				retorno = 0;
			}
		} else {
			pArchivo = fopen(path, "w");
			if (pArchivo != NULL) {
				printf("\nEL ARCHIVO NO EXISTIA Y FUE CREADO CORRECTAMENTE.");
			}
		}
		fclose(pArchivo);
	}
	return retorno;
}

int controller_guardarIdUnicoModoTexto(char *path, int id) {
	int retorno;
	FILE *pArchivo;
	int retornoEscrito;

	retorno = -1;

	if (path != NULL && id >= 0) {
		pArchivo = fopen(path, "w");
		if (pArchivo != NULL) {
			retornoEscrito = fprintf(pArchivo, "%d", id);
			if (retornoEscrito == 1) {
				retorno = 0;
			}
		}
		fclose(pArchivo);
	}

	return retorno;
}
