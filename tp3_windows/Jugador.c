#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Jugador.h"
#include "inputs.h"
#include "Controller.h"
#include "Seleccion.h"

#define VACIO 0
#define LLENO 1

/// @fn Jugador jug_new*()
/// @brief Reserva espacio en memoria para un jugador
/// @return Retorna el puntero al espacio de memoria asignado o NULL si hubo algún problema
Jugador* jug_new() {
	Jugador *pJugadorRetorno = NULL;
	Jugador *auxPuntero = NULL;

	auxPuntero = (Jugador*) malloc(sizeof(Jugador));

	if (auxPuntero != NULL) {
		pJugadorRetorno = auxPuntero;
	}

	return pJugadorRetorno;
}

/// @fn Jugador jug_newParametros*(char*, char*, char*, char*, char*, char*)
/// @brief Reserva un espacio de memoria para un jugador y setea sus paramentros
/// @param idStr Array de caracteres con el ID del jugador
/// @param nombreCompletoStr Array de caracteres con el nombre completo del jugador
/// @param edadStr Array de caracteres con la edad del jugador
/// @param posicionStr Array de caracteres con la posicion del jugador
/// @param nacionalidadStr Array de caracteres con la nacionalidad del jugador
/// @param idSeleccionStr Array de caracteres con el ID de seleccion del jugador
/// @return
Jugador* jug_newParametros(char *idStr, char *nombreCompletoStr, char *edadStr,
		char *posicionStr, char *nacionalidadStr, char *idSeleccionStr) {
	Jugador *pJugadorRetorno = NULL;
	Jugador *auxPuntero = NULL;
	int contadorErrores;

	contadorErrores = 0;

	auxPuntero = (Jugador*) malloc(sizeof(Jugador));

	if (auxPuntero != NULL) {
		contadorErrores += jug_setId(auxPuntero, atoi(idStr));
		contadorErrores += jug_setNombreCompleto(auxPuntero, nombreCompletoStr);
		contadorErrores += jug_setEdad(auxPuntero, atoi(edadStr));
		contadorErrores += jug_setPosicion(auxPuntero, posicionStr);
		contadorErrores += jug_setNacionalidad(auxPuntero, nacionalidadStr);
		contadorErrores += jug_setIdSeleccion(auxPuntero, atoi(idSeleccionStr));
		if (contadorErrores == 0) {
			pJugadorRetorno = auxPuntero;
		}
	}

	return pJugadorRetorno;
}

/// @fn int jug_setId(Jugador*, int)
/// @brief Setea el campo id del jugador
/// @param this Puntero al elemento jugador
/// @param id Dato a setear
/// @return Retorna 0 si pudo setearlo y -1 si no pudo
int jug_setId(Jugador *this, int id) {
	int retorno;

	retorno = -1;

	if (this != NULL && id > 0) {
		this->id = id;
		retorno = 0;
	}

	return retorno;
}

/// @fn int jug_getId(Jugador*, int*)
/// @brief Obtiene el campo id del jugador y lo devuelve por parametro
/// @param this Puntero al elemento jugador
/// @param id Puntero a entero que contendra el dato
/// @return Retorna 0 si pudo obtener el dato y -1 si no pudo
int jug_getId(Jugador *this, int *id) {
	int retorno;

	retorno = -1;

	if (this != NULL && this->id > 0) {
		*id = this->id;
		retorno = 0;
	}

	return retorno;
}

/// @fn int jug_setNombreCompleto(Jugador*, char*)
/// @brief Setea el campo nombreCompleto del jugador
/// @param this Puntero al elemento jugador
/// @param char Dato a setear
/// @return Retorna 0 si pudo setearlo y -1 si no pudo
int jug_setNombreCompleto(Jugador *this, char *nombreCompleto) {
	int retorno;

	retorno = -1;

	if (this != NULL && strlen(nombreCompleto) > 0) {
		strcpy(this->nombreCompleto, nombreCompleto);
		retorno = 0;
	}

	return retorno;
}

