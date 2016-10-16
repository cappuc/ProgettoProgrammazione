/*
 * Gioco.cpp
 */

#include "Gioco.hpp"

using namespace std;

Gioco::Gioco() {
	giocatoriHead = giocatoriTail = NULL;
	mappa = new Mappa();
	turno = 0;
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
		Giocatore *g = new Giocatore(nome, id_gioc++, this->mappa->getNodoIniziale());
		this->aggiungiGiocatore(g);
		this->mappa->getNodoIniziale()->addGiocatore(g);
		do {
			cout << "Vuoi inserire altri giocatori? [s/n] ";
			cin >> control;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} while (control != 's' && control != 'n');
	} while (control != 'n');
}

void Gioco::iniziaPartita() {
	StructGiocatori *currentGiocatore = this->giocatoriHead;
	this->mappa->stampaMappa();

	do {
		cout << "Turno [" << turno << "] di: " << currentGiocatore->giocatore->getNome() << endl;

		this->mappa->stampaMappa();

		currentGiocatore = currentGiocatore->next;
		if (currentGiocatore == this->giocatoriHead) turno++;
	} while (turno < 10);
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

