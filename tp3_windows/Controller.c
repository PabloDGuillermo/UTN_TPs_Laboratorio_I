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
 * \param path char* Nombre del archivo a cargar
 * \param pArrayListJugador LinkedList* Puntero a la LinkedList donde se guardaran los datos
 * \return int Retorna 0 si pudo cargar los archivos y -1 si no pudo
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
 * \param path char* Nombre del archivo a cargar
 * \param pArrayListJugador LinkedList* Puntero a la LinkedList donde se guardaran los datos
 * \return int Retorna 0 si pudo cargar los archivos y -1 si no pudo
 *
 */
int controller_cargarJugadoresDesdeBinario(char *path,
		LinkedList *pArrayListJugador) {
	int retorno;
	FILE *pArchivo;

	retorno = -1;

	if (path != NULL && pArrayListJugador != NULL) {
		pArchivo = fopen(path, "rb");
		if (pArchivo != NULL) {
			if (parser_JugadorFromBinary(pArchivo, pArrayListJugador) == 0) {
				printf(
						"\nEL ARCHIVO BINARIO DE JUGADORES SE LEYO CORRECTAMENTE\n");
				retorno = 0;
			} else {
				printf(
						"\nHUBO UN ERROR AL LEER EL ARCHIVO BINARIO DE JUGADORES\n");
			}
		} else {
			pArchivo = fopen(path, "wb");
			if (pArchivo != NULL) {
				printf(
						"\nEL ARCHIVO BINARIO DE JUGADORES NO EXISTIA Y SE CREO CORRECTAMENTE\n");
				retorno = 1;
			}
		}
		fclose(pArchivo);
	}

	return retorno;
}

