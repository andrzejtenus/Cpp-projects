#pragma once
#include"SFML\Graphics.hpp"
#include<iostream>

class Object
{
public:
	Object::Object(std::string , sf::Vector2f, sf::Vector2i, sf::Vector2f );
	Object()=default;
	~Object()=default;
	void draw(sf::RenderWindow &r) { r.draw(sprite);
	}
	void setPostion(sf::Vector2f vector_) { sprite.setPosition(vector_); };
	sf::Vector2f getPosition() { return sprite.getPosition(); };

protected:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Vector2f sizeVector;
	sf::Vector2i positionVector;
	sf::Vector2f scaleVector;
};

/*
std::cout << positionVector.x<<"\t";
std::cout << positionVector.y << "\t";
std::cout << sizeVector.x << "\t";
std::cout << sizeVector.y << "\t";
std::cout << std::endl;
*/