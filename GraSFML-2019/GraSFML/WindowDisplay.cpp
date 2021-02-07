#include "WindowDisplay.h"
#include"SFML\Graphics.hpp"
#include<vector>

void cooldown(int sec)
{
	clock_t cooldown;
	cooldown = clock() + sec * CLOCKS_PER_SEC;
	while (clock() < cooldown) {}
}

WindowDisplay::WindowDisplay() :X_Size(1600), Y_size(800), fps(60){}
WindowDisplay::WindowDisplay(float X_size_, float y_size_, int fps_):X_Size(X_size_), Y_size(y_size_), fps(fps_){}

void WindowDisplay::display()
{
	Character hipek("zeus.png", { 110, 110 }, { 512, 512 }, this->scaleVector);

	sf::RenderWindow renderWindow(sf::VideoMode(X_Size, Y_size), "Suchar69 Shooter");

	renderWindow.setFramerateLimit(fps);
	sf::Event event;
	clock_t cooldown= clock();

	Bullet bullet("lightning.png", { 110, 110 }, { 512, 512 }, 0.7f*this->scaleVector,10);
	std::vector<Bullet> bullets;
	//bullets.push_back(Bullet(bullet));



	while (renderWindow.isOpen()) {
		while (renderWindow.pollEvent(event)) {
			if (event.type == sf::Event::EventType::Closed) {
				renderWindow.close();
			}
		}
		renderWindow.clear(sf::Color::Black);
		/////////hipek
		hipek.CharacterUpdate();
		if (cooldown<clock())
		{
			if (hipek.skill(renderWindow)){
				cooldown = clock() + this->flashCD * CLOCKS_PER_SEC;
			}
		}
		hipek.draw(renderWindow);
		////////////pocisk
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			bullet.setPostion(hipek.getPosition());
			bullet.setspeedVector(hipek.mousevector(renderWindow));
			bullets.push_back(bullet);
		}
		for (size_t i = 0; i < bullets.size(); i++)
		{
			bullets[i].BulletUpdate();
			bullets[i].draw(renderWindow);
		}


		renderWindow.display();
	}
}


