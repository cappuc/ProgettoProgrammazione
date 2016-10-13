/*
 * Mappa.cpp
 */

#include "Mappa.hpp"
#include <stdio.h>

using namespace std;

Mappa::Mappa() {
	minX = minY = maxX = maxY = 0;
	nodiVisitati = NULL;
	space_number = 10;
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

	for (int i = -10; i < 11; i++) {
		for (int j = -10; j < 4; j++) {
			if (!(i == 1 && j == -1))
				this->addNodoVisitato(this->nuovoNodo(i, j));
		}
	}

	Giocatore* g = new Giocatore("Fabio", 1, this->findNodoCord(2, 3));
	Giocatore* g1 = new Giocatore("Fabio", 2, this->findNodoCord(2, 3));
	this->findNodoCord(2, 3)->addGiocatore(g);
	this->findNodoCord(2, 3)->addGiocatore(g1);

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

//	if (nord == NULL && sud == NULL && ovest == NULL && est == NULL) {
//		return NULL;
//	}

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

	this->minX = (this->minX > x) ? x : this->minX;
	this->minY = (this->minY > y) ? y : this->minY;
	this->maxX = (this->maxX < x) ? x : this->maxX;
	this->maxY = (this->maxY < y) ? y : this->maxY;

	return newNodo;
}

/**
 * Stampa la mappa
 */
void Mappa::stampaMappa() {
	for (int y = this->minY; y <= this->maxY; y++) {
		for (int x = this->minX; x <= this->maxX; x++) {
			Visitati *v1 = this->nodiVisitati;
			bool trovato = false;
			while (v1 != NULL && !trovato) {
				if (v1->nodo->getCordX() == x && v1->nodo->getCordY() == y) {
					trovato = true;
					this->stampaNodo(x, y, v1->nodo->getGiocatori());
				}
				v1 = v1->next;
			}
			if (!trovato) {
				int cx_space = (minX < -9) ? 3 : 2;
				int cy_space = (minY < -9) ? 3 : 2;
				int space = cx_space + cy_space + 3 + this->space_number;

				for (int i = 0; i < space; i++) {
					cout << " ";
				}
			}
		}
		cout << endl;
	}
}

/**
 * Stampa un nodo
 * @param x Coordinata x
 * @param y Coordinata y
 * @param g Lista dei giocatori presenti nel nodo
 */
void Mappa::stampaNodo(int x, int y, StructGiocatori *g) {
	int cx_space = (minX < -9) ? 3 : 2;
	int cy_space = (minY < -9) ? 3 : 2;

	cout << "[";

	if (x >= 0 && x < 10) {
		for (int i = 0; i < cx_space - 1; i++)
			cout << " ";
	} else if (x > 10 || (x < 0 && x > -10)) {
		for (int i = 0; i < cx_space - 2; i++)
			cout << " ";
	}

	cout << x;
	cout << ":";

	if (y >= 0 && y < 10) {
		for (int i = 0; i < cy_space - 1; i++)
			cout << " ";
	} else if (y > 10 || (y < 0 && y > -10)) {
		for (int i = 0; i < cy_space - 2; i++)
			cout << " ";
	}

	cout << y;

	int count = 0;
	while (g != NULL) {
		count++;
		cout << ";" << g->giocatore->getId();
		g = g->next;
	}

	cout << "]";

	for (int i = 0; i < this->space_number - 2 * count; i++) {
		cout << " ";
	}
}

