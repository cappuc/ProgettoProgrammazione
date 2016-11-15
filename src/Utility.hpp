/*
 * Utility.hpp
 */

#ifndef UTILITY_HPP_
#define UTILITY_HPP_

#include <iostream>
#include <stdlib.h>
#include <cstring>

#define STRING_LENGTH 50
#define CLEARBUF cin.ignore(numeric_limits<streamsize>::max(), '\n')

class Giocatore;
struct StructGiocatori {
	Giocatore *giocatore;
	StructGiocatori *next;
};

void printStart(int punteggio);
void printStartTurn(char* nome, int punteggio, int turno);
void printEndTurn(char* nome, int punteggio);
void printWin(char* nome, int punti);
void printMap();
void printWait();

#endif /* UTILITY_HPP_ */