/** \brief Alta de jugadores Da de alta a un jugador
 *
 * \param pArrayListJugador LinkedList* Puntero a la LinkedList donde se agregara el jugador al final
 * \return int Retorna 0 si pudo agregar al jugador y -1 si no pudo
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
	Jugador *pNuevoJugador = jug_new();

	retorno = -1;

	if (pNuevoJugador != NULL) {
		printf("\n-------AGREGANDO JUGADOR-------\n");

		controller_cargarIdUnicoDesdeTexto("ID_Unico.csv", &auxId);
		auxId++;

		if (utn_pedirTexto(auxNombreCompleto,
				"Ingrese el nombre completo (max 100 caracteres): ",
				"ERROR. Nombre invalido.", 100, 3) == 0
				&& utn_pedirNumero(&auxEdad, "Ingrese la edad: ",
						"ERROR. Edad invalida.", 14, 40, 3) == 0
				&& utn_pedirTexto(auxPosicion, "Ingrese la posicion: ",
						"ERROR. Posicion invalida.", 50, 3) == 0
				&& utn_pedirNumero(&auxNacionalidadInt, "\n1 - Aleman"
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
						"\nIngrese la nacionalidad: ",
						"ERROR. Nacionalidad invalida", 1, 32, 3) == 0) {
			jug_elegirNacionalidad(auxNacionalidadInt, auxNacionalidad);
			auxIdSeleccion = 0;
			if (jug_setId(pNuevoJugador, auxId) == 0
					&& jug_setNombreCompleto(pNuevoJugador, auxNombreCompleto)
							== 0 && jug_setEdad(pNuevoJugador, auxEdad) == 0
					&& jug_setPosicion(pNuevoJugador, auxPosicion) == 0
					&& jug_setNacionalidad(pNuevoJugador, auxNacionalidad) == 0
					&& jug_setIdSeleccion(pNuevoJugador, auxIdSeleccion) == 0) {
				if (ll_add(pArrayListJugador, pNuevoJugador) == 0) {
					controller_guardarIdUnicoModoTexto("ID_Unico.csv", auxId);
					retorno = 0;
				}
			}
		}
	}

	return retorno;
}

/** \brief Modificar datos del jugador Edita un dato de un jugador seleccionado por el usuario
 *
 * \param pArrayListJugador LinkedList* Puntero a la LinkedList donde se encuentra el jugador a editar
 * \return int Retorna 0 si pudo editar al jugador y -1 si no pudo
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

/** \brief Baja del jugador Elimina a un jugador de la LinkedList seleccionado por el usuario
 *
 * \param pArrayListJugador LinkedList* Puntero a la LinkedList que contiene el jugador a eliminar
 * \return int Retorna 0 si pudo eliminarlo y -1 si no pudo
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

/** \brief Listar jugadores Imprime por pantalla una lista de todos los jugadores
 *
 * \param pArrayListJugador LinkedList* Puntero a la LinkedList donde estan los datos de los jugadores
 * \return int Retorna 0 si pudo imprimir y -1 si no pudo
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

/// @fn int controller_listarJugadoresConvocados(LinkedList*)
/// @brief Imprime por pantalla una lista de los jugadores convocados
/// @param pArrayListJugador Puntero a la LinkedList que contiene los datos de los jugadores
/// @return Retorna 0 si pudo imprimir y -1 si no pudo
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
			if (jug_estaConvocado(pJugador) == 0) {

				if (jug_getId(pJugador, &auxId) == 0
						&& jug_getNombreCompleto(pJugador, auxNombre) == 0
						&& jug_getEdad(pJugador, &auxEdad) == 0
						&& jug_getPosicion(pJugador, auxPosicion) == 0
						&& jug_getNacionalidad(pJugador, auxNacionalidad) == 0
						&& jug_getIdSeleccion(pJugador, &auxIdSeleccion) == 0
						&& jug_elegirConvocatoria(auxIdSeleccion,
								auxConvocatoria) == 0) {
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

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char* Nombre del archivo donde se guardaran los datos
 * \param pArrayListSeleccion LinkedList* Puntero a la LinkedList que contiene los datos de los jugadores
 * \return int Retorna 0 si pudo guardar el archivo y -1 si no pudo
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
			fprintf(pArchivo, "%s",
					"id,nombreCompleto,edad,posicion,nacionalidad,idSelecion");
			for (int i = 0; i < ll_len(pArrayListJugador); i++) {
				auxJugador = (Jugador*) ll_get(pArrayListJugador, i);

				if (jug_getId(auxJugador, &auxId) == 0
						&& jug_getNombreCompleto(auxJugador, auxNombre) == 0
						&& jug_getEdad(auxJugador, &auxEdad) == 0
						&& jug_getPosicion(auxJugador, auxPosicion) == 0
						&& jug_getNacionalidad(auxJugador, auxNacionalidad) == 0
						&& jug_getIdSeleccion(auxJugador, &auxIdSeleccion)
								== 0) {

					if (fprintf(pArchivo, "%d,%s,%d,%s,%s,%d\n", auxId,
							auxNombre, auxEdad, auxPosicion, auxNacionalidad,
							auxIdSeleccion) > 0) {
						retorno = 0;
					} else {
						printf(
								"\nHUBO UN ERROR AL INTENTAR GUARDAR UN JUGADOR.");
					}
				}
			}
		}
		fclose(pArchivo);
	}

	return retorno;
}

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char* Nombre del archivo binario donde se guardaran los datos
 * \param pArrayListJugador LinkedList* Puntero a la LinkedList que contiene los datos de los jugadores
 * \return int Retorna 0 si pudo guardar el archivo binario y -1 si no pudo
 *
 */
int controller_guardarJugadoresModoBinario(char *path,
		LinkedList *pArrayListJugador) {
	int retorno;
	FILE *pArchivo = NULL;
	Jugador *auxJugador = NULL;

	retorno = -1;

	if (path != NULL && pArrayListJugador != NULL) {
		pArchivo = fopen(path, "wb");
		if (pArchivo != NULL) {
			for (int i = 0; i < ll_len(pArrayListJugador); i++) {
				auxJugador = ll_get(pArrayListJugador, i);
				if (auxJugador != NULL) {
					if (fwrite(auxJugador, sizeof(Jugador), 1, pArchivo) == 1) {
						retorno = 0;
					} else {
						printf("\nHUBO UN PROBLEMA AL ESCRIBIR EL ARCHIVO\n");
						break;
					}
				}
			}
		}
		fclose(pArchivo);
	}

	return retorno;
}

