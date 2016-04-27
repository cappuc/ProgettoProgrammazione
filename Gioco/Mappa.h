#ifndef Mappa_H
#define Mappa_H
#include "Nodo.h"

class Mappa {
	
private:
	Nodo *nodoIniziale;
public:
	Mappa();
	void stampaMappa(Nodo *n);
};

#endif