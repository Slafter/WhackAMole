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
		// TODO
	}
	else if (activeScreen == PLAY_SCREEN)
	{
		playScreen.draw(this);
	}
	else if (activeScreen == SCORE_SCREEN)
	{
		// TODO
	}
}


void GameWindow::handleMouseClick()
{
	if (activeScreen == PLAY_SCREEN)
	{
		mousePos = sf::Mouse::getPosition(*this);
		playScreen.handleMouseClick(mousePos);
	}
}

void GameWindow::updateActiveScreenItems()
{
	if (activeScreen == START_SCREEN)
	{

	}
	else if (activeScreen == PLAY_SCREEN)
	{
		playScreen.updateTimerBar();
		playScreen.updateMoleCreationRate();
		playScreen.updateMoleCreation();
		playScreen.updateActiveMoles();
		if (playScreen.isGameOver())
		{
			activeScreen = SCORE_SCREEN;
		}

	}
	else if (activeScreen == SCORE_SCREEN)
	{

	}
}
