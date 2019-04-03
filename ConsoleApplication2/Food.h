#pragma once
#include <SFML\Graphics.hpp>
#include <cstdlib>

class Food {
public:
	Food(int windowSize, int gridSize);
	sf::FloatRect getFoodHitbox();
	void setNewRandomPosition();
	void draw(sf::RenderWindow *w);
	int gridSize;
	int windowSize;
private:
	sf::CircleShape food;
};
