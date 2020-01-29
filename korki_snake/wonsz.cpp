#include "wonsz.h"

wonsz::wonsz()
{
}

wonsz::~wonsz()
{
}

wonsz::wonsz(int x, int y, int lgth)
{
	for (int i = 0; i<lgth; i++)
	{
		CialoWensza.push_back(segment(x, y));
	}
	setkierunek(GORA);
}

void wonsz::ruch(int kierunek)
{
	for (int i = getrozmiar()-1; i >= 1; i--)
	{
		CialoWensza.at(i).setKordX(CialoWensza.at(i - 1).getKordX());
		CialoWensza.at(i).setKordY(CialoWensza.at(i - 1).getKordY());
	}
	switch (kierunek)
	{
	case GORA: 
		CialoWensza.at(0).setKordY(CialoWensza.at(0).getKordY()-1);
		break;
	case DOL:
		CialoWensza.at(0).setKordY(CialoWensza.at(0).getKordY() + 1);
		break;
	case PRAWO:
		CialoWensza.at(0).setKordX(CialoWensza.at(0).getKordX()+1);
		break;
	case LEWO:
		CialoWensza.at(0).setKordX(CialoWensza.at(0).getKordX()-1);
		break;
	}
}

void wonsz::rosnij()
{
	int x=CialoWensza.at(getrozmiar()-1).getKordX(), y=CialoWensza.at(getrozmiar()-1).getKordY();
	CialoWensza.push_back(segment(x, y));
}

void wonsz::setkierunek(int a)
{
	if(a!=0)
	if(abs(a)- abs(kierunek)!=0)
	this->kierunek = a;
}

int wonsz::getkierunek()
{
	return kierunek;
}

segment wonsz::getsegment(int a)
{
	return CialoWensza.at(a);
}

int wonsz::getrozmiar()
{
	return CialoWensza.size();
}
