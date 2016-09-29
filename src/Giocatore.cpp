/*
 * Giocatore.cpp
 */

#include "Giocatore.hpp"

Giocatore::Giocatore(char* n, int id) {
	strcpy(this->nome, n);
	this->id = id;
}

char* Giocatore::getNome() {
//	strcpy(n, this->nome);
	return this->nome;
}

int Giocatore::getId() {
	return this->id;
}
