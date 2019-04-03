#include "pch.h"
#include "MenuScreen.h"

MenuScreen::MenuScreen() 
{
	playButton.setFillColor(sf::Color::Blue);
	playButton.setPosition(10, 10);
	playButton.setSize(sf::Vector2f(20, 100));
}

int MenuScreen::Run(sf::RenderWindow &App)
{
	bool Running = true;
	while (Running) {
		App.clear();
		App.draw(playButton);
		App.display();
	}

	return -1;
}
