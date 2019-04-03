#pragma once
#include <SFML/Graphics.hpp>    


class Snake {
public:
	enum Direction {Up, Right, Down, Left, Stop};
	Snake(int windowSize, int gridSize);
	void increaseSize();
	void move();
	void draw(sf::RenderWindow *w);
	void setDirection(Direction direction);
	Direction getDirection();
	bool isDead;
	sf::FloatRect getHeadHitbox();
	int getLength();
	int gridSize;
	int windowSize;
	Direction lastDir;

private:
	std::vector<sf::RectangleShape> body;
	Direction directionOfMovement = Direction::Right;
	int length;
	int speed = 1;
	int cpteur = 0;
};