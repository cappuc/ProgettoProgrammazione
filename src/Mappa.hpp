/*
 * Mappa.hpp
 */

#ifndef MAPPA_HPP_
#define MAPPA_HPP_

#include "Nodo.hpp"

class Mappa {

	struct Visitati {
		Visitati *next;
		Nodo *nodo;
	};

private:
	Nodo *nodoIniziale;

public:
	Mappa();
	void stampaMappa(Nodo *n, Visitati *v);
};

#endif /* MAPPA_HPP_ */
