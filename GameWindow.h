#pragma once
#include <SFML/Graphics.hpp>
#include "PlayScreen.h"

class GameWindow : public sf::RenderWindow
{
public:
	const static int WINDOW_SIZE_X = 800;
	const static int WINDOW_SIZE_Y = 600;

public:
	GameWindow(sf::Uint32 style);
	PlayScreen playScreen;
	void drawPlayScreen();

private:
	sf::Vector2i mousePos;
};
