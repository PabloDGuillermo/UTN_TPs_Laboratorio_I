/*
 ============================================================================
 Name        : tp1_laboratorio.c
 Author      : Pablo Guillermo
 Version     : 2.0
 Copyright   : 1ra Div E
 Description : Trabajo Práctico número 1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "biblioteca_tp1.h"
#include "inputs.h"
#include "calculos_tp1.h"

int main(void) {
	setbuf(stdout, NULL);

	int opcion;
	int costoTransporte;
	int costoHospedaje;
	int costoComida;
	int costoMantenimiento;
	int contadorArqueros;
	int contadorDefensores;
	int contadorMediocampistas;
	int contadorDelanteros;
	int numeroCamiseta[22];
	int contadorAFC;
	int contadorCAF;
	int contadorCONCACAF;
	int contadorCONMEBOL;
	int contadorUEFA;
	int contadorOFC;
	int contadorJugadores;
	float promedioAFC;
	float promedioCAF;
	float promedioCONCACAF;
	float promedioCONMEBOL;
	float promedioUEFA;
	float promedioOFC;
	int diferenciaCosto;
	int costoConAumento;
	int flagCalculosRealizados;
	char confirmacion;

	costoTransporte = 0;
	costoHospedaje = 0;
	costoComida = 0;
	costoMantenimiento = 0;
	contadorArqueros = 0;
	contadorDefensores = 0;
	contadorMediocampistas = 0;
	contadorDelanteros = 0;
	contadorAFC = 0;
	contadorCAF = 0;
	contadorCONCACAF = 0;
	contadorCONMEBOL = 0;
	contadorUEFA = 0;
	contadorOFC = 0;
	contadorJugadores = 0;
	promedioAFC = 0;
	promedioCAF = 0;
	promedioCONCACAF = 0;
	promedioCONMEBOL = 0;
	promedioUEFA = 0;
	promedioOFC = 0;
	diferenciaCosto = 0;
	costoConAumento = 0;
	flagCalculosRealizados = 0;

	inicializarArrayEnteros(numeroCamiseta, 22);

	do {
		opcion = 0;
		confirmacion = 'n';
		printf("\n|============================================|");
		printf("\n|---------------MENU PRINCIPAL---------------|");
		printf("\n|--------------------------------------------|");
		printf("\n1. Ingreso de los costos de Mantenimiento\n"
				"\tCosto de Hospedaje -> $%d\n"
				"\tCosto de Comida -> $%d\n"
				"\tCosto de Transporte -> $%d\n"
				"2. Carga de jugadores\n"
				"\tArqueros -> %d\n"
				"\tDefensores -> %d\n"
				"\tMediocampistas -> %d\n"
				"\tDelanteros -> %d\n"
				"3. Realizar todos los calculos\n"
				"4. Informar todos los resultados\n"
				"5. Salir", costoHospedaje, costoComida, costoTransporte,
				contadorArqueros, contadorDefensores, contadorMediocampistas,
				contadorDelanteros);
		if (utn_pedirNumero(&opcion, "\nIngrese una opcion: ",
				"ERROR. No ingreso una opcion valida.", 1, 5, 3) == 0) {
			switch (opcion) {

			case 1:
				if (ingresarCostos(&costoTransporte, &costoHospedaje,
						&costoComida) == 0) {
					printf("\nEL COSTO FUE INGRESADO CORRECTAMENTE\n");
				}
				break;

			case 2:
				if (contadorJugadores <= 22) {
					if (altaJugador(&contadorArqueros, &contadorDefensores,
							&contadorMediocampistas, &contadorDelanteros,
							numeroCamiseta, &contadorAFC, &contadorCAF,
							&contadorCONCACAF, &contadorCONMEBOL, &contadorUEFA,
							&contadorOFC) == 0) {
						contadorJugadores++;
					}
				} else {
					printf("\nYa hay 22 jugadores ingresados\n"
							"VOLVIENDO AL MENÚ PRINCIPAL\n");
				}
				break;
			case 3:
				if (contadorJugadores == 22) {
					if (calcularPromediosConfederaciones(&promedioAFC,
							&promedioCAF, &promedioCONCACAF, &promedioCONMEBOL,
							&promedioUEFA, &promedioOFC, contadorAFC,
							contadorCAF, contadorCONCACAF, contadorCONMEBOL,
							contadorUEFA, contadorOFC) == 0) {
						if (calcularCostoMantenimiento(&costoMantenimiento,
								&diferenciaCosto, &costoConAumento,
								costoTransporte, costoHospedaje, costoComida,
								promedioUEFA) == 0) {
							printf("\n------CALCULOS REALIZADOS------\n");
							flagCalculosRealizados = 1;
						} else {
							printf(
									"\nHUBO UN ERROR AL CALCULAR LOS COSTOS DE MANTENIMIENTO\n");
						}
					} else {
						printf(
								"\nHUBO UN ERROR AL REALIZAR LOS PROMEDIOS DE LAS CONFEDERACIONES\n");
					}
				} else {
					printf(
							"\nERROR. Aún no están todos los datos ingresados\n");
				}
				break;

			case 4:
				if (contadorJugadores == 22 && flagCalculosRealizados == 1) {
					if (mostrarCalculosRealizados(costoMantenimiento,
							diferenciaCosto, costoConAumento, promedioAFC,
							promedioCAF, promedioCONCACAF, promedioCONMEBOL,
							promedioUEFA, promedioOFC) == 0) {
						printf("\nVOLVIENDO AL MENU PRINCPIAL\n");
					} else {
						printf(
								"\nHUBO UN ERROR AL QUERER MOSTRAR LOS CALCULOS REALIZADOS\n");
					}
				} else {
					printf(
							"\nAUN NO SE INGRESARON 22 JUGADORES O NO SE REALIZARON LOS CALCULOS\n");
				}
				break;

			case 5:
				utn_pedirChar(&confirmacion, "Seguro que quiere salir? (s/n): ",
						"ERROR. opcion invalida", 3);
				break;
			}
		} else {
			printf("\nVUELVA A INTENTAR\n");
		}

	} while (opcion != 5 || confirmacion != 's');

	printf("\n--------PROGRAMA FINALIZADO--------");

	return EXIT_SUCCESS;
}

