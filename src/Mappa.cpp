/*
 * Mappa.cpp
 */

#include "Mappa.hpp"
#include <stdio.h>

using namespace std;

Mappa::Mappa() {
	nodiVisitati = NULL;
	printf("Ciao sono la Mappa!\n");
	this->nodoIniziale = new Nodo(0, 0, 0, 0, 0, 0);
	this->addNodoVisitato(this->nodoIniziale);
	Nodo *nn = this->findNodoCord(0, 0);
	cout << nn->getCordX() << endl;

//	this->nodoIniziale->goNord()->goOvest();
//	this->nodoIniziale->goEst()->goSud();

//	stampaMappa(this->nodoIniziale, 0);

	Giocatore* g = new Giocatore("Fabio", 1, this->nodoIniziale);
	this->nodoIniziale->addGiocatore(g);
	this->nodoIniziale->stampaGiocatori();
//	cout << g->getPosizione()->getCordY();
}

/**
 * Cerca un nodo fra quelli visitati
 * @param x Coordinata x del nodo
 * @param y Coordinata y del nodo
 * @return Nodo* se il nodo esiste, NULL se non esiste
 */
Nodo* Mappa::findNodoCord(int x, int y) {
	Visitati *visit = this->nodiVisitati;
	while (visit != NULL) {
		if (visit->nodo->getCordX() == x && visit->nodo->getCordY() == y) {
			return visit->nodo;
		}
		visit = visit->next;
	}
	return NULL;
}

void Mappa::addNodoVisitato(Nodo *n) {
	if (n != NULL) {
		Visitati *nuovoNodo = new Visitati;
		nuovoNodo->nodo = n;
		nuovoNodo->next = this->nodiVisitati;
		this->nodiVisitati = nuovoNodo;
	}
}

/**
 * Crea un nuovo nodo e collega i nodi vicini
 * @param x Coordinata x del nuovo nodo
 * @param y Coordinata y del nuovo nodo
 * @return newNodo se esiste almeno un nodo vicino, NULL altrimenti
 */
Nodo* Mappa::nuovoNodo(int x, int y) {
	Nodo *nord = this->findNodoCord(x, y - 1);
	Nodo *sud = this->findNodoCord(x, y + 1);
	Nodo *ovest = this->findNodoCord(x - 1, y);
	Nodo *est = this->findNodoCord(x + 1, y);

	if (nord == NULL && sud == NULL && ovest == NULL && est == NULL) {
		return NULL;
	}

	Nodo *newNodo = new Nodo(x, y, nord, sud, ovest, est);

	if (nord != NULL) {
		nord->linkSud(newNodo);
	}
	if (sud != NULL) {
		sud->linkNord(newNodo);
	}
	if (ovest != NULL) {
		ovest->linkEst(newNodo);
	}
	if (est != NULL) {
		est->linkOvest(newNodo);
	}

	return newNodo;
}

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

