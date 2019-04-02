#pragma once
#include <SFML/Graphics.hpp>    


class Snake {
public:
	enum Direction {Up, Right, Down, Left};
	Snake(sf::RenderWindow *w);
	void increaseSize();
	void move();
	void draw();
	void setDirection(Direction direction);
	bool isDead;
	sf::FloatRect getHeadHitbox();

private:
	sf::RenderWindow *screen;
	std::vector<sf::RectangleShape> body;
	Direction directionOfMovement = Direction::Right;
	int length;
	int speed = 1;
	int cpteur = 0;
};