#include "GameWindow.h"

GameWindow::GameWindow(sf::Uint32 style) 
	: sf::RenderWindow(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "Whack-A-Mole", style), 
	playScreen(PlayScreen::NUM_MOLE_HOLE_COLS, PlayScreen::NUM_MOLE_HOLE_ROWS, sf::Vector2f((float)WINDOW_SIZE_X, (float)WINDOW_SIZE_Y))
{
	this->setMouseCursorVisible(false);
	this->activeScreen = PLAY_SCREEN; // TODO: remove once other screens are implemented
}

void GameWindow::displayActiveScreen()
{
	if (activeScreen == START_SCREEN)
	{
		this->displayStartScreen();
	}
	else if (activeScreen == PLAY_SCREEN)
	{
		this->displayPlayScreen();
	}
	else if (activeScreen == SCORE_SCREEN)
	{
		this->displayScoreScreen();
	}
}

void GameWindow::displayStartScreen()
{
	// TODO
}

void GameWindow::displayPlayScreen()
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

	mousePos = sf::Mouse::getPosition(*this);
	playScreen.mousePointer.setPosition((float)mousePos.x, (float)mousePos.y);
	
	this->draw(playScreen.mousePointer);

	this->display();

}

void GameWindow::displayScoreScreen()
{
	// TODO
}

void GameWindow::handleMouseClick()
{
	if (activeScreen == PLAY_SCREEN)
	{
		playScreen.handleMouseClick(mousePos);
	}
}
