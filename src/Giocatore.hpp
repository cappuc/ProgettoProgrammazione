/*
 * Giocatore.hpp
 */

#ifndef GIOCATORE_HPP_
#define GIOCATORE_HPP_

#define STRING_LENGTH 20

#include<string.h>

class Giocatore {
private:
	char nome[STRING_LENGTH];
	int id;

public:
	Giocatore(char n[STRING_LENGTH], int id);
	void getNome(char n[STRING_LENGTH]);
	int getId();
};

#endif /* GIOCATORE_HPP_ */
