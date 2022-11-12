#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Seleccion.h"

Seleccion* selec_new(){
	Seleccion *pSeleccionRetorno = NULL;
	Seleccion *auxPuntero = NULL;

	auxPuntero = (Seleccion*) malloc(sizeof(Seleccion));

	if (auxPuntero != NULL) {
		pSeleccionRetorno = auxPuntero;
	}

	return pSeleccionRetorno;
}

Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr){

	Seleccion *pSeleccionRetorno = NULL;
	Seleccion *auxPuntero = NULL;

	auxPuntero = (Seleccion*) malloc(sizeof(Seleccion));

	if (auxPuntero != NULL) {
		auxPuntero->id=atoi(idStr);
		strcpy(auxPuntero->pais,paisStr);
		strcpy(auxPuntero->confederacion,confederacionStr);
		auxPuntero->convocados=atoi(convocadosStr);

		pSeleccionRetorno = auxPuntero;
	}

	return pSeleccionRetorno;
}

void selec_delete(Seleccion *this){


	if(this!=NULL){
		free(this);
	}

}

int selec_getId(Seleccion* this,int* id){
	int retorno;

	retorno = -1;

	if (this != NULL && this->id > 0) {
		*id = this->id;
		retorno = 0;
	}

	return retorno;
}

int selec_getPais(Seleccion* this,char* pais){
	int retorno;

	retorno = -1;

	if (this != NULL && strlen(this->pais) > 0) {
		strcpy(pais,this->pais);
		retorno = 0;
	}

	return retorno;
}

int selec_getConfederacion(Seleccion* this,char* confederacion){
	int retorno;

	retorno = -1;

	if (this != NULL && strlen(this->confederacion) > 0) {
		strcpy(confederacion, this->confederacion);
		retorno = 0;
	}

	return retorno;
}


int selec_setConvocados(Seleccion* this,int convocados){
	int retorno;

	retorno = -1;

	if (this != NULL && convocados >= 0) {
		this->convocados = convocados;
		retorno = 0;
	}

	return retorno;
}

int selec_getConvocados(Seleccion* this,int* convocados){
	int retorno;

	retorno = -1;

	if (this != NULL && this->convocados >= 0) {
		*convocados = this->convocados;
		retorno = 0;
	}

	return retorno;
}
