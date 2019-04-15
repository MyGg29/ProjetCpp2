#include "pch.h"
#include "GameOverOverlay.h"
#include <iostream>

GameOverOverlay::GameOverOverlay(sf::Vector2u windowSize)
{
	bool success = police.loadFromFile("arial.ttf");
	if (success) {
		gameOverMessage.setFont(police);
		gameOverMessage.setString("Game Over :(");
		gameOverMessage.setCharacterSize(30);
		gameOverMessage.setStyle(sf::Text::Bold);
		gameOverMessage.setFillColor(sf::Color::White);
		//centers the text on the screen
		Util::centerTransformable(gameOverMessage,gameOverMessage.getLocalBounds(),windowSize);

		button.setContent("Retry ?");
		button.setContentColor(sf::Color::Red);
		button.setBackgroundColor(sf::Color::Blue);
		Util::centerTransformable(button, button.getLocalBounds(), windowSize);
		button.move(0, 60);
	}
	else {
		throw std::exception("Font failled to load");
	}

}

void GameOverOverlay::setScoreAAfficher(sf::String score) {
	gameOverMessage.setString("Game Over :( \nScore : " + score);
}

void GameOverOverlay::handleEvent(sf::Event event) {
	if (event.type == sf::Event::MouseButtonReleased) {
		if (event.mouseButton.button == sf::Mouse::Left) {
			if (button.isClicked(event.mouseButton)) {
				restartGame = true;
			}
		}
	}
}

void GameOverOverlay::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(gameOverMessage);
	target.draw(button);
}

GameOverOverlay::~GameOverOverlay()
{
}

