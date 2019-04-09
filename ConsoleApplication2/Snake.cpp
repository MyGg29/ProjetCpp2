#include "pch.h"
#include "Snake.h"
#include "Util.h"

Snake::Snake()
{
	length = 1;
	for (int i = 0; i < length; i++) {
		sf::RectangleShape e;
		e.setFillColor(sf::Color::Blue);
		e.setSize(sf::Vector2f(20, 20));
		e.setPosition(200,200);
		body.push_back(e);
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
		body.front().move(0, -20);
		break;
	case Snake::Right:
		body.front().move(20, 0);
		break;
	case Snake::Down:
		body.front().move(0, 20);
		break;
	case Snake::Left:
		body.front().move(-20, 0);
		break;
	default:
		break;
	}
	//We can't die if we are length 1, nor 2
	if (body.size() > 2) {
		//if the head is touching a body part
		for(int i = 1; i < body.size(); i++){
			isDead = Util::checkCollision(body.front(), body[i]);
			if (isDead == true) {
				break;
			}
		}
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

sf::FloatRect Snake::getHeadHitbox()
{
	return body.front().getGlobalBounds();
}

int Snake::getLength()
{
	return length;
}

void Snake::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < length; i++) {
		target.draw(body[i]);
	}
}
