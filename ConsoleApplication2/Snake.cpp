#include "pch.h"
#include "Snake.h"

Snake::Snake()
{
	length = 2;
	bodyPart.setSize(sf::Vector2f(100, 50));
	bodyPart.setFillColor(sf::Color::Red);
	bodyPart.setPosition(300, 300);
	allBodyParts = new sf::RectangleShape[2];
	for (int i = 0; i < length; i++) {
		(allBodyParts + i)->setFillColor(sf::Color::Blue);
		(allBodyParts + i)->setSize(sf::Vector2f(100, 50));
		(allBodyParts + i)->setPosition(100,100);
	}
}

void Snake::move(Direction direction)
{
	switch (direction)
	{
	case Snake::up:
		bodyPart.move(0, -1);
		break;
	case Snake::right:
		bodyPart.move(1, 0);
		break;
	case Snake::down:
		bodyPart.move(0, 1);
		break;
	case Snake::left:
		bodyPart.move(-1, 0);
		break;
	default:
		break;
	}
	if (bodyPart.getPosition().x < 0){
		bodyPart.setPosition(600, bodyPart.getPosition().y);
	}
	if (bodyPart.getPosition().x > 600) {
		bodyPart.setPosition(0, bodyPart.getPosition().y);
	}
	if (bodyPart.getPosition().y < 0){
		bodyPart.setPosition(bodyPart.getPosition().x, 600);
	}
	if (bodyPart.getPosition().y > 600) {
		bodyPart.setPosition(bodyPart.getPosition().x, 0);
	}
}

sf::RectangleShape Snake::getBodyPart()
{
	return bodyPart;
}

sf::RectangleShape* Snake::getAllBodyParts() {
	return allBodyParts;
}

void Snake::update()
{
	this->move(this->directionOfMovement);
}


