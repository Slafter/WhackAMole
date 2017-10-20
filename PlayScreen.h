#pragma once
#include <SFML/Graphics.hpp>
#include "Mole.h"

class PlayScreen
{
public:
	const std::string MOLE_HOLE_TEXTURE = "images/ellipse.png";
	const std::string MOUSE_TEXTURE = "images/hammer.png";
	const float MOUSE_POINTER_SIZE_X = 100.0f;
	const float MOUSE_POINTER_SIZE_Y = 100.0f;
	const static int NUM_MOLE_HOLE_COLS = 4;
	const static int NUM_MOLE_HOLE_ROWS = 4;

public:
	PlayScreen();
	PlayScreen(int numCols, int numRows, sf::Vector2f);
	sf::RectangleShape background; // TODO: sf::Texture backgroundTexture;
	sf::RectangleShape* mousePointer;
	sf::RectangleShape moleHoles[NUM_MOLE_HOLE_COLS][NUM_MOLE_HOLE_ROWS];
	Mole moles[NUM_MOLE_HOLE_COLS][NUM_MOLE_HOLE_ROWS];

private:
	sf::Texture mouseTexture;
	sf::Texture moleHoleTexture;

	// TODO: sf::Rectangle timerBar
};
