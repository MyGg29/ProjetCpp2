#pragma once
#include <SFML\Graphics.hpp>
#include "Button.h"
class GameOverOverlay : public sf::Drawable
{
public:
	GameOverOverlay();
	~GameOverOverlay();
	void handleEvent(sf::Event e);
	bool restartGame = false;
	void setScoreAAfficher(sf::String);
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	Button button;
	sf::Text gameOverMessage;
	sf::Text userNameInput;
	sf::String playerUserName;
	//arial needs to stay alive because it's not copied inside Text
	sf::Font police;
};

