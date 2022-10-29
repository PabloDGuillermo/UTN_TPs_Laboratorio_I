/*
 ============================================================================
 Name        : tp2_laboratorio.c
 Author      : Pablo Guillermo
 Version     :
 Copyright   : 1ra Div E
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "eConfederacion.h"
#include "eJugador.h"
#include "menuPrincipal.h"
#include "inputs.h"
#include "outputs.h"

#define LONG_CONFEDERACION 6
#define LONG_JUGADORES 3000

int main(void) {
	setbuf(stdout,NULL);

	eConfederacion aConfederaciones[LONG_CONFEDERACION];
	eJugador aJugadores[LONG_JUGADORES];
	int retornoMenu;
	char confirmacion;

	if((inicializarArrayJugador(aJugadores,LONG_JUGADORES))==0 && (inicializarArrayConfederacion(aConfederaciones,LONG_CONFEDERACION))==0){

		hardcodeoConfederaciones(aConfederaciones,LONG_CONFEDERACION);

		do{
			mostrarDatosIngresadosJugador(aJugadores,LONG_JUGADORES,aConfederaciones,LONG_CONFEDERACION);
			retornoMenu=menuPrincipal(aConfederaciones,LONG_CONFEDERACION,aJugadores,LONG_JUGADORES);
			if(retornoMenu==-1){
				printf("\nALGO SALIO MAL");
				exit(-1);
			}
			utn_pedirChar(&confirmacion, "¿Desea finalizar el programa? (s/n): ","ERROR. Opcion invalida.",3);
		}while(confirmacion!='s');

	}else{
		printf("IMPOSIBLE INICIAR EL PROGRAMA\nALGO SALIO MAL...");
	}

	printf("\nPROGRAMA FINALIZADO");

	return EXIT_SUCCESS;
}
