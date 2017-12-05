#include "Mole.h"

Mole::Mole(sf::Vector2f size, int xCoordinate, int yCoordinate) : sf::RectangleShape(size)
{
	this->xCoordinate = xCoordinate;
	this->yCoordinate = yCoordinate;

	animDeltaTime = 0.0f;

	moleTexture.loadFromFile(MOLE_TEXTURE);
	this->setTexture(&moleTexture);
	moleAnim = new Animation(&moleTexture, sf::Vector2u(TEXTURE_COLS, TEXTURE_ROWS), ACTIVE_MOLE_DURATION / (float)(TEXTURE_COLS * TEXTURE_ROWS));

	moleClickedTexture.loadFromFile(MOLE_CLICKED_TEXTURE);
	moleClickedAnim = new Animation(&moleClickedTexture, sf::Vector2u(TEXTURE_COLS, TEXTURE_ROWS), ACTIVE_MOLE_DURATION / (float)(TEXTURE_COLS * TEXTURE_ROWS));

	isActive = false;
	isClicked = false;
	activeDeltaTime = 0.0f;
}

Mole::~Mole()
{
	delete moleAnim;
	delete moleClickedAnim;
}

void Mole::updateActiveStatus()
{
	if (isActive)
	{
		activeDeltaTime = moleActiveTimer.getElapsedTime().asSeconds();

		if (activeDeltaTime > ACTIVE_MOLE_DURATION)
		{
			isActive = false;
			isClicked = false;
			moleActiveTimer.restart();
		}
	}
}

void Mole::restartActiveTimer()
{
	moleActiveTimer.restart();
}

void Mole::updateTexture()
{
	animDeltaTime = animTimer.getElapsedTime().asSeconds();
	animTimer.restart();

	if (isClicked)
	{
		moleClickedAnim->update(animDeltaTime);
		this->setTexture(&moleClickedTexture);
		this->setTextureRect(moleClickedAnim->uvRect);
	}
	else
	{
		moleAnim->update(animDeltaTime);
		// update the clicked animation so that it remains synced up until it is clicked
		moleClickedAnim->update(animDeltaTime);
		this->setTexture(&moleTexture);
		this->setTextureRect(moleAnim->uvRect);
	}	
}

void Mole::resetAnimation()
{
	moleAnim->reset();
	moleClickedAnim->reset();
}

void Mole::restartAnimTimer()
{
	animTimer.restart();
}
