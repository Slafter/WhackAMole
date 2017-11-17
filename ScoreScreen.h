#pragma once
#include <SFML/Graphics.hpp>
#include <cstdlib>

#include <iostream>

class ScoreScreen
{
public:
	const std::string BACKGROUND_TEXTURE = "images/SSbackground.png";
	const std::string FONT = "fonts/uni0553-webfont.ttf";
	const std::string REPLAY_TEXTURE = ""; // TODO

public:
	ScoreScreen(sf::Vector2f windowSize);
	void display(sf::RenderWindow* window);

private:
	void createHeader();
	void createScoreSection();
	void createDescription();

private:
	sf::Texture backgroundTexture;
	sf::RectangleShape background;
	sf::Texture replayButtonTexture;
	sf::RectangleShape replayButton;
	sf::Font font;
	sf::Text gameOver;
	sf::Text gameOverShadow;
	sf::RectangleShape scoreOutline;
	sf::Text scoreText;
	sf::Text scoreValue;
	sf::Text scoreDescription;
	sf::Text scoreDescriptionShadow;
	int score;

};