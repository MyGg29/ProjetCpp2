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
	bool isDead;

private:
	sf::RenderWindow *screen;
	std::vector<sf::RectangleShape> body;
	Direction directionOfMovement = Direction::Right;
	int length;
	int speed;
	int cpteur = 0;
	bool checkCollision(sf::RectangleShape a, sf::RectangleShape b);

};