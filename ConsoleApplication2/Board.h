#pragma once
#include <SFML\Graphics.hpp>
#include "Snake.h"
#include "Food.h"
#include "Util.h"

class Board {
public:
	Board();
	void handleKeyEvent(sf::Event event);
	void draw(sf::RenderWindow *w);
	float gameSpeed = 5;
	int windowSize = 600;
	int gridSize = 20;
	bool isPaused();
	bool isGameOver();
	void update(sf::Clock *clock);
	float getScore();

private:
	Snake snake;
	Food food;
	bool pause = false;
};
