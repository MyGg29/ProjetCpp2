#pragma once
#include <SFML/Graphics.hpp>
#include "Food.h"
#include "Snake.h"

class Util {
public:
	static bool checkCollision(sf::RectangleShape a, sf::RectangleShape b);
	static bool checkCollision(Snake s, Food f);

	static void centerTransformable(sf::Transformable& object,sf::FloatRect objectBounds, sf::Vector2u windowSize);
	static sf::Vector2f GetLocalSize(const sf::Text& text);

	void DrawText(sf::RenderWindow& window, const char* str, float x, float y);

};