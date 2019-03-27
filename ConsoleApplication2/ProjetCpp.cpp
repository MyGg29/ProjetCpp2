// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <SFML/Graphics.hpp>    

#include <SFML/Window.hpp>
#include "Snake.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "My window");
	sf::RectangleShape rectangle;
	window.setFramerateLimit(60);
	Snake snake;
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
					snake.directionOfMovement = Snake::Direction::up;
					break;
				case sf::Keyboard::Right:
					snake.directionOfMovement = Snake::Direction::right;
					break;
				case sf::Keyboard::Down:
					snake.directionOfMovement = Snake::Direction::down;
					break;
				case sf::Keyboard::Left:
					snake.directionOfMovement = Snake::Direction::left;
					break;
				default:
					break;
				}
			}
        }

		snake.update();
		window.clear();
		window.draw(snake.getBodyPart());
		window.draw(snake.getAllBodyParts()[0]);
		window.draw(snake.getAllBodyParts()[1]);
		window.display();
    }
    return 0;
}
