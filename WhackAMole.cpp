#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameWindow.h"

int main()
{
	GameWindow gameWindow(sf::Style::Close);

	sf::Event evnt;
	sf::Vector2i mousePos;

	while (gameWindow.isOpen())
	{
		while (gameWindow.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::Closed)
				gameWindow.close();
		}

		gameWindow.drawPlayScreen();

	}

	return 0;
}
