#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
class GUI
{
	
	Image imga;
	Texture texture;
public:
	Sprite sprite;
	GUI()
	{

	}
	GUI(string localeto, bool mask, float scalex, float scaley, int pox, int poy)
	{
		imga.loadFromFile(localeto);
		if (mask)
			imga.createMaskFromColor(imga.getPixel(5, 0));
		texture.loadFromImage(imga);
		sprite.setTexture(texture);
		sprite.setPosition(pox, poy);
		sprite.setScale(scalex, scaley);
	}
	void Load(string localeto, bool mask, float scalex, float scaley, int pox, int poy)
	{
		imga.loadFromFile(localeto);
		if (mask)
			imga.createMaskFromColor(imga.getPixel(5, 0));
		texture.loadFromImage(imga);
		sprite.setTexture(texture);
		sprite.setPosition(pox, poy);
		sprite.setScale(scalex, scaley);
	}
	void SetPosition(int pox, int poy)
	{
		sprite.setPosition(pox, poy);
	}
	void SetMove(int pox, int poy)
	{
		sprite.move(pox, poy);
	}
	void draw(RenderWindow& window)
	{
		window.draw(sprite);
	}
	bool checkint(FloatRect rect)
	{
		bool otvet=sprite.getGlobalBounds().intersects(rect);
			return otvet;
	}
};