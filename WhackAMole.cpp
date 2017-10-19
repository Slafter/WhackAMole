#include <SFML/Graphics.hpp>
#include <iostream>
#include "Mole.h"

const int WINDOW_SIZE_X = 800;
const int WINDOW_SIZE_Y = 600;

const std::string MOLE_HOLE_TEXTURE = "images/ellipse.png";
const int NUM_MOLE_HOLE_COLS = 4;
const int NUM_MOLE_HOLE_ROWS = 4;
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
	/*////////////////////////
	// Mole.cpp Unit Test
	std::srand(std::time(0));
	int ranNum1 = std::rand() % NUM_MOLE_HOLE_COLS;
	int ranNum2 = std::rand() % NUM_MOLE_HOLE_ROWS;

	std::cout << ranNum1 << ", " << ranNum2 << std::endl;

	Mole mole1(sf::Vector2f(MOLE_HOLE_SIZE_Y, MOLE_HOLE_SIZE_Y), ranNum1, ranNum2);
	mole1.setOrigin(MOLE_HOLE_SIZE_Y / 2.0f, MOLE_HOLE_SIZE_Y / 2.0f);
	mole1.setPosition((float)(ranNum1 * ((WINDOW_SIZE_X - (450.0f / NUM_MOLE_HOLE_COLS) / 2.0f) / (float)NUM_MOLE_HOLE_COLS) + (450.0f / NUM_MOLE_HOLE_COLS)), 
		(float)(ranNum2 * ((WINDOW_SIZE_Y - (50.0f + (300.0f / NUM_MOLE_HOLE_ROWS)) / 2.0f) / (float)NUM_MOLE_HOLE_ROWS) + (50.0f + (300.0f / NUM_MOLE_HOLE_ROWS))));
	
	int ranNum3 = std::rand() % NUM_MOLE_HOLE_COLS;
	int ranNum4 = std::rand() % NUM_MOLE_HOLE_ROWS;

	std::cout << ranNum3 << ", " << ranNum4 << std::endl;

	Mole mole2(sf::Vector2f(MOLE_HOLE_SIZE_Y, MOLE_HOLE_SIZE_Y), ranNum3, ranNum4);
	mole2.setOrigin(MOLE_HOLE_SIZE_Y / 2.0f, MOLE_HOLE_SIZE_Y / 2.0f);
	mole2.setPosition((float)(ranNum3 * ((WINDOW_SIZE_X - (450.0f / NUM_MOLE_HOLE_COLS) / 2.0f) / (float)NUM_MOLE_HOLE_COLS) + (450.0f / NUM_MOLE_HOLE_COLS)), 
		(float)(ranNum4 * ((WINDOW_SIZE_Y - (50.0f + (300.0f / NUM_MOLE_HOLE_ROWS)) / 2.0f) / (float)NUM_MOLE_HOLE_ROWS) + (50.0f + (300.0f / NUM_MOLE_HOLE_ROWS))));
	/////////////////////////*/


	sf::RenderWindow gameWindow(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "Whack-A-Mole", sf::Style::Close);
	gameWindow.setMouseCursorVisible(false);

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

		/*//////////////////////////////
		// Mole.cpp Unit Test
		gameWindow.draw(mole1);
		gameWindow.draw(mole2);
		//////////////////////////////*/

		gameWindow.draw(mousePointer);
		gameWindow.display();
	}

	delete moleHoles;

	return 0;
}

sf::RectangleShape** createMoleHoleMatrix()
{
	float xOrigin = 450.0f / NUM_MOLE_HOLE_COLS;
	float yOrigin = 50.0f + (300.0f / NUM_MOLE_HOLE_ROWS);
	float xOffset = (WINDOW_SIZE_X - xOrigin / 2.0f) / (float)NUM_MOLE_HOLE_COLS;
	float yOffset = (WINDOW_SIZE_Y - yOrigin / 2.0f) / (float)NUM_MOLE_HOLE_ROWS;

	sf::RectangleShape** moleHoles;
	moleHoles = new sf::RectangleShape*[NUM_MOLE_HOLE_COLS];

	for (int i = 0; i < NUM_MOLE_HOLE_COLS; i++)
	{
		moleHoles[i] = new sf::RectangleShape[NUM_MOLE_HOLE_ROWS];

		for (int j = 0; j < NUM_MOLE_HOLE_ROWS; j++)
		{
			moleHoles[i][j] = sf::RectangleShape(sf::Vector2f(MOLE_HOLE_SIZE_X, MOLE_HOLE_SIZE_Y));
			moleHoles[i][j].setOrigin(MOLE_HOLE_SIZE_X / 2.0f, MOLE_HOLE_SIZE_Y / 2.0f);
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