/*
 * Giocatore.cpp
 */

#include "Giocatore.hpp"

/**
 * Inizializza il giocatore
 * @param n 	Nome del giocatore
 * @param id 	Id del giocatore
 * @param init 	Posizione iniziale
 */
Giocatore::Giocatore(char* n, int id, Nodo* init) {
	strcpy(this->nome, n);
	this->id = id;
	this->posizione = init;
	this->punti = 0;
}

/**
 * Resituisce il nome del giocatore
 * @return 	Nome del giocatore
 */
char* Giocatore::getNome() {
	return this->nome;
}

/**
 * Restituisce l'id del giocatore
 * @return 	ID giocatore
 */
int Giocatore::getId() {
	return this->id;
}

/**
 * Imposta la posizione del giocatore
 * @param n Nuova posizione
 */
void Giocatore::setPosizione(Nodo* n) {
	this->posizione->removeGiocatore(this);
	this->posizione = n;
	this->posizione->addGiocatore(this);
}

/**
 * Restituisce la posizione del giocatore
 * @return 	Posizione giocatore
 */
Nodo* Giocatore::getPosizione() {
	return this->posizione;
}

/**
 * Incrementa i punti del giocatore
 * @param punti Punti da incrementare
 */
void Giocatore::incPunti(int punti) {
	if (punti > 0) this->punti += punti;
}

/**
 * Restituisce i punti del giocatore
 * @return Punti giocatore
 */
int Giocatore::getPunti() {
	return this->punti;
}
