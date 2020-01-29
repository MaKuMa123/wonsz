#include "plansza.h"
#include "wonsz.h"
#include "jedzenie.h"
#include <iostream>
#include <time.h>
#include <cstdlib>
 

plansza::~plansza()
{
	for (int i = 0; i < sizeof(mapa[i]); i++)
	{
		delete this->mapa[i];
		
	}
	delete mapa;
}

plansza::plansza(int x, int y)
{
	this->x = x;
	this->y = y;
	this->mapa = new int*[x];
	for (int i = 0; i < x; i++)
	{
		this->mapa[i] = new int[y];
		for (int j = 0; j < y; j++)
		{
			if (i == 0 || i == x - 1 || j == 0 || j == y - 1)
			{
				mapa[i][j] = SCIANA;
			}
			else {
				mapa[i][j] = PUSTE;
			}
			
		}
	}
}

int** plansza::getmapa()
{
	return mapa;
}

void plansza::start()
{
	flaga = false;
	wensz = wonsz(x/2, y/2, 3);
	jedzeniee = jedzenie();
	LOSULOSU();
}

void plansza::koniec()
{
	flaga = true;
}

void plansza::update()
{
	wensz.ruch(wensz.getkierunek());
	int Wartosc = mapa[wensz.getsegment(0).getKordY()][wensz.getsegment(0).getKordX()];

	switch (Wartosc) {
	default:
		break;
	case JEDZENIE:
		wensz.rosnij();
		break;
	case SCIANA:
		koniec();
		break;
	case WONSZ:
		koniec();
		break;
			}

	for (int i = 0; i < x; i++)
	{
		
		for (int j = 0; j < y; j++)
		{
			if (i == 0 || i == x - 1 || j == 0 || j == y - 1)
			{
				mapa[i][j] = SCIANA;
			}
			else {
				mapa[i][j] = PUSTE;
			}

		}
	}
	for (int i = 0; i<wensz.getrozmiar(); i++)
	{
		 int xpom = wensz.getsegment(i).getKordX();
		 int ypom = wensz.getsegment(i).getKordY();
		 mapa[ypom][xpom] = WONSZ;
		 
	}
	int xpom2 = jedzeniee.getX();
	int ypom2 = jedzeniee.getY();
	mapa[ypom2][xpom2] = JEDZENIE;
}

void plansza::LOSULOSU()
{
	int xpom3, ypom3;
	srand(time(NULL));
	do
	{
		xpom3 = std::rand() % x;
		ypom3 = std::rand() % y;
	} while (mapa[xpom3][ypom3] != PUSTE);
	jedzeniee.setXY(xpom3, ypom3);
}

void plansza::setkierunek(int kierunek)
{
	wensz.setkierunek(kierunek);
}

bool plansza::czyKoniec()
{
	return flaga;
}
