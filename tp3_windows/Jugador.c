#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Jugador.h"
#include "inputs.h"
#include "Controller.h"

#define VACIO 0
#define LLENO 1

Jugador* jug_new() {
	Jugador *pJugadorRetorno = NULL;
	Jugador *auxPuntero = NULL;

	auxPuntero = (Jugador*) malloc(sizeof(Jugador));

	if (auxPuntero != NULL) {
		pJugadorRetorno = auxPuntero;
	}

	return pJugadorRetorno;
}

Jugador* jug_newParametros(char *idStr, char *nombreCompletoStr, char *edadStr,
		char *posicionStr, char *nacionalidadStr, char *idSeleccionStr) {
	Jugador *pJugadorRetorno = NULL;
	Jugador *auxPuntero = NULL;
	int contadorErrores;

	contadorErrores = 0;

	auxPuntero = (Jugador*) malloc(sizeof(Jugador));

	if (auxPuntero != NULL) {
		contadorErrores += jug_setId(auxPuntero, atoi(idStr));
		contadorErrores += jug_setNombreCompleto(auxPuntero, nombreCompletoStr);
		contadorErrores += jug_setEdad(auxPuntero, atoi(edadStr));
		contadorErrores += jug_setPosicion(auxPuntero, posicionStr);
		contadorErrores += jug_setNacionalidad(auxPuntero, nacionalidadStr);
		contadorErrores += jug_setIdSeleccion(auxPuntero, atoi(idSeleccionStr));
		if (contadorErrores == 0) {
			pJugadorRetorno = auxPuntero;
		}
	}

	return pJugadorRetorno;
}

void jug_delete(Jugador *this) {

}

int jug_setId(Jugador *this, int id) {
	int retorno;

	retorno = -1;

	if (this != NULL && id > 0) {
		this->id = id;
		retorno = 0;
	}

	return retorno;
}

int jug_getId(Jugador *this, int *id) {
	int retorno;

	retorno = -1;

	if (this != NULL && this->id > 0) {
		*id = this->id;
		retorno = 0;
	}

	return retorno;
}

int jug_setNombreCompleto(Jugador *this, char *nombreCompleto) {
	int retorno;

	retorno = -1;

	if (this != NULL && strlen(nombreCompleto) > 0) {
		strcpy(this->nombreCompleto, nombreCompleto);
		retorno = 0;
	}

	return retorno;
}
int jug_getNombreCompleto(Jugador *this, char *nombreCompleto) {
	int retorno;

	retorno = -1;

	if (this != NULL && strlen(this->nombreCompleto) > 0) {
		strcpy(nombreCompleto, this->nombreCompleto);
		retorno = 0;
	}

	return retorno;
}

int jug_setPosicion(Jugador *this, char *posicion) {
	int retorno;

	retorno = -1;

	if (this != NULL && strlen(posicion) > 0) {
		strcpy(this->posicion, posicion);
		retorno = 0;
	}

	return retorno;
}

int jug_getPosicion(Jugador *this, char *posicion) {
	int retorno;

	retorno = -1;

	if (this != NULL && strlen(this->posicion) > 0) {
		strcpy(posicion, this->posicion);
		retorno = 0;
	}

	return retorno;
}

int jug_setNacionalidad(Jugador *this, char *nacionalidad) {
	int retorno;

	retorno = -1;

	if (this != NULL && strlen(nacionalidad) > 0) {
		strcpy(this->nacionalidad, nacionalidad);
		retorno = 0;
	}

	return retorno;
}

int jug_getNacionalidad(Jugador *this, char *nacionalidad) {
	int retorno;

	retorno = -1;

	if (this != NULL && strlen(this->nacionalidad) > 0) {
		strcpy(nacionalidad, this->nacionalidad);
		retorno = 0;
	}

	return retorno;
}

int jug_setEdad(Jugador *this, int edad) {
	int retorno;

	retorno = -1;

	if (this != NULL && edad > 0) {
		this->edad = edad;
		retorno = 0;
	}

	return retorno;
}

