#include "PlayScreen.h"

PlayScreen::PlayScreen()
{

}

PlayScreen::PlayScreen(int numCols, int numRows, sf::Vector2f windowSize) : background(windowSize)
{
	background.setFillColor(sf::Color::Green); // TODO: replace with sf::Texture

	mousePointer = new sf::RectangleShape(sf::Vector2f(MOUSE_POINTER_SIZE_X, MOUSE_POINTER_SIZE_Y));
	mouseTexture.loadFromFile(MOUSE_TEXTURE);
	mousePointer->setTexture(&mouseTexture);

	float moleHoleSizeX = 600.0f / (float)numCols;
	float moleHoleSizeY = 300.0f / (float)numRows;
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
