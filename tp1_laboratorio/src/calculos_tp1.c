/// \brief Calcula los costos de mantenimiento
/// \param costoMantenimiento Puntero a entero que guardara el costo de mantenimiento
/// \param diferenciaCosto Puntero a entero que guardara la diferencia del costo en caso de que haya mas de 50% de jugadores UEFA
/// \param costoConAumento Puntero a entero que guardara el costo con aumento
/// \param costoTransporte Entero que guarda el costo de transporte
/// \param costoHospedaje Entero que guarda el costo de hospedaje
/// \param costoComida Entero que guarda el costo de comida
/// \param promedioUEFA Flotante que guarda el porcentaje de jugadores de UEFA
/// \return Retorna 0 si pudo realizar bien los calculos y -1 si no pudo
int calcularCostoMantenimiento(int *costoMantenimiento, int *diferenciaCosto,
		int *costoConAumento, int costoTransporte, int costoHospedaje,
		int costoComida, float promedioUEFA) {
	int retorno;

	retorno = -1;

	if (costoMantenimiento >= 0 && diferenciaCosto >= 0 && costoConAumento >= 0
			&& costoTransporte > 0 && costoHospedaje > 0 && costoComida > 0) {
		*costoMantenimiento = costoTransporte + costoHospedaje + costoComida;
		if (promedioUEFA >= 50) {
			*diferenciaCosto = *costoMantenimiento * 0.35;
			*costoConAumento = *costoMantenimiento + *diferenciaCosto;
			retorno = 1;
		}
		retorno = 0;
	}
	return retorno;
}

/// \brief Calcula los promedios de la cantidad de jugadores que juegan en cada confederacion
/// \param promAFC Puntero a flotante que guardara el promedio de jugadores de la AFC
/// \param promCAF Puntero a flotante que guardara el promedio de jugadores de la CAF
/// \param promCONCACAF Puntero a flotante que guardara el promedio de jugadores de la CONCACAF
/// \param promCONMEBOL Puntero a flotante que guardara el promedio de jugadores de la CONMEBOL
/// \param promUEFA Puntero a flotante que guardara el promedio de jugadores de la UEFA
/// \param promOFC Puntero a flotante que guardara el promedio de jugadores de la OFC
/// \param AFC Entero que guarda la cantidad de jugadores de la AFC
/// \param CAF Entero que guarda la cantidad de jugadores de la CAF
/// \param CONCACAF Entero que guarda la cantidad de jugadores de la CONCACAF
/// \param CONMEBOL Entero que guarda la cantidad de jugadores de la CONMEBOL
/// \param UEFA Entero que guarda la cantidad de jugadores de la UEFA
/// \param OFC Entero que guarda la cantidad de jugadores de la OFC
/// \return Retorna 0 si pudo hacer bien los calculos y -1 si no pudo
int calcularPromediosConfederaciones(float *promAFC, float *promCAF,
		float *promCONCACAF, float *promCONMEBOL, float *promUEFA,
		float *promOFC, int AFC, int CAF, int CONCACAF, int CONMEBOL, int UEFA,
		int OFC) {
	int retorno;

	retorno = -1;

	if (promAFC >= 0 && promCAF >= 0 && promCONCACAF >= 0 && promCONMEBOL >= 0
			&& promUEFA >= 0 && promOFC >= 0 && AFC >= 0 && CAF >= 0
			&& CONCACAF >= 0 && CONMEBOL >= 0 && UEFA >= 0 && OFC >= 0) {
		*promAFC = (AFC * 100) / 22;
		*promCAF = (CAF * 100) / 22;
		*promCONCACAF = (CONCACAF * 100) / 22;
		*promCONMEBOL = (CONMEBOL * 100) / 22;
		*promUEFA = (UEFA * 100) / 22;
		*promOFC = (OFC * 100) / 22;
		retorno = 0;
	}

	return retorno;
}
