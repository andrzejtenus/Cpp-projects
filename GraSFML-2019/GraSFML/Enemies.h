#pragma once
#include "Object.h"
class Enemies :
	public Object
{
public:
	Enemies();
	~Enemies();
private:
	sf::Vector2f speed;
};

