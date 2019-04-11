#pragma once
#include "cScreen.h"
#include <SFML\Graphics.hpp>
#include "Button.h"

class MenuScreen : public cScreen {
public:
	MenuScreen();
	virtual int Run(sf::RenderWindow &App);
private:
	sf::Font police;
	Button playButton;
	sf::Text titleScreen;

};
