#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Pomehi.h"
class Screamer1
{
	const char animm[146][12]{
"tile001.jpg",
"tile002.jpg",
"tile003.jpg",
"tile004.jpg",
"tile005.jpg",
"tile006.jpg",
"tile007.jpg",
"tile008.jpg",
"tile009.jpg",
"tile010.jpg",
"tile011.jpg",
"tile012.jpg",
"tile013.jpg",
"tile014.jpg",
"tile015.jpg",
"tile016.jpg",
"tile017.jpg",
"tile018.jpg",
"tile019.jpg",
"tile020.jpg",
"tile021.jpg",
"tile022.jpg",
"tile023.jpg",
"tile024.jpg",
"tile025.jpg",
"tile026.jpg",
"tile027.jpg",
"tile028.jpg",
"tile029.jpg",
"tile030.jpg",
"tile031.jpg",
"tile032.jpg",
"tile033.jpg",
"tile034.jpg",
"tile035.jpg",
"tile036.jpg",
"tile037.jpg",
"tile038.jpg",
"tile039.jpg",
"tile040.jpg",
"tile041.jpg",
"tile042.jpg",
"tile043.jpg",
"tile044.jpg",
"tile045.jpg",
"tile046.jpg",
"tile047.jpg",
"tile048.jpg",
"tile049.jpg",
"tile050.jpg",
"tile051.jpg",
"tile052.jpg",
"tile053.jpg",
"tile054.jpg",
"tile055.jpg",
"tile056.jpg",
"tile057.jpg",
"tile058.jpg",
"tile059.jpg",
"tile060.jpg",
"tile061.jpg",
"tile062.jpg",
"tile063.jpg",
"tile064.jpg",
"tile065.jpg",
"tile066.jpg",
"tile067.jpg",
"tile068.jpg",
"tile069.jpg",
"tile070.jpg",
"tile071.jpg",
"tile072.jpg",
"tile073.jpg",
"tile074.jpg",
"tile075.jpg",
"tile076.jpg",
"tile077.jpg",
"tile078.jpg",
"tile079.jpg",
"tile080.jpg",
"tile081.jpg",
"tile082.jpg",
"tile083.jpg",
"tile084.jpg",
"tile085.jpg",
"tile086.jpg",
"tile087.jpg",
"tile088.jpg",
"tile089.jpg",
"tile090.jpg",
"tile091.jpg",
"tile092.jpg",
"tile093.jpg",
"tile094.jpg",
"tile095.jpg",
"tile096.jpg",
"tile097.jpg",
"tile098.jpg",
"tile099.jpg",
"tile100.jpg",
"tile101.jpg",
"tile102.jpg",
"tile103.jpg",
"tile104.jpg",
"tile105.jpg",
"tile106.jpg",
"tile107.jpg",
"tile108.jpg",
"tile109.jpg",
"tile110.jpg",
"tile111.jpg",
"tile112.jpg",
"tile113.jpg",
"tile114.jpg",
"tile115.jpg",
"tile116.jpg",
"tile117.jpg",
"tile118.jpg",
"tile119.jpg",
"tile120.jpg",
"tile121.jpg",
"tile122.jpg",
"tile123.jpg",
"tile124.jpg",
"tile125.jpg",
"tile126.jpg",
"tile127.jpg",
"tile128.jpg",
"tile129.jpg",
"tile130.jpg",
"tile131.jpg",
"tile132.jpg",
"tile133.jpg",
"tile134.jpg",
"tile135.jpg",
"tile136.jpg",
"tile137.jpg",
"tile138.jpg",
"tile139.jpg",
"tile140.jpg",
"tile141.jpg",
"tile142.jpg",
"tile143.jpg",
"tile144.jpg",
"tile145.jpg" };

sf::SoundBuffer scream;
sf::Sound screamer;
sf::Sprite	sprite;
sf::Texture texture[145];
sf::Clock clock11;
sf::Clock clock12;
public:
	void play(sf::RenderWindow& window)
	{
		Pomehi pomehi;
		pomehi.load();
		int ii = 0;
		scream.loadFromFile("resources\\ScreamerAktep.ogg");
		screamer.setBuffer(scream);
		for (int i = 0; i < 145; i++)
		{
			string filename{ "resources\\ScreamerAktep\\" };
			filename += animm[i];
			texture[i].loadFromFile(filename);
		}
		screamer.play();
	while (ii < 146)
	{
		if (clock11.getElapsedTime().asMilliseconds() >= 2.8)
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

class Screamer2
{
	
	sf::SoundBuffer scream;
	sf::Sound screamer;
	sf::Sprite	sprite;
	sf::Texture texture[33];
	sf::Clock clock11;
	sf::Clock clock12;
public:
	void play(sf::RenderWindow& window)
	{
		Pomehi pomehi;
		pomehi.load();
		int ii = 0;
		scream.loadFromFile("resources\\screamerus.ogg");
		screamer.setBuffer(scream);
		for (int i = 0; i < 33; i++)
		{
			string filename{ "resources\\ScreamerUsya\\" };
			filename += "frame ("+to_string(i+1)+").jpg";
			texture[i].loadFromFile(filename);
		}
		screamer.play();
		while (ii < 33)
		{
			if (clock11.getElapsedTime().asMilliseconds() >= 56.8)
			{
				sprite.setTexture(texture[ii]);
				sprite.setScale(1920 / 600.0, 1080 / 338.0);
				window.draw(sprite);
				window.display();
				ii++;clock11.restart();
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