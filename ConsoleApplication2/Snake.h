#pragma once
#include <SFML/Graphics.hpp>    


class Snake : public sf::Drawable{
public:
	enum Direction {Up, Right, Down, Left, Stop};
	Snake(int windowSize, int gridSize);
	void increaseSize();
	void move();
	void setDirection(Direction direction);
	Direction getDirection();
	bool isDead = false;
	sf::FloatRect getHeadHitbox();
	int getLength();
	int gridSize;
	int windowSize;
	Direction lastDir;

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	std::vector<sf::RectangleShape> body;
	Direction directionOfMovement = Direction::Right;
	int length;
	int speed = 1;
	int cpteur = 0;
};