/*
 * libreria_tp1.c
 *
 *  Created on: 15 sep. 2022
 *      Author: Pablo Guillermo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libreria_tp1.h"

/// \brief Le pide al usuario un número entero. Devuelve 0 si lo obtuvo y devuelve -1 si no.
/// \param pResultado Puntero a la variable que se quiere escribir
/// \param mensaje Mensaje que se le muestra al usuario al pedir el número
/// \param mensajeError Mensaje de error que se le muestra al usuario si ingresó mal el dato
/// \param mensajeFinal Mensaje que se muestra si se queda sin reintentos
/// \param min Rango mínimo para el número a ingresar
/// \param max Rango máximo para el número a ingresar
/// \param reintentos Cantidad disponible de reintentos
/// \return Retorna 0 si pudo obtener el número y -1 si no pudo
int utn_GetNumeroEntero(int *pResultado, char mensaje[], char mensajeError[],
		char mensajeFinal[], int min, int max, int reintentos) {
	int ret;
	int buffer;

	while (reintentos > 0) {
		printf("%s", mensaje);
		if (getInt(&buffer) == 0) {
			if (buffer <= max && buffer >= min) {
				break;
			} else {
				printf("%s\n", mensajeError);
			}
		} else {
			printf("El valor no es numérico.\n");
		}
		reintentos--;

		if (reintentos == 0) {
			printf("%s", mensajeFinal);
		}
	}

	if (reintentos == 0) {
		ret = -1;
	} else {
		ret = 0;
		*pResultado = buffer;
	}

	return ret;
}

/// \brief Obtiene un buffer, verifica que sea numérico y lo devuelve con un puntero
/// \param pResultado El puntero que se escribe si el buffer es numérico
/// \return retorna 0 si es numérico y -1 si no lo es
int getInt(int *pResultado) {
	int ret;
	char buffer[64];

	ret = -1;

	if (myGets(buffer, sizeof(buffer)) == 0) {
		if (esNumericaEntera(buffer) == 0) {
			ret = 0;
			*pResultado = atoi(buffer);
		}
	}
	return ret;
}

/// \brief Recibe una cadena de caracteres y verifica que sea numérica entera
/// \param cadena Recibe este array de caracteres para verificar que cada elemento que esté en un índice sea un número entre el 0 y el 9
/// \return retorna 0 si es numérica y -1 si no lo es
int esNumericaEntera(char cadena[]) {

	int i;
	int ret;

	ret = 0;

	i = 0;

	if (cadena != NULL && strlen(cadena) > 0) {
		while (cadena[i] != '\0') {
			if (cadena[0] != '-') {
				if (cadena[i] < '0' || cadena[i] > '9') {
					ret = -1;
					break;
				}
			}
			i++;
		}
	}
	return ret;
}

/// \brief Toma desde la consola una cadena de caracteres. Verifica que el array no tenga basura, que tenga más de 0 índices y le quita el \n
/// \param Cadena Es el array que debe escribir
/// \param Len la longitud del array que debe escribir
/// \return Retorna 0 si pudo escribir la cadena y -1 si no pudo
int myGets(char cadena[], int len) {
	int ret;

	ret = -1;

	if (cadena != NULL && len > 0) {
		fgets(cadena, len, stdin);
		fflush(stdin);
		if (cadena[strlen(cadena) - 1] == '\n') {
			cadena[strlen(cadena) - 1] = '\0';
		}
		ret = 0;
	}

	return ret;
}

/// \brief Inicializa un array de enteros con todos sus índices en 0
/// \param array Array que se quiere inicializar
/// \param len Longitud del array que se quiere inicializar
void inicializarArray(int *array, int len) {
	if (array != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			array[i] = 0;
		}
	}
}

/// \brief Inicializa un array de decimales con todos sus índices en 0,00
/// \param array Array que se quiere inicializar
/// \param len Longitud del array que se quiere inicializar
void inicializarArrayFloat(float *array, int len) {
	if (array != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			array[i] = 0;
		}
	}
}

/// \brief Muestra el menú de opciones
/// \param opcion Puntero a la dirección de memoria de la variable que se utiliza como opción
/// \param arrayUno Se utiliza para mostrar los datos de los costos
/// \param arrayDos Se utiliza para mostrar los datos de los jugadores
/// \return Utiliza el retorno de utn_GetNumeroEntero. 0 si salió bien y -1 si salió mal
int mostrarMenu(int *opcion, int *arrayUno, int *arrayDos) {
	int ret;

	printf("\n\n--------MENÚ DE OPCIONES--------"
			"\n\n1. Ingreso de los costos de Mantenimiento\n"
			" Costo de Hospedaje -> $%d\n"
			" Costo de Comida -> $%d\n"
			" Costo de Transporte -> $%d\n"
			"2. Carga de jugadores\n"
			" Arqueros -> %d\n"
			" Defensores -> %d\n"
			" Mediocampistas -> %d\n"
			" Delanteros -> %d\n"
			"3. Realizar todos los calculos\n"
			"4. Informar todos los resultados\n"
			"5. Salir", arrayUno[0], arrayUno[1], arrayUno[2], arrayDos[0],
			arrayDos[1], arrayDos[2], arrayDos[3]);
	ret = utn_GetNumeroEntero(opcion, "\nIngrese una opción: ",
			"ERROR. No ingresó una opción válida.",
			"ERROR FATAL. No ingresó una opción válida.", 1, 5, 3);

	return ret;
}

/// \brief Le pide una opción al usuario. Si la ingresó bien, la devuelve por puntero, si la ingresó mal, imprime un mensaje de error
/// \param opcion Apunta a la dirección de memoria de la variable que se quiere utilizar como opción
/// \param mensaje Recibe una cadena de caracteres para mostrar el mensaje que le pide el ingreso de datos al usuario
/// \param mensajeError Recibe una cadena de caracteres para mostrarle un mensaje de error al usuario
/// \param mensajeFinal Recibe una cadena de caracteres para mostrar un mensaje de error final al usuario
/// \param min La opción mínima que se puede ingresar
/// \param max La opción máxima que se puede ingresar
/// \param reintentos La cantidad de reintentos que tiene el usuario
/// \return Retorna 0 si pudo obtener una opción válida y -1 si no pudo
int pedirOpcion(int *opcion, char *mensaje, char *mensajeError,
		char *mensajeFinal, int min, int max, int reintentos) {
	int fail;
	int opcionIngresada;

	fail = utn_GetNumeroEntero(&opcionIngresada, mensaje, mensajeError,
			mensajeFinal, min, max, reintentos);
	if (fail == 0) {
		*opcion = opcionIngresada;
	} else {
		printf("\n\nVolviendo al menú principal...\n");
	}

	return fail;
}

/// \brief A diferencia de pedirOpcion(), esta función suma el dato solicitado a lo que ya estaba guardado en la variable
/// \param array Array que guarda los datos que queremos solicitar
/// \param mensaje Recibe una cadena de caracteres para mostrar el mensaje que le pide el ingreso de datos al usuario
/// \param mensajeError Recibe una cadena de caracteres para mostrarle un mensaje de error al usuario
/// \param mensajeFinal Recibe una cadena de caracteres para mostrar un mensaje de error final al usuario
/// \param min La opción mínima que se puede ingresar
/// \param max La opción máxima que se puede ingresar
/// \param reintentos La cantidad de reintentos que tiene el usuario
/// \return Retorna 0 si pudo obtener un dato válido y -1 si no pudo
void pedirDato(int *array, int index, char *mensaje, char *mensajeError,
		char *mensajeFinal, int min, int max, int reintentos) {
	int fail;
	int numeroIngresado;

	fail = utn_GetNumeroEntero(&numeroIngresado, mensaje, mensajeError,
			mensajeFinal, min, max, reintentos);

	if (fail == 0) {
		array[index - 1] = array[index - 1] + numeroIngresado;
	} else {
		printf("\n\nVolviendo al menú principal...\n");
	}
}

/// \brief Muestra el menú para ingresar los costos
/// \param arrayCostos Array que guarda en cada uno de sus índices los costos de hospedaje, comida y transporte
void menuCostos(int *arrayCostos) {
	int opcion;
	int fail;

	fail = pedirOpcion(&opcion, "\n1. Costo de hospedaje \n"
			"2. Costo de comida\n"
			"3. Costo de transporte\n"
			"¿Cuál desea ingresar?: ", "\nERROR. No ingreso una opcion valida.",
			"\nERROR FATAL. No ingresó una opcion valida.", 1, 3, 3);
	if (fail == 0) {
		pedirDato(arrayCostos, opcion, "\nIngrese el monto: ",
				"Error. Monto fuera de rango",
				"ERROR FATAL. Ingresó un monto fuera de rango", 1, 1000000, 3);
	}
}

/// \brief Muestra las opciones para la carga de jugadores y escribe las variables que están en el main
/// \param arrayPuestos Array que contiene la cantidad de jugadores en cada puesto
/// \param lenPuestos Longitud del array que contiene la cantidad de jugadores en cada puesto
/// \param arrayCamiseta Array que indica si una camiseta está elegida o no. Guarda 1 o 0 en cada índice
/// \param lenCamiseta Longitud del array que indica si una camiseta está elegida o no
/// \param arrayConfederaciones Array que contiene la cantidad de jugadores en cada confederación
/// \param lenConfederaciones Longitud del array que contiene la cantidad de jugadores en cada confederación
/// \param pContJugadores Apunta a la dirección de memoria de la variable que cuenta la cantidad de jugadores ingresados
void menuJugadores(int *arrayPuestos, int lenPuestos, int *arrayCamiseta,
		int lenCamiseta, int *arrayConfederaciones, int lenConfederaciones,
		int *pContJugadores) {
	int opcion;
	int fail;

	opcion = 0;

	fail = pedirOpcion(&opcion, "\n1. Arquero"
			"\n2. Defensor"
			"\n3. Mediocampista"
			"\n4. Delantero"
			"\n¿Qué puesto va a ingresar?: ",
			"Error. No inrgesó un puesto válido",
			"ERROR FATAL. No ingresó un puesto válido", 1, 4, 3);
	if (arrayPuestos[opcion - 1] < contadorPuestos(arrayPuestos, opcion)
			&& fail == 0) {
		fail = pedirCamiseta(arrayCamiseta);
		if (fail == 0) {
			fail =
					pedirOpcion(&opcion,
							"\n1. AFC (Confederación Asiática de Fútbol)"
									"\n2. CAF (Confederación Africana de Naciones)"
									"\n3. CONCACAF (Confederación de Norteamérica, Centroamérica y el Caribe de Fútbol)"
									"\n4. CONMEBOL (Confederación Sudamericana de Fútbol)"
									"\n5. UEFA (Union of European Football Associations)"
									"\n6. OFC (Confederación de Fútbol de Oceanía)"
									"\nIngrese la confederación del jugador: ",
							"Error. No ingresó una confederación válida",
							"ERROR FATAL. No ingresó una confederación válida",
							1, 6, 3);
			if (fail == 0) {
				contadorConfederaciones(arrayConfederaciones, opcion);
				(*pContJugadores)++;
			}
		}
	}
}

/// \brief Cada vez que el usuario elige un puesto a cargar, la función aumenta un contador que es un array
/// \param array Array utilizado como contador. Dentro de cada índice se guardan números que indican la cantidad de jugadores en cada posición
/// \param index Es el índice que se quiere escribir del array
/// \return Retorna el número máximo de jugadores en una posición
int contadorPuestos(int *array, int index) {
	int max;

	if (index == 1) {
		max = 2;
	} else if (index == 2 || index == 3) {
		max = 8;
	} else {
		max = 4;
	}

	if (limite(array, index, max) == 0) {
		array[index - 1]++;
	}

	return max;
}

/// \brief Determina si se llegó al número máximo de jugadores por posición. Si se llegó a un máximo, imprime un mensaje por pantalla
/// \param array Es el array contador de puestos
/// \param index Es el índice al que se quiere acceder
/// \param max El número máximo que puede estar guardado en un índice determinado
/// \return Retorna 0 si no superó el límite y -1 si lo superó
int limite(int *array, int index, int max) {
	int ret;

	ret = -1;

	if (array[index - 1] < max) {
		ret = 0;
	} else {
		printf("\nSe superó el límite para esta posición");
	}

	return ret;
}

/// \brief Le pide al usuario que ingrese el número de camiseta para cada jugador
/// \param array Array que, en cada posición, guarda 0 si la camiseta fue elegida o 1 si la camiseta no fue elegida
/// \return Retorna 0 si se pudo elegir una camiseta o -1 si no se pudo elegir
int pedirCamiseta(int *array) {
	int numeroCamiseta;
	int flag;
	int fail;

	flag = -1;

	do {
		fail = utn_GetNumeroEntero(&numeroCamiseta,
				"\nIngrese el número de camiseta (del 1 al 22): ",
				"Error. No ingresó un número de camiseta válido",
				"ERROR FATAL. No ingresó un número de camiseta válido", 1, 22,
				3);

		if (fail == -1) {
			break;
		}

		if (numeroCamiseta >= 1 && numeroCamiseta <= 22) {
			if (noRepetirCamiseta(array, numeroCamiseta) == 0) {
				array[numeroCamiseta - 1] = 1;
				flag = 0;
			} else {
				printf("\nNúmero de camiseta ya usado\n");
			}
		}
	} while (flag == -1);

	return fail;
}

/// \brief Función que valida si una camiseta ya fue elegida o no
/// \param array Array que contiene 1 o 0 en cada uno de sus índices para indicar si la camiseta ya fue elegida o no
/// \param index Posición que se quiere validar
/// \return Retorna 0 si se puede elegir ese número de camiseta o -1 si ya fue elegido
int noRepetirCamiseta(int *array, int index) {
	int ret;

	ret = -1;

	if (array[index - 1] == 0) {
		ret = 0;
	}

	return ret;
}

/// \brief Se encarga de aumentar un contador para saber cuántos jugadores hay en cada confederación
/// \param array Array que guarda números en cada uno de sus índices para saber cuántos jugadores hay en cada confederación
/// \param index Índice del array de confederaciónes que se quiere aumentar
void contadorConfederaciones(int *array, int index) {
	array[index - 1]++;
}

/// \brief Calcula los resutados y escribe las variables que están en el main
/// \param arrayPromedioMercados Array que guarda el promedio de jugadores en cada confederación
/// \param arrayConferaciones Array que guarda la cantidad de jugadores en cada confederación
/// \param contadorJugador Guarda la cantidad de jugadores ingresados hasta el momento
/// \param pCostoMantenimiento Apunta a la dirección de memoria de la variable que guarda el costo de mantenimiento
/// \param arrayCostos Array que guarda los costos de hospedaje, comida y transporte en cada uno de sus índices
/// \param pDiferenciaCosto Apunta a la dirección de memoria de la variable que guarda la diferencia del costo con aumento
/// \param pCostoConAumento Apunta a la dirección de memoria de la variable que guarda el costo final con aumento
/// \param arrayFlag Array que guarda las flags utilizadas en el main
void calcularResultados(float *arrayPromedioMercados, int *arrayConferaciones,
		int contadorJugador, int *pCostoMantenimiento, int *arrayCostos,
		int *pDiferenciaCosto, int *pCostoConAumento, int *arrayFlag) {
	calcularPromedio(arrayPromedioMercados, arrayConferaciones, contadorJugador);

	*pCostoMantenimiento = arrayCostos[0] + arrayCostos[1] + arrayCostos[2];

	if (arrayPromedioMercados[4] >= 50.00) {
		*pDiferenciaCosto = *pCostoMantenimiento * 35 / 100;
		*pCostoConAumento = *pDiferenciaCosto + *pCostoMantenimiento;
	}

	arrayFlag[2] = 1;
}

/// \brief Calcula el promedio de jugadores en cada confederación
/// \param promedio Apunta a la dirección de memoria de la variable que guarda el promedio
/// \param dato Array que contiene la cantidad de jugadores en cada confederación
/// \param cantidad Cantidad de jugadores ingresados
void calcularPromedio(float *pPromedio, int *dato, int cantidad) {
	for (int i = 0; i < 6; i++) {
		pPromedio[i] = dato[i] / (float) cantidad * 100;
	}
}

/// \brief Muestra los datos ya calculados
/// \param array Array de confederaciones
/// \param datoUno Variable que guarda el costo de mantenimiento
/// \param datoDos Variable que guarda la diferencia de los costos de mantenimiento con aumento
/// \param datoTres Variable que guarda el costo de mantenimiento con aumento
void mostrarDatos(float *array, int datoUno, int datoDos, int datoTres) {
	printf("		Informar todos los resultados\n");
	printf("\nPorcentaje AFC: %.2f", array[0]);
	printf("\nPorcentaje CAF: %.2f", array[1]);
	printf("\nPorcentaje CONCACAF: %.2f", array[2]);
	printf("\nPorcentaje CONMEBOL: %.2f", array[3]);
	printf("\nPorcentaje UEFA: %.2f", array[4]);
	printf("\nPorcentaje OFC: %.2f", array[5]);

	if (datoDos == 0) {
		printf("\nEl costo de Mantenimiento es de $%d", datoUno);
	} else {
		printf(
				"\nEl costo de Mantenimiento era de $%d y recibió un aumento de $%d, su nuevo valor es de $%d",
				datoUno, datoDos, datoTres);
	}
}
