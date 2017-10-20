#pragma once
#include <SFML/Graphics.hpp>

class Mole : public sf::RectangleShape
{
public:
	const std::string MOLE_TEXTURE = "images/turtle.png";

public:
	Mole();
	Mole(sf::Vector2f size, int xCoordinate, int yCoordinate);

public:
	bool isActive;
	int xCoordinate;
	int yCoordinate;
	sf::Texture moleTexture;

};
