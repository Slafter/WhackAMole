#include "PlayScreen.h"

PlayScreen::PlayScreen()
{

}

PlayScreen::PlayScreen(int numCols, int numRows, sf::Vector2f windowSize) : background(windowSize), mousePointer(sf::Vector2f(MOUSE_POINTER_SIZE_X, MOUSE_POINTER_SIZE_Y))
{
	std::srand(time(0));

	molesWhacked = 0;
	moleDeltaTime = 0;
	createMoleFreq = STARTING_MOLE_FREQ;

	background.setFillColor(sf::Color::Green); // TODO: replace with sf::Texture

	mouseTexture.loadFromFile(MOUSE_TEXTURE);
	mousePointer.setTexture(&mouseTexture);

	moleHoleSizeX = 600.0f / (float)numCols;
	moleHoleSizeY = 300.0f / (float)numRows;
	float xOrigin = 450.0f / numCols;
	float yOrigin = 50.0f + (300.0f / numRows);
	float xOffset = (windowSize.x - xOrigin / 2.0f) / (float)numCols;
	float yOffset = (windowSize.y - yOrigin / 2.0f) / (float)numRows;

	moleHoleTexture.loadFromFile(MOLE_HOLE_TEXTURE);

	for (int i = 0; i < numCols; i++)
	{
		for (int j = 0; j < numRows; j++)
		{
			moleHoles[i][j] = sf::RectangleShape(sf::Vector2f(moleHoleSizeX, moleHoleSizeY));
			moleHoles[i][j].setOrigin(moleHoleSizeX / 2.0f, moleHoleSizeY / 2.0f);
			moleHoles[i][j].setPosition((float)(i * xOffset + xOrigin), (float)(j * yOffset + yOrigin));
			moleHoles[i][j].setTexture(&moleHoleTexture);
		}
	}

	for (int i = 0; i < numCols; i++)
	{
		for (int j = 0; j < numRows; j++)
		{
			moles[i][j].setSize(sf::Vector2f(moleHoleSizeY, moleHoleSizeY)); // moles are squares, henze a (y, y) size
			moles[i][j].xCoordinate = i;
			moles[i][j].yCoordinate = j;
			moles[i][j].setOrigin(moleHoleSizeY / 2.0f, moleHoleSizeY / 2.0f);
			moles[i][j].setPosition((float)(i * xOffset + xOrigin), (float)(j * yOffset + yOrigin));
		}
	}

}

void PlayScreen::handleMouseClick(sf::Vector2i mousePos)
{
	// TODO pause button, audio

	for (int i = 0; i < NUM_MOLE_HOLE_COLS; i++)
	{
		for (int j = 0; j < NUM_MOLE_HOLE_ROWS; j++)
		{
			if (this->mouseClicksMole(mousePos, i, j) && moles[i][j].isActive)
			{
				moles[i][j].isActive = false;
				molesWhacked++;
			}
		}
	}
}

bool PlayScreen::mouseClicksMole(sf::Vector2i mousePos, int xCoord, int yCoord)
{
	int moleCoordX1 = (int)moles[xCoord][yCoord].getPosition().x - (int)(moleHoleSizeY / 2.0f); // size Y is not a typo
	int moleCoordX2 = moleCoordX1 + (int)moleHoleSizeY;
	int moleCoordY1 = (int)moles[xCoord][yCoord].getPosition().y - (int)(moleHoleSizeY / 2.0f);
	int moleCoordY2 = moleCoordY1 + (int)moleHoleSizeY;

	if (mousePos.x > moleCoordX1 && mousePos.x < moleCoordX2)
	{
		if (mousePos.y > moleCoordY1 && mousePos.y < moleCoordY2)
		{
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

int PlayScreen::getMolesWhacked()
{
	return molesWhacked;
}

void PlayScreen::updateActiveMoles()
{
	for (int i = 0; i < NUM_MOLE_HOLE_COLS; i++)
	{
		for (int j = 0; j < NUM_MOLE_HOLE_ROWS; j++)
		{
			moles[i][j].updateActiveStatus();
			moles[i][j].updateTexture();
		}
	}
}

void PlayScreen::updateMoleCreation()
{
	moleDeltaTime = moleCreationTimer.getElapsedTime().asSeconds();

	if (moleDeltaTime > createMoleFreq)
	{
		std::vector<Mole*> inactiveMoles;
		int numActive = 0;

		for (int i = 0; i < NUM_MOLE_HOLE_COLS; i++)
		{
			for (int j = 0; j < NUM_MOLE_HOLE_ROWS; j++)
			{
				if (!moles[i][j].isActive)
				{
					inactiveMoles.push_back(&moles[i][j]);
					numActive++;
				}
			}
		}

		if (numActive > 0)
		{
			int randMoleIndex = rand() % numActive;
			inactiveMoles[randMoleIndex]->isActive = true;
			inactiveMoles[randMoleIndex]->animTimer.restart(); ////
			inactiveMoles[randMoleIndex]->moleAnim.reset(); ////
			inactiveMoles[randMoleIndex]->restartTimer();
		}

		moleCreationTimer.restart();
	}
}

void PlayScreen::updateMoleCreationRate()
{
	if (timerBarClock.getElapsedTime().asSeconds() > THIRD_PHASE_START_TIME)
	{
		createMoleFreq = THIRD_MOLE_FREQ;
	}
	else if (timerBarClock.getElapsedTime().asSeconds() > SECOND_PHASE_START_TIME)
	{
		createMoleFreq = SECOND_MOLE_FREQ;
	}

}
