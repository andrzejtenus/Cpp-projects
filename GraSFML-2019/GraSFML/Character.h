#pragma once
#include "Object.h"
#include "SFML\Graphics.hpp"

class Character:public Object
{
public:
	Character(std::string, sf::Vector2f, sf::Vector2i, sf::Vector2f);
	Character()=delete;
	~Character()=default;
	void CharacterUpdate();
	void kayBoard();
	int skill(sf::RenderWindow &);
	void HPUpdate(float dmg);
	sf::Vector2f mousevector(sf::RenderWindow &);
protected:
	
	float CharacterVelocity{ 6.0f };	
	sf::Vector2f velocity{ CharacterVelocity,CharacterVelocity };
	float HP;
};

