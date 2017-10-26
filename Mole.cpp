#include "Mole.h"

Mole::Mole()
{
	xCoordinate = 0;
	yCoordinate = 0;
	moleTexture.loadFromFile(MOLE_TEXTURE);
	setTexture(&moleTexture);
	isActive = false;
	deltaTime = 0.0f;
}

Mole::Mole(sf::Vector2f size, int xCoordinate, int yCoordinate) : sf::RectangleShape(size)
{
	this->xCoordinate = xCoordinate;
	this->yCoordinate = yCoordinate;
	moleTexture.loadFromFile(MOLE_TEXTURE);
	setTexture(&moleTexture);
	isActive = false;
	deltaTime = 0.0f;
}

void Mole::updateActiveStatus()
{
	if (isActive)
	{
		deltaTime = moleTimer.getElapsedTime().asSeconds();

		if (deltaTime > ACTIVE_MOLE_DURATION)
		{
			isActive = false;
			moleTimer.restart();
		}
	}
}

void Mole::restartTimer()
{
	moleTimer.restart();
}
