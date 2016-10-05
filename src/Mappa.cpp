/*
 * Mappa.cpp
 */

#include "Mappa.hpp"
#include <stdio.h>

using namespace std;

Mappa::Mappa() {
	nodiVisitati = NULL;
	//printf("Ciao sono la Mappa!\n");
	this->nodoIniziale = new Nodo(0, 0, 0, 0, 0, 0);
	this->addNodoVisitato(this->nodoIniziale);
	//Nodo *nn = this->findNodoCord(0, 0);
	//cout << nn->getCordX() << endl;

//	this->nodoIniziale->goNord()->goOvest();
//	this->nodoIniziale->goEst()->goSud();

//	stampaMappa(this->nodoIniziale, 0);

	//Giocatore* g = new Giocatore("Fabio", 1, this->nodoIniziale);
	//this->nodoIniziale->addGiocatore(g);
	//this->nodoIniziale->stampaGiocatori();
//	cout << g->getPosizione()->getCordY();

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			this->addNodoVisitato(this->nuovoNodo(i, j));
		}
	}
	this->stampaMappa();
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

/**
 * Aggiunge un nodo alla lista dei nodi visitati controllando che sia diverso da NULL e che non sia gia presente
 * @param n Nodo da inserire
 */
void Mappa::addNodoVisitato(Nodo *n) {
	if (n != NULL && !this->findNodoCord(n->getCordX(), n->getCordY())) {
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

	Nodo* n = this->findNodoCord(x, y);
	if (n != NULL) {
		return n;
	}

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

void Mappa::stampaMappa() {
	Visitati *v1 = this->nodiVisitati;
	int minX = this->getMinX();
	int minY = this->getMinY();
	printf("minX: %d - minY: %d\n", minX, minY);
	while (v1 != NULL) {
		printf("[%d:%d]\n", v1->nodo->getCordX(), v1->nodo->getCordY());
		v1 = v1->next;
	}
}

/**
 * Restituisce la coordinata minima di x
 * @return minX
 */
int Mappa::getMinX() {
	Visitati *v = this->nodiVisitati;
	int minX = 0;
	while (v != NULL) {
		minX = (v->nodo->getCordX() < minX) ? v->nodo->getCordX() : minX;
		v = v->next;
	}
	return minX;
}

/**
 * Restituisce la coordinata minima di Y
 * @return minY
 */
int Mappa::getMinY() {
	Visitati *v = this->nodiVisitati;
	int minY = 0;
	while (v != NULL) {
		minY = (v->nodo->getCordY() < minY) ? v->nodo->getCordY() : minY;
		v = v->next;
	}
	return minY;
}






