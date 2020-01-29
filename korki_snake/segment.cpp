#include "segment.h"

segment::segment()
{
	this->kordX = 0;
	this->kordY = 0;
}

segment::~segment()
{
}

segment::segment(int x, int y)
{
	this->kordX = x;
	this->kordY = y;
}

int segment::getKordX()
{
	return kordX;
}

int segment::getKordY()
{
	return kordY;
}

void segment::setKordX(int x)
{
	this->kordX = x;
}

void segment::setKordY(int y)
{
	this->kordY = y;
}
