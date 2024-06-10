#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Pomehi.h"


class Win
{

	sf::SoundBuffer win;
	sf::Sound chimes;
	sf::Sprite	sprite;
	sf::Texture texture[171];
	sf::Clock clock11;
	sf::Clock clock12;
public:
	void play(sf::RenderWindow& window)
	{
		
		win.loadFromFile("resources\\chimes.ogg");
		Sound chimes{ win };
		Pomehi pomehi;
		pomehi.load();
		int ii = 0;
		
		for (int i = 0; i < 171; i++)
		{
			string filename{ "resources\\win\\" };
			filename += "frame (" + to_string(i + 1) + ").jpg";
			texture[i].loadFromFile(filename);
		}
		chimes.play();
		while (ii < 171)
		{
			if (clock11.getElapsedTime().asMilliseconds() >= 50.8)
			{
				sprite.setTexture(texture[ii]);
				sprite.setScale(1920 / 600.0, 1080 / 338.0);
				window.draw(sprite);
				window.display();
				ii++; clock11.restart();
			}
		}

		clock12.restart();
		while (clock11.getElapsedTime().asSeconds() < 5)
		{
			if (clock12.getElapsedTime().asMilliseconds() > 16)
			{
				window.clear(Color(0, 0, 0, 255));
				pomehi.draw(window);
				window.display();
				clock12.restart();
			}
		}
	}
};