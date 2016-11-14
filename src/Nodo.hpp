/*
 * Nodo.hpp
 *
 *  Created on: 29 set 2016
 *      Author: Fabio
 */

#ifndef NODO_HPP_
#define NODO_HPP_

#include "Utility.hpp"
#include "Elemento.hpp"


#define MAX_EXTRACTION 10

class Giocatore;

class Nodo {

private:
	Nodo *nord, *sud, *ovest, *est;
	int x, y;
	StructGiocatori *giocatori;
	int estrazioni;

public:
	Nodo(int x, int y, Nodo *n, Nodo *s, Nodo *o, Nodo *e);
	int getCordX();
	int getCordY();
	Nodo* getNord();
	Nodo* getSud();
	Nodo* getOvest();
	Nodo* getEst();
	void linkNord(Nodo *n);
	void linkSud(Nodo *n);
	void linkOvest(Nodo *n);
	void linkEst(Nodo *n);
	void addGiocatore(Giocatore *g);
	void removeGiocatore(Giocatore *g);
	bool giocatorePresente(Giocatore *g);
	StructGiocatori* getGiocatori();
	int getEstrazioni();
	Elemento* getElemento();
};

#endif /* NODO_HPP_ */
