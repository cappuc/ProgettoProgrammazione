/*
 * Nodo.cpp
 */

#include "Nodo.hpp"
#include "Utility.hpp"

using namespace std;

Nodo::Nodo(int xx, int yy, Nodo *n, Nodo *s, Nodo *o, Nodo *e) {
	giocatori = NULL;

	//Imposta le cordinate del nodo
	this->x = xx;
	this->y = yy;

	this->nord = n;
	this->sud = s;
	this->ovest = o;
	this->est = e;
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

void Nodo::removeGiocatore(Giocatore *g) {
	StructGiocatori *gioc = this->giocatori;
	StructGiocatori *prec = NULL;
	while (gioc != NULL || gioc->giocatore == g) {
		prec = gioc;
		gioc = gioc->next;
	}
	if (gioc != NULL) {
		prec->next = gioc->next;
		delete gioc;
	}
}

/**
 * Restituisce la lista dei giocatori
 * @return lista giocatori
 */
StructGiocatori* Nodo::getGiocatori() {
	return this->giocatori;
}

