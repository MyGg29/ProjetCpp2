#pragma once
#include <SFML/Graphics.hpp>    


class Snake {

private:
	int length;
	int speed;
	sf::RectangleShape bodyPart;
	sf::RectangleShape* allBodyParts;

public:
	enum Direction {up, right, down, left};
	Snake();
	Direction directionOfMovement = Direction::right;
	void move(Direction direction);
	void speedUp(int value);
	sf::RectangleShape getBodyPart();
	sf::RectangleShape* getAllBodyParts();
	void update();


};