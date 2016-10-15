/*
 * Giocatore.hpp
 */

#ifndef GIOCATORE_HPP_
#define GIOCATORE_HPP_

#include "Utility.hpp"
#include <string.h>

class Nodo;

class Giocatore {
private:
	char nome[STRING_LENGTH];
	int id;
	Nodo* posizione;

public:
	Giocatore(char* n, int id, Nodo* init);
	char* getNome();
	int getId();
	void setPosizione(Nodo* n);
	Nodo* getPosizione();
};

struct StructGiocatori {
	Giocatore *giocatore;
	StructGiocatori *next;
};

#endif /* GIOCATORE_HPP_ */
