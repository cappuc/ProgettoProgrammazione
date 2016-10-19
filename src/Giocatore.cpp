/*
 * Giocatore.cpp
 */

#include "Giocatore.hpp"

Giocatore::Giocatore(char* n, int id, Nodo* init) {
	strcpy(this->nome, n);
	this->id = id;
	this->posizione = init;
}

char* Giocatore::getNome() {
//	strcpy(n, this->nome);
	return this->nome;
}

int Giocatore::getId() {
	return this->id;
}

void Giocatore::setPosizione(Nodo* n) {
	this->posizione->removeGiocatore(this);
	this->posizione = n;
	this->posizione->addGiocatore(this);
}

Nodo* Giocatore::getPosizione() {
	return this->posizione;
}
