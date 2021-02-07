#pragma once
#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"Object.h"
#include "Character.h"
#include "Bullet.h"
#include <time.h>

class WindowDisplay
{
public:;
	WindowDisplay();
	~WindowDisplay()=default;
	WindowDisplay(float X_size_, float y_size_, int fps_);
	friend class Character;
	void display();
protected:
	float X_Size, Y_size;
	int fps;
	sf::Vector2f scaleVector{ 0.1,0.1 };
	int flashCD=5;
};

