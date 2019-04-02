#pragma once
#include <SFML/Graphics.hpp>
#include "Food.h"
#include "Snake.h"

class Util {
public:
	static bool checkCollision(sf::RectangleShape a, sf::RectangleShape b);
	static bool checkCollision(Snake s, Food f);
	
};