/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char* Nombre del archivo a cargar
 * \param pArrayListSeleccion LinkedList* Puntero a la LinkedList donde se guardaran los datos
 * \return int Retorna 0 si pudo cargar el archivo y -1 si no pudo
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

/** \brief Modificar datos de seleccion Edita los datos de una seleccion seleccionada por el usuario
 *
 * \param pArrayListSeleccion LinkedList* Puntero a la LinkedList que contiene la seleccion a editar
 * \return int Retorna 0 si pudo modificarla y -1 si no pudo
 *
 */
int controller_editarSeleccion(LinkedList *pArrayListSeleccion) {
	int retorno;
	int idElegido;
	Seleccion *seleccion;

	retorno = -1;

	if (pArrayListSeleccion != NULL) {
		printf("\n------DAR DE BAJA A UN JUGADOR------\n");
		if (controller_listarSelecciones(pArrayListSeleccion) == 0) {
			utn_pedirNumero(&idElegido,
					"Elija el ID de la seleccion que quiere modificar: ",
					"ERROR. ID invalido.", 1, 32, 3);

			seleccion = selec_encontrarPorId(pArrayListSeleccion, idElegido);

			if (seleccion != NULL) {
				if (menuModificarSeleccion(seleccion) == 0) {
					retorno = 0;
				} else {
					printf("\nLA SELECCOIN CON ESE ID NO EXISTE");
				}
			}
		}
	}

	return retorno;
}

/** \brief Listar selecciones Imprime por pantalla una lista de todas las selecciones
 *
 * \param pArrayListSeleccion LinkedList* Puntero a la LinkedList que contiene los datos de las selecciones
 * \return int Retorna 0 si pudo imprimir y -1 si no pudo
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

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char* Nombre del archivo donde se guardaran los datos
 * \param pArrayListSeleccion LinkedList* Puntero a la LinkedList que contiene los datos
 * \return int Retorna 0 si pudo guardar y .1 si no pudo
 *
 */
int controller_guardarSeleccionesModoTexto(char *path,
		LinkedList *pArrayListSeleccion) {
	int retorno;
	FILE *pArchivo;
	Seleccion *auxSeleccion;
	int auxId;
	char auxPais[100];
	char auxConfederacion[30];
	int auxConvocados;

	retorno = -1;

	if (path != NULL && pArrayListSeleccion != NULL) {
		pArchivo = fopen(path, "w");
		if (pArchivo != NULL) {
			fprintf(pArchivo, "%s", "id,pais,confederacion,convocados");
			for (int i = 0; i < ll_len(pArrayListSeleccion); i++) {
				auxSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, i);

				/*if (selec_getId(auxSeleccion, &auxId) == 0
				 && selec_getPais(auxSeleccion, auxPais) == 0
				 && selec_getConfederacion(auxSeleccion,
				 &auxConfederacion) == 0
				 && selec_getConvocados(auxSeleccion, &auxConvocados)
				 == 0) {*/

				if (fprintf(pArchivo, "%d,%s,%s,%d\n", auxId, auxPais,
						auxConfederacion, auxConvocados) > 0) {
					retorno = 0;
				} else {
					printf("\nHUBO UN ERROR AL INTENTAR GUARDAR UN JUGADOR.");
				}
				//}
			}
		}
		fclose(pArchivo);
	}

	return retorno;
}

/// @fn int controller_cargarIdUnicoDesdeTexto(char*, int*)
/// @brief Carga el ID Unico desde un archivo de texto
/// @param path Nombre del archivo a cargar
/// @param id Puntero a entero que guardara el ID
/// @return Retorna 0 si pudo cargarlo y -1 si no pudo
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

/// @fn int controller_guardarIdUnicoModoTexto(char*, int)
/// @brief Guarda el ID Unico en un archivo de texto
/// @param path Nombre del archivo donde se guardara la informacion
/// @param id Entero que se guardara en el archivo
/// @return Retorna 0 si pudo guardarlo y -1 si no pudo
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

