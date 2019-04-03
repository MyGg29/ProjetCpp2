#pragma once
#include "cScreen.h"
#include <SFML\Graphics.hpp>

class MenuScreen : public cScreen {
public:
	MenuScreen();
	virtual int Run(sf::RenderWindow &App);
private:
	sf::RectangleShape playButton;

};
