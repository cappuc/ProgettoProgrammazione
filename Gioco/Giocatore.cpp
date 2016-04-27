#include "Giocatore.h"

Giocatore::Giocatore(char n[STRING_LENGTH], int id) {
	strcpy(this->nome, n);
	this->id = id;
}

void Giocatore::getNome(char n[STRING_LENGTH]) {
	strcpy(n, this->nome);
}

int Giocatore::getId() {
	return this->id;
}