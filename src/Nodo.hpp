/*
 * Nodo.hpp
 *
 *  Created on: 29 set 2016
 *      Author: Fabio
 */

#ifndef NODO_HPP_
#define NODO_HPP_

#include "Utility.hpp"
#include "Giocatore.hpp"

struct StructGiocatori {
	Giocatore *giocatore;
	StructGiocatori *next;
};

class Nodo {

private:
	Nodo *nord, *sud, *ovest, *est;
	int x, y;
	StructGiocatori *giocatori;

public:
	Nodo(int xx, int yy, Nodo *n, Nodo *s, Nodo *o, Nodo *e);
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
	void stampaGiocatori();
	StructGiocatori* getGiocatori();

};

#endif /* NODO_HPP_ */
