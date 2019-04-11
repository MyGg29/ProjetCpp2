#include "pch.h"
#include <SFML/Graphics.hpp>    

#include <SFML/Window.hpp>
#include "cScreen.h"
#include "GameScreen.h"
#include "MenuScreen.h"

int main()
{
	std::vector<cScreen*> Screens;
	int screen = 0;
	sf::RenderWindow App(sf::VideoMode(600, 600),"Snake");
	MenuScreen s0;
	Screens.push_back(&s0);
	GameScreen s1;
	Screens.push_back(&s1);
	while (screen >= 0) {
		screen = Screens[screen]->Run(App);
	}
    return 0;
}
