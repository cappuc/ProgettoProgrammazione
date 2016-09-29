/*
 * Giocatore.cpp
 */

#include "Giocatore.hpp"

Giocatore::Giocatore(char* n, int id) {
	strcpy(this->nome, n);
	this->id = id;
}

void Giocatore::getNome(char n[]) {
	strcpy(n, this->nome);
}

int Giocatore::getId() {
	return this->id;
}
