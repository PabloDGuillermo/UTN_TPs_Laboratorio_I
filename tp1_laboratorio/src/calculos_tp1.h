#ifndef CALCULOS_TP1_H_
#define CALCULOS_TP1_H_

int calcularCostoMantenimiento(int *costoMantenimiento, int *diferenciaCosto,
		int *costoConAumento, int costoTransporte, int costoHospedaje,
		int costoComida, float promedioUEFA);
int calcularPromediosConfederaciones(float *promAFC, float *promCAF,
		float *promCONCACAF, float *promCONMEBOL, float *promUEFA, float *promOFC,
		int AFC, int CAF, int CONCACAF, int CONMEBOL, int UEFA, int OFC);

#endif /* CALCULOS_TP1_H_ */
