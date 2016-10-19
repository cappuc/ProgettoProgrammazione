/*
 * Gioco.hpp
 */

#ifndef GIOCO_HPP_
#define GIOCO_HPP_

#include <limits>
#include "Utility.hpp"
#include "Mappa.hpp"
#include "Nodo.hpp"
#include "Gioco.hpp"

class Gioco {
private:
	StructGiocatori *giocatoriHead, *giocatoriTail;
	Mappa *mappa;
	int turno;
	void aggiungiGiocatore(Giocatore *g);

public:
	Gioco();
	void configuraPartita();
	void iniziaPartita();
};

#endif /* GIOCO_HPP_ */
