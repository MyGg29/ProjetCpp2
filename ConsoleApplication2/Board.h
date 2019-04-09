#pragma once
#include <SFML\Graphics.hpp>
#include "Snake.h"
#include "Food.h"
#include "Util.h"

class Board : sf::Drawable {
public:
	Board();
	void handleKeyEvent(sf::Event event);
	float gameSpeed = 5;
	bool isPaused();
	bool isGameOver();
	void update(sf::Clock *clock);
	float getScore();
	void reset();

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	Snake snake;
	Food food;
	bool pause = false;
};
