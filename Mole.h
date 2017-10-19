#include <SFML\Graphics.hpp>

const std::string MOLE_TEXTURE = "images/turtle.png";

class Mole : public sf::RectangleShape
{
public:
	Mole(sf::Vector2f size, int xCoordinate, int yCoordinate);
	int getXCoord();
	int getYCoord();
private:
	int xCoordinate;
	int yCoordinate;
	sf::Texture moleTexture;
};