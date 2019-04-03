#include "pch.h"
#include "Board.h"
#include "Snake.h"

Board::Board() 
{
}

void Board::handleKeyEvent(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed) {
		switch (event.key.code)
		{
		case sf::Keyboard::Up:
			snake.setDirection(Snake::Direction::Up);
			snake.lastDir = snake.getDirection();
			break;
		case sf::Keyboard::Right:
			snake.setDirection(Snake::Direction::Right);
			snake.lastDir = snake.getDirection();
			break;
		case sf::Keyboard::Down:
			snake.setDirection(Snake::Direction::Down);
			snake.lastDir = snake.getDirection();
			break;
		case sf::Keyboard::Left:
			snake.setDirection(Snake::Direction::Left);
			snake.lastDir = snake.getDirection();
			break;
		case sf::Keyboard::A:
			snake.increaseSize();
			break;
		case sf::Keyboard::Escape:
			pause = !pause;
			if (pause) {
				snake.setDirection(Snake::Direction::Stop);
			}
			else {
				snake.setDirection(snake.lastDir);
			}
			break;
		default:
			break;
		}
	}
}

bool Board::isPaused()
{
	return pause;
}

bool Board::isGameOver()
{
	return snake.isDead;
}

void Board::update(sf::Clock *clock) {
	float elapsedSeconds = (*clock).getElapsedTime().asSeconds();
	//should we move the snake ?
	if (elapsedSeconds > 1/gameSpeed) {
		//we move the snake every second.
		//this makes us independent of the framerate
		if (!pause) { snake.move(); }
		if (Util::checkCollision(snake, food)) {
			snake.increaseSize();
			food.setNewRandomPosition(100,100);
			gameSpeed += 0.5;
		}
		clock->restart();
	}
}

float Board::getScore()
{
	float score = 0;
	score += snake.getLength();
	//score depends on the time spent as well ? 
	return score;
}

void Board::draw(sf::RenderWindow *screen) {
	snake.draw(screen);
	food.draw(screen);
}
