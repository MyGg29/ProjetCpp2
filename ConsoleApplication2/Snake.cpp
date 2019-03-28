#include "pch.h"
#include "Snake.h"

Snake::Snake(sf::RenderWindow *w)
{
	screen = w;
	length = 1;
	for (int i = 0; i < length; i++) {
		sf::RectangleShape e;
		e.setFillColor(sf::Color::Blue);
		e.setSize(sf::Vector2f(20, 20));
		e.setPosition(200,200);
		body.push_back(e);
	}
}

void Snake::draw() {
	for (int i = 0; i < length; i++) {
		screen->draw(body[i]);
	}
}

void Snake::move()
{
	cpteur++;
	if (body.size() > 1 && cpteur >= 20)
	{
		cpteur = 0;
		for (int i = body.size() - 1; i > 0; i--)
		{
			//Chaque partie du corps prend la place de celui qui est devant lui
			body[i].setPosition(body[i - 1].getPosition().x, body[i - 1].getPosition().y);
		}
	}
	switch (directionOfMovement)
	{
	case Snake::Up:
		body.front().move(0, -1);
		break;
	case Snake::Right:
		body.front().move(1, 0);
		break;
	case Snake::Down:
		body.front().move(0, 1);
		break;
	case Snake::Left:
		body.front().move(-1, 0);
		break;
	default:
		break;
	}
	//clip
	if (body.front().getPosition().x < 0){
		body.front().setPosition(600, body.front().getPosition().y);
	}
	if (body.front().getPosition().x > 600) {
		body.front().setPosition(0, body.front().getPosition().y);
	}
	if (body.front().getPosition().y < 0){
		body.front().setPosition(body.front().getPosition().x, 600);
	}
	if (body.front().getPosition().y > 600) {
		body.front().setPosition(body.front().getPosition().x, 0);
	}
}

void Snake::increaseSize() {
	sf::RectangleShape newPart;
	newPart.setFillColor(sf::Color::Red);
	newPart.setSize(sf::Vector2f(20	, 20));
	sf::Vector2f newPosition(body.back().getPosition().x ,body.back().getPosition().y);
	newPart.setPosition(newPosition);

	body.push_back(newPart);
	length++;
}

void Snake::setDirection(Direction d) {
	directionOfMovement = d;
}
