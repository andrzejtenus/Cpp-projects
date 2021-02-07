#pragma once
#include "Object.h"
#include"Character.h"

class Bullet 
	:public Object
{
public:
	Bullet(std::string, sf::Vector2f, sf::Vector2i, sf::Vector2f, float);
	void BulletUpdate();
	void setspeedVector(sf::Vector2f);
private:
	float DMG;
	sf::Vector2f speedVector;
	float speed = 12.0f;
};
