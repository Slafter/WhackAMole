#pragma once
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <vector>
#include "Mole.h"

class PlayScreen
{
public:
	const std::string MOLE_HOLE_TEXTURE = "images/ellipse3.png";
	const std::string MOUSE_TEXTURE = "images/hammer.png";
	const std::string BACKGROUND_TEXTURE = "images/PSbackground.png";
	const std::string TIMERBAR_TEXTURE = "images/timerbar.png";
	const float MOUSE_POINTER_SIZE_X = 100.0f;
	const float MOUSE_POINTER_SIZE_Y = 100.0f;
	const static int NUM_MOLE_HOLE_COLS = 3;
	const static int NUM_MOLE_HOLE_ROWS = 3;
	const float GAMEOVER_TIME = 30.0f; // game length in seconds
	const float STARTING_MOLE_FREQ = 2.5f;
	const float SECOND_MOLE_FREQ = STARTING_MOLE_FREQ / 2.0f;
	const float THIRD_MOLE_FREQ = SECOND_MOLE_FREQ / 3.0f;
	const float SECOND_PHASE_START_TIME = 10.0f;
	const float THIRD_PHASE_START_TIME = 20.0f;
	const float TIMER_BAR_POS_X = 275.0f;
	const float TIMER_BAR_POS_Y = 25.0f;
	const float TIMER_BAR_SIZE_X = 250.0f;
	const float TIMER_BAR_SIZE_Y = 25.0f;

public:
	PlayScreen(int numCols, int numRows, sf::Vector2f);
	~PlayScreen();
	void handleMouseClick(sf::Vector2i clickPos);
	void updateActiveMoles();
	void updateMoleCreationRate();
	void updateMoleCreation();
	void updateTimerBar();
	void draw(sf::RenderWindow* window);
	bool isGameOver();
	int getMolesWhacked();
	void reset();

public:
	sf::RectangleShape background; // TODO: sf::Texture backgroundTexture;
	sf::RectangleShape mousePointer;
	sf::RectangleShape timerBar;
	sf::RectangleShape timerBarOutline;
	sf::RectangleShape moleHoles[NUM_MOLE_HOLE_COLS][NUM_MOLE_HOLE_ROWS];
	Mole* moles[NUM_MOLE_HOLE_COLS][NUM_MOLE_HOLE_ROWS];

private:
	bool mouseClicksMole(sf::Vector2i mousePos, int xCoord, int yCoord);
	
private:
	sf::Texture mouseTexture;
	sf::Texture moleHoleTexture;
	sf::Texture backgroundTexture;
	sf::Texture timerBarTexture;
	sf::Vector2i mousePos;
	int molesWhacked;
	float moleHoleSizeX;
	float moleHoleSizeY;
	sf::Clock timerBarClock;
	sf::Clock moleCreationTimer;
	float moleDeltaTime;
	float createMoleFreq;
};
