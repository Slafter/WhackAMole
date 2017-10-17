#include <SFML/Graphics.hpp>
#include <iostream>

const int WINDOW_SIZE_X = 800;
const int WINDOW_SIZE_Y = 600;

const std::string MOLE_HOLE_TEXTURE = "images/ellipse.png";
const int NUM_MOLE_HOLE_COLS = 3;
const int NUM_MOLE_HOLE_ROWS = 3;
const float MOLE_HOLE_SIZE_X = 600.0 / (float)NUM_MOLE_HOLE_COLS;
const float MOLE_HOLE_SIZE_Y = 300.0 / (float)NUM_MOLE_HOLE_ROWS;

const std::string POINTER_TEXTURE = "images/hammer.png";
const float POINTER_SIZE_X = 100.0;
const float POINTER_SIZE_Y = 100.0;

sf::RectangleShape** createMoleHoleMatrix();
void applyTextureToMoleHoles(sf::RectangleShape** moleHoles, const sf::Texture& holeTexture);
void drawMoleHoles(sf::RenderWindow& gameWindow, sf::RectangleShape** moleHoles);

int main()
{
	sf::RenderWindow gameWindow(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "Whack-A-Mole", sf::Style::Close);

	sf::RectangleShape background(sf::Vector2f((float)WINDOW_SIZE_X, (float)WINDOW_SIZE_Y));
	background.setFillColor(sf::Color::Green);

	sf::RectangleShape** moleHoles = createMoleHoleMatrix();

	sf::Texture moleHoleTexture;
	moleHoleTexture.loadFromFile(MOLE_HOLE_TEXTURE);
	applyTextureToMoleHoles(moleHoles, moleHoleTexture);

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
		drawMoleHoles(gameWindow, moleHoles);
		gameWindow.draw(mousePointer);
		gameWindow.display();
	}

	delete moleHoles;

	return 0;
}

sf::RectangleShape** createMoleHoleMatrix()
{
	float xOrigin = 150.0 / (float)NUM_MOLE_HOLE_COLS;
	float yOrigin = 75.0;
	float xOffset = (WINDOW_SIZE_X - xOrigin) / (float)NUM_MOLE_HOLE_COLS;
	float yOffset = (WINDOW_SIZE_Y - yOrigin) / (float)NUM_MOLE_HOLE_ROWS;

	sf::RectangleShape** moleHoles;
	moleHoles = new sf::RectangleShape*[NUM_MOLE_HOLE_COLS];

	for (int i = 0; i < NUM_MOLE_HOLE_COLS; i++)
	{
		moleHoles[i] = new sf::RectangleShape[NUM_MOLE_HOLE_ROWS];

		for (int j = 0; j < NUM_MOLE_HOLE_ROWS; j++)
		{
			moleHoles[i][j] = sf::RectangleShape(sf::Vector2f(MOLE_HOLE_SIZE_X, MOLE_HOLE_SIZE_Y));
			moleHoles[i][j].setPosition((float)(i * xOffset + xOrigin), (float)(j * yOffset + yOrigin));
		}
	}

	return moleHoles;
}

void applyTextureToMoleHoles(sf::RectangleShape** moleHoles, const sf::Texture& holeTexture)
{
	for (int i = 0; i < NUM_MOLE_HOLE_COLS; i++)
	{
		for (int j = 0; j < NUM_MOLE_HOLE_ROWS; j++)
		{
			moleHoles[i][j].setTexture(&holeTexture);
		}
	}
}

void drawMoleHoles(sf::RenderWindow& gameWindow, sf::RectangleShape** moleHoles)
{
	for (int i = 0; i < NUM_MOLE_HOLE_COLS; i++)
	{
		for (int j = 0; j < NUM_MOLE_HOLE_ROWS; j++)
		{
			gameWindow.draw(moleHoles[i][j]);
		}
	}
}