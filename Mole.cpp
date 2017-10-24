#include "Mole.h"

Mole::Mole()
{
	this->xCoordinate = 0;
	this->yCoordinate = 0;
	moleTexture.loadFromFile(MOLE_TEXTURE);
	this->setTexture(&moleTexture);
	this->isActive = true;
}

Mole::Mole(sf::Vector2f size, int xCoordinate, int yCoordinate) : sf::RectangleShape(size)
{
	this->xCoordinate = xCoordinate;
	this->yCoordinate = yCoordinate;
	moleTexture.loadFromFile(MOLE_TEXTURE);
	this->setTexture(&moleTexture);
	this->isActive = true;
}
