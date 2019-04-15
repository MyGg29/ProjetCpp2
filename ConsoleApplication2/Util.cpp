#include "pch.h"
#include "Util.h"

bool Util::checkCollision(sf::RectangleShape a, sf::RectangleShape b){
	return a.getGlobalBounds().intersects(b.getGlobalBounds());
}
bool Util::checkCollision(Snake snake, Food food) {
	return snake.getHeadHitbox().intersects(food.getFoodHitbox());
}

//an attempt to make a generic method
void Util::centerTransformable(sf::Transformable& object, sf::FloatRect objectBounds, sf::Vector2u windowSize) {
	object.setOrigin(objectBounds.left + objectBounds.width / 2.0f,
							objectBounds.top + objectBounds.height / 2.0f);
	object.setPosition(windowSize.x/2.0f,windowSize.y/2.0f);
}

