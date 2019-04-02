#include "pch.h"
#include "Food.h"

Food::Food(sf::RenderWindow *w)
{
	screen = w;
	food.setRadius(10);
	food.setFillColor(sf::Color::Red);
	food.setPosition(50, 50);
}

sf::FloatRect Food::getFoodHitbox()
{
	return food.getGlobalBounds();
}

void Food::draw()
{
	screen->draw(food);
}
