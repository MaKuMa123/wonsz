#pragma once
#include <vector>
#include "segment.h"
class wonsz
{
public:
	wonsz();
	~wonsz();
	wonsz(int x, int y, int lgth);
	void ruch(int kierunek);
	void rosnij();
	int kierunek;
	int getkierunek();
	void setkierunek(int k);
	static const int GORA = 4;
	static const int DOL = -4;
	static const int PRAWO = 6;
	static const int LEWO = -6;
	segment getsegment(int a);
	int getrozmiar();
private:
	std::vector<segment> CialoWensza;

};

