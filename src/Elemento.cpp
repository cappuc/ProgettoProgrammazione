/*
 * Elemento.cpp
 */

#include "Elemento.hpp"

/**
 * Genera un elemento casualmente
 */
Elemento::Elemento() {
	int percentuale = rand() % 100;
	int el_perc = 0;

	for (int i=0; i<Elemento_Num; i++) {
		el_perc += Elemento_Prob[i];
		if (el_perc >= percentuale) {
			this->el_indice = i;
			break;
		}
	}
}

/**
 * Restituisce il nome dell'elemento trovato
 * @return
 */
char* Elemento::getElemento() {
	return strdup(Elemento_Nomi[this->el_indice]);
}

/**
 * Restituisce i punti corrispondenti all'elemento trovato
 * @return
 */
int Elemento::getPunti() {
	return Elemento_Punti[this->el_indice];
}



