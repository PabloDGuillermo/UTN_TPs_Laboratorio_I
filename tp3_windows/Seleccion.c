#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Seleccion.h"
#include "inputs.h"

Seleccion* selec_new() {
	Seleccion *pSeleccionRetorno = NULL;
	Seleccion *auxPuntero = NULL;

	auxPuntero = (Seleccion*) malloc(sizeof(Seleccion));

	if (auxPuntero != NULL) {
		pSeleccionRetorno = auxPuntero;
	}

	return pSeleccionRetorno;
}

Seleccion* selec_newParametros(char *idStr, char *paisStr,
		char *confederacionStr, char *convocadosStr) {

	Seleccion *pSeleccionRetorno = NULL;
	Seleccion *auxPuntero = NULL;

	auxPuntero = (Seleccion*) malloc(sizeof(Seleccion));

	if (auxPuntero != NULL) {
		auxPuntero->id = atoi(idStr);
		strcpy(auxPuntero->pais, paisStr);
		strcpy(auxPuntero->confederacion, confederacionStr);
		auxPuntero->convocados = atoi(convocadosStr);

		pSeleccionRetorno = auxPuntero;
	}

	return pSeleccionRetorno;
}

void selec_delete(Seleccion *this) {

	if (this != NULL) {
		free(this);
	}

}

int selec_getId(Seleccion *this, int *id) {
	int retorno;

	retorno = -1;

	if (this != NULL && this->id > 0) {
		*id = this->id;
		retorno = 0;
	}

	return retorno;
}

int selec_getPais(Seleccion *this, char *pais) {
	int retorno;

	retorno = -1;

	if (this != NULL && strlen(this->pais) > 0) {
		strcpy(pais, this->pais);
		retorno = 0;
	}

	return retorno;
}

int selec_getConfederacion(Seleccion *this, char *confederacion) {
	int retorno;

	retorno = -1;

	if (this != NULL && strlen(this->confederacion) > 0) {
		strcpy(confederacion, this->confederacion);
		retorno = 0;
	}

	return retorno;
}

int selec_setConvocados(Seleccion *this, int convocados) {
	int retorno;

	retorno = -1;

	if (this != NULL && convocados >= 0) {
		this->convocados = convocados;
		retorno = 0;
	}

	return retorno;
}

int selec_getConvocados(Seleccion *this, int *convocados) {
	int retorno;

	retorno = -1;

	if (this != NULL && this->convocados >= 0) {
		*convocados = this->convocados;
		retorno = 0;
	}

	return retorno;
}

int menuModificarSeleccion(Seleccion *seleccion) {
	int retorno;
	int opcion;
	char auxPais[100];
	char auxConfederacion[50];

	retorno = -1;

	utn_pedirNumero(&opcion, "\n1 - Pais"
			"\n2 - Confederacion"
			"\n3 - Volver"
			"\nQue desea modificar?: ", "ERROR. Opcion invalida.", 1, 3, 3);

	switch (opcion) {
	case 1:
		if (utn_pedirTexto(auxPais,
				"Ingrese el nuevo pais (maximo 100 caracteres: ",
				"ERROR. Pais invalido.", 100, 3) == 0
		/*&& selec_setPais(seleccion, auxPais) == 0*/) {
			retorno = 0;
		}
		break;

	case 2:
		if (utn_pedirTexto(auxConfederacion, "Ingrese la confederacion: ",
				"ERROR. Posicion invalida.", 50, 3) == 0
		/*&& selec_setConfederacion(seleccion, auxConfederacion) == 0*/) {
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

Seleccion* selec_encontrarPorId(LinkedList *this, int id) {
	Seleccion *retorno = NULL;
	Seleccion *auxRetorno = NULL;
	int auxId;

	if (this != NULL && id > 0) {
		for (int i = 0; i < ll_len(this); i++) {
			auxRetorno = (Seleccion*) ll_get(this, i);
			selec_getId(auxRetorno, &auxId);
			if (auxId == id) {
				retorno = auxRetorno;
				break;
			}
		}
	}

	return retorno;
}

int selec_ordenarPorPais(void *selec1, void *selec2) {
	int retorno;
	char nombre1[50];
	char nombre2[50];

	if (selec1 != NULL && selec2 != NULL) {
		if (selec_getPais(selec1, nombre1) == 0
				&& selec_getPais(selec2, nombre2) == 0) {
			retorno = strcmp(nombre1, nombre2);
		}
	}

	return retorno;
}

int selec_ordenarPorConfederacion(void *selec1, void *selec2) {
	int retorno;
	char confederacion1[50];
	char confederacion2[50];

	if (selec1 != NULL && selec2 != NULL) {
		if (selec_getConfederacion(selec1, confederacion1) == 0
				&& selec_getConfederacion(selec2, confederacion2) == 0) {
			retorno = strcmp(confederacion1, confederacion2);
		}
	}

	return retorno;
}
