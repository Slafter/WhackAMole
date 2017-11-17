#pragma once
#include <SFML/Graphics.hpp>
#include <cstdlib>

class ScoreScreen
{
public:
	const std::string BACKGROUND_TEXTURE = "images/SSbackground.png";
	const std::string REPLAY_TEXTURE = ""; // TODO

public:
	ScoreScreen(int score);
	void display(sf::RenderWindow* window);

private:
	sf::Texture backgroundTexture;
	sf::RectangleShape background;
	sf::Texture replayButtonTexture;
	sf::RectangleShape replayButton;
	int score;


};