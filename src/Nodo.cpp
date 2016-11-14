/*
 * Nodo.cpp
 */

#include "Nodo.hpp"

using namespace std;

/**
 * Inizializza il nodo
 * @param x Coordinata x
 * @param y Coordinata y
 * @param n Nodo a nord
 * @param s	Nodo a sud
 * @param o Nodo a ovest
 * @param e Nodo a est
 */
Nodo::Nodo(int x, int y, Nodo *n, Nodo *s, Nodo *o, Nodo *e) {
	giocatori = NULL;

	//Imposta le cordinate del nodo
	this->x = x;
	this->y = y;

	this->nord = n;
	this->sud = s;
	this->ovest = o;
	this->est = e;

	this->estrazioni = MAX_EXTRACTION;
}

/**
 * Restituisce la coordinata x del nodo
 * @return cordX
 */
int Nodo::getCordX() {
	return this->x;
}

/**
 * Restituisce la coordinata y del nodo
 * @return cordY
 */
int Nodo::getCordY() {
	return this->y;
}

/**
 * Restituisce nodo a nord
 * @return nodoNord
 */
Nodo* Nodo::getNord() {
	return this->nord;
}

/**
 * Restituisce nodo a sud
 * @return nodoSud
 */
Nodo* Nodo::getSud() {
	return this->sud;
}

/**
 * Restituisce nodo a ovest
 * @return nodoOvest
 */
Nodo* Nodo::getOvest() {
	return this->ovest;
}

/**
 * Restituisce nodo a est
 * @return nodoEst
 */
Nodo* Nodo::getEst() {
	return this->est;
}

/**
 * Collega il nodo a nord
 * @param n Nodo da collegare
 */
void Nodo::linkNord(Nodo *n) {
	this->nord = n;
}

/**
 * Collega il nodo a sud
 * @param n Nodo da collegare
 */
void Nodo::linkSud(Nodo *n) {
	this->sud = n;
}

/**
 * Collega il nodo a ovest
 * @param n Nodo da collegare
 */
void Nodo::linkOvest(Nodo *n) {
	this->ovest = n;
}

/**
 * Collega il nodo a est
 * @param n Nodo da collegare
 */
void Nodo::linkEst(Nodo *n) {
	this->est = n;
}

/**
 * Aggiunge un giocatore alla lista dei giocatori
 * @param g Giocatore
 */
void Nodo::addGiocatore(Giocatore *g) {
	StructGiocatori* nuovoGiocatore = new StructGiocatori;
	nuovoGiocatore->giocatore = g;
	nuovoGiocatore->next = this->giocatori;
	this->giocatori = nuovoGiocatore;
}

/**
 * Rimuove un giocatore dal nodo
 * @param g Giocatore
 */
void Nodo::removeGiocatore(Giocatore *g) {
	StructGiocatori *gioc = this->giocatori;
	StructGiocatori *prec = NULL;
	if (gioc != NULL) {
		if (gioc->giocatore == g) {
			this->giocatori = gioc->next;
			delete gioc;
		} else {
			prec = gioc;
			gioc = gioc->next;
			while (gioc != NULL && gioc->giocatore != g) {
				prec = gioc;
				gioc = gioc->next;
			}
			if (gioc != NULL) {
				prec->next = gioc->next;
				delete gioc;
			}
		}
	}
}

/**
 * Restituisce la lista dei giocatori
 * @return lista giocatori
 */
StructGiocatori* Nodo::getGiocatori() {
	return this->giocatori;
}

/**
 * Restituisce il numero di estrazioni rimaste nel nodo
 * @return num. estrazioni rimaste
 */
int Nodo::getEstrazioni() {
	return this->estrazioni;
}

/**
 * Restituisce un elemento
 * @return Elemento
 */
Elemento* Nodo::getElemento() {
	if (this->estrazioni > 0) {
		this->estrazioni--;
		return new Elemento();
	} else {
		return NULL;
	}
}

