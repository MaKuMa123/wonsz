#pragma once
#include "wonsz.h"
#include "jedzenie.h"

class plansza
{
	
public:
	
	~plansza();
	plansza(int x, int y);
	static const int PUSTE = 0;
	static const int WONSZ = 1;
	static const int JEDZENIE = 2;
	static const int SCIANA = 3;
	int** getmapa();
	void start();
	void koniec();
	void update();
	void LOSULOSU();
	void setkierunek(int kierunek);
	bool czyKoniec();
private:
	int** mapa;
	wonsz wensz;
	jedzenie jedzeniee;
	int x, y;
	int kierunek;
	bool flaga;

};

