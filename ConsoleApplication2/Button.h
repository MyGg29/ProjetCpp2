#pragma once
#include <SFML/Graphics.hpp>
class Button : public sf::Drawable, public sf::Transformable
{
public:
	Button(sf::String content = "Placeholder", sf::Color contentColor = sf::Color::Blue, sf::Color backgroundColor = sf::Color::Red);
	~Button();
	bool isClicked(sf::Event::MouseButtonEvent);
	void setContent(sf::String);
	void setContentColor(sf::Color);
	void setBackgroundColor(sf::Color);
	sf::FloatRect getLocalBounds();

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::Text text;
	sf::Font police;
	sf::Color backgroundColor;
	sf::Vector2f size;
	sf::Vector2f position;
	sf::RectangleShape background ;
	
};

