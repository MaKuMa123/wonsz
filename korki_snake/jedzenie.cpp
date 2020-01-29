#include "jedzenie.h"

jedzenie::jedzenie()
{
	this->x = 0;
	this->y = 0;
}

jedzenie::~jedzenie()
{
}

int jedzenie::getX()
{
	return x;
}

int jedzenie::getY()
{
	return y;
}

void jedzenie::setXY(int x, int y)
{
	this->x = x;
	this->y = y;
}
