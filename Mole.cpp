#include "Mole.h"

Mole::Mole(sf::Vector2f size, int xCoordinate, int yCoordinate) : sf::RectangleShape(size)
{
	this->xCoordinate = xCoordinate;
	this->yCoordinate = yCoordinate;
	moleTexture.loadFromFile(MOLE_TEXTURE);
	this->setTexture(&moleTexture);
}

int Mole::getXCoord()
{
	return this->xCoordinate;
}

int Mole::getYCoord()
{
	return this->yCoordinate;
}