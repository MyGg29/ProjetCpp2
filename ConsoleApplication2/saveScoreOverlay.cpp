#include "pch.h"
#include "saveScoreOverlay.h"


SaveScoreOverlay::SaveScoreOverlay()
{
	sf::Font font;
	bool success = font.loadFromFile("arial.ttf");
	if (success) {
		gameOverMessage = sf::Text("Test", font);
		gameOverMessage.setCharacterSize(30);
		gameOverMessage.setStyle(sf::Text::Bold);
		gameOverMessage.setFillColor(sf::Color::Red);
	}
	else {
		throw std::exception("Font failled to load");
	}

}


SaveScoreOverlay::~SaveScoreOverlay()
{
}

void SaveScoreOverlay::draw(sf::RenderWindow * w)
{
	w->draw(gameOverMessage);
}