/// @fn int jug_getNombreCompleto(Jugador*, char*)
/// @brief Obtiene el campo nombreCompleto del jugador y lo devuelve por parametro
/// @param this Puntero al elemento jugador
/// @param char Array de char que contendra el dato
/// @return Retorna 0 si pudo obtener el dato y -1 si no pudo
int jug_getNombreCompleto(Jugador *this, char *nombreCompleto) {
	int retorno;

	retorno = -1;

	if (this != NULL && strlen(this->nombreCompleto) > 0) {
		strcpy(nombreCompleto, this->nombreCompleto);
		retorno = 0;
	}

	return retorno;
}

/// @fn int jug_setPosicion(Jugador*, char*)
/// @brief Setea el campo posicion del jugador
/// @param this Puntero al elemento jugador
/// @param posicion Dato a setear
/// @return Retorna 0 si pudo setearlo y -1 si no pudo
int jug_setPosicion(Jugador *this, char *posicion) {
	int retorno;

	retorno = -1;

	if (this != NULL && strlen(posicion) > 0) {
		strcpy(this->posicion, posicion);
		retorno = 0;
	}

	return retorno;
}

/// @fn int jug_getPosicion(Jugador*, char*)
/// @brief Obtiene el campo posicion del jugador y lo devuelve por parametro
/// @param this Puntero al elemento jugador
/// @param posicion Array de char que contendra el dato
/// @return Retorna 0 si pudo obtener el dato y -1 si no pudo
int jug_getPosicion(Jugador *this, char *posicion) {
	int retorno;

	retorno = -1;

	if (this != NULL && strlen(this->posicion) > 0) {
		strcpy(posicion, this->posicion);
		retorno = 0;
	}

	return retorno;
}

/// @fn int jug_setNacionalidad(Jugador*, char*)
/// @brief Setea el campo nacionalidad del jugador
/// @param this Puntero al elemento jugador
/// @param nacionalidad Dato a setear
/// @return Retorna 0 si pudo setearlo y -1 si no pudo
int jug_setNacionalidad(Jugador *this, char *nacionalidad) {
	int retorno;

	retorno = -1;

	if (this != NULL && strlen(nacionalidad) > 0) {
		strcpy(this->nacionalidad, nacionalidad);
		retorno = 0;
	}

	return retorno;
}

/// @fn int jug_getNacionalidad(Jugador*, char*)
/// @brief Obtiene el campo nacionalidad del jugador y lo devuelve por parametro
/// @param this Puntero al elemento jugador
/// @param nacionalidad Array de char que contendra el dato
/// @return Retorna 0 si pudo obtener el dato y -1 si no pudo
int jug_getNacionalidad(Jugador *this, char *nacionalidad) {
	int retorno;

	retorno = -1;

	if (this != NULL && strlen(this->nacionalidad) > 0) {
		strcpy(nacionalidad, this->nacionalidad);
		retorno = 0;
	}

	return retorno;
}

/// @fn int jug_setEdad(Jugador*, int)
/// @brief Setea el campo edad del jugador
/// @param this Puntero al elemento jugador
/// @param edad Dato a setear
/// @return Retorna 0 si pudo setearlo y -1 si no pudo
int jug_setEdad(Jugador *this, int edad) {
	int retorno;

	retorno = -1;

	if (this != NULL && edad > 0) {
		this->edad = edad;
		retorno = 0;
	}

	return retorno;
}

/// @fn int jug_getEdad(Jugador*, int*)
/// @brief Obtiene el campo edad del jugador y lo devuelve por parametro
/// @param this Puntero al elemento jugador
/// @param edad Puntero a entero que contendra el dato
/// @return Retorna 0 si pudo obtener el dato y -1 si no pudo
int jug_getEdad(Jugador *this, int *edad) {
	int retorno;

	retorno = -1;

	if (this != NULL && this->edad > 0) {
		*edad = this->edad;
		retorno = 0;
	}

	return retorno;
}

