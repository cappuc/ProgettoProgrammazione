/**
 * main.cpp
 */

#include "Mappa.hpp"
#include "Gioco.hpp"
#include <time.h>

int main(int argc, char **argv)
{
	srand(time(NULL));
	Gioco g;
	g.configuraPartita();
	g.iniziaPartita();
	return 0;
}
