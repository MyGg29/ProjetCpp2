#include "pch.h"
#include "Button.h"


Button::Button()
{
}

bool Button::isClicked(sf::Event::MouseButtonEvent mouseButton) {
	if (background.getGlobalBounds().contains(mouseButton.x, mouseButton.y)) {
		return true;
	}
	else {
		return false;
	}
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(background);
}

Button::~Button()
{
}