/// @fn int jug_setIdSeleccion(Jugador*, int)
/// @brief Setea el campo idSeleccion del jugador
/// @param this Puntero al elemento jugador
/// @param idSeleccion Dato a setear
/// @return Retorna 0 si pudo setearlo y -1 si no pudo
int jug_setIdSeleccion(Jugador *this, int idSeleccion) {
	int retorno;

	retorno = -1;
	if (this != NULL && idSeleccion >= 0) {
		this->idSeleccion = idSeleccion;
		retorno = 0;
	}

	return retorno;
}

/// @fn int jug_getIdSeleccion(Jugador*, int*)
/// @brief Obtiene el campo idSeleccion del jugador y lo devuelve por parametro
/// @param this Puntero al elemento jugador
/// @param idSeleccion Puntero a entero que contendra el dato
/// @return Retorna 0 si pudo obtener el dato y -1 si no pudo
int jug_getIdSeleccion(Jugador *this, int *idSeleccion) {
	int retorno;

	retorno = -1;

	if (this != NULL && this->idSeleccion >= 0) {
		*idSeleccion = this->idSeleccion;
		retorno = 0;
	}

	return retorno;
}

/// @fn int jug_elegirNacionalidad(int, char*)
/// @brief Elige la nacionalidad del jugador segun el dato entero que se le pase por paramentro
/// @param paisElegido Entero que determinara la nacionalidad
/// @param nacionalidad Array de char que contendra la nacionaldad elegida
/// @return Retorna 0 si pudo obtener la nacionalidad y -1 si no pudo
int jug_elegirNacionalidad(int paisElegido, char *nacionalidad) {
	int retorno;

	retorno = -1;

	if (paisElegido >= 0) {
		switch (paisElegido) {
		case 0:
			strcpy(nacionalidad, "No convocado");
			break;

		case 1:
			strcpy(nacionalidad, "Aleman");
			break;

		case 2:
			strcpy(nacionalidad, "Arabe");
			break;

		case 3:
			strcpy(nacionalidad, "Argentino");
			break;

		case 4:
			strcpy(nacionalidad, "Australiano");
			break;

		case 5:
			strcpy(nacionalidad, "Belga");
			break;

		case 6:
			strcpy(nacionalidad, "Brasilero");
			break;

		case 7:
			strcpy(nacionalidad, "Camerunes");
			break;

		case 8:
			strcpy(nacionalidad, "Canadiense");
			break;

		case 9:
			strcpy(nacionalidad, "Coreano del Sur");
			break;

		case 10:
			strcpy(nacionalidad, "Costarricense");
			break;

		case 11:
			strcpy(nacionalidad, "Croata");
			break;

		case 12:
			strcpy(nacionalidad, "Danes");
			break;

		case 13:
			strcpy(nacionalidad, "Ecuatoriano");
			break;

		case 14:
			strcpy(nacionalidad, "Español");
			break;

		case 15:
			strcpy(nacionalidad, "Estados Unidense");
			break;

		case 16:
			strcpy(nacionalidad, "Frances");
			break;

		case 17:
			strcpy(nacionalidad, "Gales");
			break;

		case 18:
			strcpy(nacionalidad, "Ghanes");
			break;

		case 19:
			strcpy(nacionalidad, "Holandes");
			break;

		case 20:
			strcpy(nacionalidad, "Ingles");
			break;

		case 21:
			strcpy(nacionalidad, "Irani");
			break;

		case 22:
			strcpy(nacionalidad, "Japones");
			break;

		case 23:
			strcpy(nacionalidad, "Marroqui");
			break;

		case 24:
			strcpy(nacionalidad, "Mexicano");
			break;

		case 25:
			strcpy(nacionalidad, "Polaco");
			break;

		case 26:
			strcpy(nacionalidad, "Portugues");
			break;

		case 27:
			strcpy(nacionalidad, "Qatari");
			break;

		case 28:
			strcpy(nacionalidad, "Senegales");
			break;

		case 29:
			strcpy(nacionalidad, "Serbio");
			break;

		case 30:
			strcpy(nacionalidad, "Suizo");
			break;

		case 31:
			strcpy(nacionalidad, "Tunecino");
			break;

		case 32:
			strcpy(nacionalidad, "Uruguayo");
			break;
		}
		retorno = 0;
	}

	return retorno;
}

