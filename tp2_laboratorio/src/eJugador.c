/*
 * eJugador.c
 *
 *  Created on: 26 oct. 2022
 *      Author: pablo
 */

#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
#include "eJugador.h"
#include <string.h>
#include "outputs.h"
#include "eConfederacion.h"

#define VACIO 0
#define LLENO 1

int inicializarArrayJugador(eJugador aJugador[], int longitud_aJugador) {
	int retorno;

	retorno = -1;

	if (aJugador != NULL && longitud_aJugador > 0) {
		for (int i = 0; i < longitud_aJugador; i++) {
			aJugador[i].isEmpty = VACIO;
		}
		retorno = 0;
	}

	return retorno;
}

int hayJugadores(eJugador aJugador[], int longitud_aJugador) {
	int retorno;

	retorno = -1;

	if (aJugador != NULL && longitud_aJugador > 0) {
		for (int i = 0; i < longitud_aJugador; i++) {
			if (aJugador[i].isEmpty == LLENO) {
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

int buscarIndiceVacioJugador(eJugador aJugador[], int longitud_aJugador) {
	int indice;

	if (aJugador != NULL && longitud_aJugador > 0) {
		for (int i = 0; i < longitud_aJugador; i++) {
			if (aJugador[i].isEmpty == VACIO) {
				indice = i;
				break;
			}
		}
	}

	return indice;
}

int asignarIdJugador(eJugador aJugador[], int longitud_aJugador) {
	static int id = -1;

	if (aJugador != NULL && longitud_aJugador > 0) {
		id++;
	}
	return id;
}

int buscarJugadorPorId(eJugador aJugador[], int longitud_aJugador, int id,
		int *index) {
	int retorno;

	retorno = -1;

	if (aJugador != NULL && longitud_aJugador > 0 && id > 0 && index != NULL) {
		for (int i = 0; i < longitud_aJugador; i++) {
			if (id == aJugador[i].id) {
				*index = i;
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

int pedirNombreJugador(eJugador *unJugador) {
	int retorno;
	char bufferNombre[50];

	retorno = -1;

	if (unJugador != NULL) {
		if (utn_pedirTexto(bufferNombre,
				"Ingrese el nombre del jugador (max 50 caracteres): ",
				"ERROR. Nombre invalido. Intente nuevamente.", 50, 3) == 0) {
			strcpy(unJugador->nombre, bufferNombre);
			retorno = 0;
		} else {
			printf("\nSIN REINTENTOS\nVOLVIENDO AL MENU PRINCIPAL...\n");
		}
	}

	return retorno;
}

int pedirPosicionJugador(eJugador *unJugador) {
	int retorno;
	int posicionElegida;
	char mensaje[1024] = { "1 - ARQUERO\n"
			"2 - DEFENSOR\n"
			"3 - MEDIOCAMPISTA\n"
			"4 - DELANTERO\n"
			"¿EN QUE POSICION JUEGA?: " };

	retorno = -1;

	if (unJugador != NULL) {

		if (utn_pedirNumero(&posicionElegida, mensaje,
				"ERROR. Posicion invalida. Intente nuevamente.", 1, 4, 3) == 0
				&& asignarPosicionJugador(unJugador, posicionElegida) == 0) {
			retorno = 0;
		} else {
			printf("\nSIN REINTENTOS\nVOLVIENDO AL MENU PRINCIPAL...");
		}
	}

	return retorno;
}

int asignarPosicionJugador(eJugador *unJugador, int opcionElegida) {
	int retorno;

	retorno = -1;

	if (opcionElegida >= 1 && opcionElegida <= 4) {
		switch (opcionElegida) {
		case 1:
			strcpy(unJugador->posicion, "Arquero");
			break;

		case 2:
			strcpy(unJugador->posicion, "Defensor");
			break;

		case 3:
			strcpy(unJugador->posicion, "Mediocampista");
			break;

		case 4:
			strcpy(unJugador->posicion, "Delantero");
			break;
		}
		retorno = 0;
	}

	return retorno;
}

int pedirNumeroCamisetaJugador(eJugador *unJugador) {
	int retorno;
	int bufferNumeroCamiseta;

	retorno = -1;

	if (unJugador != NULL) {

		if (utn_pedirNumero(&bufferNumeroCamiseta,
				"Ingrese el numero de camiseta (de 1 a 99): ",
				"ERROR. Numero de camiseta invalido", 1, 99, 3) == 0) {
			unJugador->numeroCamiseta = bufferNumeroCamiseta;
			retorno = 0;
		} else {
			printf("\nSIN REINTENTOS\nVOLVIENDO AL MENU PRINCIPAL...");
		}
	}

	return retorno;
}

int pedirIdConfederacionJugador(eJugador *unJugador,
		eConfederacion aConfederacion[], int longitud_aConfederacion) {
	int retorno;
	int bufferIdConfederacion;

	retorno = -1;

	if (unJugador != NULL && aConfederacion != NULL
			&& longitud_aConfederacion > 0) {
		mostrarDatosIngresadosConfederacion(aConfederacion,
				longitud_aConfederacion);
		if (utn_pedirNumero(&bufferIdConfederacion,
				"Ingrese el ID de la confederacion: ",
				"ERROR. ID de la confederacion invalido", 100, 106, 3) == 0) {
			unJugador->idConfederacion = bufferIdConfederacion;
			retorno = 0;
		} else {
			printf("\nSIN REINTENTOS\nVOLVIENDO AL MENU PRINCIPAL...");
		}
	}

	return retorno;
}

int pedirSalarioJugador(eJugador *unJugador) {
	int retorno;
	float bufferSalario;

	retorno = -1;

	if (unJugador != NULL) {

		if (utn_pedirNumeroFlotante(&bufferSalario,
				"Ingrese el sueldo del jugador (entre 0 y 1000000): ",
				"ERROR. Sueldo invalido", 0, 1000000, 3) == 0) {
			unJugador->salario = bufferSalario;
			retorno = 0;
		} else {
			printf("\nSIN REINTENTOS\nVOLVIENDO AL MENU PRINCIPAL...");
		}
	}

	return retorno;
}

int pedirAniosDeContratoJugador(eJugador *unJugador) {
	int retorno;
	int bufferAniosDeContrato;

	retorno = -1;

	if (unJugador != NULL) {

		if (utn_pedirNumero(&bufferAniosDeContrato,
				"Ingrese los años de contrato (de 0 a 5): ",
				"ERROR. Años de contrato invalidos", 0, 5, 3) == 0) {
			unJugador->aniosContrato = bufferAniosDeContrato;
			retorno = 0;
		} else {
			printf("\nSIN REINTENTOS\nVOLVIENDO AL MENU PRINCIPAL...");
		}
	}

	return retorno;
}

int altaJugador(eJugador aJugador[], int longitud_aJugador,
		eConfederacion aConfederacion[], int longitud_aConfederaicon) {
	int retorno;
	eJugador bufferJugador;
	int indice;

	retorno = -1;

	if (aJugador != NULL && longitud_aJugador > 0) {
		indice = buscarIndiceVacioJugador(aJugador, longitud_aJugador);
		if (indice >= 0) {
			bufferJugador.id = asignarIdJugador(aJugador, longitud_aJugador);
			if (pedirNombreJugador(&bufferJugador) == 0
					&& pedirPosicionJugador(&bufferJugador) == 0
					&& pedirNumeroCamisetaJugador(&bufferJugador) == 0
					&& pedirIdConfederacionJugador(&bufferJugador,
							aConfederacion, longitud_aConfederaicon) == 0
					&& pedirSalarioJugador(&bufferJugador) == 0
					&& pedirAniosDeContratoJugador(&bufferJugador) == 0) {
				aJugador[indice].id = bufferJugador.id + 1;
				strcpy(aJugador[indice].nombre, bufferJugador.nombre);
				strcpy(aJugador[indice].posicion, bufferJugador.posicion);
				aJugador[indice].numeroCamiseta = bufferJugador.numeroCamiseta;
				aJugador[indice].idConfederacion =
						bufferJugador.idConfederacion;
				aJugador[indice].salario = bufferJugador.salario;
				aJugador[indice].aniosContrato = bufferJugador.aniosContrato;
				aJugador[indice].isEmpty = LLENO;
				retorno = 0;
			}
		}
	}

	return retorno;
}

int darBajaJugador(eJugador aJugador[], int longitud_aJugador, int index) {
	int retorno;

	retorno = -1;

	if (aJugador != NULL && longitud_aJugador > 0 && index >= 0) {

		aJugador[index].isEmpty = VACIO;
		retorno = 0;

	}

	return retorno;
}

int menuDarBajaJugador(eJugador aJugador[], int longitud_aJugador,
		eConfederacion aConfederacion[], int longitud_aConfederacion) {
	int retorno;
	int idElegido;
	int index;

	retorno = -1;

	if (aJugador != NULL && longitud_aJugador > 0) {
		if (mostrarDatosIngresadosJugador(aJugador, longitud_aJugador,
				aConfederacion, longitud_aConfederacion) == 0
				&& utn_pedirNumero(&idElegido,
						"Elija el ID del jugador a dar de baja: ",
						"ERROR. ID invalido.", 0, 3000, 3) == 0) {
			if (buscarJugadorPorId(aJugador, longitud_aJugador, idElegido,
					&index) == 0) {
				if (darBajaJugador(aJugador, longitud_aJugador, index) == 0) {
					retorno = 0;
				}
			} else {
				printf("\nEL JUGADOR CON ESE ID NO EXISTE\n");
			}
		} else {
			printf("\nSIN REINTENTOS\nVOLVIENDO AL MENU PRINCIPAL...");
		}
	}

	return retorno;
}

int ordenarPorIdJugador(eJugador aJugador[], int longitud_aJugador) {
	int retorno;
	int ordenado;
	eJugador bufferJugador;

	retorno = -1;
	ordenado = -1;
	if (aJugador != NULL && longitud_aJugador > 0) {
		while (ordenado != 0) {
			ordenado = 0;
			for (int i = 0; i < longitud_aJugador; i++) {
				if (aJugador[i].id > aJugador[i + 1].id) {
					bufferJugador = aJugador[i];
					aJugador[i] = aJugador[i + 1];
					aJugador[i + 1] = bufferJugador;
					ordenado = -1;
				}
			}
		}
		retorno = 0;
	}

	return retorno;
}

int menuModificarJugador(eJugador aJugador[], int longitud_aJugador,
		eConfederacion aConfederacion[], int longitud_aConfederacion) {
	int retorno;
	int idElegido;
	int index;

	retorno = -1;

	if (mostrarDatosIngresadosJugador(aJugador, longitud_aJugador,
			aConfederacion, longitud_aConfederacion) == 0
			&& utn_pedirNumero(&idElegido,
					"Elija el ID del jugador que quiere modificar: ",
					"ERROR. ID invalido", 0, 3000, 3) == 0) {
		if (buscarJugadorPorId(aJugador, longitud_aJugador, idElegido, &index)
				== 0) {

			if (modificarJugador(aJugador, longitud_aJugador, aConfederacion,
					longitud_aConfederacion, idElegido) == 0) {
				retorno = 0;
			}
		} else {
			printf("\nEL JUGADOR CON ESE ID NO EXISTE\n");
		}
	} else {
		printf("\nSIN REINTENTOS\nVOLVIENDO AL MENU PRINCIPAL...");
	}

	return retorno;
}

int modificarJugador(eJugador aJugador[], int longitud_aJugador,
		eConfederacion aConfederacion[], int longitud_aConfederacion, int index) {
	int retorno;
	int opcionElegida;
	eJugador bufferJugador;
	char mensaje[1024] = { "1 - Modificar nombre\n"
			"2 - Modificar posicion\n"
			"3 - Modificar numero de camiseta\n"
			"4 - Modificar confederacion\n"
			"5 - Modificar salario\n"
			"6 - Modificar años de contrato\n"
			"7 - Volver\n"
			"¿Que desea modificar?: " };

	retorno = -1;

	if (utn_pedirNumero(&opcionElegida, mensaje, "ERROR. Opcion invalida.", 1,
			7, 3) == 0) {
		switch (opcionElegida) {
		case 1:
			if (pedirNombreJugador(&bufferJugador) == 0) {
				strcpy(aJugador[index].nombre, bufferJugador.nombre);
				retorno = 0;
			}
			break;

		case 2:
			if (pedirPosicionJugador(&bufferJugador) == 0) {
				strcpy(aJugador[index].posicion, bufferJugador.posicion);
				retorno = 0;
			}
			break;

		case 3:
			if (pedirNumeroCamisetaJugador(&bufferJugador) == 0) {
				aJugador[index].numeroCamiseta = bufferJugador.numeroCamiseta;
				retorno = 0;
			}
			break;

		case 4:
			if (pedirIdConfederacionJugador(&bufferJugador, aConfederacion,
					longitud_aConfederacion) == 0) {
				aJugador[index].idConfederacion = bufferJugador.idConfederacion;
				retorno = 0;
			}
			break;

		case 5:
			if (pedirSalarioJugador(&bufferJugador) == 0) {
				aJugador[index].salario = bufferJugador.salario;
				retorno = 0;
			}
			break;

		case 6:
			if (pedirAniosDeContratoJugador(&bufferJugador) == 0) {
				aJugador[index].aniosContrato = bufferJugador.aniosContrato;
				retorno = 0;
			}
			break;

		default:
			printf("\nVOLVIENDO AL MENU PRINCIPAL...");
			retorno = 0;
		}
	} else {
		printf("\nSIN REINTENTOS\nVOLVIENDO AL MENU PRINCIPAL...\n");
	}

	return retorno;
}

int contadorJugadoresIngresados(eJugador aJugador[], int longitud_aJugador) {
	int retorno;

	retorno = 0;

	if (aJugador != NULL && longitud_aJugador > 0) {
		for (int i = 0; i < longitud_aJugador; i++) {
			if (aJugador[i].isEmpty == LLENO) {
				retorno++;
			}
		}
	}

	return retorno;
}