/// @fn int controller_ordenarSeleccionPorPais(LinkedList*)
/// @brief Ordena la LinkedList de selecciones de acuerdo al nombre del pais
/// @param pArrayListSeleccion Puntero a la LinkedList donde estan los datos a ordenar
/// @return Retorna 0 si pudo ordenar y -1 si no pudo
int controller_ordenarSeleccionPorPais(LinkedList *pArrayListSeleccion) {
	int retorno;

	retorno = -1;

	if (pArrayListSeleccion != NULL) {
		if (ll_sort(pArrayListSeleccion, selec_ordenarPorPais, 1) == 0) {
			retorno = 0;
		}
	}

	return retorno;
}

/// @fn int controller_ordenarJugadorPorNacionalidad(LinkedList*)
/// @brief Ordena la LinkedList de jugadores de acuerdo al nombre de la nacionalidad del jugador
/// @param pArrayListJugador Puntero a la LinkedList de jugadores a ordenar
/// @return Retorna 0 si pudo ordenar y -1 si no pudo
int controller_ordenarJugadorPorNacionalidad(LinkedList *pArrayListJugador) {
	int retorno;

	retorno = -1;

	if (pArrayListJugador != NULL) {
		if (ll_sort(pArrayListJugador, jug_ordenarPorNacionalidad, 1) == 0) {
			retorno = 0;
		}
	}

	return retorno;
}

/// @fn int controller_ordenarSeleccionPorConfederacion(LinkedList*)
/// @brief Ordena la LinkedList de selecciones de acuerdo al nombre de la confederacion
/// @param pArrayListSeleccion Puntero a la LinkedList donde estan los datos a ordenar
/// @return Retorna 0 si pudo ordenar y -1 si no pudo
int controller_ordenarSeleccionPorConfederacion(LinkedList *pArrayListSeleccion) {
	int retorno;

	retorno = -1;

	if (pArrayListSeleccion != NULL) {
		if (ll_sort(pArrayListSeleccion, selec_ordenarPorConfederacion, 1)
				== 0) {
			retorno = 0;
		}
	}

	return retorno;
}

/// @fn int controller_ordenarJugadorPorEdad(LinkedList*)
/// @brief Ordena la LinkedList de jugadores de acuerdo a la edad del jugador
/// @param pArrayListJugador Puntero a la LinkedList de jugadores a ordenar
/// @return Retorna 0 si pudo ordenar y -1 si no pudo
int controller_ordenarJugadorPorEdad(LinkedList *pArrayListJugador) {
	int retorno;

	retorno = -1;

	if (pArrayListJugador != NULL) {
		if (ll_sort(pArrayListJugador, jug_ordenarPorEdad, 1) == 0) {
			retorno = 0;
		}
	}

	return retorno;
}

/// @fn int controller_ordenarJugadorPorNombre(LinkedList*)
/// @brief Ordena la LinkedList de jugadores de acuerdo al nombre del jugador
/// @param pArrayListJugador Puntero a la LinkedList de jugadores a ordenar
/// @return Retorna 0 si pudo ordenar y -1 si no pudo
int controller_ordenarJugadorPorNombre(LinkedList *pArrayListJugador) {
	int retorno;

	retorno = -1;

	if (pArrayListJugador != NULL) {
		if (ll_sort(pArrayListJugador, jug_ordenarPorNombre, 1) == 0) {
			retorno = 0;
		}
	}

	return retorno;
}

/// @fn int controller_ordenarJugadorPorId(LinkedList*)
/// @brief Ordena la LinkedList de jugadores de acuerdo al ID del jugador
/// @param pArrayListJugador Puntero a la LinkedList de jugadores a ordenar
/// @return Retorna 0 si pudo ordenar y -1 si no pudo
int controller_ordenarJugadorPorId(LinkedList *pArrayListJugador) {
	int retorno;

	retorno = -1;

	if (pArrayListJugador != NULL) {
		if (ll_sort(pArrayListJugador, jug_ordenarPorId, 1) == 0) {
			retorno = 0;
		}
	}

	return retorno;
}
