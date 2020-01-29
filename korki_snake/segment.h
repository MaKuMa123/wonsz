#pragma once
class segment
{
public:
	segment();
	~segment();
	segment(int x, int y);
	int getKordX();
	int getKordY();
	void setKordX(int x);
	void setKordY(int y);
private:
	int kordX;
	int kordY;

};

