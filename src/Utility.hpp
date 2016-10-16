/*
 * Utility.hpp
 */

#ifndef UTILITY_HPP_
#define UTILITY_HPP_

#include <iostream>
#include <stdlib.h>
#include <cstring>

#define STRING_LENGTH 50

class Giocatore;
struct StructGiocatori {
	Giocatore *giocatore;
	StructGiocatori *next;
};

#endif /* UTILITY_HPP_ */
