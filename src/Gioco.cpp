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

/**
 * Configura la partita
 */
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

/**
 * Inizia la partita
 */
void Gioco::iniziaPartita() {
	char dir;

	StructGiocatori *currentGiocatore = this->giocatoriHead;
	this->mappa->stampaMappa();

	do {
		cout << "Turno [" << turno << "] di: " << currentGiocatore->giocatore->getNome() << endl;

		do {
			dir = ' ';
			cout << "In che direzione vuoi muoverti? [w/a/s/d] ";
			cin >> dir;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} while (dir != 'w' && dir != 'a' && dir != 's' && dir != 'd');

		this->mappa->moveGiocatore(currentGiocatore->giocatore, dir);

		this->mappa->stampaMappa();

		currentGiocatore = currentGiocatore->next;
		if (currentGiocatore == this->giocatoriHead) turno++;
	} while (turno < 10);
}

/**
 * Aggiunge un giocatore alla partita
 * Inserimento in coda - lista circolare
 * @param g Giocatore
 */
void Gioco::aggiungiGiocatore(Giocatore *g) {
	StructGiocatori *newGioc = new StructGiocatori;
	newGioc->giocatore = g;
	newGioc->next = this->giocatoriHead;

	if (this->giocatoriHead == NULL && this->giocatoriTail == NULL) {
		newGioc->next = newGioc;
		this->giocatoriHead = this->giocatoriTail = newGioc;
	} else {
		this->giocatoriTail->next = newGioc;
		this->giocatoriTail = newGioc;
	}
}

