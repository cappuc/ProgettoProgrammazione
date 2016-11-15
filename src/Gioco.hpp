/*
 * Gioco.hpp
 */

#ifndef GIOCO_HPP_
#define GIOCO_HPP_

#include <limits>
#include <stdio.h>
#include "Utility.hpp"
#include "Mappa.hpp"
#include "Nodo.hpp"
#include "Elemento.hpp"

#define PUNTEGGIO_VITTORIA 1000

class Gioco {
private:
	StructGiocatori *giocatoriHead, *giocatoriTail;
	Mappa *mappa;
	int turno;
	void aggiungiGiocatore(Giocatore *g);
	void turnoGiocatore(Giocatore *g);
	void muoviGiocatore(Giocatore *g);
	void estraiElemento(Giocatore *g);
	bool controlloVittoria(Giocatore *g);

public:
	Gioco();
	void configuraPartita();
	void iniziaPartita();
};

#endif /* GIOCO_HPP_ */
