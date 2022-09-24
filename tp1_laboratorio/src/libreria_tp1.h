/*
 * libreria_tp1.h
 *
 *  Created on: 15 sep. 2022
 *      Author: Pablo Guillermo
 */

#ifndef LIBRERIAUTN_H_
#define LIBRERIAUTN_H_

int utn_GetNumeroEntero(int *pResultado, char mensaje[], char mensajeError[],
		char mensajeFinal[], int min, int max, int reintentos);
int getInt(int *pResultado);
int esNumericaEntera(char cadena[]);
int myGets(char cadena[], int len);
void inicializarArray(int *array, int len);
void inicializarArrayFloat(float *array, int len);
int mostrarMenu(int *opcion, int *arrayUno, int *arrayDos);
int pedirOpcion(int *opcion, char *mensaje, char *mensajeError,
		char *mensajeFinal, int min, int max, int reintentos);
void pedirDato(int *array, int index, char *mensaje, char *mensajeError,
		char *mensajeFinal, int min, int max, int reintentos);
void menuCostos(int *arrayCostos);
void menuJugadores(int *arrayPuestos, int lenPuestos, int *arrayCamiseta,
		int lenCamiseta, int *arrayConfederaciones, int lenConfederaciones,
		int *pContJugadores);
int contadorPuestos(int *array, int index);
int limite(int *array, int index, int max);
int pedirCamiseta(int *array);
int noRepetirCamiseta(int *array, int index);
void contadorConfederaciones(int *array, int index);
void calcularResultados(float *arrayPromedioMercados, int *arrayConederaciones,
		int contadorJugador, int *pCostoMantenimiento, int *arrayCostos,
		int *pDiferenciaCosto, int *pCostoConAumento, int *arrayFlag);
void calcularPromedio(float *pPromedio, int *dato, int cantidad);
void mostrarDatos(float *array, int datoUno, int datoDos, int datoTres);

#endif /* LIBRERIAUTN_H_ */

