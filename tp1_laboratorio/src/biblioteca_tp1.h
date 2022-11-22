#ifndef BIBLIOTECA_TP1_H_
#define BIBLIOTECA_TP1_H_

void inicializarArrayEnteros(int *array, int len);
int ingresarCostos(int *transporte, int *hospedaje, int *comida);
int altaJugador(int *arqueros, int *defensores, int *mediocampistas,
		int *delanteros, int numeroCamiseta[], int *AFC, int *CAF,
		int *CONCACAF, int *CONMEBOL, int *UEFA, int *OFC);
int pedirPosicion(int *arqueros, int *defensores, int *mediocampistas,
		int *delanteros);
int pedirCamiseta(int numeroCamiseta[]);
int pedirConfederacion(int *AFC, int *CAF, int *CONCACAF, int *CONMEBOL,
		int *UEFA, int *OFC);
int mostrarCalculosRealizados(int costoMantenimiento, int diferenciaCosto,
		int costoConAumento, float promAFC, float promCAF, float promCONCACAF,
		float promCONMEBOL, float promUEFA, float promOFC);

#endif /* BIBLIOTECA_TP1_H_ */
