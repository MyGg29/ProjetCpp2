#include "pch.h"
#include "Snake.h"
#include "Util.h"

Snake::Snake(int windowSizeP, int gridSizeP)
{
	windowSize = windowSizeP;
	gridSize = gridSizeP;
	length = 1;
	for (int i = 0; i < length; i++) {
		sf::RectangleShape e;
		e.setFillColor(sf::Color::Blue);
		e.setSize(sf::Vector2f(gridSize, gridSize));
		e.setPosition(200,200);
		body.push_back(e);
	}
}

void Snake::draw(sf::RenderWindow *screen) {
	for (int i = 0; i < length; i++) {
		screen->draw(body[i]);
	}
}

void Snake::move()
{
	if (body.size() > 1)
	{
		//moves the rest of the body
		for (int i = body.size() - 1; i > 0; i--)
		{
			//Chaque partie du corps prend la place de celui qui est devant lui
			body[i].setPosition(body[i - 1].getPosition().x, body[i - 1].getPosition().y);
		}
	}
	//moves the head
	switch (directionOfMovement)
	{
	case Snake::Up:
		body.front().move(0, -gridSize);
		break;
	case Snake::Right:
		body.front().move(gridSize, 0);
		break;
	case Snake::Down:
		body.front().move(0, gridSize);
		break;
	case Snake::Left:
		body.front().move(-gridSize, 0);
		break;
	default:
		break;
	}
	//We can't die if we are length 1, nor 2
	if (body.size() > 2 || directionOfMovement!=Snake::Direction::Stop) {
		//if the head is touching a body part
		for(int i = 1; i < body.size(); i++){
			isDead = Util::checkCollision(body.front(), body[i]);
			if (isDead == true) {
				break;
			}
		}
	}
	//GameOver condition
	if (body.front().getPosition().x < 0){
		Snake::isDead = true;
		//body.front().setPosition(windowSize, body.front().getPosition().y);
	}
	if (body.front().getPosition().x > windowSize) {
		Snake::isDead = true;
		//body.front().setPosition(0, body.front().getPosition().y);
	}
	if (body.front().getPosition().y < 0){
		Snake::isDead = true;
		//body.front().setPosition(body.front().getPosition().x, windowSize);
	}
	if (body.front().getPosition().y > windowSize) {
		Snake::isDead = true;
		//body.front().setPosition(body.front().getPosition().x, 0);
	}
}


void Snake::increaseSize() {
	sf::RectangleShape newPart;
	newPart.setFillColor(sf::Color::Red);
	newPart.setSize(sf::Vector2f(gridSize, gridSize));
	sf::Vector2f newPosition(body.back().getPosition().x ,body.back().getPosition().y);
	newPart.setPosition(newPosition);

	body.push_back(newPart);
	length++;
}

void Snake::setDirection(Direction d) {
	directionOfMovement = d;
}

Snake::Direction Snake::getDirection() {
	return directionOfMovement;
}


sf::FloatRect Snake::getHeadHitbox()
{
	return body.front().getGlobalBounds();
}

int Snake::getLength()
{
	return length;
}

Snake::Direction Snake::getDirection()
{
	return directionOfMovement;
}
