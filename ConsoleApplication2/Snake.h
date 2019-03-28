#pragma once
#include <SFML/Graphics.hpp>    


class Snake {
public:
	enum Direction {Up, Right, Down, Left};
	Snake(sf::RenderWindow *w);
	void increaseSize();
	void speedUp(int value);
	void move();
	void draw();
	void setDirection(Direction direction);

private:
	Direction directionOfMovement = Direction::Right;
	sf::RenderWindow *screen;
	Direction lastDirection = Direction::Right;
	int length;
	int speed;
	std::vector<sf::RectangleShape> body;
	int cpteur = 0;

};