#ifndef Nodo_H
#define Nodo_H

class Nodo {
private:
	Nodo *nord, *sud, *ovest, *est;
	int x,y;
	
public:
	Nodo(int xx, int yy, Nodo *n, Nodo *s, Nodo *o, Nodo *e);
	int getCordX();
	int getCordY();
	Nodo* goNord();
	Nodo* goSud();
	Nodo* goOvest();
	Nodo* goEst();
	Nodo* getNord();
	Nodo* getSud();
	Nodo* getOvest();
	Nodo* getEst();
	
};

#endif