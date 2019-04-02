#pragma once
#include <SFML\Graphics.hpp>

class Food {
public:
	Food(sf::RenderWindow *w);
	sf::FloatRect getFoodHitbox();
	void setNewRandomPosition();
	void draw();
private:
	sf::CircleShape food;
	sf::RenderWindow* screen;
};
