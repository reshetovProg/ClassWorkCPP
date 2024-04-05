#include "Player.h"

Player::Player(char symbol, int positionX, int PositionY)
{
    this->symbol = symbol;
    this->positionX = positionX;
    this->positionY = positionY;
}

void Player::setX(int positionX)
{
    this->positionX = positionX;
}

void Player::setY(int positionY)
{
    this->positionY = positionY;
}

int Player::getX()
{
    return positionX;
}

int Player::getY()
{
    return positionY;
}
