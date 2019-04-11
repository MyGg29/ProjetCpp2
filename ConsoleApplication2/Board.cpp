#include "pch.h"
#include "Board.h"
#include "Snake.h"
#include <iostream>


Board::Board():snake(windowSize, gridSize),food(windowSize, gridSize)
{
}

void Board::handleKeyEvent(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed) {
		switch (event.key.code)
		{
		case sf::Keyboard::Up:
			if (snake.getDirection() != Snake::Direction::Down) {
				snake.setDirection(Snake::Direction::Up);
			}
			snake.lastDir = snake.getDirection();
			break;
		case sf::Keyboard::Right:
			if (snake.getDirection() != Snake::Direction::Left) {
				snake.setDirection(Snake::Direction::Right);
			}
			snake.lastDir = snake.getDirection();
			break;
		case sf::Keyboard::Down:
			if (snake.getDirection() != Snake::Direction::Up) {
				snake.setDirection(Snake::Direction::Down);
			}
			snake.lastDir = snake.getDirection();
			break;
		case sf::Keyboard::Left:
			if (snake.getDirection() != Snake::Direction::Right) {
				snake.setDirection(Snake::Direction::Left);
			}
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
		}
	}
}

bool Board::isPaused()
{
	return pause;
}

// Le Board decide si la partie est fini parce que ca pourrai être fonction d'autre choses que le snake (le temps de jeu, le nombre de pomme mangé, etc)
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
			food.setNewRandomPosition();
			gameSpeed += 0.5;
		}
		clock->restart();
	}
}

float Board::getScore()
{
	int score = 0;
	score += snake.getLength();
	//score depends on the time spent as well ? 
	return score;
}

void Board::reset()
{
	snake = Snake(windowSize,gridSize);
	food = Food(windowSize,gridSize);
}

void Board::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(snake);
	target.draw(food);
}

