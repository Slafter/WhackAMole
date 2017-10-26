#pragma once
#include <SFML/Graphics.hpp>

class Mole : public sf::RectangleShape
{
public:
	const std::string MOLE_TEXTURE = "images/turtle.png";
	const float ACTIVE_MOLE_DURATION = 2.0f;

public:
	Mole();
	Mole(sf::Vector2f size, int xCoordinate, int yCoordinate);
	void updateActiveStatus();
	void restartTimer();

public:
	bool isActive;
	int xCoordinate;
	int yCoordinate;
	sf::Texture moleTexture;


private:
	float deltaTime;
	sf::Clock moleTimer;

};
