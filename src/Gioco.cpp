/*
 * Gioco.cpp
 */

#include "Gioco.hpp"

using namespace std;

Gioco::Gioco() {
	giocatoriHead = giocatoriTail = NULL;
	mappa = new Mappa();
}

void Gioco::configuraPartita() {
	char control;
	char nome[STRING_LENGTH];
	int id_gioc = 1;

	//Inserimento giocatori
	do {
		cout << "Nome giocatore: ";
		cin >> nome;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		Giocatore *g = new Giocatore(nome, id_gioc, this->mappa->getNodoIniziale());
		this->mappa->getNodoIniziale()->addGiocatore(g);
		do {
			cout << "Vuoi inserire altri giocatori? [s/n] ";
			cin >> control;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} while (control != 's' && control != 'n');
	} while (control != 'n');
}

void Gioco::iniziaPartita() {

}

void Gioco::aggiungiGiocatore(Giocatore *g) {
	StructGiocatori *newGioc = new StructGiocatori;
	newGioc->giocatore = g;
	newGioc->next = this->giocatoriHead;

	if (this->giocatoriHead == NULL && this->giocatoriTail == NULL) {
		this->giocatoriHead = this->giocatoriTail = newGioc;
	} else {
		this->giocatoriTail->next = newGioc;
		this->giocatoriTail = newGioc;
	}
}

