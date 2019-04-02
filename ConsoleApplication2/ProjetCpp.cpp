#include "pch.h"
#include <SFML/Graphics.hpp>    

#include <SFML/Window.hpp>
#include "Snake.h"
#include "Board.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "My window");
	window.setFramerateLimit(60);
	sf::Clock clock;
	Board board;

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
			board.handleKeyEvent(event);
        }
		//we pass the clock so that the board knows how much time passed since the last frame
		board.update(&clock);
		window.clear();
		board.draw(&window);
		window.display();
		if (board.isGameOver()) {
			break;
		}
    }
    return 0;
}
