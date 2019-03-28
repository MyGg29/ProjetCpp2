#pragma once
#include <SFML/Graphics.hpp>    


class Snake {

private:
	int length;
	sf::RectangleShape bodyPart;
	sf::RectangleShape* allBodyParts;

public:
	enum Direction {up, right, down, left};
	Snake();
	Direction directionOfMovement = Direction::right;
	Direction instructionDirection;
	int speed;
	void move(Direction direction);
	void speedUp(int value);
	sf::RectangleShape getBodyPart();
	sf::RectangleShape* getAllBodyParts();
	void update();
};