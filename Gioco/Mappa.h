#ifndef Mappa_H
#define Mappa_H
#include "Nodo.h"

class Mappa {
	
	struct Visitati{
		Visitati *next;
		Nodo *nodo;
	};
	
private:
	Nodo *nodoIniziale;
	
public:
	Mappa();
	void stampaMappa(Nodo *n, Visitati *v);
};

#endif