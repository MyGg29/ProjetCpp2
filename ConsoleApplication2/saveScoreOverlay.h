#pragma once
#include <SFML\Graphics.hpp>
class SaveScoreOverlay
{
public:
	SaveScoreOverlay();
	~SaveScoreOverlay();
	void draw(sf::RenderWindow *w);
private:
	sf::Text gameOverMessage;
};

