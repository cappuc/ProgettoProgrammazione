/*
 * Nodo.hpp
 *
 *  Created on: 29 set 2016
 *      Author: Fabio
 */

#ifndef NODO_HPP_
#define NODO_HPP_

class Nodo {
private:
	Nodo *nord, *sud, *ovest, *est;
	int x, y;

public:
	Nodo(int xx, int yy, Nodo *n, Nodo *s, Nodo *o, Nodo *e);
	int getCordX();
	int getCordY();
	Nodo* goNord();
	Nodo* goSud();
	Nodo* goOvest();
	Nodo* goEst();
	Nodo* getNord();
	Nodo* getSud();
	Nodo* getOvest();
	Nodo* getEst();

};

#endif /* NODO_HPP_ */
