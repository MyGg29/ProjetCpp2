#pragma once
#include <SFML\Graphics.hpp>
#include "Button.h"
class SaveScoreOverlay
{
public:
	SaveScoreOverlay();
	~SaveScoreOverlay();
	void draw(sf::RenderWindow *w);
	void handleEvent(sf::Event e);
	bool restartGame = false;
private:
	sf::Text gameOverMessage;
	sf::Text userNameInput;
	sf::String playerUserName;
	//arial needs to stay alive because it's not copied inside Text
	sf::Font arial;
	Button button;
};

