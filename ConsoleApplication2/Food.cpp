#include "pch.h"
#include "Food.h"

Food::Food()
{
	food.setRadius(10);
	food.setFillColor(sf::Color::Red);
	food.setPosition(20, 20);
}

sf::FloatRect Food::getFoodHitbox()
{
	return food.getGlobalBounds();
}

void Food::setNewRandomPosition(int xBound, int yBound)
{
	float newXposition = rand() % xBound;
	float newYposition = rand() % yBound;
	food.setPosition(newXposition, newYposition);
}

void Food::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(food);
}