/// @fn int jug_elegirConvocatoria(int, char*)
/// @brief Segun el id de la seleccion, retorna por parametro el nombre del pais al que fue convocado
/// @param idSeleccion Entero que determinara el pais al que fue convocado el jugador
/// @param convocatoria Array de char que contendra el pais
/// @return Retorna 0 si pudo elegir un pais y -1 si no pudo
int jug_elegirConvocatoria(int idSeleccion, char *convocatoria) {
	int retorno;

	retorno = -1;

	if (idSeleccion >= 0) {
		switch (idSeleccion) {
		case 0:
			strcpy(convocatoria, "No convocado");
			break;

		case 1:
			strcpy(convocatoria, "Alemania");
			break;

		case 2:
			strcpy(convocatoria, "Arabia Saudita");
			break;

		case 3:
			strcpy(convocatoria, "Argentina");
			break;

		case 4:
			strcpy(convocatoria, "Australia");
			break;

		case 5:
			strcpy(convocatoria, "Belgica");
			break;

		case 6:
			strcpy(convocatoria, "Brasil");
			break;

		case 7:
			strcpy(convocatoria, "Camerun");
			break;

		case 8:
			strcpy(convocatoria, "Canada");
			break;

		case 9:
			strcpy(convocatoria, "Corea del Sur");
			break;

		case 10:
			strcpy(convocatoria, "Costa Rica");
			break;

		case 11:
			strcpy(convocatoria, "Croacia");
			break;

		case 12:
			strcpy(convocatoria, "Dinamarca");
			break;

		case 13:
			strcpy(convocatoria, "Ecuador");
			break;

		case 14:
			strcpy(convocatoria, "España");
			break;

		case 15:
			strcpy(convocatoria, "Estados Unidos");
			break;

		case 16:
			strcpy(convocatoria, "Francia");
			break;

		case 17:
			strcpy(convocatoria, "Gales");
			break;

		case 18:
			strcpy(convocatoria, "Ghana");
			break;

		case 19:
			strcpy(convocatoria, "Holanda");
			break;

		case 20:
			strcpy(convocatoria, "Inglaterra");
			break;

		case 21:
			strcpy(convocatoria, "Iran");
			break;

		case 22:
			strcpy(convocatoria, "Japon");
			break;

		case 23:
			strcpy(convocatoria, "Marruecos");
			break;

		case 24:
			strcpy(convocatoria, "Mexico");
			break;

		case 25:
			strcpy(convocatoria, "Polonia");
			break;

		case 26:
			strcpy(convocatoria, "Portugal");
			break;

		case 27:
			strcpy(convocatoria, "Qatar");
			break;

		case 28:
			strcpy(convocatoria, "Senegal");
			break;

		case 29:
			strcpy(convocatoria, "Serbia");
			break;

		case 30:
			strcpy(convocatoria, "Suiza");
			break;

		case 31:
			strcpy(convocatoria, "Tunez");
			break;

		case 32:
			strcpy(convocatoria, "Uruguay");
			break;
		}
		retorno = 0;
	}

	return retorno;
}

