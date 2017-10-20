#include "GameWindow.h"

GameWindow::GameWindow(sf::Uint32 style) 
	: sf::RenderWindow(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "Whack-A-Mole", style), 
	playScreen(PlayScreen::NUM_MOLE_HOLE_COLS, PlayScreen::NUM_MOLE_HOLE_ROWS, sf::Vector2f((float)WINDOW_SIZE_X, (float)WINDOW_SIZE_Y))
{
	this->setMouseCursorVisible(false);
}

void GameWindow::drawPlayScreen()
{
	this->clear();
	this->draw(playScreen.background);
	for (int i = 0; i < PlayScreen::NUM_MOLE_HOLE_COLS; i++)
	{
		for (int j = 0; j < PlayScreen::NUM_MOLE_HOLE_ROWS; j++)
		{
			this->draw(playScreen.moleHoles[i][j]);
		}
	}

	for (int i = 0; i < PlayScreen::NUM_MOLE_HOLE_COLS; i++)
	{
		for (int j = 0; j < PlayScreen::NUM_MOLE_HOLE_ROWS; j++)
		{
			if (playScreen.moles[i][j].isActive)
			{
				this->draw(playScreen.moles[i][j]);
			}
		}
	}

	sf::Vector2i mousePos = sf::Mouse::getPosition(*this);
	playScreen.mousePointer->setPosition((float)mousePos.x, (float)mousePos.y);
	
	this->draw(*playScreen.mousePointer);

	this->display();

}
