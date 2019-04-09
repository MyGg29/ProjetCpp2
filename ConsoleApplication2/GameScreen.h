#pragma once
#include "cScreen.h"
#include "Board.h"
#include "GameOverOverlay.h"

class GameScreen : public cScreen {
public:
	GameScreen();
	virtual int Run(sf::RenderWindow &App);
private:
	Board board;
};
