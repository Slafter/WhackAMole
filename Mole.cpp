#include "Mole.h"

Mole::Mole()
{
	xCoordinate = 0;
	yCoordinate = 0;

	animDeltaTime = 0.0f;

	moleTexture.loadFromFile(MOLE_TEXTURE);

	moleAnim.imageCount = sf::Vector2u(TEXTURE_COLS, TEXTURE_ROWS);
	moleAnim.switchTime = ACTIVE_MOLE_DURATION / (float)(TEXTURE_COLS * TEXTURE_ROWS);
	moleAnim.totalTime = 0.0f;
	moleAnim.currentImage.x = 0;
	moleAnim.currentImage.y = 0;
	moleAnim.uvRect.width = moleTexture.getSize().x / (float)(moleAnim.imageCount.x);
	moleAnim.uvRect.height = moleTexture.getSize().y / (float)(moleAnim.imageCount.y);

	// moleTexture.loadFromFile(MOLE_TEXTURE);
	this->setTexture(&moleTexture);

	isActive = false;
	deltaTime = 0.0f;
}

Mole::Mole(sf::Vector2f size, int xCoordinate, int yCoordinate) : sf::RectangleShape(size)
{
	this->xCoordinate = xCoordinate;
	this->yCoordinate = yCoordinate;
	moleTexture.loadFromFile(MOLE_TEXTURE);
	this->setTexture(&moleTexture);
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

void Mole::updateTexture()
{
	animDeltaTime = animTimer.getElapsedTime().asSeconds();
	animTimer.restart();
	moleAnim.update(animDeltaTime);
	this->setTextureRect(moleAnim.uvRect);
		
}
