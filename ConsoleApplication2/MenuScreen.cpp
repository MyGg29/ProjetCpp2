#include "pch.h"
#include "MenuScreen.h"

MenuScreen::MenuScreen() 
{
	bool success = police.loadFromFile("arial.ttf");
	if (success) {
		titleScreen.setFont(police);
		titleScreen.setString("ISNAKE");
		titleScreen.setCharacterSize(30);
		titleScreen.setStyle(sf::Text::Bold);
		titleScreen.setFillColor(sf::Color::Red);
		titleScreen.setPosition(100,280);
	}
	else {
		throw std::exception("Font failled to load");
	}

	playButton.setContent("Play");
	playButton.setPosition(sf::Vector2f(200, 200));
}

int MenuScreen::Run(sf::RenderWindow &App)
{
	bool Running = true;
	sf::Event event;
	while (Running) {
		App.clear();
		while (App.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				return (-1);
			if (event.type == sf::Event::MouseButtonReleased) {
				if (playButton.isClicked(event.mouseButton)) {
					return (1);
				}
			}
		}
		App.draw(titleScreen);
		App.draw(playButton);
		App.display();
	}

	return -1;
}
