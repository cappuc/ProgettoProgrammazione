/*
 * Giocatore.hpp
 */

#ifndef GIOCATORE_HPP_
#define GIOCATORE_HPP_

#include <string.h>

#include "Utility.hpp"
#include "Nodo.hpp"

class Giocatore {
private:
	char nome[STRING_LENGTH];
	int id;
	Nodo* posizione;
	int punti;

public:
	Giocatore(char* n, int id, Nodo* init);
	char* getNome();
	int getId();
	void setPosizione(Nodo* n);
	Nodo* getPosizione();
	void incPunti(int punti);
	int getPunti();
};

#endif /* GIOCATORE_HPP_ */
