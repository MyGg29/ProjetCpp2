#pragma once
#include <SFML\Graphics.hpp>
#include <cstdlib>

class Food {
public:
	Food();
	sf::FloatRect getFoodHitbox();
	void setNewRandomPosition(int xBound, int yBound);
	void draw(sf::RenderWindow *w);
private:
	sf::CircleShape food;
};
