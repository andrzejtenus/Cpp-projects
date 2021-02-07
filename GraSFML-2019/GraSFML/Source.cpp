
#include"WindowDisplay.h"
int main()
{
	WindowDisplay window;
	window.display();

	
	return 0;
}	

/*
	Character hipek("zeus.png");
	Circle ball(400, 300, 2);
	sf::RenderWindow renderWindow(sf::VideoMode(1600, 800), "Suchar69 Shooter");
	renderWindow.setFramerateLimit(144);
	sf::Event event;

	while (renderWindow.isOpen()){
	while (renderWindow.pollEvent(event)){
	if (event.type == sf::Event::EventType::Closed) {
	renderWindow.close();
	}
	}

	renderWindow.clear(sf::Color::Black);
	renderWindow.draw(ball);
	hipek.CharacterUpdate();
	hipek.draw(renderWindow);
	renderWindow.display();
	}
	*/