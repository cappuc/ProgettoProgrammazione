/*
 * Utillity.cpp
 */

#include "Utility.hpp"

using namespace std;

void printStart(int punteggio) {
	cout << endl << "Vince il giocatore che guadagna per primo: " << punteggio << " punti" << endl << endl;
	cout << "========================= INIZIO PARTITA =========================" << endl << endl;
}

void printStartTurn(char* nome, int id, int punteggio, int turno) {
	cout << "=========================  INIZIO TURNO  =========================" << endl;
	cout << "Turno [" << turno << "] di: " << nome << " - ID: " << id << " - Punti: " << punteggio << endl << endl;
}

void printEndTurn(char* nome, int punteggio) {
	cout << "=========================   FINE TURNO   =========================" << endl;
	cout << nome << " - Punti: " << punteggio << endl << endl;
}

void printWin(char* nome, int punti) {

}

void printMap() {
	cout << "=========================     MAPPA      =========================" << endl;
}

void printWait() {
	cout << "Premi invio per continuare.";
	cin.get();
	cout << endl;
}
