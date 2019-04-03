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
	while (Running) {
		while (App.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				return (-1);
			board.handleKeyEvent(event);
		}
		board.update(&clock);
		App.clear();
		board.draw(&App);
		App.display();
		if (board.isGameOver()) {
			Running = false;
		}
	}
	while (true) {
		float score = board.getScore();
		SaveScoreOverlay so;
		so.draw(&App);
		App.display();
	}

}
