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
	int minX, maxX, minY, maxY;
	int space_number;
	void setNodoVisitato(Nodo *n);
	Nodo* findNodoCord(int x, int y);
	void addNodoVisitato(Nodo *n);
	Nodo* nuovoNodo(int x, int y);
	void stampaNodo(int x, int y, StructGiocatori *g);

public:
	Mappa();
	Nodo* getNodoIniziale();
	void stampaMappa();
	void moveGiocatore(Giocatore *g, char dir);
};

#endif /* MAPPA_HPP_ */
