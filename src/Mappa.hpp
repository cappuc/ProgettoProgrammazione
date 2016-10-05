/*
 * Mappa.hpp
 */

#ifndef MAPPA_HPP_
#define MAPPA_HPP_

#include "Nodo.hpp"
#include "Giocatore.hpp"

class Mappa {

	struct Visitati {
		Visitati *next;
		Nodo *nodo;
	};

private:
	Nodo *nodoIniziale;
	Visitati *nodiVisitati;
	void setNodoVisitato(Nodo *n);
	Nodo* findNodoCord(int x, int y);
	void addNodoVisitato(Nodo *n);
	Nodo* nuovoNodo(int x, int y);
	int getMinX();
	int getMinY();

public:
	Mappa();
	void stampaMappa();
};

#endif /* MAPPA_HPP_ */
