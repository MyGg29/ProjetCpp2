#pragma once
#include <SFML/Graphics.hpp>
class Button : public sf::Drawable
{
public:
	Button();
	~Button();
	bool isClicked(sf::Event::MouseButtonEvent);
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::Text text;
	sf::Color backgroundColor = sf::Color(sf::Color::Blue);
	sf::Vector2f size = sf::Vector2f(30,60);
	sf::Vector2f position = sf::Vector2f(100,100);
	sf::RectangleShape background = sf::RectangleShape(size);
	
};

