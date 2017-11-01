#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"

class Mole : public sf::RectangleShape
{
public:
	const std::string MOLE_TEXTURE = "images/turtle-anim.png";
	const float ACTIVE_MOLE_DURATION = 2.0f;
	const int TEXTURE_COLS = 7;
	const int TEXTURE_ROWS = 7;

public:
	Mole();
	Mole(sf::Vector2f size, int xCoordinate, int yCoordinate);
	void updateActiveStatus();
	void restartTimer();
	void updateTexture();
	sf::Clock animTimer;
	Animation moleAnim;

public:
	bool isActive;
	int xCoordinate;
	int yCoordinate;
	sf::Texture moleTexture;


private:
	float deltaTime;
	sf::Clock moleTimer;
	float animDeltaTime;
	

};