/// @fn int menuModificarJugador(Jugador*)
/// @brief Muestra el menu para modificar un campo a un jugador seleccionado por el usuario
/// @param jugadorElegido Puntero al elemento jugador a modificar
/// @return Retorna 0 si pudo modificarlo y -1 si no pudo
int menuModificarJugador(Jugador *jugadorElegido) {
	int retorno;
	int opcion;
	char auxNombre[100];
	int auxEdad;
	char auxPosicion[50];
	char auxNacionalidad[50];

	retorno = -1;

	utn_pedirNumero(&opcion, "\n1 - Nombre completo"
			"\n2 - Edad"
			"\n3 - Posicion"
			"\n4 - Nacionalidad"
			"\n5 - Volver"
			"\nQue desea modificar?: ", "ERROR. Opcion invalida.", 1, 5, 3);

	switch (opcion) {
	case 1:
		if (utn_pedirTexto(auxNombre,
				"Ingrese el nuevo nombre (maximo 100 caracteres: ",
				"ERROR. Nombre invalido.", 100, 3) == 0
				&& jug_setNombreCompleto(jugadorElegido, auxNombre) == 0) {
			retorno = 0;
		}
		break;

	case 2:
		if (utn_pedirNumero(&auxEdad, "Ingrese la nueva edad: ",
				"ERROR. Edad invalida.", 14, 65, 3) == 0
				&& jug_setEdad(jugadorElegido, auxEdad) == 0) {
			retorno = 0;
		}
		break;

	case 3:
		if (utn_pedirTexto(auxPosicion, "Ingrese la posicion: ",
				"ERROR. Posicion invalida.", 50, 3) == 0
				&& jug_setPosicion(jugadorElegido, auxPosicion) == 0) {
			retorno = 0;
		}
		break;

	case 4:
		if (utn_pedirTexto(auxNacionalidad, "Ingrese la nueva nacionalidad: ",
				"ERROR. nacionalidad invalida.", 50, 3) == 0
				&& jug_setNacionalidad(jugadorElegido, auxNacionalidad) == 0) {
			retorno = 0;
		}
		break;

	default:
		printf("\nVOLVIENDO AL MENU PRINCIPAL...\n");
		retorno = 0;
		break;

	}

	return retorno;
}

/// @fn Jugador jug_encontrarPorId*(LinkedList*, int)
/// @brief Encuentra a un elemento Jugador dentro de una LinkedList mediante el entero recibido por parametro
/// @param pArrayListJugador Puntero a la LinkedList que contiene los datos
/// @param id Entero que determinara el elemento a encontrar
/// @return Retorna un puntero a la estructura Jugador
Jugador* jug_encontrarPorId(LinkedList *pArrayListJugador, int id) {
	Jugador *retorno = NULL;
	Jugador *auxRetorno = NULL;
	int auxId;

	if (pArrayListJugador != NULL && id > 0) {
		for (int i = 0; i < ll_len(pArrayListJugador); i++) {
			auxRetorno = (Jugador*) ll_get(pArrayListJugador, i);
			jug_getId(auxRetorno, &auxId);
			if (auxId == id) {
				retorno = auxRetorno;
				break;
			}
		}
	}

	return retorno;
}

/// @fn int jug_eliminarJugador(LinkedList*, Jugador*)
/// @brief Elimina un jugador dentro de la LinkedList
/// @param pArrayListJugador Puntero a la LinkedList que contiene los datos
/// @param pJugador Puntero al elemento a eliminar
/// @return Retorna 0 si pudo eliminarlo y -1 si no pudo
int jug_eliminarJugador(LinkedList *pArrayListJugador, Jugador *pJugador) {
	int retorno;
	Jugador *pAuxJugador;

	retorno = -1;

	if (pArrayListJugador != NULL && pJugador != NULL) {
		for (int i = 0; i < ll_len(pArrayListJugador); i++) {
			pAuxJugador = (Jugador*) ll_get(pArrayListJugador, i);
			if (pAuxJugador == pJugador) {
				if (ll_remove(pArrayListJugador, i) == 0) {
					retorno = 0;
				}
				break;
			}
		}
	}

	return retorno;
}

/// @fn int hayConvocados(LinkedList*)
/// @brief Recorre una LinkedList para saber si hay jugadores convocados
/// @param pArrayListJugador Puntero a la LinkedList que contiene los datos
/// @return Retorna 0 si hay jugadores convocados y -1 si no los hay
int hayConvocados(LinkedList *pArrayListJugador) {
	int retorno;
	Jugador *auxJugador;
	int auxConvocatoria;

	retorno = -1;

	if (pArrayListJugador != NULL) {
		for (int i = 0; i < ll_len(pArrayListJugador); i++) {
			auxJugador = ll_get(pArrayListJugador, i);
			if (auxJugador != NULL
					&& jug_getIdSeleccion(auxJugador, &auxConvocatoria) == 0) {
				if (auxConvocatoria != 0) {
					retorno = 0;
					break;
				}
			}
		}
	}

	return retorno;
}

