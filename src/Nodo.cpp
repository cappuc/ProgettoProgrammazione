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
;

int Nodo::getCordX() {
	return this->x;
}

int Nodo::getCordY() {
	return this->y;
}

Nodo* Nodo::getNord() {
	return this->nord;
}
Nodo* Nodo::getSud() {
	return this->sud;
}
Nodo* Nodo::getOvest() {
	return this->ovest;
}
Nodo* Nodo::getEst() {
	return this->est;
}

void Nodo::linkNord(Nodo *n) {
	this->nord = n;
}

void Nodo::linkSud(Nodo *n) {
	this->sud = n;
}

void Nodo::linkOvest(Nodo *n) {
	this->ovest = n;
}

void Nodo::linkEst(Nodo *n) {
	this->est = n;
}

void Nodo::addGiocatore(Giocatore *g) {
	StructGiocatori* nuovoGiocatore = new StructGiocatori;
	nuovoGiocatore->giocatore = g;
	nuovoGiocatore->next = this->giocatori;
	this->giocatori = nuovoGiocatore;
}

void Nodo::stampaGiocatori() {
	StructGiocatori* giocatori = this->giocatori;
	while (giocatori != NULL) {
		//Da modificare
		cout << giocatori->giocatore->getNome();
		giocatori = giocatori->next;
	}
}

