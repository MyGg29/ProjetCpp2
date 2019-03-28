#include "pch.h"
#include "Snake.h"

Snake::Snake()
{
	length = 2;

	int nbWidth = 20;
	int nbHeight = 20;

	bodyPart.setSize(sf::Vector2f(nbWidth, nbHeight));
	bodyPart.setFillColor(sf::Color::Red);
	bodyPart.setPosition(300, 300);
	allBodyParts = new sf::RectangleShape[2];

	for (int i = 0; i < length; i++) {

		(allBodyParts + i)->setFillColor(sf::Color::Blue);
		(allBodyParts + i)->setSize(sf::Vector2f(nbWidth, nbHeight));
		(allBodyParts + i)->setPosition(100,100);
	}
}

void Snake::move(Direction direction)
{
	int windowWidth = 600;
	int windowHeight = 600;

	int nbWidth = 20;
	int nbHeight = 20;

	int gridWidth = windowWidth / nbWidth;
	int gridHeight = windowHeight / nbHeight;

	if (Snake::speed != 0)
	{
		// Change l'état de la direction au bon moment
		if (Snake::directionOfMovement != Snake::instructionDirection) {

			if (((int)bodyPart.getPosition().x%gridWidth) == 0 || ((int)bodyPart.getPosition().y%gridHeight) == 0) {

				Snake::directionOfMovement = Snake::instructionDirection;
			}
		}

		// Déplace le snake
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
		}

		// Gestion des collisions sur les bords de la fenêtre (à changer pour un game over)
		if (bodyPart.getPosition().x < 0) {

			bodyPart.setPosition(windowWidth, bodyPart.getPosition().y);
		}
		if (bodyPart.getPosition().x > windowWidth) {

			bodyPart.setPosition(0, bodyPart.getPosition().y);
		}
		if (bodyPart.getPosition().y < 0) {

			bodyPart.setPosition(bodyPart.getPosition().x, windowHeight);
		}
		if (bodyPart.getPosition().y > windowHeight) {

			bodyPart.setPosition(bodyPart.getPosition().x, 0);
		}
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


