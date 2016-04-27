#ifndef GIOCATORE_H
#define GIOCATORE_H

#define STRING_LENGTH

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

#endif