#include "ScoreScreen.h"

ScoreScreen::ScoreScreen(int score)
{
	this->score = score;

	backgroundTexture.loadFromFile(BACKGROUND_TEXTURE);
	background.setTexture(&backgroundTexture);

	// TODO: replay button stuff


}

void ScoreScreen::display(sf::RenderWindow* window)
{
	window->clear();
	window->draw(background);
}
