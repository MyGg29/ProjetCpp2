// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <SFML/Graphics.hpp>    

#include <SFML/Window.hpp>
#include "Snake.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "My window");
	window.setFramerateLimit(60);
	Snake snake(&window);
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
			if (event.type == sf::Event::KeyPressed) {
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					snake.setDirection(Snake::Direction::Up);
					break;
				case sf::Keyboard::Right:
					snake.setDirection(Snake::Direction::Right);
					break;
				case sf::Keyboard::Down:
					snake.setDirection(Snake::Direction::Down);
					break;
				case sf::Keyboard::Left:
					snake.setDirection(Snake::Direction::Left);
					break;
				case sf::Keyboard::A:
					snake.increaseSize();
				default:
					break;
				}
			}
        }
		snake.move();
		window.clear();
		snake.draw();
		window.display();
		if (snake.isDead) {
			break;
		}
    }
    return 0;
}
