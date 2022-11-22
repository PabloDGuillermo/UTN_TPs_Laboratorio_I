/*
 * inputs.c
 *
 *  Created on: 21 nov. 2022
 *      Author: pablo
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputs.h"

/// @fn int utn_getNumero(int*, char*, char*, int, int, int)
/// @brief Le pide el ingreso de un numero entero al usuario, sea del largo que sea.
/// @param pResultado Puntero a entero por el que se devuelve el numero pedido
/// @param mensaje Mensaje que se le muestra al usuario pidiéndole que ingrese un número
/// @param mensajeError Mensaje de error que se le muestra al usuario si no puso un número
/// @param minimo Rango mínimo del número pedido
/// @param maximo Rando máximo del número pedido
/// @param reintentos Cantidad disponible de reintentos
/// @return Retorna 0 si el número pudo ser obtenido y -1 si no
int utn_pedirNumero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos) {
	int bufferInt;
	int retorno = -1;
	while (reintentos > 0) {
		reintentos--;
		printf("%s", mensaje);
		if (getInt(&bufferInt) == 0) {
			if (bufferInt >= minimo && bufferInt <= maximo) {
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
		}
		printf("%s\n", mensajeError);
	}
	return retorno;
}

/// @fn int esNumerica(char*)
/// @brief Valida que la cadena que le llega sea numérica entera
/// @param cadena Se le pasa un array de caracteres
/// @return Retorna 0 si la cadena son números y 1 si no lo son
int esNumerica(char *cadena) {
	int i = 0;
	int retorno = 1;
	if (cadena != NULL && strlen(cadena) > 0) {
		while (cadena[i] != '\0') {
			if (cadena[0] != '-') {
				if (cadena[i] < '0' || cadena[i] > '9') {
					retorno = 0;
					break;
				}
			}
			i++;
		}
	}
	return retorno;
}

/// @fn int getInt(int*)
/// @brief Retorna por parámetro un número entero luego de validar que lo sea
/// @param pResultado Recibe un puntero a entero donde escribe el número
/// @return Retorna 0 si el número pedido es correcto y -1 si no lo es
int getInt(int *pResultado) {
	int retorno = -1;
	char buffer[64];
	if (pResultado != NULL) {
		if (myGets(buffer, sizeof(buffer)) == 0 && esNumerica(buffer)) {
			*pResultado = atoi(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

/// @fn int myGets(char*, int)
/// @brief Pide por consola una cadena y le quita el caracter "\n"
/// @param cadena puntero a la cadena de caracteres
/// @param longitud el largo de la cadena de caracteres
/// @return Retorna 0 si pudo tomar la cadena y quitarle el caracter "\n" y -1 si no pudo
int myGets(char *cadena, int longitud) {
	if (cadena != NULL && longitud > 0
			&& fgets(cadena, longitud, stdin) == cadena) {
		fflush(stdin);
		if (cadena[strlen(cadena) - 1] == '\n') {
			cadena[strlen(cadena) - 1] = '\0';
		}
		return 0;
	}
	return -1;
}

/// @fn int utn_getNumeroFlotante(float*, char*, char*, float, float, int)
/// @brief Le pide el ingreso de un numero decimal al usuario, sea del largo que sea.
/// @param pResultado Puntero a flotante por el que se devuelve el número pedido
/// @param mensaje Mensaje que se le muestra al usuario pidiéndole que ingrese un número decimal
/// @param mensajeError Mensaje de error que se le muestra al usuario si no puso un número decimal
/// @param minimo Rango mínimo del número pedido
/// @param maximo Rando máximo del número pedido
/// @param reintentos Cantidad disponible de reintentos
/// @return Retorna 0 si el número decimal pudo ser obtenido y -1 si no
int utn_pedirNumeroFlotante(float *pResultado, char *mensaje,
		char *mensajeError, float minimo, float maximo, int reintentos) {
	float bufferFloat;
	int retorno = -1;
	while (reintentos > 0) {
		reintentos--;
		printf("%s", mensaje);
		if (getFloat(&bufferFloat) == 0) {
			if (bufferFloat >= minimo && bufferFloat <= maximo) {
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
		}
		printf("%s\n", mensajeError);
	}
	return retorno;
}

/// @fn int esNumericaFlotante(char*)
/// @brief Valida que la cadena que le llega sea numérica decimal
/// @param cadena Se le pasa una cadena de números decimales
/// @return Retorna 0 si la cadena son números decimales y 1 si no lo son
int esNumericaFlotante(char *cadena) {
	int i = 0;
	int retorno = 1;
	if (cadena != NULL && strlen(cadena) > 0) {
		while (cadena[i] != '\0') {
			if (cadena[0] != '-' && cadena[i] != '.') {
				if (cadena[i] < '0' || cadena[i] > '9') {
					retorno = 0;
					break;
				}
			}
			i++;
		}
	}
	return retorno;
}

/// @fn int getFloat(float*)
/// @brief Retorna por puntero un número decimal luego de validar que lo sea
/// @param pResultado Recibe un puntero a flotante donde escribe el número decimal
/// @return Retorna 0 si el número decimal pedido es correcto y -1 si no lo es
int getFloat(float *pResultado) {
	int retorno = -1;
	char buffer[64];
	if (pResultado != NULL) {
		if (myGets(buffer, sizeof(buffer)) == 0 && esNumericaFlotante(buffer)) {
			*pResultado = atof(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

/// @fn int utn_getTexto(char*, char*, char*, int, int)
/// @brief Le pide al usuario el ingreso de un texto de 64 caracteres como máximo
/// @param pResultado Puntero a la cadena de caracteres
/// @param mensaje Mensaje que se le muestra al usuario pidiéndole que ingrese un texto
/// @param mensajeError Mensaje de error que se le muestra al usuario si la cadena es demasiado larga
/// @param maxCaracteres Cantidad máxima de caracteres que se pueden ingresar
/// @param reintentos Retorna 0 si la cadena de caracteres es correcta o -1 si se quedó sin reintentos
/// @return
int utn_pedirTexto(char *pResultado, char *mensaje, char *mensajeError,
		int maxCaracteres, int reintentos) {
	char bufferTexto[64];
	int retorno = -1;
	while (reintentos > 0) {
		reintentos--;
		printf("%s", mensaje);
		if (myGets(bufferTexto, sizeof(bufferTexto)) == 0
				&& strlen(bufferTexto) < maxCaracteres) {
			strcpy(pResultado, bufferTexto);
			retorno = 0;
			break;
		}
		printf("%s\n", mensajeError);
	}
	return retorno;
}

/// @fn int utn_getChar(char*, char*, char*, int)
/// @brief Le pide al usuario el ingreso de un caracter
/// @param pResultado Puntero a caracter en el cual se devuelve el caracter obtenido
/// @param mensaje Mensaje que se le muestra al usuario solicitando el ingreso de un caracter
/// @param mensajeError Mensaje de error que se le muestra al usuario si lo ingresado no es un caracter
/// @param reintentos Cantidad disponible de reintentos
/// @return Retorna 0 si Lo ingresado es un caracter y -1 si se quedó sin reintentos
int utn_pedirChar(char *pResultado, char *mensaje, char *mensajeError,
		int reintentos) {
	char bufferChar[64];
	int retorno = -1;

	while (reintentos > 0) {
		reintentos--;
		printf("%s", mensaje);
		if (getChar(bufferChar) == 0) {
			*pResultado = *bufferChar;
			retorno = 0;
			break;
		}
		printf("%s\n", mensajeError);
	}

	return retorno;
}

/// @fn int getChar(char*)
/// @brief Pide una cadena caderacteres y, si es valida, la devuelve por puntero
/// @param pResultado Recibe un puntero a char donde se guardará la cadena obtenida
/// @return Retorna 0 si pudo validar y devolver el char y -1 si no pudo
int getChar(char *pResultado) {
	int retorno = -1;
	char buffer[64];
	if (pResultado != NULL) {
		if (myGets(buffer, sizeof(buffer)) == 0 && esChar(buffer) == 0) {
			*pResultado = *buffer;
			retorno = 0;
		}
	}
	return retorno;
}

/// @fn int esChar(char*)
/// @brief Recibe una cadena de caracteres y valida que sea un caracter
/// @param cadena Recibe una cadena de caracteres
/// @return Retorna 0 si es un caracter y -1 si no lo es
int esChar(char *cadena) {
	int i = 0;
	int retorno = 1;
	if (cadena != NULL && strlen(cadena) > 0) {
		while (cadena[i] != '\0') {
			if (isalpha(*cadena)) {
				retorno = 0;
				break;
			}
			i++;
		}
	}
	return retorno;
}
