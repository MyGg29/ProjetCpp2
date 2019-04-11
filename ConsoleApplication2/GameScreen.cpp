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
	GameOverOverlay overlay;
	while (Running) {
		App.clear();
		while (App.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				return (-1);
			board.handleKeyEvent(event);
			overlay.handleEvent(event);
		}
		if (board.isGameOver()) {
			int score = board.getScore();
			overlay.setScoreAAfficher(std::to_string(score));
			if (overlay.restartGame) {
				board.reset();
				overlay.restartGame = false;
			}
			App.draw(overlay);
		}
		else {
			board.update(&clock);
		}
		App.draw(board);
		App.display();
	}
}
