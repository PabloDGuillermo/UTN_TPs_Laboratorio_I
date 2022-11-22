#include <stdio.h>
#include "inputs.h"
#include "biblioteca_tp1.h"

/// \brief Inicializa un array de enteros con todos sus índices en 0
/// \param array Array que se quiere inicializar
/// \param len Longitud del array que se quiere inicializar
void inicializarArrayEnteros(int *array, int len) {
	if (array != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			array[i] = 0;
		}
	}
}

/// \brief Menu para ingresar los costos
/// \param transporte Puntero a entero que guardara el costo de transporte
/// \param hospedaje Puntero a entero que guardara el costo de hospedaje
/// \param comida Puntero a entero que guardara el costo de comida
/// \return Retorna 0 si pudo ingresarse el costo correctamente y -1 si no se pudo
int ingresarCostos(int *transporte, int *hospedaje, int *comida) {
	int retorno;
	int opcion;
	int costoIngresado;

	retorno = -1;

	if (transporte >= 0 && hospedaje >= 0 && comida >= 0) {
		if (utn_pedirNumero(&opcion, "\n1. Costo de hospedaje \n"
				"2. Costo de comida\n"
				"3. Costo de transporte\n"
				"4. Volver\n"
				"¿Cuál desea ingresar?: ",
				"ERROR. No ingreso una opcion valida", 1, 4, 3) == 0) {

			switch (opcion) {
			case 1:
				if (utn_pedirNumero(&costoIngresado,
						"Ingrese el costo de hospedaje: ",
						"ERROR. Costo invalido", 1, 1000000, 3) == 0) {
					*hospedaje += costoIngresado;
					retorno = 0;
				}
				break;

			case 2:
				if (utn_pedirNumero(&costoIngresado,
						"Ingrese el costo de comida: ", "ERROR. Costo invalido",
						1, 1000000, 3) == 0) {
					*comida += costoIngresado;
					retorno = 0;
				}
				break;

			case 3:
				if (utn_pedirNumero(&costoIngresado,
						"Ingrese el costo de transporte: ",
						"ERROR. Costo invalido", 1, 1000000, 3) == 0) {
					*transporte += costoIngresado;
					retorno = 0;
				}
				break;
			}
		} else {
			printf("\nVOLVIENDO AL MENU PRINCIPAL\n");
		}
	}
	return retorno;
}

/// \brief Menu para dar de alta un jugador
/// \param arqueros Puntero a entero que guardara la cantidad de arqueros
/// \param defensores Puntero a entero que guardara la cantidad de defensores
/// \param mediocampistas Puntero a entero que guardara la cantidad de mediocampistas
/// \param delanteros Puntero a entero que guardara la cantidad de delanteros
/// \param numeroCamiseta Array que contiene los numeros de camiseta utilizados
/// \param AFC Puntero a entero que guardara la cantidad de jugadores de la AFC
/// \param CAF Puntero a entero que guardara la cantidad de jugadores de la CAF
/// \param CONCACAF Puntero a entero que guardara la cantidad de jugadores de la CONCACAF
/// \param CONMEBOL Puntero a entero que guardara la cantidad de jugadores de la CONMEBOL
/// \param UEFA Puntero a entero que guardara la cantidad de jugadores de la UEFA
/// \param OFC Puntero a entero que guardara la cantidad de jugadores de la OFC
/// \return Retorna 0 si pudo darse de alta al jugador o -1 si no se pudo
int altaJugador(int *arqueros, int *defensores, int *mediocampistas,
		int *delanteros, int numeroCamiseta[], int *AFC, int *CAF,
		int *CONCACAF, int *CONMEBOL, int *UEFA, int *OFC) {
	int retorno;

	retorno = -1;

	if (arqueros >= 0 && defensores >= 0 && mediocampistas >= 0
			&& delanteros >= 0 && numeroCamiseta != NULL && AFC >= 0 && CAF >= 0
			&& CONCACAF >= 0 && CONMEBOL >= 0 && UEFA >= 0 && OFC >= 0) {
		if (pedirPosicion(arqueros, defensores, mediocampistas, delanteros)
				== 0) {
			if (pedirCamiseta(numeroCamiseta) == 0) {
				if (pedirConfederacion(AFC, CAF, CONCACAF, CONMEBOL, UEFA, OFC)
						== 0) {
					retorno = 0;
				}
			} else {
				printf("\nNUMERO DE CAMISETA YA USADO\nINTENTELO NUEVAMENTE\n");
			}
		} else {
			printf("\nINTENTELO NUEVAMENTE\n");
		}
	}
	return retorno;
}

