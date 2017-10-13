#include <SFML/Graphics.hpp>
#include <iostream>


const int WINDOW_SIZE_X = 800;
const int WINDOW_SIZE_Y = 600;

const float POINTER_SIZE_X = 100.0;
const float POINTER_SIZE_Y = 100.0;
const std::string POINTER_TEXTURE = "images/hammer.png";

const std::string MOLE_HOLE_TEXTURE = "images/ellipse.png";
const float MOLE_HOLE_SIZE_X = 200.0;
const float MOLE_HOLE_SIZE_Y = 100.0;

int main()
{
	sf::RenderWindow gameWindow(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "Whack-A-Mole", sf::Style::Close);
	sf::RectangleShape background(sf::Vector2f((float)WINDOW_SIZE_X, (float)WINDOW_SIZE_Y));
	background.setFillColor(sf::Color::Green);

	sf::RectangleShape moleHoles[3][3];
	sf::Texture moleHoleTexture;
	moleHoleTexture.loadFromFile(MOLE_HOLE_TEXTURE);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			moleHoles[i][j] = sf::RectangleShape(sf::Vector2f(MOLE_HOLE_SIZE_X, MOLE_HOLE_SIZE_Y));
			moleHoles[i][j].setTexture(&moleHoleTexture);
			float xOffset = 250;
			float yOffset = 200;
			moleHoles[i][j].setPosition((float)(i * xOffset + 50), (float)(j * yOffset + 75));
		}
	}

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
		gameWindow.draw(background);
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				gameWindow.draw(moleHoles[i][j]);
			}
		}
		gameWindow.draw(mousePointer);
		gameWindow.display();
	}

	return 0;
}
