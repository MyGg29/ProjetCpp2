#include "pch.h"
#include "MenuScreen.h"
#include "Util.h"

MenuScreen::MenuScreen() 
{
}

int MenuScreen::Run(sf::RenderWindow &App)
{
	bool Running = true;
	sf::Event event;
	loadTitleScreen(App.getSize());
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

void MenuScreen::loadTitleScreen(sf::Vector2u windowSize){
	bool success = police.loadFromFile("arial.ttf");
	if (success) {
		titleScreen.setFont(police);
		titleScreen.setString("ISNAKE");
		titleScreen.setCharacterSize(30);
		titleScreen.setStyle(sf::Text::Bold);
		titleScreen.setFillColor(sf::Color::Red);
		Util::centerTransformable(titleScreen, titleScreen.getGlobalBounds(), windowSize);

	}
	else {
		throw std::exception("Font failled to load");
	}

	playButton.setContent("Play");
	Util::centerTransformable(playButton, playButton.getLocalBounds(), windowSize);
	playButton.move(0, 30);
	
}