/// \brief Le pide al usuario que ingrese la posicion del jugador
/// \param arqueros Puntero a entero que guardara la cantidad de arqueros
/// \param defensores Puntero a entero que guardara la cantidad de defensores
/// \param mediocampistas Puntero a entero que guardara la cantidad de mediocampistas
/// \param delanteros Puntero a entero que guardara la cantidad de delanteros
/// \return Retorna 0 si se ingreso bien la posicion y -1 si no se ingreso bien
int pedirPosicion(int *arqueros, int *defensores, int *mediocampistas,
		int *delanteros) {
	int retorno;
	int opcion;

	retorno = -1;

	if (arqueros >= 0 && defensores >= 0 && mediocampistas >= 0
			&& delanteros >= 0) {
		if (utn_pedirNumero(&opcion, "\n1 - Arquero"
				"\n2 - Defensor"
				"\n3 - Mediocampista"
				"\n4 - Delantero"
				"\n¿En que posicion juega?: ", "ERROR. Posicion invalida.", 1,
				4, 3) == 0) {
			switch (opcion) {
			case 1:
				if (*arqueros < 2) {
					*arqueros += 1;
					retorno = 0;
				} else {
					printf("\nSE ALCANZO EL LIMITE EN ESTA POSICION\n");
				}
				break;

			case 2:
				if (*defensores < 8) {
					*defensores+=1;
					retorno = 0;
				} else {
					printf("\nSE ALCANZO EL LIMITE EN ESTA POSICION\n");
				}
				break;

			case 3:
				if (*mediocampistas > 8) {
					*mediocampistas+=1;
					retorno = 0;
				} else {
					printf("\nSE ALCANZO EL LIMITE EN ESTA POSICION\n");
				}
				break;

			case 4:
				if (*delanteros < 4) {
					*delanteros+=1;
					retorno = 0;
				} else {
					printf("\nSE ALCANZO EL LIMITE EN ESTA POSICION\n");
				}
				break;
			}
		}
	}

	return retorno;
}

/// \brief Le pide el numero de camiseta al usuario
/// \param numeroCamiseta Array que guarda los numeros de camiseta
/// \return Retorna 0 si pudo ingresar bien el numero de camiseta y -1 si no pudo
int pedirCamiseta(int numeroCamiseta[]) {
	int retorno;
	int opcion;
	int reintentos;

	reintentos = 3;

	retorno = -1;

	if (numeroCamiseta != NULL) {
		if (utn_pedirNumero(&opcion, "Ingrese el numero de camiseta: ",
				"ERROR. Numero de camiseta invalido.", 1, 22, 3) == 0) {
			if (numeroCamiseta[opcion - 1] == 1) {
				do {
					reintentos--;
					printf("\nNUMERO DE CAMISETA YA USADO\n");
					if (utn_pedirNumero(&opcion,
							"Ingrese el numero de camiseta: ",
							"ERROR. Numero de camiseta invalido.", 1, 22, 3)
							== 0) {
						if (numeroCamiseta[opcion - 1] == 0) {
							numeroCamiseta[opcion - 1] = 1;
							retorno = 0;
							break;
						}
					}
				} while (numeroCamiseta[opcion - 1] == 1 && reintentos != 0);
			} else {
				numeroCamiseta[opcion - 1] = 1;
				retorno = 0;
			}
		}
	}

	return retorno;
}

