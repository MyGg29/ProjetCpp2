#include "pch.h"
#include "Food.h"

Food::Food(int windowSizeP, int gridSizeP)
{
	windowSize = windowSizeP;
	gridSize = gridSizeP;
	food.setRadius(10);
	food.setFillColor(sf::Color::Red);
	food.setPosition(gridSize, gridSize);
}

sf::FloatRect Food::getFoodHitbox()
{
	return food.getGlobalBounds();
}

void Food::setNewRandomPosition()
{
	float newXposition = (rand() % windowSize/gridSize) * gridSize;
	float newYposition = (rand() % windowSize/gridSize) * gridSize;
	food.setPosition(newXposition, newYposition);
}

void Food::draw(sf::RenderWindow *screen)
{
	screen->draw(food);
}
