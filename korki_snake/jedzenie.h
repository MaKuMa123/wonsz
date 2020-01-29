#pragma once
class jedzenie
{
public:
	jedzenie();
	~jedzenie();
	int getX(); int getY();
	void setXY(int x, int y);
private:
	int x, y;
};

