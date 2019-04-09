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
	GameOverOverlay so;
	while (Running) {
		App.clear();
		while (App.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				return (-1);
			board.handleKeyEvent(event);
			so.handleEvent(event);
		}
		if (board.isGameOver()) {
			int score = board.getScore();
			so.setScoreAAfficher(std::to_string(score));
			if (so.restartGame) {
				board.reset();
				so.restartGame = false;
			}
			App.draw(so);
		}
		else {
			board.update(&clock);
		}
		App.draw(board);
		App.display();
	}
}
