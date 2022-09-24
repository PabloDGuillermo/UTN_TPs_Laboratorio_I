/*
 ============================================================================
 Name        : tp1_laboratorio.c
 Author      : Pablo Guillermo
 Version     :
 Copyright   : 1ra Div E
 Description : Trabajo Práctico número 1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "libreria_tp1.h"

int main(void) {
	setbuf(stdout, NULL);

	int opcionMenu;
	int fail;
	int costos[3];
	int puestos[4];
	int numeroCamiseta[22];
	int confederacion[6];
	int contadorJugadores;
	int flag[3];
	float promedioMercado[6];
	int costoDeMantenimiento;
	int diferenciaCosto;
	int costoConAumento;

	contadorJugadores = 0;
	diferenciaCosto = 0;

	inicializarArray(costos, 3);
	inicializarArray(puestos, 4);
	inicializarArray(confederacion, 6);
	inicializarArray(numeroCamiseta, 22);
	inicializarArray(flag, 3);
	inicializarArrayFloat(promedioMercado, 6);

	do {

		fail = mostrarMenu(&opcionMenu, costos, puestos);

		if (fail == 0) {
			switch (opcionMenu) {
			case 1:
				menuCostos(costos);
				flag[0] = 1;
				break;

			case 2:
				if (contadorJugadores <= 22) {
					menuJugadores(puestos, 4, numeroCamiseta, 22, confederacion,
							6, &contadorJugadores);
				} else {
					printf("\nYa hay 22 jugadores ingresados\n"
							"VOLVIENDO AL MENÚ PRINCIPAL\n");
				}
				if (contadorJugadores == 22) {
					flag[1] = 1;
				}
				break;
			case 3:
				if (flag[0] == 1 && flag[1] == 1) {
					calcularResultados(promedioMercado, confederacion,
							contadorJugadores, &costoDeMantenimiento, costos,
							&diferenciaCosto, &costoConAumento, flag);
					printf("\n------CALCULOS REALIZADOS------\n");
				} else {
					printf(
							"\nERROR. Aún no están todos los datos ingresados\n");
				}
				break;

			case 4:
				if (flag[2] == 1) {
					mostrarDatos(promedioMercado, costoDeMantenimiento,
							diferenciaCosto, costoConAumento);
				} else {
					printf("\nERROR. Aún no se calcularon los datos\n");
				}

				break;
			}
		} else {
			printf("\nVUELVA A INTENTAR\n");
		}

	} while (opcionMenu != 5);

	printf("\n--------PROGRAMA FINALIZADO--------");

	return EXIT_SUCCESS;
}

