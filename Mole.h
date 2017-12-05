#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"

class Mole : public sf::RectangleShape
{
public:
	const std::string MOLE_TEXTURE = "images/turtle-anim.png";
	const std::string MOLE_CLICKED_TEXTURE = "images/turtle-anim-clicked.png";
	const float ACTIVE_MOLE_DURATION = 2.0f;
	const int TEXTURE_COLS = 7;
	const int TEXTURE_ROWS = 7;

public:
	Mole(sf::Vector2f size, int xCoordinate, int yCoordinate);
	~Mole();
	void updateActiveStatus();
	void restartActiveTimer();
	void restartAnimTimer();
	void updateTexture();
	void resetAnimation();

public:
	bool isActive;
	bool isClicked;
	int xCoordinate;
	int yCoordinate;

private:
	sf::Texture moleTexture;
	sf::Texture moleClickedTexture;
	float activeDeltaTime;
	sf::Clock moleActiveTimer;
	float animDeltaTime;
	Animation* moleAnim;
	Animation* moleClickedAnim;
	sf::Clock animTimer;

};
