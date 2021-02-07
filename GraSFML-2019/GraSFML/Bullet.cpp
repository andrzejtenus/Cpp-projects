#include "Bullet.h"

Bullet::Bullet(std::string file_link, sf::Vector2f positionVestor_, sf::Vector2i sizeVector_, sf::Vector2f scaleVector_, float DMG_)
	:Object(file_link, positionVestor_, sizeVector_, scaleVector_), DMG(DMG_)
{
	speedVector = { 0,0 };
}
void Bullet::setspeedVector(sf::Vector2f vector_)
{
	float deg = atan2(vector_.y, vector_.x) * 180 / 3.14f;
	this->sprite.setRotation(deg + 90);
	this->speedVector = vector_*this->speed;
}
void Bullet::BulletUpdate()
{
	sprite.move(this->speedVector);
}