#include "pch.h"
#include "saveScoreOverlay.h"
#include <iostream>

SaveScoreOverlay::SaveScoreOverlay()
{
	
	bool success = arial.loadFromFile("arial.ttf");
	if (success) {
		gameOverMessage.setFont(arial);
		gameOverMessage.setString("Game Over :(");
		gameOverMessage.setCharacterSize(30);
		gameOverMessage.setStyle(sf::Text::Bold);
		gameOverMessage.setFillColor(sf::Color::Red);
	}
	else {
		throw std::exception("Font failled to load");
	}

}

void SaveScoreOverlay::draw(sf::RenderWindow *w)
{
	gameOverMessage.setPosition(w->getSize().x / 2, w->getSize().y / 2);
	w->draw(gameOverMessage);
	w->draw(button);
}

void SaveScoreOverlay::handleEvent(sf::Event event) {
	if (event.type == sf::Event::MouseButtonReleased) {
		if (event.mouseButton.button == sf::Mouse::Left) {
			if (button.isClicked(event.mouseButton)) {
				restartGame = true;
			}
		}
	}
}

SaveScoreOverlay::~SaveScoreOverlay()
{
}

