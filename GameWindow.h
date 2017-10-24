#pragma once
#include <SFML/Graphics.hpp>
#include "PlayScreen.h"

class GameWindow : public sf::RenderWindow
{
public:
	const static int WINDOW_SIZE_X = 800;
	const static int WINDOW_SIZE_Y = 600;
	const static int START_SCREEN = 0;
	const static int PLAY_SCREEN = 1;
	const static int SCORE_SCREEN = 2;

public:
	GameWindow(sf::Uint32 style);
	void handleMouseClick();
	void displayActiveScreen();

public:
	PlayScreen playScreen;

private:
	void displayStartScreen();
	void displayPlayScreen();
	void displayScoreScreen();

private:
	sf::Vector2i mousePos;
	int activeScreen;
};
