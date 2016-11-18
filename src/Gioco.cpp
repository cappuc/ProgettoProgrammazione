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
		CLEARBUF;
		Giocatore *g = new Giocatore(nome, id_gioc++, this->mappa->getNodoIniziale());
		this->aggiungiGiocatore(g);
		this->mappa->getNodoIniziale()->addGiocatore(g);
		do {
			cout << "Vuoi inserire altri giocatori? [s/n] ";
			cin >> control;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} while (control != 's' && control != 'n');
	} while (control != 'n');

	printStart(PUNTEGGIO_VITTORIA);
}

/**
 * Inizia la partita
 */
void Gioco::iniziaPartita() {
	bool fine = false;
	StructGiocatori *currentGiocatore = this->giocatoriHead;
	this->mappa->stampaMappa();

	do {

		this->turnoGiocatore(currentGiocatore->giocatore);

		printWait();

		fine = controlloVittoria(currentGiocatore->giocatore);

		if (!fine) {
			currentGiocatore = currentGiocatore->next;
			if (currentGiocatore == this->giocatoriHead) turno++;
		}
	} while (!fine);

	cout << endl;
	cout << "Ha vinto " << currentGiocatore->giocatore->getNome() << " con " << currentGiocatore->giocatore->getPunti() << " punti!" << endl;
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

/**
 * Elabora il turno del giocatore
 * @param giocatore
 */
void Gioco::turnoGiocatore(Giocatore *giocatore) {
	char scelta;

//	cout << "Turno [" << turno << "] di: " << giocatore->getNome() << " - Punti: " << giocatore->getPunti() << endl;
	printStartTurn(giocatore->getNome(), giocatore->getId(), giocatore->getPunti(), turno);

	do {
		scelta = ' ';
		cout << "Vuoi muoverti o estrarre un elemento dal nodo corrente? [m/e] ";
		cin >> scelta;
		CLEARBUF;

		switch (scelta) {
		case 'm':
			this->muoviGiocatore(giocatore);
			this->estraiElemento(giocatore);
			break;
		case 'e':
			this->estraiElemento(giocatore);
			break;
		}
	} while (scelta != 'm' && scelta != 'e');

//	cout << "Fine turno di: " << giocatore->getNome() << " - Punti: " << giocatore->getPunti() << endl;

	printEndTurn(giocatore->getNome(), giocatore->getPunti());

	this->mappa->stampaMappa();
}

/**
 * Muove il giocatore in un nuovo nodo
 * @param giocatore
 */
void Gioco::muoviGiocatore(Giocatore *giocatore) {
	char dir;
	do {
		dir = ' ';
		cout << "In che direzione vuoi muoverti? [w/a/s/d] ";
		cin >> dir;
		CLEARBUF;
	} while (dir != 'w' && dir != 'a' && dir != 's' && dir != 'd');

	this->mappa->moveGiocatore(giocatore, dir);
}

/**
 * Estrae un elemento dal nodo corrente e assegna i punti al giocatore
 * @param giocatore
 */
void Gioco::estraiElemento(Giocatore *giocatore) {
	Elemento* el = giocatore->getPosizione()->getElemento();
	cout << endl;
	if (el != NULL) {
		cout << "Hai trovato: " << el->getElemento() << " - Punti: " << el->getPunti() << endl;
		giocatore->incPunti(el->getPunti());
	} else {
		if (giocatore->getPosizione()->getEstrazioni() == 0) {
			cout << "Non ci sono più risorse disponibili in questo nodo" << endl;
		} else {
			cout << "Non hai trovato niente" << endl;
		}
	}
	cout << endl;
	delete el;
}

/**
 * Controlla se il giocatore ha raggiunto il punteggio per la vittoria
 * @param giocatore
 * @return true/false
 */
bool Gioco::controlloVittoria(Giocatore *giocatore) {
	return giocatore->getPunti() >= PUNTEGGIO_VITTORIA ? true : false;
}

