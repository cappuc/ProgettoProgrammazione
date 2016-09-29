/*
 * Mappa.cpp
 */

#include "Mappa.hpp"
//#include "Nodo.h"
#include <stdio.h>

Mappa::Mappa() {
	printf("Ciao sono la Mappa!\n");
	this->nodoIniziale = new Nodo(0, 0, 0, 0, 0, 0);

	this->nodoIniziale->goNord()->goOvest();
	this->nodoIniziale->goEst()->goSud();

	stampaMappa(this->nodoIniziale, 0);
}
;

void Mappa::stampaMappa(Nodo *n, Visitati *v) {
	if (n == 0) {
		return;
	} else {
		Visitati *pos = v;
		bool visit = false;
		while (pos != 0) {
			if (pos->nodo == n) {
				visit = true;
			}
			pos = pos->next;
		}
		if (!visit) {
			printf("x: %d - y: %d\n", n->getCordX(), n->getCordY());
			pos = new Visitati;
			pos->nodo = n;
			pos->next = v;
			v = pos;
			stampaMappa(n->getNord(), v);
			stampaMappa(n->getSud(), v);
			stampaMappa(n->getOvest(), v);
			stampaMappa(n->getEst(), v);
		}
	}
}

