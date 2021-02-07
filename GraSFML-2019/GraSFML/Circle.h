#pragma once
#include "Object.h"
#include "SFML\Graphics.hpp"
class Circle : sf::Drawable
{
public:
	Circle(float x, float y, float circleRadious);
	Circle()=delete;
	~Circle()=default;
private:
	sf::CircleShape shape;
	const float velocity{ 3.0f };
	sf::Vector2f vector{ velocity, velocity };
	void draw(sf::RenderTarget &target, sf::RenderStates state) const override;
};
