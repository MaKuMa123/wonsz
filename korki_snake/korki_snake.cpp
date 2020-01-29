#include <iostream>
#include "plansza.h"
#include <Windows.h>
#include <conio.h>
#include <ctime>
#include <chrono>
using namespace std;

void zwracaMape(int** mapa)
{
	system("cls");

	for (int i = 0; i < 20; i++)
	{
		
		for (int j = 0; j<20; j++)
		{
			
			if (mapa[i][j] == plansza::PUSTE)
			{
				cout << "   ";
			}
			else if (mapa[i][j] == plansza::WONSZ)
			{
				cout << "[ ]";
			}
			else if (mapa[i][j] == plansza::JEDZENIE)
			{
				cout << " * ";
			}
			else if (mapa[i][j] == plansza::SCIANA)
			{
				cout << "###";
			}
			
		}
		cout << endl;
	}
	
}
int Kierunek()
{
	int k=0;
	if (GetAsyncKeyState('D'))
	{
		k = wonsz::PRAWO;
	}
	else if (GetAsyncKeyState('S'))
	{
		k = wonsz::DOL;
	}
	else if (GetAsyncKeyState('A'))
	{
		k = wonsz::LEWO;
	}
	else if (GetAsyncKeyState('W'))
	{
		k = wonsz::GORA;
	}
	return k;
}


int main()
{
	auto start = chrono::system_clock::now();
	auto aktualne = chrono::system_clock::now();
	
	float interval=0.3;
	plansza gra = plansza(20, 20);
	gra.start();
	while (!gra.czyKoniec())
	{
		aktualne = chrono::system_clock::now();
		chrono::duration<float> tajm=aktualne-start;
		float tajmUplynol=tajm.count();
		if (tajmUplynol>interval)
		{
			start = chrono::system_clock::now();
			gra.update();
			zwracaMape(gra.getmapa());
		}
		
		
			gra.setkierunek(Kierunek());
		
	}
	
	
	
	
	return 0;
}

