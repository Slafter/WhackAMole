#include <SFML/Graphics.hpp>
#include <iostream>

const float POINTER_SIZE_X = 100.0;
const float POINTER_SIZE_Y = 100.0;
const std::string POINTER_TEXTURE = "hammer.png";

int main()
{
	sf::RenderWindow gameWindow(sf::VideoMode(800, 600), "Whack-A-Mole", sf::Style::Close);

	sf::RectangleShape mousePointer(sf::Vector2f(POINTER_SIZE_X, POINTER_SIZE_Y));
	sf::Texture mouseTexture;
	mouseTexture.loadFromFile(POINTER_TEXTURE);
	mousePointer.setTexture(&mouseTexture);

	sf::Event evnt;
	sf::Vector2i mousePos;

	while (gameWindow.isOpen())
	{
		while (gameWindow.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::Closed)
				gameWindow.close();
		}

		mousePos = sf::Mouse::getPosition(gameWindow);
		mousePointer.setPosition((float)mousePos.x, (float)mousePos.y);

		gameWindow.clear();
		gameWindow.draw(mousePointer);
		gameWindow.display();
	}

	return 0;
}
