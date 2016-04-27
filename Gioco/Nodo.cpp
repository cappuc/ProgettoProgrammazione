#include "Nodo.h"

Nodo::Nodo(int xx, int yy, Nodo *n, Nodo *s, Nodo *o, Nodo *e) {
	//Imposta le cordinate del nodo
	this->x = xx;
	this->y = yy;
	
	this->nord = n;
	this->sud = s;
	this->ovest = o;
	this->est = e;
};

int Nodo::getCordX() {
	return this->x;
}

int Nodo::getCordY() {
	return this->y;
}

Nodo* Nodo::goNord() {
	if (this->nord != 0) {
		return this->nord;
	} else {
		this->nord = new Nodo(this->x, this->y-1, 0, this, 0, 0);
		return this->nord;
	}
}

Nodo* Nodo::goSud() {
	if (this->sud != 0) {
		return this->sud;
	} else {
		this->sud = new Nodo(this->x, this->y+1, this, 0, 0, 0);
		return this->sud;
	}
}

Nodo* Nodo::goOvest() {
	if (this->ovest != 0) {
		return this->ovest;
	} else {
		this->ovest = new Nodo(this->x-1, this->y, 0, 0, 0, this);
		return this->ovest;
	}
}

Nodo* Nodo::goEst() {
	if (this->est != 0) {
		return this->est;
	} else {
		this->est = new Nodo(this->x+1, this->y, 0, 0, this, 0);
		return this->est;
	}
}

Nodo* Nodo::getNord() {
	return this->nord;
}
Nodo* Nodo::getSud() {
	return this->sud;
}
Nodo* Nodo::getOvest() {
	return this->ovest;
}
Nodo* Nodo::getEst() {
	return this->est;
}