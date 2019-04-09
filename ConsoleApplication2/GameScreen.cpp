#include "pch.h"
#include "GameScreen.h"

GameScreen::GameScreen()
{
}

int GameScreen::Run(sf::RenderWindow &App)
{
	bool Running = true;
	sf::Event event;
	sf::Clock clock;
	SaveScoreOverlay so;
	while (Running) {
		App.clear();
		while (App.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				return (-1);
			board.handleKeyEvent(event);
			so.handleEvent(event);
		}
		if (board.isGameOver()) {
			float score = board.getScore();
			if (so.restartGame) {
				board.reset();
				so.restartGame = false;
			}
			so.draw(&App);
		}
		else {
			board.update(&clock);
		}
		board.draw(&App);
		App.display();
	}
}