int jug_getEdad(Jugador *this, int *edad) {
	int retorno;

	retorno = -1;

	if (this != NULL && this->edad > 0) {
		*edad = this->edad;
		retorno = 0;
	}

	return retorno;
}

int jug_setIdSeleccion(Jugador *this, int idSeleccion) {
	int retorno;

	retorno = -1;

	if (this != NULL && idSeleccion >= 0) {
		idSeleccion = this->idSeleccion;
		retorno = 0;
	}

	return retorno;
}

int jug_getIdSeleccion(Jugador *this, int *idSeleccion) {
	int retorno;

	retorno = -1;

	if (this != NULL && this->idSeleccion >= 0) {
		*idSeleccion = this->idSeleccion;
		retorno = 0;
	}

	return retorno;
}

int jug_elegirPosicion(int opcion, char *posicion) {
	int retorno;

	retorno = -1;

	switch (opcion) {
	case 1:
		strcpy(posicion, "Portero");
		retorno = 0;
		break;

	case 2:
		strcpy(posicion, "Defensa central");
		retorno = 0;
		break;

	case 3:
		strcpy(posicion, "Lateral izquierdo");
		retorno = 0;
		break;

	case 4:
		strcpy(posicion, "Lateral derecho");
		retorno = 0;
		break;

	case 5:
		strcpy(posicion, "Pivote");
		retorno = 0;
		break;

	case 6:
		strcpy(posicion, "Mediocentro");
		retorno = 0;
		break;

	case 7:
		strcpy(posicion, "Extremo izquierdo");
		retorno = 0;
		break;

	case 8:
		strcpy(posicion, "Extremo derecho");
		retorno = 0;
		break;

	case 9:
		strcpy(posicion, "Mediapunta");
		retorno = 0;
		break;

	case 10:
		strcpy(posicion, "Delantero centro");
		retorno = 0;
		break;
	}

	return retorno;
}

int jug_elegirNacionalidad(int paisElegido, char *nacionalidad) {
	int retorno;

	retorno = -1;

	if (paisElegido >= 0) {
		switch(paisElegido) {
		case 0:
			strcpy(nacionalidad, "No convocado");
			break;

		case 1:
			strcpy(nacionalidad, "Aleman");
			break;

		case 2:
			strcpy(nacionalidad, "Arabe");
			break;

		case 3:
			strcpy(nacionalidad, "Argentino");
			break;

		case 4:
			strcpy(nacionalidad, "Australiano");
			break;

		case 5:
			strcpy(nacionalidad, "Belga");
			break;

		case 6:
			strcpy(nacionalidad, "Brasilero");
			break;

		case 7:
			strcpy(nacionalidad, "Camerunes");
			break;

		case 8:
			strcpy(nacionalidad, "Canadiense");
			break;

		case 9:
			strcpy(nacionalidad, "Coreano del Sur");
			break;

		case 10:
			strcpy(nacionalidad, "Costarricense");
			break;

		case 11:
			strcpy(nacionalidad, "Croata");
			break;

		case 12:
			strcpy(nacionalidad, "Danes");
			break;

		case 13:
			strcpy(nacionalidad, "Ecuatoriano");
			break;

		case 14:
			strcpy(nacionalidad, "Español");
			break;

		case 15:
			strcpy(nacionalidad, "Estados Unidense");
			break;

		case 16:
			strcpy(nacionalidad, "Frances");
			break;

		case 17:
			strcpy(nacionalidad, "Gales");
			break;

		case 18:
			strcpy(nacionalidad, "Ghanes");
			break;

		case 19:
			strcpy(nacionalidad, "Holandes");
			break;

		case 20:
			strcpy(nacionalidad, "Ingles");
			break;

		case 21:
			strcpy(nacionalidad, "Irani");
			break;

		case 22:
			strcpy(nacionalidad, "Japones");
			break;

		case 23:
			strcpy(nacionalidad, "Marroqui");
			break;

		case 24:
			strcpy(nacionalidad, "Mexicano");
			break;

		case 25:
			strcpy(nacionalidad, "Polaco");
			break;

		case 26:
			strcpy(nacionalidad, "Portugues");
			break;

		case 27:
			strcpy(nacionalidad, "Qatari");
			break;

		case 28:
			strcpy(nacionalidad, "Senegales");
			break;

		case 29:
			strcpy(nacionalidad, "Serbio");
			break;

		case 30:
			strcpy(nacionalidad, "Suizo");
			break;

		case 31:
			strcpy(nacionalidad, "Tunecino");
			break;

		case 32:
			strcpy(nacionalidad, "Uruguayo");
			break;
		}
		retorno = 0;
	}

	return retorno;
}

