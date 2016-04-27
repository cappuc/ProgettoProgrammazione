#include "Mappa.h"
//#include "Nodo.h"
#include <stdio.h>

Mappa::Mappa() {
	printf("Ciao sono la Mappa!\n");
	this->nodoIniziale = new Nodo(0,0,0,0,0,0);
	
	this->nodoIniziale->goNord()->goOvest();
	//printf("X: %d - Y: %d\n", n->getCordX(), n->getCordY());
	//printf("X: %d - Y: %d\n", n->goNord()->getCordX(), n->goNord()->getCordY());
	//printf("X: %d - Y: %d\n", n->goNord()->getCordX(), n->goNord()->getCordY());
	stampaMappa(this->nodoIniziale);
};

void Mappa::stampaMappa(Nodo *n) {
	if (n == 0) {
		return;
	} else {
		printf("x: %d - y: %d\n", n->getCordX(), n->getCordY());
		stampaMappa(n->getNord());
		stampaMappa(n->getSud());
		stampaMappa(n->getOvest());
		stampaMappa(n->getSud());
	}
}