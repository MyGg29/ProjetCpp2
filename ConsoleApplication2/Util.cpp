#include "pch.h"
#include "Util.h"

bool Util::checkCollision(sf::RectangleShape a, sf::RectangleShape b){
	return a.getGlobalBounds().intersects(b.getGlobalBounds());
}
bool Util::checkCollision(Snake snake, Food food) {
	return snake.getHeadHitbox().intersects(food.getFoodHitbox());
}

