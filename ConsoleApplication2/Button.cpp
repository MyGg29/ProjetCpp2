#include "pch.h"
#include "Button.h"


Button::Button(sf::String content, sf::Color textColor, sf::Color backgroundColor )
{
	bool success = police.loadFromFile("arial.ttf");
	if (success) {
		text.setFont(police);
		text.setString(content);
		text.setCharacterSize(25);
		text.setStyle(sf::Text::Bold);
		text.setFillColor(textColor);
	}
	background.setSize(sf::Vector2f(text.getLocalBounds().width + 5, text.getCharacterSize() + 5));
	background.setFillColor(backgroundColor);
}

bool Button::isClicked(sf::Event::MouseButtonEvent mouseButton) {
	sf::FloatRect bounds = background.getGlobalBounds();
	sf::FloatRect transformedBounds = getTransform().transformRect(bounds);
	if (transformedBounds.contains(mouseButton.x, mouseButton.y)) {
		return true;
	}
	else {
		return false;
	}
}

void Button::setContent(sf::String s)
{
	text.setString(s);
}

void Button::setContentColor(sf::Color c)
{
	text.setFillColor(c);
}

void Button::setBackgroundColor(sf::Color c)
{
	background.setFillColor(c);
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();
	target.draw(background, states);
	target.draw(text, states);
}

Button::~Button()
{
}
