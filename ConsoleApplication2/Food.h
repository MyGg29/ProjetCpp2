#pragma once
#include <SFML\Graphics.hpp>
#include <cstdlib>

class Food : public sf::Drawable {
public:
	Food();
	sf::FloatRect getFoodHitbox();
	void setNewRandomPosition(int xBound, int yBound);
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::CircleShape food;
};
