/*
 * eConfederacion.c
 *
 *  Created on: 26 oct. 2022
 *      Author: pablo
 */

#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
#include "eConfederacion.h"
#include <string.h>
#include "eJugador.h"
#include "outputs.h"

#define VACIO 0
#define LLENO 1

/// @fn int inicializarArrayConfederacion(eConfederacion*, int)
/// @brief Inicializa el array de confederacion con el campo isEmpty en VACIO(0)
/// @param aConfederacion Array de confederaciones
/// @param longitud_aConfederacion Entero que contiene la longitud del array de la confederacion
/// @return Retorna 0 si pudo ser inicializado y -1 si no
int inicializarArrayConfederacion(eConfederacion aConfederacion[],
		int longitud_aConfederacion) {
	int retorno;

	retorno = -1;

	if (aConfederacion != NULL && longitud_aConfederacion > 0) {
		for (int i = 0; i < longitud_aConfederacion; i++) {
			aConfederacion[i].isEmpty = VACIO;
		}
		retorno = 0;
	}

	return retorno;
}

/// @fn int buscarIndiceVacioConfederacion(eConfederacion*, int)
/// @brief Busca el indice en donde una de las estructuras tiene el campo isEmpty en VACIO(0)
/// @param aConfederacion Array de confederaciones
/// @param longitud_aConfederacion Entero que contiene la longitud del array de la confederacion
/// @return Rertona el indice en el que el campo isEmpty esta en VACIO(0) o -1 si no hay ninguno
int buscarIndiceVacioConfederacion(eConfederacion aConfederacion[],
		int longitud_aConfederacion) {
	int indice;

	indice=-1;

	for (int i = 0; i < longitud_aConfederacion; i++) {
		if (aConfederacion[i].isEmpty == VACIO) {
			indice = i;
			break;
		}
	}

	return indice;
}

/// @fn int asignarIdConfederacion(eConfederacion*, int)
/// @brief Le asigna un ID unico a la confederacion que queremos dar de alta
/// @param aConfederacion Array de confederaciones
/// @param longitud_aConfederacion Entero que contiene la longitud del array de la confederacion
/// @return Rertona el ID a asignar
int asignarIdConfederacion(eConfederacion aConfederacion[],
		int longitud_aConfederacion) {
	static int id = 99;

	if (aConfederacion != NULL && longitud_aConfederacion > 0) {
		id++;
	}

	return id;
}