int jug_elegirConvocatoria(int idSeleccion,
		char *convocatoria) {
	int retorno;

	retorno = -1;

	if (idSeleccion >= 0) {
		switch(idSeleccion) {
		case 0:
			strcpy(convocatoria, "No convocado");
			break;

		case 1:
			strcpy(convocatoria, "Alemania");
			break;

		case 2:
			strcpy(convocatoria, "Arabia Saudita");
			break;

		case 3:
			strcpy(convocatoria, "Argentina");
			break;

		case 4:
			strcpy(convocatoria, "Australia");
			break;

		case 5:
			strcpy(convocatoria, "Belgica");
			break;

		case 6:
			strcpy(convocatoria, "Brasil");
			break;

		case 7:
			strcpy(convocatoria, "Camerun");
			break;

		case 8:
			strcpy(convocatoria, "Canada");
			break;

		case 9:
			strcpy(convocatoria, "Corea del Sur");
			break;

		case 10:
			strcpy(convocatoria, "Costa Rica");
			break;

		case 11:
			strcpy(convocatoria, "Croacia");
			break;

		case 12:
			strcpy(convocatoria, "Dinamarca");
			break;

		case 13:
			strcpy(convocatoria, "Ecuador");
			break;

		case 14:
			strcpy(convocatoria, "España");
			break;

		case 15:
			strcpy(convocatoria, "Estados Unidos");
			break;

		case 16:
			strcpy(convocatoria, "Francia");
			break;

		case 17:
			strcpy(convocatoria, "Gales");
			break;

		case 18:
			strcpy(convocatoria, "Ghana");
			break;

		case 19:
			strcpy(convocatoria, "Holanda");
			break;

		case 20:
			strcpy(convocatoria, "Inglaterra");
			break;

		case 21:
			strcpy(convocatoria, "Iran");
			break;

		case 22:
			strcpy(convocatoria, "Japon");
			break;

		case 23:
			strcpy(convocatoria, "Marruecos");
			break;

		case 24:
			strcpy(convocatoria, "Mexico");
			break;

		case 25:
			strcpy(convocatoria, "Polonia");
			break;

		case 26:
			strcpy(convocatoria, "Portugal");
			break;

		case 27:
			strcpy(convocatoria, "Qatar");
			break;

		case 28:
			strcpy(convocatoria, "Senegal");
			break;

		case 29:
			strcpy(convocatoria, "Serbia");
			break;

		case 30:
			strcpy(convocatoria, "Suiza");
			break;

		case 31:
			strcpy(convocatoria, "Tunez");
			break;

		case 32:
			strcpy(convocatoria, "Uruguay");
			break;
		}
		retorno = 0;
	}

	return retorno;
}

