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
	void setNodoVisitato(Nodo *n);
	Nodo findNodoCord(int x, int y);

public:
	Mappa();
	void stampaMappa(Nodo *n, Visitati *v);
};

#endif /* MAPPA_HPP_ */
