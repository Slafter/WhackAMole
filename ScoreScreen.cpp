#include "ScoreScreen.h"

ScoreScreen::ScoreScreen(sf::Vector2f windowSize)
	: background(windowSize)
{
	score = 15; // TODO: change to zero before merge to master

	backgroundTexture.loadFromFile(BACKGROUND_TEXTURE);
	background.setTexture(&backgroundTexture);

	// TODO: replay button stuff

	font.loadFromFile(FONT);

	createHeader();
	createScoreSection();
	createDescription();
}

void ScoreScreen::display(sf::RenderWindow* window)
{
	window->clear();
	window->draw(background);
	window->draw(gameOverShadow);
	window->draw(gameOver);
	window->draw(scoreOutline);
	window->draw(scoreText);
	window->draw(scoreValue);
	window->draw(scoreDescriptionShadow);
	window->draw(scoreDescription);
	window->display();
}

// to de-clutter the constructor
void ScoreScreen::createHeader()
{
	gameOver.setFont(font);
	gameOver.setCharacterSize(80);
	gameOver.setString("---Game Over---");
	gameOver.setPosition(sf::Vector2f(18.0f, 5.0f));

	gameOverShadow.setFont(font);
	gameOverShadow.setCharacterSize(80);
	gameOverShadow.setString("---Game Over---");
	gameOverShadow.setFillColor(sf::Color::Black);
	gameOverShadow.setPosition(sf::Vector2f(21.0f, 8.0f));
}

// to de-clutter the constructor
void ScoreScreen::createScoreSection()
{
	//***********************************************************/
	// the world's most complex way of making a see-through box.
	// scoreOutline copies the background texture behind it based
	// on it's position, making it compatible with changes to it's
	// position or changes to the background texture.
	//***********************************************************/
	scoreOutline.setTexture(&backgroundTexture);
	sf::Vector2f scoreOutlineSize(350.0f, 100.0f);
	scoreOutline.setSize(scoreOutlineSize);
	sf::Vector2f scoreOutlinePosition(225.0f, 200.0f);
	scoreOutline.setPosition(scoreOutlinePosition);
	scoreOutline.setTextureRect(sf::IntRect(scoreOutlinePosition.x * 10,
		scoreOutlinePosition.y * 10, scoreOutlineSize.x * 10, scoreOutlineSize.y * 10));
	scoreOutline.setOutlineColor(sf::Color::Black);
	scoreOutline.setOutlineThickness(4);

	scoreText.setFont(font);
	scoreText.setCharacterSize(45);
	scoreText.setFillColor(sf::Color(20, 100, 10));
	scoreText.setString("Score:");
	scoreText.setPosition(sf::Vector2f(245.0f, 220.0f));

	scoreValue.setFont(font);
	scoreValue.setCharacterSize(45);
	scoreValue.setString(std::to_string(score * 100));
	scoreValue.setPosition(sf::Vector2f(435.0f, 220.0f));
}

// to de-clutter the constructor
void ScoreScreen::createDescription()
{
	scoreDescription.setFont(font);
	scoreDescription.setCharacterSize(70);
	scoreDescription.setString("Great Job!!");
	scoreDescription.setPosition(sf::Vector2f(190.0f, 340.0f));

	scoreDescriptionShadow.setFont(font);
	scoreDescriptionShadow.setCharacterSize(70);
	scoreDescriptionShadow.setFillColor(sf::Color::Black);
	scoreDescriptionShadow.setString("Great Job!!");
	scoreDescriptionShadow.setPosition(sf::Vector2f(193.0f, 343.0f));
}
