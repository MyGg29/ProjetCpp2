#pragma once
#include <SFML\Graphics.hpp>
#include <cstdlib>

class Food : public sf::Drawable {
public:
	Food(int windowSize, int gridSize);
	sf::FloatRect getFoodHitbox();
	void setNewRandomPosition();
	int gridSize;
	int windowSize;
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::CircleShape food;
};