/// \brief Le pide al usuario que ingrese la confederacion del jugador
/// \param AFC Puntero a entero que guarda la cantidad de jugadores en la AFC
/// \param CAF Puntero a entero que guarda la cantidad de jugadores en la CAF
/// \param CONCACAF Puntero a entero que guarda la cantidad de jugadores en la CONCACAF
/// \param CONMEBOL Puntero a entero que guarda la cantidad de jugadores en la CONMEBOL
/// \param UEFA Puntero a entero que guarda la cantidad de jugadores en la UEFA
/// \param OFC Puntero a entero que guarda la cantidad de jugadores en la OFC
/// \return Retorna 0 si pudo ingresar bien la confederacion y -1 si no pudo
int pedirConfederacion(int *AFC, int *CAF, int *CONCACAF, int *CONMEBOL,
		int *UEFA, int *OFC) {
	int retorno;
	int opcion;

	retorno = -1;

	if (AFC >= 0 && CAF >= 0 && CONCACAF >= 0 && CONMEBOL >= 0 && UEFA >= 0
			&& OFC >= 0) {
		if (utn_pedirNumero(&opcion, "\n1 - AFC"
				"\n2 - CAF"
				"\n3 - CONCACAF"
				"\n4 - CONMEBOL"
				"\n5 - UEFA"
				"\n6 - OFC"
				"\n¿En que confederacion juega?: ",
				"ERROR. confederacion invalida.", 1, 6, 3) == 0) {
			switch (opcion) {
			case 1:
				AFC++;
				retorno = 0;
				break;

			case 2:
				CAF++;
				retorno = 0;
				break;

			case 3:
				CONCACAF++;
				retorno = 0;
				break;

			case 4:
				CONMEBOL++;
				retorno = 0;
				break;

			case 5:
				UEFA++;
				retorno = 0;
				break;

			case 6:
				OFC++;
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

/// \brief Imprime en pantalla los datos de los calculos realizados
/// \param costoMantenimiento Entero que guarda el coste de mantenimiento
/// \param diferenciaCosto Entero que guarda la diferencia del coste de mantenimiento
/// \param costoConAumento Entero que guarda el costo con aumento
/// \param promAFC Flotante que guarda el promedio de jugadores en la AFC
/// \param promCAF Flotante que guarda el promedio de jugadores en la CAF
/// \param promCONCACAF Flotante que guarda el promedio de jugadores en la CONCACAF
/// \param promCONMEBOL Flotante que guarda el promedio de jugadores en la CONMEBOL
/// \param promUEFA Flotante que guarda el promedio de jugadores en la UEFA
/// \param promOFC Flotante que guarda el promedio de jugadores en la OFC
/// \return Retorna 0 si pudo mostrar los calculos y -1 si no pudo
int mostrarCalculosRealizados(int costoMantenimiento, int diferenciaCosto,
		int costoConAumento, float promAFC, float promCAF, float promCONCACAF,
		float promCONMEBOL, float promUEFA, float promOFC) {
	int retorno;

	retorno = -1;

	if (costoMantenimiento >= 0 && diferenciaCosto >= 0 && costoConAumento >= 0
			&& promAFC >= 0 && promCAF >= 0 && promCONCACAF >= 0
			&& promCONMEBOL >= 0 && promUEFA >= 0 && promOFC >= 0) {
		printf("\n-----INFORME DE CALCULOS REALIZADOS-----\n");
		printf("- Promedio de jugadores en las confederaciones:\n");
		printf("\t- AFC: %.2f \n", promAFC);
		printf("\t- CAF: %.2f \n", promCAF);
		printf("\t- CONCACAF: %.2f \n", promCONCACAF);
		printf("\t- CONMEBOL: %.2f \n", promCONMEBOL);
		printf("\t- UEFA: %.2f \n", promUEFA);
		printf("\t- OFC: %.2f \n", promOFC);
		if (costoConAumento > 0 && promUEFA >= 50) {
			printf(
					"El costo de mantenimiento era de $%d, pero recibio un aumento de $%d y ahora es de $%d\n",
					costoMantenimiento, diferenciaCosto, costoConAumento);
		} else {
			printf("El costo de mantenimiento es de $%d\n", costoMantenimiento);
		}
		retorno = 0;
	}
	return retorno;
}
