#pragma once
#include <SFML\Graphics.hpp>
#include "Snake.h"
#include "Food.h"
#include "Util.h"

class Board {
public:
	Board(sf::RenderWindow *w);
	void handleKeyEvent(sf::Event event);
	void setSnake(Snake snake);
	void draw();
	int gameSpeed;
	bool isPaused();
	bool isGameOver();
	void update(sf::Clock *clock);

private:
	sf::RenderWindow *screen;
	Snake snake;
	Food food;
};
