/*
 * Elemento.hpp
 */

#ifndef ELEMENTO_HPP_
#define ELEMENTO_HPP_

#include <stdlib.h>
#include "Utility.hpp"

//Possibili elementi
static const char Elemento_Nomi[][10] = { "Bronzo", "Argento", "Oro", "Platino", "Diamante"};
static const int Elemento_Punti[] = { 25, 75, 100, 125, 200 };
static const int Elemento_Prob[] = { 45, 30, 15, 7, 3 };
static const int Elemento_Num = 5;

class Elemento {
private:
	int el_indice;

public:
	Elemento();
	char* getElemento();
	int getPunti();
};

#endif /* ELEMENTO_HPP_ */
