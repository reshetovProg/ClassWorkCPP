#pragma once
class Player
{
	char symbol;
	int positionX = 0;
	int positionY = 0;
public:
	Player(char symbol, int positionX, int PositionY);
	void setX(int positionX);
	void setY(int positionY);
	int getX();
	int getY();

};

