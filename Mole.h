#include <SFML\Graphics.hpp>

const std::string MOLE_TEXTURE = "images/turtle.png";

class Mole : public sf::RectangleShape
{
public:
	Mole();
	Mole(int xCoordinate, int yCoordinate);
private:
	int xCoordinate;
	int yCoordinate;
};