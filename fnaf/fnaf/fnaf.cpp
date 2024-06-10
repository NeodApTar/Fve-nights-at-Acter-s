#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>
#include "Pomehi.h"
#include "GUI.h"
#include "Game.h"
using namespace std;
using namespace sf;

int main()

{
	srand(time(NULL));
	RenderWindow window(VideoMode(1920, 1080), "fnaf", Style::Fullscreen);
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);
	Texture menu;
	Texture Button1;
	Image button1;
	//button1.loadFromFile("Resources\\ne.bmp");
	///*button1.createMaskFromColor(button1.getPixel(1, 1));*/
	//Button1.loadFromImage(button1);
	menu.loadFromFile("resources\\1.png");
	menu.setSmooth(true);
	Sprite Menu;
	Sprite BUtton1;
	/*Button1.setSmooth(true);
	BUtton1.setTexture(Button1);
	BUtton1.setScale(1.2, 1.2);*/
	Menu.setTexture(menu);
	Music mainmenu;
	Pomehi pomehi;
	pomehi.load();
	mainmenu.openFromFile("resources\\fnaf1.ogg");
	Menu.setTextureRect(IntRect(0, 0, 1920, 1080));
	//Menu.setScale(2.4, 1.8);
	mainmenu.play();
	mainmenu.setLoop(true);
	Clock clock4;
	/*BUtton1.setPosition(960 - 200, 540 - 38);*/
	GUI button;
	GUI Name;
	Vector2f mousef;
	Vector2i mouse;
	
	game gam;
	
	FloatRect test(Vector2f(200, 600), Vector2f(203, 33));
	button.Load("resources\\448.png", true, 1, 1, 200, 600);
	Name.Load("resources\\444.png", true, 2, 2, 200,50);
	while (window.isOpen())
	{
		mouse = sf::Mouse::getPosition(window);
		mousef.x = mouse.x;
		mousef.y = mouse.y;
		FloatRect mouses(mousef, Vector2f(100, 100));
		Event event;
		if (test.intersects(mouses))
			if (button.checkint(mouses) && Mouse::isButtonPressed(Mouse::Left))
			{
				mainmenu.pause();
				gam.game_run(window);
			}	while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear(Color::Black);

		window.draw(Menu);
		
		Name.draw(window);
			pomehi.draw(window);
		
		button.draw(window);
		window.display();
	}
		
}