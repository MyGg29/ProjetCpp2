#include "pch.h"
#include "Board.h"

Board::Board(sf::RenderWindow *w) : snake(w), food(w)
{
	screen = w;
}

void Board::handleKeyEvent(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed) {
		switch (event.key.code)
		{
		case sf::Keyboard::Up:
			snake.setDirection(Snake::Direction::Up);
			break;
		case sf::Keyboard::Right:
			snake.setDirection(Snake::Direction::Right);
			break;
		case sf::Keyboard::Down:
			snake.setDirection(Snake::Direction::Down);
			break;
		case sf::Keyboard::Left:
			snake.setDirection(Snake::Direction::Left);
			break;
		case sf::Keyboard::A:
			snake.increaseSize();
		default:
			break;
		}
	}
}

bool Board::isGameOver()
{
	return snake.isDead;
}

void Board::update(sf::Clock *clock) {
	float elapsedSeconds = (*clock).getElapsedTime().asSeconds();
	//should we move the snake ?
	if (elapsedSeconds > 1) {
		//we move the snake every second.
		//this makes us independent of the framerate
		snake.move();
		if (Util::checkCollision(snake, food)) {
			snake.increaseSize();
		}
		clock->restart();
	}
}

void Board::draw() {
	snake.draw();
	food.draw();
}

void Board::setSnake(Snake snake)
{
}