/// @fn int jug_convocarJugador(LinkedList*, LinkedList*)
/// @brief Muestra el menu para convocar a un jugador
/// @param pArrayListJugador Puntero a la LinkedList de jugadores
/// @param pArrayListSeleccion Puntero a la LinkedList de selecciones
/// @return Retorna 0 si pudo convocarlo y -1 si no pudo
int jug_convocarJugador(LinkedList *pArrayListJugador,
		LinkedList *pArrayListSeleccion) {
	int retorno;
	int idJugador;
	int cantidadConvocados;
	int auxId;
	Seleccion *auxSeleccion = NULL;
	Jugador *auxJugador = NULL;

	retorno = -1;

	if (pArrayListJugador != NULL && pArrayListSeleccion != NULL) {
		controller_listarJugadores(pArrayListJugador);
		if (utn_pedirNumero(&idJugador,
				"Ingrese el ID del jugador que quiere convocar: ",
				"ERROR. ID invalido", 1, 1000000, 3) == 0) {
			if ((auxJugador = jug_encontrarPorId(pArrayListJugador, idJugador))
					!= NULL) {
				if (controller_ordenarSeleccionPorPais(pArrayListSeleccion)
						== 0&& controller_listarSelecciones(pArrayListSeleccion)
						== 0&& utn_pedirNumero(&auxId,
								"Ingrese el ID de la seleccion a la que quiere convocar al jugador: ",
								"ERROR. ID invalido", 1, 32, 3) == 0 && (auxSeleccion=selec_encontrarPorId(pArrayListSeleccion, auxId)) != NULL) {
					if (selec_getConvocados(auxSeleccion, &cantidadConvocados)
							>= 0 && cantidadConvocados < 26) {
						cantidadConvocados++;
						if (selec_setConvocados(auxSeleccion,
								cantidadConvocados) == 0
								&& jug_setIdSeleccion(auxJugador, auxId) == 0) {
							retorno = 0;
						}
					} else {
						printf(
								"\nLA SELECCION YA TIENE 26 JUGADORES CONVOCADOS\n");
					}
				}
			} else {
				printf(
						"\nEL JUGADOR CON ESE ID NO EXISTE\nVOLVIENDO AL MENU PRINCIPAL...\n");
			}
		}

		retorno = 0;
	}

	return retorno;
}

/// @fn int jug_quitarDeConvocatoria(LinkedList*, LinkedList*)
/// @brief Quita de la convocatoria a un jugador, volviendo a poner el campo idSeleccion en 0 y restando uno al campo convocados de la seleccion
/// @param pArrayListJugador Puntero a la LinkedList de jugadores
/// @param pArrayListSeleccion Puntero a la LinkedList de selecciones
/// @return
int jug_quitarDeConvocatoria(LinkedList *pArrayListJugador,
		LinkedList *pArrayListSeleccion) {
	int retorno;
	int idJugador;
	Jugador *auxJugador;
	int idSeleccion;
	Seleccion *auxSeleccion;
	int convocados;

	retorno = -1;

	if (pArrayListJugador != NULL && pArrayListSeleccion != NULL) {
		controller_listarJugadores(pArrayListJugador);
		if (utn_pedirNumero(&idJugador,
				"Ingrese el ID del jugador que quiere quitar de la convocatoria: ",
				"ERROR. ID invalido", 1, 1000000, 3) == 0) {
			if ((auxJugador = jug_encontrarPorId(pArrayListJugador, idJugador))
					!= NULL) {
				if (jug_getIdSeleccion(auxJugador, &idSeleccion) == 0
						&& jug_setIdSeleccion(auxJugador, 0) == 0
						&& (auxSeleccion = selec_encontrarPorId(
								pArrayListSeleccion, idSeleccion)) != NULL
						&& selec_getConvocados(auxSeleccion, &convocados)
								== 0) {
					convocados--;
					if (selec_setConvocados(auxSeleccion, convocados) == 0) {
						retorno = 0;
					}
				}
			} else {
				printf(
						"\nEL JUGADOR CON ESE ID NO EXISTE\nVOLVIENDO AL MENU PRINCIPAL...\n");
			}
		}
	}

	return retorno;
}