int menuModificarJugador(Jugador *jugadorElegido) {
	int retorno;
	int opcion;
	char auxNombre[100];
	int auxEdad;
	int opcionPosicion;
	char auxPosicion[50];
	char auxNacionalidad[50];

	retorno = -1;

	utn_pedirNumero(&opcion, "\n1 - Nombre completo"
			"\n2 - Edad"
			"\n3 - Posicion"
			"\n4 - Nacionalidad"
			"\n5 - Volver"
			"\nQue desea modificar?: ", "ERROR. Opcion invalida.", 1, 5, 3);

	switch (opcion) {
	case 1:
		if (utn_pedirTexto(auxNombre,
				"Ingrese el nuevo nombre (maximo 100 caracteres: ",
				"ERROR. Nombre invalido.", 100, 3) == 0
				&& jug_setNombreCompleto(jugadorElegido, auxNombre) == 0) {
			retorno = 0;
		}
		break;

	case 2:
		if (utn_pedirNumero(&auxEdad, "Ingrese la nueva edad: ",
				"ERROR. Edad invalida.", 14, 65, 3) == 0
				&& jug_setEdad(jugadorElegido, auxEdad) == 0) {
			retorno = 0;
		}
		break;

	case 3:
		if (utn_pedirNumero(&opcionPosicion, "\n1 - Portero"
				"\n2 - Defensa central"
				"\n3 - Lateral izquierdo"
				"\n4 - Lateral derecho"
				"\n5 - Pivote"
				"\n6 - Mediocentro"
				"\n7 - Extremo izquierdo"
				"\n8 - Extermo derecho"
				"\n9 - Mediapunta"
				"\n10 - Delantero centro"
				"\nElija una posicion: ", "ERROR. Posicion invalida.", 1, 10, 3)
				== 0 && jug_elegirPosicion(opcionPosicion, auxPosicion) == 0
				&& jug_setPosicion(jugadorElegido, auxPosicion) == 0) {
			retorno = 0;
		}
		break;

	case 4:
		if (utn_pedirTexto(auxNacionalidad, "Ingrese la nueva nacionalidad: ",
				"ERROR. nacionalidad invalida.", 50, 3) == 0
				&& jug_setNacionalidad(jugadorElegido, auxNacionalidad) == 0) {
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

Jugador* jug_encontrarPorId(LinkedList *pArrayListJugador, int id) {
	Jugador *retorno = NULL;
	Jugador *auxRetorno = NULL;
	int auxId;

	if (pArrayListJugador != NULL && id > 0) {
		for (int i = 0; i < ll_len(pArrayListJugador); i++) {
			auxRetorno = (Jugador*) ll_get(pArrayListJugador, i);
			jug_getId(auxRetorno, &auxId);
			if (auxId == id) {
				retorno = auxRetorno;
				break;
			}
		}
	}

	return retorno;
}

int jug_eliminarJugador(LinkedList *pArrayListJugador, Jugador *pJugador) {
	int retorno;
	Jugador *pAuxJugador;

	retorno = -1;

	if (pArrayListJugador != NULL && pJugador != NULL) {
		for (int i = 0; i < ll_len(pArrayListJugador); i++) {
			pAuxJugador = (Jugador*) ll_get(pArrayListJugador, i);
			if (pAuxJugador == pJugador) {
				if (ll_remove(pArrayListJugador, i) == 0) {
					retorno = 0;
				}
				break;
			}
		}
	}

	return retorno;
}

int hayConvocados(LinkedList *pArrayListJugador) {
	int retorno;
	Jugador *auxJugador;
	int auxConvocatoria;

	retorno = -1;

	if (pArrayListJugador != NULL) {
		for (int i = 0; i < ll_len(pArrayListJugador); i++) {
			auxJugador = ll_get(pArrayListJugador, i);
			if (auxJugador != NULL
					&& jug_getIdSeleccion(auxJugador, &auxConvocatoria) == 0) {
				if (auxConvocatoria != 0) {
					retorno = 0;
				}
			}
		}
	}

	return retorno;
}

int jug_convocarJugador(LinkedList *pArrayListJugador,
		LinkedList *pArrayListSeleccion) {
	int retorno;
	int idJugador;
	int cantidadConvocados;
	Seleccion* auxSeleccion=NULL;
	Jugador* auxJugador=NULL;

	retorno = -1;

	if (pArrayListJugador != NULL && pArrayListSeleccion != NULL) {
		controller_listarJugadores(pArrayListJugador);
		if(utn_pedirNumero(&idJugador, "Ingrese el ID del jugador que quiere convocar: ", "ERROR. ID invalido",1,1000000,3)==0){
			auxJugador=jug_encontrarPorId(pArrayListJugador,idJugador);
			if(auxJugador!=NULL){

			}else{
				printf("\nEL JUGADOR CON ESE ID NO EXISTE\nVOLVIENDO AL MENU PRINCIPAL...\n");
			}
		}

		retorno = 0;
	}

	return retorno;
}
