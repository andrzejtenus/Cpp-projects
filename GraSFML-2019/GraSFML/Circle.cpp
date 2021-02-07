#include "Circle.h"



Circle::Circle(float x, float y, float circleRadious)
{
	shape.setPosition(x, y);
	shape.setRadius(circleRadious);
	shape.setFillColor(sf::Color::White);
	shape.setOrigin(circleRadious, circleRadious);
}

void Circle::draw(sf::RenderTarget &target, sf::RenderStates state) const
{
	target.draw(this->shape, state);
}