/// @fn int jug_ordenarPorNacionalidad(void*, void*)
/// @brief Verifica si el nombre de la nacionalidad de un jugador es mayor que otro segun strcmp
/// @param jugador1 Puntero a void que contendra el primer elemento
/// @param jugador2 Puntero a void que contendra el segundo elemento
/// @return Retorna el resultado de strcmp
int jug_ordenarPorNacionalidad(void *jugador1, void *jugador2) {
	int retorno;
	char nacionalidad1[50];
	char nacionalidad2[50];

	if (jugador1 != NULL && jugador2 != NULL) {
		if (jug_getNacionalidad(jugador1, nacionalidad1) == 0
				&& jug_getNacionalidad(jugador2, nacionalidad2) == 0) {
			retorno = strcmp(nacionalidad1, nacionalidad2);
		}
	}

	return retorno;
}

/// @fn int jug_ordenarPorEdad(void*, void*)
/// @brief Compara el dato contenido en el campo edad de dos estructuras de jugadores
/// @param jugador1 Puntero a void que contendra el primer elemento
/// @param jugador2 Puntero a void que contendra el segundo elemento
/// @return Retorna 0 si el primer elemento es menor en edad que el segundo y 1 si es al reves
int jug_ordenarPorEdad(void *jugador1, void *jugador2) {
	int retorno;
	int edad1;
	int edad2;

	if (jugador1 != NULL && jugador2 != NULL) {
		if (jug_getEdad(jugador1, &edad1) == 0
				&& jug_getEdad(jugador2, &edad2) == 0) {
			if (edad1 <= edad2) {
				retorno = 0;
			} else if (edad1 > edad2) {
				retorno = 1;
			}
		}
	}

	return retorno;
}

/// @fn int jug_ordenarPorNombre(void*, void*)
/// @brief Verifica si el nombre de un jugador es mayor que otro segun strcmp
/// @param jugador1 Puntero a void que contendra el primer elemento
/// @param jugador2 Puntero a void que contendra el segundo elemento
/// @return Retorna el resultado de strcmp
int jug_ordenarPorNombre(void *jugador1, void *jugador2) {
	int retorno;
	char nombre1[50];
	char nombre2[50];

	if (jugador1 != NULL && jugador2 != NULL) {
		if (jug_getNombreCompleto(jugador1, nombre1) == 0
				&& jug_getNombreCompleto(jugador2, nombre2) == 0) {
			retorno = strcmp(nombre1, nombre2);
		}
	}

	return retorno;
}

/// @fn int jug_estaConvocado(void*)
/// @brief Verifica si un jugador esta convocado segun el campo idSeleccion
/// @param jugador Puntero a void que contiene el elemento a verificar
/// @return Retorna 0 si esta convocado y -1 si no lo esta
int jug_estaConvocado(void *jugador) {
	int retorno;
	int idSeleccion;

	retorno = -1;

	if (jugador != NULL) {
		if (jug_getIdSeleccion(jugador, &idSeleccion) == 0) {
			if (idSeleccion != 0) {
				retorno = 0;
			}
		}
	}

	return retorno;
}

/// @fn int jug_ordenarPorId(void*, void*)
/// @brief Compara el dato contenido en el campo id de dos estructuras de jugadores
/// @param jugador1 Puntero a void que contendra el primer elemento
/// @param jugador2 Puntero a void que contendra el segundo elemento
/// @return Retorna 0 si el primer elemento es menor en id que el segundo y 1 si es al reves
int jug_ordenarPorId(void *jugador1, void *jugador2) {
	int retorno;
	int id1;
	int id2;

	if (jugador1 != NULL && jugador2 != NULL) {
		if (jug_getId(jugador1, &id1) == 0 && jug_getId(jugador2, &id2) == 0) {
			if (id1 < id2) {
				retorno = 0;
			} else {
				retorno = 1;
			}
		}
	}

	return retorno;
}
