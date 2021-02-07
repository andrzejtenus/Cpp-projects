#include "Character.h"

Character::Character(std::string file_link, sf::Vector2f positionVestor_, sf::Vector2i sizeVector_, sf::Vector2f scaleVector_)
	:Object(file_link, positionVestor_, sizeVector_, scaleVector_), HP(100)
{
}

void Character::CharacterUpdate()
{
	Character::kayBoard();
}
void Character::kayBoard()
{
	this->sprite.move(this->velocity);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && this->sprite.getPosition().y > 0 + (this->sizeVector.y*this->scaleVector.y) / 2)//
	{
		velocity.x = 0;
		velocity.y = -this->CharacterVelocity;
		this->sprite.setRotation(0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && this->sprite.getPosition().y < 800 - (this->sizeVector.y*this->scaleVector.y) / 2)
	{
		velocity.x = 0;
		velocity.y = this->CharacterVelocity;
		this->sprite.setRotation(180);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && this->sprite.getPosition().x > 0 + (this->sizeVector.y*this->scaleVector.x) / 2)
	{
		velocity.x = -this->CharacterVelocity;
		velocity.y = 0;
		this->sprite.setRotation(270);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && this->sprite.getPosition().x < 1600 - (this->sizeVector.y*this->scaleVector.x) / 2)
	{
		velocity.x = this->CharacterVelocity;
		velocity.y = 0;
		this->sprite.setRotation(90);
	}
	else
	{
		velocity.x = velocity.y = 0;
	}
}
void Character::HPUpdate(float dmg_)
{
	this->HP -= dmg_;
	std::cout << "twoja stara sra do gara12312";
}
int Character::skill(sf::RenderWindow &window)
{
		float maxflashRage=200;
		float flashRage=0;//
		float aimVectorMod=0;	//md³ugoœæ wektora myszki
		float PI = 3.14159265f;
		sf::Vector2f playerCenter;//
		sf::Vector2f aimDirNorm;
		playerCenter = sf::Vector2f(this->sprite.getPosition());
		aimDirNorm = mousevector(window);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		//ustawianie spritea
		this->sprite.setPosition(playerCenter + aimDirNorm*maxflashRage);
		float deg = atan2(aimDirNorm.y, aimDirNorm.x) * 180 / PI;
		this->sprite.setRotation(deg + 90);
		return 1;
	}
	return 0;
}
sf::Vector2f Character::mousevector(sf::RenderWindow &window)
{
	float aimVectorMod = 0;	//md³ugoœæ wektora myszki
	sf::Vector2f mousePosWindow;
	sf::Vector2f aimDir;
	sf::Vector2f aimDirNorm;
	mousePosWindow = sf::Vector2f(sf::Mouse::getPosition(window));
	aimDir = mousePosWindow - sf::Vector2f(this->sprite.getPosition());;
	aimVectorMod = sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));
	aimDirNorm = aimDir / aimVectorMod;
	return aimDirNorm;
}