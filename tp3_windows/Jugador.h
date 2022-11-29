#include "LinkedList.h"

#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED

typedef struct {
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
} Jugador;

Jugador* jug_new();
Jugador* jug_newParametros(char *idStr, char *nombreCompletoStr, char *edadStr,
		char *posicionStr, char *nacionalidadStr, char *idSeleccionStr);

int jug_setId(Jugador *this, int id);
int jug_getId(Jugador *this, int *id);

int jug_setNombreCompleto(Jugador *this, char *nombreCompleto);
int jug_getNombreCompleto(Jugador *this, char *nombreCompleto);

int jug_setPosicion(Jugador *this, char *posicion);
int jug_getPosicion(Jugador *this, char *posicion);

int jug_setNacionalidad(Jugador *this, char *nacionalidad);
int jug_getNacionalidad(Jugador *this, char *nacionalidad);

int jug_setEdad(Jugador *this, int edad);
int jug_getEdad(Jugador *this, int *edad);

int jug_setIdSeleccion(Jugador *this, int idSeleccion);
int jug_getIdSeleccion(Jugador *this, int *idSeleccion);

int jug_elegirPosicion(int opcion, char *posicion);
int jug_elegirNacionalidad(int paisElegido, char *nacionalidad);
int jug_elegirConvocatoria(int idSeleccion, char *convocatoria);
int menuModificarJugador(Jugador *jugadorElegido);
Jugador* jug_encontrarPorId(LinkedList *pArrayListJugador, int id);
int jug_eliminarJugador(LinkedList *pArrayListJugador, Jugador *pJugador);
int hayConvocados(LinkedList *pArrayListJugador);
int jug_convocarJugador(LinkedList *pArrayListJugador,
		LinkedList *pArrayListSeleccion);
int jug_quitarDeConvocatoria(LinkedList *pArrayListJugador,
		LinkedList *pArrayListSeleccion);
int jug_ordenarPorNacionalidad(void *jugador1, void *jugador2);
int jug_ordenarPorEdad(void *jugador1, void *jugador2);
int jug_ordenarPorNombre(void *jugador1, void *jugador2);
int jug_estaConvocado(void *jugador);
int jug_ordenarPorId(void *jugador1, void *jugador2);

#endif // jug_H_INCLUDED