/// @fn int buscarConfederacionPorId(eConfederacion*, int)
/// @brief Busca el indice en el que se encuentra la estructura que buscamos por el ID que pasamos por parametro
/// @param aConfederacion Array de confederaciones
/// @param longitud_aConfederacion Entero que contiene la longitud del array de la confederacion
/// @param id Entero que tiene el dato del ID que estamos buscando
/// @param index Puntero a entero que retornara por parametro el indice que estamos buscando
/// @return Rertona 0 si pudo encontrarlo y -1 si no pudo
int buscarConfederacionPorId(eConfederacion aConfederacion[],
		int longitud_aConfederacion, int id, int *index) {
	int retorno;

	retorno = -1;

	if (aConfederacion != NULL
			&& longitud_aConfederacion > 0&& id>0 && index!=NULL) {
		for (int i = 0; i < longitud_aConfederacion; i++) {
			if (aConfederacion[i].id == id) {
				*index = i;
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

int pedirNombreConfederacion(eConfederacion *unaConfederacion) {
	int retorno;
	char bufferNombre[50];

	retorno = -1;

	if (unaConfederacion != NULL) {
		if (utn_pedirTexto(bufferNombre,
				"Ingrese el nombre de la confederacion (max 50 caracteres): ",
				"ERROR. Nombre invalido. Intente nuevamente.", 50, 3) == 0) {
			strcpy(unaConfederacion->nombre, bufferNombre);
			retorno = 0;
		} else {
			printf("\nSIN REINTENTOS\nVOLVIENDO AL MENU PRINCIPAL...");
		}
	}

	return retorno;
}

int pedirRegionConfederacion(eConfederacion *unaConfederacion) {
	int retorno;
	char bufferRegion[50];

	retorno = -1;
	if (unaConfederacion != NULL) {
		if (utn_pedirTexto(bufferRegion,
				"Ingrese la region (max 50 caracteres): ",
				"ERROR. Region invalida. Intente nuevamente.", 50, 3) == 0) {
			strcpy(unaConfederacion->region, bufferRegion);
			retorno = 0;
		} else {
			printf("\nSIN REINTENTOS\nVOLVIENDO AL MENU PRINCIPAL...");
		}
	}

	return retorno;
}

int pedirAnioCreacionConfederacion(eConfederacion *unaConfederacion) {
	int retorno;
	int bufferAnioCreacion;

	retorno = -1;

	if (unaConfederacion != NULL) {

		if (utn_pedirNumero(&bufferAnioCreacion, "Ingrese el año de creación: ",
				"ERROR. Año de creacion invalido", 1900, 2022, 3) == 0) {
			unaConfederacion->anioCreacion = bufferAnioCreacion;
			retorno = 0;
		} else {
			printf("\nSIN REINTENTOS\nVOLVIENDO AL MENU PRINCIPAL...");
		}
	}

	return retorno;
}

int altaConfederacion(eConfederacion aConfederacion[],
		int longitud_aConfederacion) {
	int retorno;
	eConfederacion bufferConfederacion;
	int indice;

	retorno = -1;

	if (aConfederacion != NULL && longitud_aConfederacion > 0) {
		indice = buscarIndiceVacioConfederacion(aConfederacion,
				longitud_aConfederacion);
		if (indice >= 0) {
			bufferConfederacion.id = asignarIdConfederacion(aConfederacion,
					longitud_aConfederacion);
			if (pedirNombreConfederacion(&bufferConfederacion) == 0
					&& pedirRegionConfederacion(&bufferConfederacion) == 0
					&& pedirAnioCreacionConfederacion(&bufferConfederacion)
							== 0) {
				aConfederacion[indice].id = bufferConfederacion.id;
				strcpy(aConfederacion[indice].nombre,
						bufferConfederacion.nombre);
				strcpy(aConfederacion[indice].region,
						bufferConfederacion.region);
				aConfederacion[indice].anioCreacion =
						bufferConfederacion.anioCreacion;
				aConfederacion[indice].isEmpty = LLENO;
				retorno = 0;
			}
		}
	}

	return retorno;
}

int darBajaConfederacion(eConfederacion aConfederacion[],
		int longitud_aConfederacion, int index) {
	int retorno;

	retorno = -1;

	if (aConfederacion != NULL && longitud_aConfederacion > 0 && index >= 0) {

		aConfederacion[index].isEmpty = VACIO;
		retorno = 0;

	}

	return retorno;
}

int menuDarBajaConfederacion(eConfederacion aConfederacion[],
		int longitud_aConfederacion) {
	int retorno;
	int idElegido;
	int index;

	retorno = -1;

	if (aConfederacion != NULL && longitud_aConfederacion > 0) {
		if (mostrarDatosIngresadosConfederacion(aConfederacion,
				longitud_aConfederacion) == 0
				&& utn_pedirNumero(&idElegido,
						"Elija el ID de la confederacion a dar de baja: ",
						"ERROR. ID invalido.", 0, 6, 3)) {
			if (buscarConfederacionPorId(aConfederacion,
					longitud_aConfederacion, idElegido, &index) == 0) {
				if (darBajaConfederacion(aConfederacion,
						longitud_aConfederacion, idElegido) == 0) {
					retorno = 0;
				}
			} else {
				printf("\nLA CONFEDERACION CON ESE ID NO EXISTE\n");
			}
		} else {
			printf("\nSIN REINTENTOS\nVOLVIENDO AL MENU PRINCIPAL...");
		}
	}

	return retorno;
}

int menuModificarConfederacion(eConfederacion aConfederacion[],
		int longitud_aConfederacion) {
	int retorno;
	int idElegido;
	int index;

	retorno = -1;

	if (mostrarDatosIngresadosConfederacion(aConfederacion,
			longitud_aConfederacion) == 0
			&& utn_pedirNumero(&idElegido,
					"Elija el ID de la confederacion que quiere modificar: ",
					"ERROR. ID invalido", 100, longitud_aConfederacion, 3)
					== 0) {
		if (buscarConfederacionPorId(aConfederacion, longitud_aConfederacion,
				idElegido, &index) == 0) {
			if (modificarConfederacion(aConfederacion, longitud_aConfederacion,
					index) == 0) {
				retorno = 0;
			}
		} else {
			printf("\nLA CONFEDERACION CON ESE ID NO EXISTE\n");
		}
	} else {
		printf("\nSIN REINTENTOS\nVOLVIENDO AL MENU PRINCIPAL...");
	}

	return retorno;
}

int modificarConfederacion(eConfederacion aConfederacion[],
		int longitud_aConfederacion, int index) {
	int retorno;
	int opcionElegida;
	eConfederacion bufferConfederacion;
	char mensaje[1024] = { "1 - Modificar nombre\n"
			"2 - Modificar region\n"
			"3 - Modificar año de creacion\n"
			"4 - Volver\n"
			"¿Que desea modificar?: " };

	retorno = -1;

	if (utn_pedirNumero(&opcionElegida, mensaje, "ERROR. Opcion invalida.", 1,
			4, 3) == 0) {
		switch (opcionElegida) {
		case 1:
			if (pedirNombreConfederacion(&bufferConfederacion) == 0) {
				strcpy(aConfederacion[index].nombre,
						bufferConfederacion.nombre);
				retorno = 0;
			}
			break;

		case 2:
			if (pedirRegionConfederacion(&bufferConfederacion) == 0) {
				strcpy(aConfederacion[index].region,
						bufferConfederacion.region);
				retorno = 0;
			}
			break;

		case 3:
			if (pedirAnioCreacionConfederacion(&bufferConfederacion) == 0) {
				aConfederacion[index].anioCreacion =
						bufferConfederacion.anioCreacion;
				retorno = 0;
			}
			break;

		default:
			printf("\nVOLVIENDO AL MENU PRINCIPAL...");
			retorno = 0;
		}
	} else {
		printf("\nSIN REINTENTOS\nVOLVIENDO AL MENU PRINCIPAL...");
	}

	return retorno;
}

int buscarNombreConfederacionPorId(eConfederacion aConfederacion[],
		int longitud_aConfederacion, int id, char bufferNombre[]) {
	int retorno;

	retorno = -1;

	if (aConfederacion != NULL
			&& longitud_aConfederacion > 0&& id>0 && bufferNombre!=NULL) {
		for (int i = 0; i < longitud_aConfederacion; i++) {
			if (aConfederacion[i].id == id) {
				strcpy(bufferNombre, aConfederacion[i].nombre);
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}
