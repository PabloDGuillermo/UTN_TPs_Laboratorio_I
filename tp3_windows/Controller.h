#include "LinkedList.h"

int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador);
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador);
int controller_agregarJugador(LinkedList* pArrayListJugador);
int controller_editarJugador(LinkedList* pArrayListJugador);
int controller_removerJugador(LinkedList* pArrayListJugador);
int controller_listarJugadores(LinkedList* pArrayListJugador);
int controller_listarJugadoresConvocados(LinkedList* pArrayListJugador);
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador);
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador);
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion);
int controller_editarSeleccion(LinkedList* pArrayListSeleccion);
int controller_listarSelecciones(LinkedList* pArrayListSeleccion);
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion);
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion);
int controller_cargarIdUnicoDesdeTexto(char* path, int* id);
int controller_guardarIdUnicoModoTexto(char* path, int id);
int controller_ordenarSeleccionPorPais(LinkedList *pArrayListSeleccion);
int controller_ordenarJugadorPorNacionalidad(LinkedList *pArrayListJugador);
int controller_ordenarSeleccionPorConfederacion(LinkedList *pArrayListSeleccion);
int controller_ordenarJugadorPorEdad(LinkedList *pArrayListJugador);
int controller_ordenarJugadorPorNombre(LinkedList *pArrayListJugador);
int controller_ordenarJugadorPorId(LinkedList *pArrayListJugador);

