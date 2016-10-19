/**
 * main.cpp
 */

#include "Mappa.hpp"
#include "Gioco.hpp"

int main(int argc, char **argv)
{
	Gioco g;
	g.configuraPartita();
	g.iniziaPartita();
	return 0;
}
