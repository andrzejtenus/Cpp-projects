#include "Object.h"

Object::Object(std::string file_link, sf::Vector2f positionVestor_, sf::Vector2i sizeVector_,sf::Vector2f scaleVector_)
	:positionVector(positionVestor_), sizeVector(sizeVector_),scaleVector(scaleVector_)
{
	texture.loadFromFile(file_link);
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, sizeVector.x, sizeVector.y));
	sprite.setOrigin(sizeVector.x / 2, sizeVector.y / 2);
	sprite.setColor(sf::Color(255, 255, 255, 200));
	sprite.scale(scaleVector);
	sprite.setPosition(positionVector.x, positionVector.y);
}


