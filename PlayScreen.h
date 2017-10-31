#pragma once
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <vector>
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
	const float STARTING_MOLE_FREQ = 2.5f;
	const float SECOND_MOLE_FREQ = STARTING_MOLE_FREQ / 2.0f;
	const float THIRD_MOLE_FREQ = SECOND_MOLE_FREQ / 3.0f;
	const float SECOND_PHASE_START_TIME = 10.0f;
	const float THIRD_PHASE_START_TIME = 20.0f;

public:
	PlayScreen();
	PlayScreen(int numCols, int numRows, sf::Vector2f);
	sf::RectangleShape background; // TODO: sf::Texture backgroundTexture;
	sf::RectangleShape mousePointer;
	sf::RectangleShape moleHoles[NUM_MOLE_HOLE_COLS][NUM_MOLE_HOLE_ROWS];
	Mole moles[NUM_MOLE_HOLE_COLS][NUM_MOLE_HOLE_ROWS];
	void handleMouseClick(sf::Vector2i mousePos);
	void updateActiveMoles();
	void updateMoleCreationRate();
	void updateMoleCreation();
	int getMolesWhacked();

private:
	bool mouseClicksMole(sf::Vector2i mousePos, int xCoord, int yCoord);
	
private:
	sf::Texture mouseTexture;
	sf::Texture moleHoleTexture;
	int molesWhacked;
	float moleHoleSizeX;
	float moleHoleSizeY;
	sf::Clock timerBarClock;
	float createMoleFreq;
	sf::Clock moleCreationTimer;
	float moleDeltaTime;

	// TODO: sf::Rectangle timerBar
};
